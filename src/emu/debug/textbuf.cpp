// license:BSD-3-Clause
// copyright-holders:Aaron Giles
/***************************************************************************

    textbuf.cpp

    Debugger text buffering engine.

***************************************************************************/

#include "textbuf.h"

#include <new>



/***************************************************************************
    CONSTANTS
***************************************************************************/

#define MAX_LINE_LENGTH         250



/***************************************************************************
    TYPE DEFINITIONS
***************************************************************************/

struct text_buffer
{
	text_buffer(u32 bytes, u32 lines) noexcept
		: buffer(new (std::nothrow) char [bytes])
		, lineoffs(new (std::nothrow) s32 [lines])
		, bufsize(buffer ? bytes : 0)
		, linesize(lineoffs ? lines : 0)
	{
	}

	std::unique_ptr<char []> const  buffer;
	std::unique_ptr<s32 []> const   lineoffs;
	s32 const                       bufsize;
	s32                             bufstart = 0;
	s32                             bufend = 0;
	s32 const                       linesize;
	s32                             linestart = 0;
	s32                             lineend = 0;
	u32                             linestartseq = 0;
	s32                             maxwidth = 0;

	/*-------------------------------------------------
	    buffer_used - return the number of bytes
	    currently held in the buffer
	-------------------------------------------------*/

	s32 buffer_used() const noexcept
	{
		s32 const used(bufend - bufstart);
		return (used < 0) ? (used + bufsize) : used;
	}

	/*-------------------------------------------------
	    buffer_space - return the number of bytes
	    available in the buffer
	-------------------------------------------------*/

	s32 buffer_space() const noexcept
	{
		return bufsize - buffer_used();
	}
};



/***************************************************************************

    Buffer object management

***************************************************************************/

/*-------------------------------------------------
    text_buffer_alloc - allocate a new text buffer
-------------------------------------------------*/

text_buffer_ptr text_buffer_alloc(u32 bytes, u32 lines)
{
	// allocate memory for the text buffer object
	text_buffer_ptr text(new (std::nothrow) text_buffer(bytes, lines));

	if (!text)
		return nullptr;

	if (!text->buffer || !text->lineoffs)
		return nullptr;

	// initialize the buffer description
	text_buffer_clear(*text);

	return text;
}


/*-------------------------------------------------
    text_buffer_free - free a previously allocated
    text buffer
-------------------------------------------------*/

void text_buffer_deleter::operator()(text_buffer *text) const
{
	delete text;
}


/*-------------------------------------------------
    text_buffer_clear - clear a text buffer
-------------------------------------------------*/

void text_buffer_clear(text_buffer &text)
{
	// reset all the buffer pointers and other bits
	text.bufstart = 0;
	text.bufend = 0;

	text.linestart = 0;
	text.lineend = 0;
	text.linestartseq = 0;

	text.maxwidth = 0;

	// create the initial line
	text.lineoffs[0] = 0;
	text.buffer[text.lineoffs[0]] = 0;
}



/***************************************************************************

    Adding data to the buffer

***************************************************************************/

//-------------------------------------------------
//  text_buffer_print - print data to the text
//  buffer
//-------------------------------------------------

void text_buffer_print(text_buffer &text, std::string_view data)
{
	text_buffer_print_wrap(text, data, MAX_LINE_LENGTH);
}


//-------------------------------------------------
//  text_buffer_print_wrap - print data to the
//  text buffer with word wrapping to a given
//  column
//-------------------------------------------------

void text_buffer_print_wrap(text_buffer &text, std::string_view data, int wrapcol)
{
	s32 const stopcol = (wrapcol < MAX_LINE_LENGTH) ? wrapcol : MAX_LINE_LENGTH;

	// we need to ensure there is enough space for this string plus enough for the max line length
	s32 const needed_space = s32(data.length()) + MAX_LINE_LENGTH;

	// make space in the buffer if we need to
	while (text.buffer_space() < needed_space && text.linestart != text.lineend)
	{
		text.linestartseq++;
		if (++text.linestart >= text.linesize)
			text.linestart = 0;
		text.bufstart = text.lineoffs[text.linestart];
	}

	// now add the data
	for (int ch : data)
	{
		int linelen;

		// a CR resets our position
		if (ch == '\r')
			text.bufend = text.lineoffs[text.lineend];

		// non-CR data is just characters
		else if (ch != '\n')
			text.buffer[text.bufend++] = ch;

		// an explicit newline or line-too-long condition inserts a newline */
		linelen = text.bufend - text.lineoffs[text.lineend];
		if (ch == '\n' || linelen >= stopcol)
		{
			int overflow = 0;

			// if we're wrapping, back off until we hit a space
			if (linelen >= wrapcol)
			{
				// scan backwards, removing characters along the way
				overflow = 1;
				while (overflow < linelen && text.buffer[text.bufend - overflow] != ' ')
					overflow++;

				// if we found a space, take it; otherwise, reset and pretend we didn't try
				if (overflow < linelen)
					linelen -= overflow;
				else
					overflow = 0;
			}

			// did we beat the max width
			if (linelen > text.maxwidth)
				text.maxwidth = linelen;

			// append a terminator
			if (overflow == 0)
				text.buffer[text.bufend++] = 0;
			else
				text.buffer[text.bufend - overflow] = 0;

			// determine what the next line will be
			if (++text.lineend >= text.linesize)
				text.lineend = 0;

			// if we're out of lines, consume the next one
			if (text.lineend == text.linestart)
			{
				text.linestartseq++;
				if (++text.linestart >= text.linesize)
					text.linestart = 0;
				text.bufstart = text.lineoffs[text.linestart];
			}

			// if we don't have enough room in the buffer for a max line, wrap to the start
			if (text.bufend + MAX_LINE_LENGTH + 1 >= text.bufsize)
				text.bufend = 0;

			// create a new empty line
			text.lineoffs[text.lineend] = text.bufend - (overflow ? (overflow - 1) : 0);
		}
	}

	// null terminate what we have on this line
	text.buffer[text.bufend] = 0;
}



/***************************************************************************

    Reading data from the buffer

***************************************************************************/

/*-------------------------------------------------
    text_buffer_max_width - return the maximum
    width of all lines seen so far
-------------------------------------------------*/

u32 text_buffer_max_width(text_buffer const &text)
{
	return text.maxwidth;
}


/*-------------------------------------------------
    text_buffer_num_lines - return the number of
    lines in the text buffer
-------------------------------------------------*/

u32 text_buffer_num_lines(text_buffer const &text)
{
	s32 const lines = text.lineend + 1 - text.linestart;
	return (lines <= 0) ? (lines + text.linesize) : lines;
}


/*-------------------------------------------------
    text_buffer_line_index_to_seqnum - convert a
    line index into a sequence number
-------------------------------------------------*/

u32 text_buffer_line_index_to_seqnum(text_buffer const &text, u32 index)
{
	return text.linestartseq + index;
}


/*-------------------------------------------------
    text_buffer_get_seqnum_line - get a pointer to
    an indexed line in the buffer
-------------------------------------------------*/

const char *text_buffer_get_seqnum_line(text_buffer const &text, u32 seqnum)
{
	u32 const numlines = text_buffer_num_lines(text);
	u32 const index = seqnum - text.linestartseq;
	if (index >= numlines)
		return nullptr;
	return &text.buffer[text.lineoffs[(text.linestart + index) % text.linesize]];
}

/*---------------------------------------------------------------------
    text_buffer_lines::text_buffer_line_iterator::operator*
    Gets the line that the iterator currently points to.
-----------------------------------------------------------------------*/

std::string_view text_buffer_lines::text_buffer_line_iterator::operator*() const
{
	char const *const line = &m_buffer.buffer[m_buffer.lineoffs[m_lineptr]];

	auto next_lineptr = m_lineptr + 1;
	if (next_lineptr == m_buffer.linesize)
		next_lineptr = 0;

	char const *const nextline = &m_buffer.buffer[m_buffer.lineoffs[next_lineptr]];

	// -1 for the '\0' at the end of line
	ptrdiff_t difference = (nextline - line) - 1;

	if (difference < 0)
		difference += m_buffer.bufsize;

	return std::string_view{ line, std::string_view::size_type(difference) };
}

/*---------------------------------------------------------------------
    text_buffer_lines::text_buffer_line_iterator::operator++
    Moves to the next line.
-----------------------------------------------------------------------*/

text_buffer_lines::text_buffer_line_iterator &text_buffer_lines::text_buffer_line_iterator::operator++()
{
	if (++m_lineptr == m_buffer.linesize)
		m_lineptr = 0;

	return *this;
}

/*------------------------------------------------------
    text_buffer_lines::begin()
    Returns an iterator that points to the first line.
--------------------------------------------------------*/

text_buffer_lines::iterator text_buffer_lines::begin() const
{
	return text_buffer_line_iterator(m_buffer, m_buffer.linestart);
}

/*-----------------------------------------------------------
    text_buffer_lines::begin()
    Returns an iterator that points just past the last line.
-------------------------------------------------------------*/

text_buffer_lines::iterator text_buffer_lines::end() const
{
	return text_buffer_line_iterator(m_buffer, m_buffer.lineend);
}
