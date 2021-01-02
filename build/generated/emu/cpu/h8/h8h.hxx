void h8h_device::mov_l_r32ih_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP2 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP1 |= read16(TMP2+2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
}

void h8h_device::mov_l_r32ih_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP2 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP1 |= read16(TMP2+2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32l_r32ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP2 = r32_r(IR[1] >> 4);
	TMP1 = r32_r(IR[1]);
	set_nzv32(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP2+2, TMP1);
	prefetch_done();
}

void h8h_device::mov_l_r32l_r32ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP2 = r32_r(IR[1] >> 4);
	TMP1 = r32_r(IR[1]);
	set_nzv32(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP2+2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_abs16_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP2 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP1 |= read16(TMP2+2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
}

void h8h_device::mov_l_abs16_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP2 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP1 |= read16(TMP2+2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_abs32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP2 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	TMP1 |= read16(TMP2+2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
}

void h8h_device::mov_l_abs32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP2 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	TMP1 |= read16(TMP2+2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32l_abs16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1]);
	TMP2 = int16_t(IR[2]);
	set_nzv32(TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP2+2, TMP1);
	prefetch_done();
}

void h8h_device::mov_l_r32l_abs16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[1]);
	TMP2 = int16_t(IR[2]);
	set_nzv32(TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP2+2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32l_abs32_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1]);
	TMP2 = (IR[2] << 16) | IR[3];
	set_nzv32(TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	write16(TMP2+2, TMP1);
	prefetch_done();
}

void h8h_device::mov_l_r32l_abs32_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[1]);
	TMP2 = (IR[2] << 16) | IR[3];
	set_nzv32(TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	write16(TMP2+2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32ph_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP2 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP1 |= read16(TMP2+2);
	TMP2 += 4;
	r32_w(IR[1] >> 4, TMP2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
}

void h8h_device::mov_l_r32ph_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP2 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read16(TMP2) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP1 |= read16(TMP2+2);
	TMP2 += 4;
	r32_w(IR[1] >> 4, TMP2);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32l_pr32h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1]);
	TMP2 = r32_r(IR[1] >> 4);
	TMP2 -= 4;
	r32_w(IR[1] >> 4, TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP2+2, TMP1);
	set_nzv32(TMP1);
	prefetch_done();
}

void h8h_device::mov_l_r32l_pr32h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1]);
	TMP2 = r32_r(IR[1] >> 4);
	TMP2 -= 4;
	r32_w(IR[1] >> 4, TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP2, TMP1 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP2+2, TMP1);
	set_nzv32(TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32d16h_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP2 |= read16(TMP1+2);
	set_nzv32(TMP2);
	r32_w(IR[1], TMP2);
	prefetch_done();
}

void h8h_device::mov_l_r32d16h_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP2 |= read16(TMP1+2);
	set_nzv32(TMP2);
	r32_w(IR[1], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32l_r32d16h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	TMP2 = r32_r(IR[1]);
	set_nzv32(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1+2, TMP2);
	prefetch_done();
}

void h8h_device::mov_l_r32l_r32d16h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	TMP2 = r32_r(IR[1]);
	set_nzv32(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1+2, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32d32hh_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	TMP2 |= read16(TMP1+2);
	set_nzv32(TMP2);
	r32_w(IR[2], TMP2);
	prefetch_done();
}

void h8h_device::mov_l_r32d32hh_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	TMP2 |= read16(TMP1+2);
	set_nzv32(TMP2);
	r32_w(IR[2], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32l_r32d32hh_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	TMP2 = r32_r(IR[2]);
	set_nzv32(TMP2);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	write16(TMP1+2, TMP2);
	prefetch_done();
}

void h8h_device::mov_l_r32l_r32d32hh_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	TMP2 = r32_r(IR[2]);
	set_nzv32(TMP2);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	write16(TMP1+2, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::ldc_w_r32ih_ccr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8h_device::ldc_w_r32ih_ccr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8h_device::stc_w_ccr_r32ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
}

void h8h_device::stc_w_ccr_r32ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::ldc_w_abs16_ccr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8h_device::ldc_w_abs16_ccr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8h_device::ldc_w_abs32_ccr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8h_device::ldc_w_abs32_ccr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8h_device::stc_w_ccr_abs16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
}

void h8h_device::stc_w_ccr_abs16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::stc_w_ccr_abs32_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
}

void h8h_device::stc_w_ccr_abs32_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = (IR[2] << 16) | IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::ldc_w_r32ph_ccr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4);
	r32_w(IR[1] >> 4, TMP1+2);
	if(icount <= bcount) { inst_substate = 2; return; }
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8h_device::ldc_w_r32ph_ccr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4);
	r32_w(IR[1] >> 4, TMP1+2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8h_device::stc_w_ccr_pr32h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4) - 2;
	r32_w(IR[1] >> 4, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
}

void h8h_device::stc_w_ccr_pr32h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP1 = r32_r(IR[1] >> 4) - 2;
	r32_w(IR[1] >> 4, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::ldc_w_r32d16h_ccr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8h_device::ldc_w_r32d16h_ccr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8h_device::stc_w_ccr_r32d16h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
}

void h8h_device::stc_w_ccr_r32d16h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + int16_t(IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::ldc_w_r32d32hh_ccr_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
}

void h8h_device::ldc_w_r32d32hh_ccr_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	CCR = read16(TMP1) >> 8;
	update_irq_filter();
	prefetch_done_noirq();
	break;
}
	inst_substate = 0;
}

void h8h_device::stc_w_ccr_r32d32hh_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
}

void h8h_device::stc_w_ccr_r32d32hh_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(4);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[1] >> 4) + (IR[3] << 16) + IR[4];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, (CCR << 8) | CCR);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mulxs_b_r8h_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = int8_t(r16_r(IR[1])) * int8_t(r8_r(IR[1] >> 4));
	set_nz16(TMP1);
	r16_w(IR[1], TMP1);
	internal(2);
	prefetch_done();
}

void h8h_device::mulxs_b_r8h_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = int8_t(r16_r(IR[1])) * int8_t(r8_r(IR[1] >> 4));
	set_nz16(TMP1);
	r16_w(IR[1], TMP1);
	internal(2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mulxs_w_r16h_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = int16_t(r32_r(IR[1])) * int16_t(r16_r(IR[1] >> 4));
	set_nz32(TMP1);
	r32_w(IR[1], TMP1);
	internal(3);
	prefetch_done();
}

void h8h_device::mulxs_w_r16h_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = int16_t(r32_r(IR[1])) * int16_t(r16_r(IR[1] >> 4));
	set_nz32(TMP1);
	r32_w(IR[1], TMP1);
	internal(3);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::divxs_b_r8h_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(11);
	TMP1 = int16_t(r16_r(IR[1]));
	TMP2 = int8_t(r8_r(IR[1] >> 4));
	CCR &= ~(F_Z|F_N);
	if(!TMP2) {
		CCR |= F_Z;
	} else {
		// Conditions:
		//    p = q*d + r
		//    abs(r) < abs(d)
		//    d and r are same sign or r=0
		// p = +20, d = +3 -> q =  6, r =  2
		// p = +20, d = -3 -> q = -6, r = -2
		// p = -20, d = +3 -> q = -7, r =  1
		// p = -20, d = -3 -> q =  7, r = -1
		int q, r;
		if(TMP2 < 0) {
			if(TMP1 < 0) { // - -
				q = (-TMP1) / (-TMP2);
				r = (-TMP1) % (-TMP2);
				if(r) {
					r = r + TMP2;
					q++;
				}
			} else {       // + -
				CCR |= F_N;
				q = -(TMP1 / (-TMP2));
				r = -(TMP1 % (-TMP2));
			}
		} else {
			if(TMP1 < 0) { // - +
				CCR |= F_N;
				q = -((-TMP1) / TMP2);
				r = (-TMP1) % TMP2;
				if(r) {
					r = TMP2 - r;
					q--;
				}
			} else {       // + +
				q = TMP1 / TMP2;
				r = TMP1 % TMP2;
			}
		}
		r16_w(IR[1], (q & 0xff) | ((r & 0xff) << 8));
	}
	prefetch_done();
}

void h8h_device::divxs_b_r8h_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(11);
	TMP1 = int16_t(r16_r(IR[1]));
	TMP2 = int8_t(r8_r(IR[1] >> 4));
	CCR &= ~(F_Z|F_N);
	if(!TMP2) {
		CCR |= F_Z;
	} else {
		// Conditions:
		//    p = q*d + r
		//    abs(r) < abs(d)
		//    d and r are same sign or r=0
		// p = +20, d = +3 -> q =  6, r =  2
		// p = +20, d = -3 -> q = -6, r = -2
		// p = -20, d = +3 -> q = -7, r =  1
		// p = -20, d = -3 -> q =  7, r = -1
		int q, r;
		if(TMP2 < 0) {
			if(TMP1 < 0) { // - -
				q = (-TMP1) / (-TMP2);
				r = (-TMP1) % (-TMP2);
				if(r) {
					r = r + TMP2;
					q++;
				}
			} else {       // + -
				CCR |= F_N;
				q = -(TMP1 / (-TMP2));
				r = -(TMP1 % (-TMP2));
			}
		} else {
			if(TMP1 < 0) { // - +
				CCR |= F_N;
				q = -((-TMP1) / TMP2);
				r = (-TMP1) % TMP2;
				if(r) {
					r = TMP2 - r;
					q--;
				}
			} else {       // + +
				q = TMP1 / TMP2;
				r = TMP1 % TMP2;
			}
		}
		r16_w(IR[1], (q & 0xff) | ((r & 0xff) << 8));
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::divxs_w_r16h_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(19);
	TMP1 = r32_r(IR[1]);
	TMP2 = int16_t(r16_r(IR[1] >> 4));
	CCR &= ~(F_Z|F_N);
	if(!TMP2) {
		CCR |= F_Z;
	} else {
		// Conditions:
		//    p = q*d + r
		//    abs(r) < abs(d)
		//    d and r are same sign or r=0
		// p = +20, d = +3 -> q =  6, r =  2
		// p = +20, d = -3 -> q = -6, r = -2
		// p = -20, d = +3 -> q = -7, r =  1
		// p = -20, d = -3 -> q =  7, r = -1
		int q, r;
		if(TMP2 < 0) {
			if(TMP1 < 0) { // - -
				q = (-TMP1) / (-TMP2);
				r = (-TMP1) % (-TMP2);
				if(r) {
					r = r + TMP2;
					q++;
				}
			} else {       // + -
				CCR |= F_N;
				q = -(TMP1 / (-TMP2));
				r = -(TMP1 % (-TMP2));
			}
		} else {
			if(TMP1 < 0) { // - +
				CCR |= F_N;
				q = -((-TMP1) / TMP2);
				r = (-TMP1) % TMP2;
				if(r) {
					r = TMP2 - r;
					q--;
				}
			} else {       // + +
				q = TMP1 / TMP2;
				r = TMP1 % TMP2;
			}
		}
		r32_w(IR[1], (q & 0xffff) | ((r & 0xffff) << 16));
	}
	prefetch_done();
}

void h8h_device::divxs_w_r16h_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(19);
	TMP1 = r32_r(IR[1]);
	TMP2 = int16_t(r16_r(IR[1] >> 4));
	CCR &= ~(F_Z|F_N);
	if(!TMP2) {
		CCR |= F_Z;
	} else {
		// Conditions:
		//    p = q*d + r
		//    abs(r) < abs(d)
		//    d and r are same sign or r=0
		// p = +20, d = +3 -> q =  6, r =  2
		// p = +20, d = -3 -> q = -6, r = -2
		// p = -20, d = +3 -> q = -7, r =  1
		// p = -20, d = -3 -> q =  7, r = -1
		int q, r;
		if(TMP2 < 0) {
			if(TMP1 < 0) { // - -
				q = (-TMP1) / (-TMP2);
				r = (-TMP1) % (-TMP2);
				if(r) {
					r = r + TMP2;
					q++;
				}
			} else {       // + -
				CCR |= F_N;
				q = -(TMP1 / (-TMP2));
				r = -(TMP1 % (-TMP2));
			}
		} else {
			if(TMP1 < 0) { // - +
				CCR |= F_N;
				q = -((-TMP1) / TMP2);
				r = (-TMP1) % TMP2;
				if(r) {
					r = TMP2 - r;
					q--;
				}
			} else {       // + +
				q = TMP1 / TMP2;
				r = TMP1 % TMP2;
			}
		}
		r32_w(IR[1], (q & 0xffff) | ((r & 0xffff) << 16));
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::or_l_r32h_r32l_full()
{
	TMP1 = r32_r(IR[1] >> 4) | r32_r(IR[1]);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::or_l_r32h_r32l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r32_r(IR[1] >> 4) | r32_r(IR[1]);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::xor_l_r32h_r32l_full()
{
	TMP1 = r32_r(IR[1] >> 4) ^ r32_r(IR[1]);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::xor_l_r32h_r32l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r32_r(IR[1] >> 4) ^ r32_r(IR[1]);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::and_l_r32h_r32l_full()
{
	TMP1 = r32_r(IR[1] >> 4) & r32_r(IR[1]);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::and_l_r32h_r32l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r32_r(IR[1] >> 4) & r32_r(IR[1]);
	set_nzv32(TMP1);
	r32_w(IR[1], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::add_l_r32h_r32l_full()
{
	r32_w(IR[0], do_add32(r32_r(IR[0]), r32_r(IR[0] >> 4)));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::add_l_r32h_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_add32(r32_r(IR[0]), r32_r(IR[0] >> 4)));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::adds_l_one_r32l_full()
{
	r32_w(IR[0], r32_r(IR[0])+1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::adds_l_one_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], r32_r(IR[0])+1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::inc_w_one_r16l_full()
{
	r16_w(IR[0], do_inc16(r16_r(IR[0]), 1));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::inc_w_one_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_inc16(r16_r(IR[0]), 1));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::inc_l_one_r32l_full()
{
	r32_w(IR[0], do_inc32(r32_r(IR[0]), 1));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::inc_l_one_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_inc32(r32_r(IR[0]), 1));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::adds_l_two_r32l_full()
{
	r32_w(IR[0], r32_r(IR[0])+2);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::adds_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], r32_r(IR[0])+2);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::adds_l_four_r32l_full()
{
	r32_w(IR[0], r32_r(IR[0])+4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::adds_l_four_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], r32_r(IR[0])+4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::inc_w_two_r16l_full()
{
	r16_w(IR[0], do_inc16(r16_r(IR[0]), 2));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::inc_w_two_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_inc16(r16_r(IR[0]), 2));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::inc_l_two_r32l_full()
{
	r32_w(IR[0], do_inc32(r32_r(IR[0]), 2));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::inc_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_inc32(r32_r(IR[0]), 2));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_r32h_r32l_full()
{
	TMP1 = r32_r(IR[0] >> 4);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::mov_l_r32h_r32l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r32_r(IR[0] >> 4);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shll_w_r16l_full()
{
	r16_w(IR[0], do_shll16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shll_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shll16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shll_l_r32l_full()
{
	r32_w(IR[0], do_shll32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shll_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shll32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shal_w_r16l_full()
{
	r16_w(IR[0], do_shal16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shal_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shal16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shal_l_r32l_full()
{
	r32_w(IR[0], do_shal32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shal_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shal32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shlr_w_r16l_full()
{
	r16_w(IR[0], do_shlr16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shlr_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shlr16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shlr_l_r32l_full()
{
	r32_w(IR[0], do_shlr32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shlr_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shlr32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shar_w_r16l_full()
{
	r16_w(IR[0], do_shar16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shar_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_shar16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::shar_l_r32l_full()
{
	r32_w(IR[0], do_shar32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::shar_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_shar32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotxl_w_r16l_full()
{
	r16_w(IR[0], do_rotxl16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotxl_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotxl16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotxl_l_r32l_full()
{
	r32_w(IR[0], do_rotxl32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotxl_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotxl32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotl_w_r16l_full()
{
	r16_w(IR[0], do_rotl16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotl_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotl16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotl_l_r32l_full()
{
	r32_w(IR[0], do_rotl32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotl_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotl32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotxr_w_r16l_full()
{
	r16_w(IR[0], do_rotxr16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotxr_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotxr16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotxr_l_r32l_full()
{
	r32_w(IR[0], do_rotxr32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotxr_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotxr32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotr_w_r16l_full()
{
	r16_w(IR[0], do_rotr16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotr_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_rotr16(r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::rotr_l_r32l_full()
{
	r32_w(IR[0], do_rotr32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::rotr_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_rotr32(r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::not_w_r16l_full()
{
	TMP1 = ~r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::not_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = ~r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::not_l_r32l_full()
{
	TMP1 = ~r32_r(IR[0]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::not_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = ~r32_r(IR[0]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::extu_w_r16l_full()
{
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = uint8_t(r16_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::extu_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = uint8_t(r16_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::extu_l_r32l_full()
{
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = uint16_t(r32_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::extu_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = uint16_t(r32_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::neg_w_r16l_full()
{
	r16_w(IR[0], do_sub16(0, r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::neg_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	r16_w(IR[0], do_sub16(0, r16_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::neg_l_r32l_full()
{
	r32_w(IR[0], do_sub32(0, r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::neg_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_sub32(0, r32_r(IR[0])));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::exts_w_r16l_full()
{
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = int8_t(r16_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::exts_w_r16l_partial()
{
switch(inst_substate) {
case 0:
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = int8_t(r16_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::exts_l_r32l_full()
{
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = int16_t(r32_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::exts_l_r32l_partial()
{
switch(inst_substate) {
case 0:
	CCR &= ~(F_N|F_Z|F_V);
	TMP1 = int16_t(r32_r(IR[0]));
	if(!TMP1)
		CCR |= F_Z;
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::sub_l_r32h_r32l_full()
{
	r32_w(IR[0], do_sub32(r32_r(IR[0]), r32_r(IR[0] >> 4)));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::sub_l_r32h_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_sub32(r32_r(IR[0]), r32_r(IR[0] >> 4)));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::subs_l_one_r32l_full()
{
	r32_w(IR[0], r32_r(IR[0])-1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::subs_l_one_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], r32_r(IR[0])-1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::dec_l_one_r32l_full()
{
	r32_w(IR[0], do_dec32(r32_r(IR[0]), 1));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::dec_l_one_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_dec32(r32_r(IR[0]), 1));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::subs_l_two_r32l_full()
{
	r32_w(IR[0], r32_r(IR[0])-2);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::subs_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], r32_r(IR[0])-2);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::subs_l_four_r32l_full()
{
	r32_w(IR[0], r32_r(IR[0])-4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::subs_l_four_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], r32_r(IR[0])-4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::dec_l_two_r32l_full()
{
	r32_w(IR[0], do_dec32(r32_r(IR[0]), 2));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::dec_l_two_r32l_partial()
{
switch(inst_substate) {
case 0:
	r32_w(IR[0], do_dec32(r32_r(IR[0]), 2));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::cmp_l_r32h_r32l_full()
{
	do_sub32(r32_r(IR[0]), r32_r(IR[0] >> 4));
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::cmp_l_r32h_r32l_partial()
{
switch(inst_substate) {
case 0:
	do_sub32(r32_r(IR[0]), r32_r(IR[0] >> 4));
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::mulxu_w_r16h_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	r32_w(IR[0], uint16_t(r32_r(IR[0])) * r16_r(IR[0] >> 4));
	internal(3);
	prefetch_done();
}

void h8h_device::mulxu_w_r16h_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	r32_w(IR[0], uint16_t(r32_r(IR[0])) * r16_r(IR[0] >> 4));
	internal(3);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::divxu_w_r16h_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(11);
	TMP1 = r32_r(IR[0]);
	TMP2 = r16_r(IR[0] >> 4);
	CCR &= ~(F_Z|F_N);
	if(TMP2 & 0x80)
		CCR |= F_N;
	if(!TMP2) {
		CCR |= F_Z;
	} else {
		int q = TMP1 / TMP2;
		int r = TMP1 % TMP2;
		r32_w(IR[0], (q & 0xffff) | ((r & 0xffff) << 16));
	}
	prefetch_done();
}

void h8h_device::divxu_w_r16h_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(11);
	TMP1 = r32_r(IR[0]);
	TMP2 = r16_r(IR[0] >> 4);
	CCR &= ~(F_Z|F_N);
	if(TMP2 & 0x80)
		CCR |= F_N;
	if(!TMP2) {
		CCR |= F_Z;
	} else {
		int q = TMP1 / TMP2;
		int r = TMP1 % TMP2;
		r32_w(IR[0], (q & 0xffff) | ((r & 0xffff) << 16));
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::rts_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch();
	TMP1 = r32_r(7);
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 2; return; }
		TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
		TMP2 |= read16(TMP1+2);
		r32_w(7, TMP1+4);
	} else {
	if(icount <= bcount) { inst_substate = 4; return; }
		TMP2 = read16(TMP1);
		r32_w(7, TMP1+2);
	}
	internal(1);
	PC = TMP2;
	if(icount <= bcount) { inst_substate = 5; return; }
	prefetch();
}

void h8h_device::rts_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch();
	TMP1 = r32_r(7);
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		TMP2 = read16(TMP1) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		TMP2 |= read16(TMP1+2);
		r32_w(7, TMP1+4);
	} else {
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		TMP2 = read16(TMP1);
		r32_w(7, TMP1+2);
	}
	internal(1);
	PC = TMP2;
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bsr_rel8_full()
{
	TMP2 = PC;
	PC += int8_t(IR[0]);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
		write16(TMP1, TMP2);
	}
	prefetch_done();
}

void h8h_device::bsr_rel8_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = PC;
	PC += int8_t(IR[0]);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		write16(TMP1, TMP2);
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::rte_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch();
	TMP1 = r32_r(7);
	if(mode_advanced) {
		if(exr_in_stack()) {
	if(icount <= bcount) { inst_substate = 2; return; }
			EXR = (read16(TMP1) >> 8) | EXR_NC;
			TMP1 += 2;
		}
	if(icount <= bcount) { inst_substate = 3; return; }
		TMP2 = read16(TMP1);
		CCR = TMP2 >> 8;
		TMP2 = (TMP2 & 0xff) << 16;
	if(icount <= bcount) { inst_substate = 4; return; }
		TMP2 |= read16(TMP1+2);
		r32_w(7, TMP1+4);
	} else {
	if(icount <= bcount) { inst_substate = 5; return; }
		TMP2 = read16(TMP1);
		r32_w(7, TMP1+2);
	}
	internal(1);
	PC = TMP2;
	update_irq_filter();
	prefetch_noirq_notrace();
}

void h8h_device::rte_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch();
	TMP1 = r32_r(7);
	if(mode_advanced) {
		if(exr_in_stack()) {
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
			EXR = (read16(TMP1) >> 8) | EXR_NC;
			TMP1 += 2;
		}
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		TMP2 = read16(TMP1);
		CCR = TMP2 >> 8;
		TMP2 = (TMP2 & 0xff) << 16;
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		TMP2 |= read16(TMP1+2);
		r32_w(7, TMP1+4);
	} else {
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
		TMP2 = read16(TMP1);
		r32_w(7, TMP1+2);
	}
	internal(1);
	PC = TMP2;
	update_irq_filter();
	prefetch_noirq_notrace();
	break;
}
	inst_substate = 0;
}

void h8h_device::trapa_imm2_full()
{
	internal(1);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	write16(TMP1, NPC);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, (CCR << 8) | ((NPC >> 16) & 0xff));
	if(exr_in_stack()) {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
		write16(TMP1, EXR << 8);
	}
	taken_irq_vector = trapa_setup() + ((IR[0] >> 4) & 3);
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 4; return; }
		IR[0] = read16i(4*taken_irq_vector);
	if(icount <= bcount) { inst_substate = 5; return; }
		IR[1] = read16i(4*taken_irq_vector+2);
		PC = (IR[0] << 16) | IR[1];
	} else {
	if(icount <= bcount) { inst_substate = 6; return; }
		PC = read16i(2*taken_irq_vector);
	}
	internal(1);
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 7; return; }
	prefetch();
}

void h8h_device::trapa_imm2_partial()
{
switch(inst_substate) {
case 0:
	internal(1);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	write16(TMP1, NPC);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, (CCR << 8) | ((NPC >> 16) & 0xff));
	if(exr_in_stack()) {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		write16(TMP1, EXR << 8);
	}
	taken_irq_vector = trapa_setup() + ((IR[0] >> 4) & 3);
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		IR[0] = read16i(4*taken_irq_vector);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
		IR[1] = read16i(4*taken_irq_vector+2);
		PC = (IR[0] << 16) | IR[1];
	} else {
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
		PC = read16i(2*taken_irq_vector);
	}
	internal(1);
	update_irq_filter();
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bt_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(true)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bt_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(true)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bf_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(false)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bf_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(false)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bhi_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(!(CCR & (F_C|F_Z)))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bhi_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(!(CCR & (F_C|F_Z)))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bls_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(CCR & (F_C|F_Z))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bls_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(CCR & (F_C|F_Z))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bcc_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(!(CCR & F_C))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bcc_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(!(CCR & F_C))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bcs_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(CCR & F_C)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bcs_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(CCR & F_C)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bne_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(!(CCR & F_Z))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bne_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(!(CCR & F_Z))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::beq_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(CCR & F_Z)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::beq_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(CCR & F_Z)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bvc_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(!(CCR & F_V))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bvc_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(!(CCR & F_V))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bvs_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(CCR & F_V)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bvs_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(CCR & F_V)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bpl_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(!(CCR & F_N))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bpl_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(!(CCR & F_N))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bmi_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(CCR & F_N)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bmi_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(CCR & F_N)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bge_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(!((CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bge_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(!((CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::blt_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if((CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::blt_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if((CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bgt_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if(!((CCR & F_Z) || (CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::bgt_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if(!((CCR & F_Z) || (CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V))
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::ble_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16i(TMP1);
	if((CCR & F_Z) || (CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::ble_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	TMP1 = PC + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16i(TMP1);
	if((CCR & F_Z) || (CCR & (F_N|F_V)) == F_N || (CCR & (F_N|F_V)) == F_V)
		prefetch_switch(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::jmp_r32h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch();
	PC = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::jmp_r32h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch();
	PC = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::jmp_abs24e_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	internal(1);
	PC = ((IR[0] & 0xff) << 16) | IR[1];
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::jmp_abs24e_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	internal(1);
	PC = ((IR[0] & 0xff) << 16) | IR[1];
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::jmp_abs8i_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch();
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 2; return; }
		TMP1 = read16(IR[0] & 0xff) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
		TMP1 |= read16((IR[0] & 0xff) + 2);
		PC = TMP1;
	} else {
	if(icount <= bcount) { inst_substate = 4; return; }
		PC = read16(IR[0] & 0xff);
	}
	internal(1);
	if(icount <= bcount) { inst_substate = 5; return; }
	prefetch();
}

void h8h_device::jmp_abs8i_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch();
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		TMP1 = read16(IR[0] & 0xff) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		TMP1 |= read16((IR[0] & 0xff) + 2);
		PC = TMP1;
	} else {
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		PC = read16(IR[0] & 0xff);
	}
	internal(1);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bsr_rel16_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	internal(1);
	TMP2 = PC;
	PC += int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 5; return; }
		write16(TMP1, TMP2);
	}
	prefetch_done();
}

void h8h_device::bsr_rel16_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	internal(1);
	TMP2 = PC;
	PC += int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
		write16(TMP1, TMP2);
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::jsr_r32h_full()
{
	TMP2 = PC;
	PC = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
		write16(TMP1, TMP2);
	}
	prefetch_done();
}

void h8h_device::jsr_r32h_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = PC;
	PC = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		write16(TMP1, TMP2);
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::jsr_abs24e_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	internal(1);
	TMP2 = PC;
	PC = ((IR[0] & 0xff) << 16) | IR[1];
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 5; return; }
		write16(TMP1, TMP2);
	}
	prefetch_done();
}

void h8h_device::jsr_abs24e_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	internal(1);
	TMP2 = PC;
	PC = ((IR[0] & 0xff) << 16) | IR[1];
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
		write16(TMP1, TMP2);
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::jsr_abs8i_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch();
	TMP2 = PC;
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 2; return; }
		TMP1 = read16(IR[0] & 0xff) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
		TMP1 |= read16((IR[0] & 0xff) + 2);
		PC = TMP1;
	} else {
	if(icount <= bcount) { inst_substate = 4; return; }
		PC = read16(IR[0] & 0xff);
	}
	if(icount <= bcount) { inst_substate = 5; return; }
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 6; return; }
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 8; return; }
		write16(TMP1, TMP2);
	}
	prefetch_done();
}

void h8h_device::jsr_abs8i_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch();
	TMP2 = PC;
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		TMP1 = read16(IR[0] & 0xff) << 16;
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		TMP1 |= read16((IR[0] & 0xff) + 2);
		PC = TMP1;
	} else {
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		PC = read16(IR[0] & 0xff);
	}
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
	prefetch_start();
	if(mode_advanced) {
		TMP1 = r32_r(7) - 4;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
		write16(TMP1, TMP2 >> 16);
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
		write16(TMP1+2, TMP2);
	} else {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 8; return; }
	[[fallthrough]];
case 8:;
		write16(TMP1, TMP2);
	}
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::or_w_r16h_r16l_full()
{
	TMP1 = r16_r(IR[0] >> 4) | r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::or_w_r16h_r16l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r16_r(IR[0] >> 4) | r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::xor_w_r16h_r16l_full()
{
	TMP1 = r16_r(IR[0] >> 4) ^ r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::xor_w_r16h_r16l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r16_r(IR[0] >> 4) ^ r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::and_w_r16h_r16l_full()
{
	TMP1 = r16_r(IR[0] >> 4) & r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch();
}

void h8h_device::and_w_r16h_r16l_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r16_r(IR[0] >> 4) & r16_r(IR[0]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r32ih_r8l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read8(r32_r(IR[0] >> 4));
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
}

void h8h_device::mov_b_r32ih_r8l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read8(r32_r(IR[0] >> 4));
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r8l_r32ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r8_r(IR[0]);
	set_nzv8(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write8(r32_r(IR[0] >> 4), TMP1);
	prefetch_done();
}

void h8h_device::mov_b_r8l_r32ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r8_r(IR[0]);
	set_nzv8(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write8(r32_r(IR[0] >> 4), TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r32ih_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read16(r32_r(IR[0] >> 4));
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
}

void h8h_device::mov_w_r32ih_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read16(r32_r(IR[0] >> 4));
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r16l_r32ih_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	TMP1 = r16_r(IR[0]);
	set_nzv16(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(r32_r(IR[0] >> 4), TMP1);
	prefetch_done();
}

void h8h_device::mov_w_r16l_r32ih_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	TMP1 = r16_r(IR[0]);
	set_nzv16(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(r32_r(IR[0] >> 4), TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_abs32_r8l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP1 = read8((IR[1] << 16) | IR[2]);
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
}

void h8h_device::mov_b_abs32_r8l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP1 = read8((IR[1] << 16) | IR[2]);
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::btst_r8h_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((r8_r(IR[3] >> 4)) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::btst_r8h_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((r8_r(IR[3] >> 4)) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::btst_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::btst_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bor_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bor_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bior_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bior_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bxor_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bxor_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bixor_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bixor_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::band_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::band_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::biand_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::biand_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bld_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bld_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[3] >> 4) & 7)))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bild_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bild_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[3] >> 4) & 7))))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bset_r8h_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 |= 1 << ((r8_r(IR[3] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bset_r8h_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 |= 1 << ((r8_r(IR[3] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bnot_r8h_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 ^= 1 << ((r8_r(IR[3] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bnot_r8h_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 ^= 1 << ((r8_r(IR[3] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bclr_r8h_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 &= ~(1 << ((r8_r(IR[3] >> 4)) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bclr_r8h_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 &= ~(1 << ((r8_r(IR[3] >> 4)) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bst_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(CCR & F_C)
		TMP1 |= 1 << ((IR[3] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[3] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bst_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(CCR & F_C)
		TMP1 |= 1 << ((IR[3] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[3] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bist_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(!(CCR & F_C))
		TMP1 |= 1 << ((IR[3] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[3] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bist_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(!(CCR & F_C))
		TMP1 |= 1 << ((IR[3] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[3] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bset_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 |= 1 << ((IR[3] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bset_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 |= 1 << ((IR[3] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bnot_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 ^= 1 << ((IR[3] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bnot_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 ^= 1 << ((IR[3] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bclr_imm3_abs32_full()
{
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 &= ~(1 << ((IR[3] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bclr_imm3_abs32_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = (IR[1] << 16) | IR[2];
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 &= ~(1 << ((IR[3] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r8l_abs32_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r8_r(IR[0]);
	set_nzv8(TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	write8((IR[1] << 16) | IR[2], TMP1);
	prefetch_done();
}

void h8h_device::mov_b_r8l_abs32_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r8_r(IR[0]);
	set_nzv8(TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write8((IR[1] << 16) | IR[2], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_abs32_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP1 = read16((IR[1] << 16) | IR[2]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
}

void h8h_device::mov_w_abs32_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP1 = read16((IR[1] << 16) | IR[2]);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r16l_abs32_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r16_r(IR[0]);
	set_nzv16(TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16((IR[1] << 16) | IR[2], TMP1);
	prefetch_done();
}

void h8h_device::mov_w_r16l_abs32_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r16_r(IR[0]);
	set_nzv16(TMP1);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16((IR[1] << 16) | IR[2], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r32ph_r8l_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read8(TMP2);
	TMP2 += 1;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
}

void h8h_device::mov_b_r32ph_r8l_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read8(TMP2);
	TMP2 += 1;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	r8_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r8l_pr32h_full()
{
	TMP1 = r8_r(IR[0]);
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP2 -= 1;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::mov_b_r8l_pr32h_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r8_r(IR[0]);
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP2 -= 1;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv8(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r32ph_r16l_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	TMP1 = read16(TMP2);
	TMP2 += 2;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
}

void h8h_device::mov_w_r32ph_r16l_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	TMP1 = read16(TMP2);
	TMP2 += 2;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	r16_w(IR[0], TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r16l_pr32h_full()
{
	TMP1 = r16_r(IR[0]);
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	prefetch_start();
	internal(1);
	TMP2 -= 2;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::mov_w_r16l_pr32h_partial()
{
switch(inst_substate) {
case 0:
	TMP1 = r16_r(IR[0]);
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	prefetch_start();
	internal(1);
	TMP2 -= 2;
	r32_w(IR[0] >> 4, TMP2);
	set_nzv16(TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r32d16h_r8l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read8(TMP1);
	set_nzv8(TMP2);
	r8_w(IR[0], TMP2);
	prefetch_done();
}

void h8h_device::mov_b_r32d16h_r8l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read8(TMP1);
	set_nzv8(TMP2);
	r8_w(IR[0], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r8l_r32d16h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	TMP2 = r8_r(IR[0]);
	set_nzv8(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::mov_b_r8l_r32d16h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	TMP2 = r8_r(IR[0]);
	set_nzv8(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r32d16h_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 3; return; }
	TMP2 = read16(TMP1);
	set_nzv16(TMP2);
	r16_w(IR[0], TMP2);
	prefetch_done();
}

void h8h_device::mov_w_r32d16h_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	TMP2 = read16(TMP1);
	set_nzv16(TMP2);
	r16_w(IR[0], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r16l_r32d16h_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	TMP2 = r16_r(IR[0]);
	set_nzv16(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	write16(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::mov_w_r16l_r32d16h_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + int16_t(IR[1]);
	TMP2 = r16_r(IR[0]);
	set_nzv16(TMP2);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write16(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r32d32hh_r8l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP2 = read8(TMP1);
	set_nzv8(TMP2);
	r8_w(IR[1], TMP2);
	prefetch_done();
}

void h8h_device::mov_b_r32d32hh_r8l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP2 = read8(TMP1);
	set_nzv8(TMP2);
	r8_w(IR[1], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_b_r8l_r32d32hh_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	TMP2 = r8_r(IR[1]);
	set_nzv8(TMP2);
	if(icount <= bcount) { inst_substate = 4; return; }
	write8(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::mov_b_r8l_r32d32hh_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	TMP2 = r8_r(IR[1]);
	set_nzv8(TMP2);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write8(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r32d32hh_r16l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	TMP2 = read16(TMP1);
	set_nzv16(TMP2);
	r16_w(IR[1], TMP2);
	prefetch_done();
}

void h8h_device::mov_w_r32d32hh_r16l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	TMP2 = read16(TMP1);
	set_nzv16(TMP2);
	r16_w(IR[1], TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_w_r16l_r32d32hh_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	TMP2 = r16_r(IR[1]);
	set_nzv16(TMP2);
	if(icount <= bcount) { inst_substate = 4; return; }
	write16(TMP1, TMP2);
	prefetch_done();
}

void h8h_device::mov_w_r16l_r32d32hh_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(2);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(3);

	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch_start();
	TMP1 = r32_r(IR[0] >> 4) + (IR[2] << 16) + IR[3];
	TMP2 = r16_r(IR[1]);
	set_nzv16(TMP2);
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
	write16(TMP1, TMP2);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::mov_l_imm32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	TMP1 = (IR[1] << 16) | IR[2];
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::mov_l_imm32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	TMP1 = (IR[1] << 16) | IR[2];
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::add_l_imm32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	r32_w(IR[0], do_add32(r32_r(IR[0]), (IR[1] << 16) | IR[2]));
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::add_l_imm32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	r32_w(IR[0], do_add32(r32_r(IR[0]), (IR[1] << 16) | IR[2]));
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::cmp_l_imm32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	do_sub32(r32_r(IR[0]), (IR[1] << 16) | IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::cmp_l_imm32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	do_sub32(r32_r(IR[0]), (IR[1] << 16) | IR[2]);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::sub_l_imm32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	r32_w(IR[0], do_sub32(r32_r(IR[0]), (IR[1] << 16) | IR[2]));
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::sub_l_imm32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	r32_w(IR[0], do_sub32(r32_r(IR[0]), (IR[1] << 16) | IR[2]));
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::or_l_imm32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	TMP1 = r32_r(IR[0]) | ((IR[1] << 16) | IR[2]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::or_l_imm32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	TMP1 = r32_r(IR[0]) | ((IR[1] << 16) | IR[2]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::xor_l_imm32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	TMP1 = r32_r(IR[0]) ^ ((IR[1] << 16) | IR[2]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::xor_l_imm32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	TMP1 = r32_r(IR[0]) ^ ((IR[1] << 16) | IR[2]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::and_l_imm32_r32l_full()
{
	if(icount <= bcount) { inst_substate = 1; return; }
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	fetch(2);

	TMP1 = r32_r(IR[0]) & ((IR[1] << 16) | IR[2]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::and_l_imm32_r32l_partial()
{
switch(inst_substate) {
case 0:
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	fetch(1);

	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	fetch(2);

	TMP1 = r32_r(IR[0]) & ((IR[1] << 16) | IR[2]);
	set_nzv32(TMP1);
	r32_w(IR[0], TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::eepmov_b_full()
{
	while(r8_r(4+8)) {
	if(icount <= bcount) { inst_substate = 1; return; }
		TMP1 = read8(r32_r(5));
	if(icount <= bcount) { inst_substate = 2; return; }
		write8(r32_r(6), TMP1);
		r32_w(5, r32_r(5)+1);
		r32_w(6, r32_r(6)+1);
		r8_w(4+8, r8_r(4+8)-1);
	}
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::eepmov_b_partial()
{
switch(inst_substate) {
case 0:
	while(r8_r(4+8)) {
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
		TMP1 = read8(r32_r(5));
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		write8(r32_r(6), TMP1);
		r32_w(5, r32_r(5)+1);
		r32_w(6, r32_r(6)+1);
		r8_w(4+8, r8_r(4+8)-1);
	}
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::eepmov_w_full()
{
	while(r16_r(4)) {
	if(icount <= bcount) { inst_substate = 1; return; }
		TMP1 = read8(r32_r(5));
	if(icount <= bcount) { inst_substate = 2; return; }
		write8(r32_r(6), TMP1);
		r32_w(5, r32_r(5)+1);
		r32_w(6, r32_r(6)+1);
		r16_w(4, r16_r(4)-1);
	}
	if(icount <= bcount) { inst_substate = 3; return; }
	prefetch();
}

void h8h_device::eepmov_w_partial()
{
switch(inst_substate) {
case 0:
	while(r16_r(4)) {
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
		TMP1 = read8(r32_r(5));
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
		write8(r32_r(6), TMP1);
		r32_w(5, r32_r(5)+1);
		r32_w(6, r32_r(6)+1);
		r16_w(4, r16_r(4)-1);
	}
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::btst_r8h_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((r8_r(IR[1] >> 4)) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::btst_r8h_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((r8_r(IR[1] >> 4)) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::btst_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::btst_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR &= ~F_Z;
	else
		CCR |= F_Z;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bor_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bor_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bior_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bior_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR |= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bxor_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bxor_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bixor_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bixor_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR ^= F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::band_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::band_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::biand_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::biand_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bld_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bld_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(TMP1 & (1 << ((IR[1] >> 4) & 7)))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bild_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch();
}

void h8h_device::bild_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(TMP1 & (1 << ((IR[1] >> 4) & 7))))
		CCR |= F_C;
	else
		CCR &= ~F_C;
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch();
	break;
}
	inst_substate = 0;
}

void h8h_device::bset_r8h_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	TMP1 |= 1 << ((r8_r(IR[1] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bset_r8h_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	TMP1 |= 1 << ((r8_r(IR[1] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bnot_r8h_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	TMP1 ^= 1 << ((r8_r(IR[1] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bnot_r8h_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	TMP1 ^= 1 << ((r8_r(IR[1] >> 4)) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bclr_r8h_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	TMP1 &= ~(1 << ((r8_r(IR[1] >> 4)) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bclr_r8h_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	TMP1 &= ~(1 << ((r8_r(IR[1] >> 4)) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bst_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(CCR & F_C)
		TMP1 |= 1 << ((IR[1] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[1] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bst_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(CCR & F_C)
		TMP1 |= 1 << ((IR[1] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[1] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bist_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	if(!(CCR & F_C))
		TMP1 |= 1 << ((IR[1] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[1] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bist_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	if(!(CCR & F_C))
		TMP1 |= 1 << ((IR[1] >> 4) & 7);
	else
		TMP1 &= ~(1 << ((IR[1] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bset_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	TMP1 |= 1 << ((IR[1] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bset_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	TMP1 |= 1 << ((IR[1] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bnot_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	TMP1 ^= 1 << ((IR[1] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bnot_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	TMP1 ^= 1 << ((IR[1] >> 4) & 7);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::bclr_imm3_r32ihh_full()
{
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	TMP1 = read8(TMP2);
	TMP1 &= ~(1 << ((IR[1] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	write8(TMP2, TMP1);
	prefetch_done();
}

void h8h_device::bclr_imm3_r32ihh_partial()
{
switch(inst_substate) {
case 0:
	TMP2 = r32_r(IR[0] >> 4);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	TMP1 = read8(TMP2);
	TMP1 &= ~(1 << ((IR[1] >> 4) & 7));
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	prefetch_start();
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
	write8(TMP2, TMP1);
	prefetch_done();
	break;
}
	inst_substate = 0;
}

void h8h_device::state_irq_full()
{
	internal(1);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	write16(TMP1, NPC);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	write16(TMP1, (CCR << 8) | ((NPC >> 16) & 0xff));
	if(exr_in_stack()) {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
		write16(TMP1, EXR << 8);
	}
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 4; return; }
		IR[0] = read16i(4*taken_irq_vector);
	if(icount <= bcount) { inst_substate = 5; return; }
		IR[1] = read16i(4*taken_irq_vector+2);
		PC = (IR[0] << 16) | IR[1];
	} else {
	if(icount <= bcount) { inst_substate = 6; return; }
		PC = read16i(2*taken_irq_vector);
	}
	internal(1);
	irq_setup();
	update_irq_filter();
	interrupt_taken();
	if(icount <= bcount) { inst_substate = 7; return; }
	prefetch_noirq();
}

void h8h_device::state_irq_partial()
{
switch(inst_substate) {
case 0:
	internal(1);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 1; return; }
	[[fallthrough]];
case 1:;
	write16(TMP1, NPC);
	TMP1 = r32_r(7) - 2;
	r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 2; return; }
	[[fallthrough]];
case 2:;
	write16(TMP1, (CCR << 8) | ((NPC >> 16) & 0xff));
	if(exr_in_stack()) {
		TMP1 = r32_r(7) - 2;
		r32_w(7, TMP1);
	if(icount <= bcount) { inst_substate = 3; return; }
	[[fallthrough]];
case 3:;
		write16(TMP1, EXR << 8);
	}
	if(mode_advanced) {
	if(icount <= bcount) { inst_substate = 4; return; }
	[[fallthrough]];
case 4:;
		IR[0] = read16i(4*taken_irq_vector);
	if(icount <= bcount) { inst_substate = 5; return; }
	[[fallthrough]];
case 5:;
		IR[1] = read16i(4*taken_irq_vector+2);
		PC = (IR[0] << 16) | IR[1];
	} else {
	if(icount <= bcount) { inst_substate = 6; return; }
	[[fallthrough]];
case 6:;
		PC = read16i(2*taken_irq_vector);
	}
	internal(1);
	irq_setup();
	update_irq_filter();
	interrupt_taken();
	if(icount <= bcount) { inst_substate = 7; return; }
	[[fallthrough]];
case 7:;
	prefetch_noirq();
	break;
}
	inst_substate = 0;
}

void h8h_device::do_exec_full()
{
	switch(inst_state >> 16) {
	case 0x00: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0xff) {
			case 0x00: nop_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x01: {
			switch(inst_state & 0xff) {
			case 0x00: dispatch_0100_full(); break;
			case 0x40: dispatch_0140_full(); break;
			case 0x80: sleep_full(); break;
			case 0xc0: dispatch_01c0_full(); break;
			case 0xd0: dispatch_01d0_full(); break;
			case 0xf0: dispatch_01f0_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf0) {
			case 0x00: stc_ccr_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf0) {
			case 0x00: ldc_r8l_ccr_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x04: {
			orc_imm8_ccr_full();
			break;
		}
		case 0x05: {
			xorc_imm8_ccr_full();
			break;
		}
		case 0x06: {
			andc_imm8_ccr_full();
			break;
		}
		case 0x07: {
			ldc_imm8_ccr_full();
			break;
		}
		case 0x08: {
			add_b_r8h_r8l_full();
			break;
		}
		case 0x09: {
			add_w_r16h_r16l_full();
			break;
		}
		case 0x0a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: inc_b_one_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: add_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0b: {
			switch(inst_state & 0xf8) {
			case 0x00: adds_l_one_r32l_full(); break;
			case 0x50: case 0x58: inc_w_one_r16l_full(); break;
			case 0x70: inc_l_one_r32l_full(); break;
			case 0x80: adds_l_two_r32l_full(); break;
			case 0x90: adds_l_four_r32l_full(); break;
			case 0xd0: case 0xd8: inc_w_two_r16l_full(); break;
			case 0xf0: inc_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0c: {
			mov_b_r8h_r8l_full();
			break;
		}
		case 0x0d: {
			mov_w_r16h_r16l_full();
			break;
		}
		case 0x0e: {
			addx_b_r8h_r8l_full();
			break;
		}
		case 0x0f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: daa_b_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: mov_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x10: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shll_b_r8l_full(); break;
			case 0x10: case 0x18: shll_w_r16l_full(); break;
			case 0x30: shll_l_r32l_full(); break;
			case 0x80: case 0x88: shal_b_r8l_full(); break;
			case 0x90: case 0x98: shal_w_r16l_full(); break;
			case 0xb0: shal_l_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x11: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shlr_b_r8l_full(); break;
			case 0x10: case 0x18: shlr_w_r16l_full(); break;
			case 0x30: shlr_l_r32l_full(); break;
			case 0x80: case 0x88: shar_b_r8l_full(); break;
			case 0x90: case 0x98: shar_w_r16l_full(); break;
			case 0xb0: shar_l_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x12: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxl_b_r8l_full(); break;
			case 0x10: case 0x18: rotxl_w_r16l_full(); break;
			case 0x30: rotxl_l_r32l_full(); break;
			case 0x80: case 0x88: rotl_b_r8l_full(); break;
			case 0x90: case 0x98: rotl_w_r16l_full(); break;
			case 0xb0: rotl_l_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x13: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxr_b_r8l_full(); break;
			case 0x10: case 0x18: rotxr_w_r16l_full(); break;
			case 0x30: rotxr_l_r32l_full(); break;
			case 0x80: case 0x88: rotr_b_r8l_full(); break;
			case 0x90: case 0x98: rotr_w_r16l_full(); break;
			case 0xb0: rotr_l_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x14: {
			or_b_r8h_r8l_full();
			break;
		}
		case 0x15: {
			xor_b_r8h_r8l_full();
			break;
		}
		case 0x16: {
			and_b_r8h_r8l_full();
			break;
		}
		case 0x17: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: not_b_r8l_full(); break;
			case 0x10: case 0x18: not_w_r16l_full(); break;
			case 0x30: not_l_r32l_full(); break;
			case 0x50: case 0x58: extu_w_r16l_full(); break;
			case 0x70: extu_l_r32l_full(); break;
			case 0x80: case 0x88: neg_b_r8l_full(); break;
			case 0x90: case 0x98: neg_w_r16l_full(); break;
			case 0xb0: neg_l_r32l_full(); break;
			case 0xd0: case 0xd8: exts_w_r16l_full(); break;
			case 0xf0: exts_l_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x18: {
			sub_b_r8h_r8l_full();
			break;
		}
		case 0x19: {
			sub_w_r16h_r16l_full();
			break;
		}
		case 0x1a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: dec_b_one_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: sub_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1b: {
			switch(inst_state & 0xf8) {
			case 0x00: subs_l_one_r32l_full(); break;
			case 0x50: case 0x58: dec_w_one_r16l_full(); break;
			case 0x70: dec_l_one_r32l_full(); break;
			case 0x80: subs_l_two_r32l_full(); break;
			case 0x90: subs_l_four_r32l_full(); break;
			case 0xd0: case 0xd8: dec_w_two_r16l_full(); break;
			case 0xf0: dec_l_two_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1c: {
			cmp_b_r8h_r8l_full();
			break;
		}
		case 0x1d: {
			cmp_w_r16h_r16l_full();
			break;
		}
		case 0x1e: {
			subx_b_r8h_r8l_full();
			break;
		}
		case 0x1f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: das_b_r8l_full(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: cmp_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: {
			mov_b_abs8_r8u_full();
			break;
		}
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: {
			mov_b_r8u_abs8_full();
			break;
		}
		case 0x40: {
			bt_rel8_full();
			break;
		}
		case 0x41: {
			bf_rel8_full();
			break;
		}
		case 0x42: {
			bhi_rel8_full();
			break;
		}
		case 0x43: {
			bls_rel8_full();
			break;
		}
		case 0x44: {
			bcc_rel8_full();
			break;
		}
		case 0x45: {
			bcs_rel8_full();
			break;
		}
		case 0x46: {
			bne_rel8_full();
			break;
		}
		case 0x47: {
			beq_rel8_full();
			break;
		}
		case 0x48: {
			bvc_rel8_full();
			break;
		}
		case 0x49: {
			bvs_rel8_full();
			break;
		}
		case 0x4a: {
			bpl_rel8_full();
			break;
		}
		case 0x4b: {
			bmi_rel8_full();
			break;
		}
		case 0x4c: {
			bge_rel8_full();
			break;
		}
		case 0x4d: {
			blt_rel8_full();
			break;
		}
		case 0x4e: {
			bgt_rel8_full();
			break;
		}
		case 0x4f: {
			ble_rel8_full();
			break;
		}
		case 0x50: {
			mulxu_b_r8h_r16l_full();
			break;
		}
		case 0x51: {
			divxu_b_r8h_r16l_full();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxu_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxu_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x54: {
			switch(inst_state & 0xff) {
			case 0x70: rts_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x55: {
			bsr_rel8_full();
			break;
		}
		case 0x56: {
			switch(inst_state & 0xff) {
			case 0x70: rte_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x57: {
			switch(inst_state & 0xcf) {
			case 0x00: trapa_imm2_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x58: {
			switch(inst_state & 0xff) {
			case 0x00: bt_rel16_full(); break;
			case 0x10: bf_rel16_full(); break;
			case 0x20: bhi_rel16_full(); break;
			case 0x30: bls_rel16_full(); break;
			case 0x40: bcc_rel16_full(); break;
			case 0x50: bcs_rel16_full(); break;
			case 0x60: bne_rel16_full(); break;
			case 0x70: beq_rel16_full(); break;
			case 0x80: bvc_rel16_full(); break;
			case 0x90: bvs_rel16_full(); break;
			case 0xa0: bpl_rel16_full(); break;
			case 0xb0: bmi_rel16_full(); break;
			case 0xc0: bge_rel16_full(); break;
			case 0xd0: blt_rel16_full(); break;
			case 0xe0: bgt_rel16_full(); break;
			case 0xf0: ble_rel16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x59: {
			switch(inst_state & 0x8f) {
			case 0x00: jmp_r32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5a: {
			jmp_abs24e_full();
			break;
		}
		case 0x5b: {
			jmp_abs8i_full();
			break;
		}
		case 0x5c: {
			switch(inst_state & 0xff) {
			case 0x00: bsr_rel16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5d: {
			switch(inst_state & 0x8f) {
			case 0x00: jsr_r32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5e: {
			jsr_abs24e_full();
			break;
		}
		case 0x5f: {
			jsr_abs8i_full();
			break;
		}
		case 0x60: {
			bset_r8h_r8l_full();
			break;
		}
		case 0x61: {
			bnot_r8h_r8l_full();
			break;
		}
		case 0x62: {
			bclr_r8h_r8l_full();
			break;
		}
		case 0x63: {
			btst_r8h_r8l_full();
			break;
		}
		case 0x64: {
			or_w_r16h_r16l_full();
			break;
		}
		case 0x65: {
			xor_w_r16h_r16l_full();
			break;
		}
		case 0x66: {
			and_w_r16h_r16l_full();
			break;
		}
		case 0x67: {
			switch(inst_state & 0x80) {
			case 0x00: bst_imm3_r8l_full(); break;
			case 0x80: bist_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x68: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ih_r8l_full(); break;
			case 0x80: mov_b_r8l_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x69: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ih_r16l_full(); break;
			case 0x80: mov_w_r16l_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6a: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x01: case 0x02: case 0x03: case 0x04: case 0x05: case 0x06: case 0x07: case 0x08: case 0x09: case 0x0a: case 0x0b: case 0x0c: case 0x0d: case 0x0e: case 0x0f: mov_b_abs16_r8l_full(); break;
			case 0x10: dispatch_6a10_full(); break;
			case 0x18: dispatch_6a18_full(); break;
			case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: mov_b_abs32_r8l_full(); break;
			case 0x30: dispatch_6a30_full(); break;
			case 0x38: dispatch_6a38_full(); break;
			case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f: movfpe_abs16_r8l_full(); break;
			case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: mov_b_r8l_abs16_full(); break;
			case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: mov_b_r8l_abs32_full(); break;
			case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: movtpe_r8l_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_abs16_r16l_full(); break;
			case 0x20: mov_w_abs32_r16l_full(); break;
			case 0x80: mov_w_r16l_abs16_full(); break;
			case 0xa0: mov_w_r16l_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6c: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ph_r8l_full(); break;
			case 0x80: mov_b_r8l_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ph_r16l_full(); break;
			case 0x80: mov_w_r16l_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32d16h_r8l_full(); break;
			case 0x80: mov_b_r8l_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32d16h_r16l_full(); break;
			case 0x80: mov_w_r16l_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x80) {
			case 0x00: bset_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x80) {
			case 0x00: bnot_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x80) {
			case 0x00: bclr_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x80) {
			case 0x00: btst_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x80) {
			case 0x00: bor_imm3_r8l_full(); break;
			case 0x80: bior_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x80) {
			case 0x00: bxor_imm3_r8l_full(); break;
			case 0x80: bixor_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x80) {
			case 0x00: band_imm3_r8l_full(); break;
			case 0x80: biand_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x80) {
			case 0x00: bld_imm3_r8l_full(); break;
			case 0x80: bild_imm3_r8l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7800_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x79: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_imm16_r16l_full(); break;
			case 0x10: add_w_imm16_r16l_full(); break;
			case 0x20: cmp_w_imm16_r16l_full(); break;
			case 0x30: sub_w_imm16_r16l_full(); break;
			case 0x40: or_w_imm16_r16l_full(); break;
			case 0x50: xor_w_imm16_r16l_full(); break;
			case 0x60: and_w_imm16_r16l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7a: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_imm32_r32l_full(); break;
			case 0x10: add_l_imm32_r32l_full(); break;
			case 0x20: cmp_l_imm32_r32l_full(); break;
			case 0x30: sub_l_imm32_r32l_full(); break;
			case 0x40: or_l_imm32_r32l_full(); break;
			case 0x50: xor_l_imm32_r32l_full(); break;
			case 0x60: and_l_imm32_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7b: {
			switch(inst_state & 0xff) {
			case 0x5c: dispatch_7b5c_full(); break;
			case 0xd4: dispatch_7bd4_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7c: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7c00_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7d: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7d00_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7e: {
			dispatch_7e00_full();
			break;
		}
		case 0x7f: {
			dispatch_7f00_full();
			break;
		}
		case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: {
			add_b_imm8_r8u_full();
			break;
		}
		case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97: case 0x98: case 0x99: case 0x9a: case 0x9b: case 0x9c: case 0x9d: case 0x9e: case 0x9f: {
			addx_b_imm8_r8u_full();
			break;
		}
		case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: {
			cmp_b_imm8_r8u_full();
			break;
		}
		case 0xb0: case 0xb1: case 0xb2: case 0xb3: case 0xb4: case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb: case 0xbc: case 0xbd: case 0xbe: case 0xbf: {
			subx_b_imm8_r8u_full();
			break;
		}
		case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: {
			or_b_imm8_r8u_full();
			break;
		}
		case 0xd0: case 0xd1: case 0xd2: case 0xd3: case 0xd4: case 0xd5: case 0xd6: case 0xd7: case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf: {
			xor_b_imm8_r8u_full();
			break;
		}
		case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7: case 0xe8: case 0xe9: case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: {
			and_b_imm8_r8u_full();
			break;
		}
		case 0xf0: case 0xf1: case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: case 0xf7: case 0xf8: case 0xf9: case 0xfa: case 0xfb: case 0xfc: case 0xfd: case 0xfe: case 0xff: {
			mov_b_imm8_r8u_full();
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x01: {
		switch(inst_state & 0xffff) {
		case 0x00: state_reset_full(); break;
		case 0x01: state_irq_full(); break;
		case 0x03: state_dma_full(); break;
		}
		break;
	}
	case 0x02: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ih_r32l_full(); break;
			case 0x80: mov_l_r32l_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_abs16_r32l_full(); break;
			case 0x20: mov_l_abs32_r32l_full(); break;
			case 0x80: mov_l_r32l_abs16_full(); break;
			case 0xa0: mov_l_r32l_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ph_r32l_full(); break;
			case 0x80: mov_l_r32l_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32d16h_r32l_full(); break;
			case 0x80: mov_l_r32l_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x0f) {
			case 0x00: dispatch_01007800_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x03: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x20: mov_l_r32d32hh_r32l_full(); break;
			case 0xa0: mov_l_r32l_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x07: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ih_ccr_full(); break;
			case 0x80: stc_w_ccr_r32ih_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x00: ldc_w_abs16_ccr_full(); break;
			case 0x20: ldc_w_abs32_ccr_full(); break;
			case 0x80: stc_w_ccr_abs16_full(); break;
			case 0xa0: stc_w_ccr_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ph_ccr_full(); break;
			case 0x80: stc_w_ccr_pr32h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32d16h_ccr_full(); break;
			case 0x80: stc_w_ccr_r32d16h_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_01407800_full(); break;
			case 0x80: dispatch_01407880_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x08: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x20: ldc_w_r32d32hh_ccr_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x09: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0xa0: stc_w_ccr_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0e: {
		switch((inst_state >> 8) & 0xff) {
		case 0x50: {
			mulxs_b_r8h_r16l_full();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxs_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0f: {
		switch((inst_state >> 8) & 0xff) {
		case 0x51: {
			divxs_b_r8h_r16l_full();
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxs_w_r16h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x11: {
		switch((inst_state >> 8) & 0xff) {
		case 0x64: {
			switch(inst_state & 0x88) {
			case 0x00: or_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x65: {
			switch(inst_state & 0x88) {
			case 0x00: xor_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x66: {
			switch(inst_state & 0x88) {
			case 0x00: and_l_r32h_r32l_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x12: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs16_full(); break;
			case 0x80: bior_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs16_full(); break;
			case 0x80: bixor_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs16_full(); break;
			case 0x80: biand_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs16_full(); break;
			case 0x80: bild_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x13: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs16_full(); break;
			case 0x80: bist_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs16_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x14: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs32_full(); break;
			case 0x80: bior_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs32_full(); break;
			case 0x80: bixor_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs32_full(); break;
			case 0x80: biand_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs32_full(); break;
			case 0x80: bild_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x15: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs32_full(); break;
			case 0x80: bist_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs32_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x16: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6a: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_b_r32d32hh_r8l_full(); break;
			case 0xa0: mov_b_r8l_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_w_r32d32hh_r16l_full(); break;
			case 0xa0: mov_w_r16l_r32d32hh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x17: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_b_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x18: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_w_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x19: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_r32ihh_full(); break;
			case 0x80: bior_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_r32ihh_full(); break;
			case 0x80: bixor_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_r32ihh_full(); break;
			case 0x80: biand_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_r32ihh_full(); break;
			case 0x80: bild_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_r32ihh_full(); break;
			case 0x80: bist_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_r32ihh_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs8_full(); break;
			case 0x80: bior_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs8_full(); break;
			case 0x80: bixor_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs8_full(); break;
			case 0x80: biand_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs8_full(); break;
			case 0x80: bild_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs8_full(); break;
			case 0x80: bist_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs8_full(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	}
}
void h8h_device::do_exec_partial()
{
	switch(inst_state >> 16) {
	case 0x00: {
		switch((inst_state >> 8) & 0xff) {
		case 0x00: {
			switch(inst_state & 0xff) {
			case 0x00: nop_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x01: {
			switch(inst_state & 0xff) {
			case 0x00: dispatch_0100_partial(); break;
			case 0x40: dispatch_0140_partial(); break;
			case 0x80: sleep_partial(); break;
			case 0xc0: dispatch_01c0_partial(); break;
			case 0xd0: dispatch_01d0_partial(); break;
			case 0xf0: dispatch_01f0_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x02: {
			switch(inst_state & 0xf0) {
			case 0x00: stc_ccr_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x03: {
			switch(inst_state & 0xf0) {
			case 0x00: ldc_r8l_ccr_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x04: {
			orc_imm8_ccr_partial();
			break;
		}
		case 0x05: {
			xorc_imm8_ccr_partial();
			break;
		}
		case 0x06: {
			andc_imm8_ccr_partial();
			break;
		}
		case 0x07: {
			ldc_imm8_ccr_partial();
			break;
		}
		case 0x08: {
			add_b_r8h_r8l_partial();
			break;
		}
		case 0x09: {
			add_w_r16h_r16l_partial();
			break;
		}
		case 0x0a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: inc_b_one_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: add_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0b: {
			switch(inst_state & 0xf8) {
			case 0x00: adds_l_one_r32l_partial(); break;
			case 0x50: case 0x58: inc_w_one_r16l_partial(); break;
			case 0x70: inc_l_one_r32l_partial(); break;
			case 0x80: adds_l_two_r32l_partial(); break;
			case 0x90: adds_l_four_r32l_partial(); break;
			case 0xd0: case 0xd8: inc_w_two_r16l_partial(); break;
			case 0xf0: inc_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x0c: {
			mov_b_r8h_r8l_partial();
			break;
		}
		case 0x0d: {
			mov_w_r16h_r16l_partial();
			break;
		}
		case 0x0e: {
			addx_b_r8h_r8l_partial();
			break;
		}
		case 0x0f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: daa_b_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: mov_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x10: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shll_b_r8l_partial(); break;
			case 0x10: case 0x18: shll_w_r16l_partial(); break;
			case 0x30: shll_l_r32l_partial(); break;
			case 0x80: case 0x88: shal_b_r8l_partial(); break;
			case 0x90: case 0x98: shal_w_r16l_partial(); break;
			case 0xb0: shal_l_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x11: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: shlr_b_r8l_partial(); break;
			case 0x10: case 0x18: shlr_w_r16l_partial(); break;
			case 0x30: shlr_l_r32l_partial(); break;
			case 0x80: case 0x88: shar_b_r8l_partial(); break;
			case 0x90: case 0x98: shar_w_r16l_partial(); break;
			case 0xb0: shar_l_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x12: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxl_b_r8l_partial(); break;
			case 0x10: case 0x18: rotxl_w_r16l_partial(); break;
			case 0x30: rotxl_l_r32l_partial(); break;
			case 0x80: case 0x88: rotl_b_r8l_partial(); break;
			case 0x90: case 0x98: rotl_w_r16l_partial(); break;
			case 0xb0: rotl_l_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x13: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: rotxr_b_r8l_partial(); break;
			case 0x10: case 0x18: rotxr_w_r16l_partial(); break;
			case 0x30: rotxr_l_r32l_partial(); break;
			case 0x80: case 0x88: rotr_b_r8l_partial(); break;
			case 0x90: case 0x98: rotr_w_r16l_partial(); break;
			case 0xb0: rotr_l_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x14: {
			or_b_r8h_r8l_partial();
			break;
		}
		case 0x15: {
			xor_b_r8h_r8l_partial();
			break;
		}
		case 0x16: {
			and_b_r8h_r8l_partial();
			break;
		}
		case 0x17: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: not_b_r8l_partial(); break;
			case 0x10: case 0x18: not_w_r16l_partial(); break;
			case 0x30: not_l_r32l_partial(); break;
			case 0x50: case 0x58: extu_w_r16l_partial(); break;
			case 0x70: extu_l_r32l_partial(); break;
			case 0x80: case 0x88: neg_b_r8l_partial(); break;
			case 0x90: case 0x98: neg_w_r16l_partial(); break;
			case 0xb0: neg_l_r32l_partial(); break;
			case 0xd0: case 0xd8: exts_w_r16l_partial(); break;
			case 0xf0: exts_l_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x18: {
			sub_b_r8h_r8l_partial();
			break;
		}
		case 0x19: {
			sub_w_r16h_r16l_partial();
			break;
		}
		case 0x1a: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: dec_b_one_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: sub_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1b: {
			switch(inst_state & 0xf8) {
			case 0x00: subs_l_one_r32l_partial(); break;
			case 0x50: case 0x58: dec_w_one_r16l_partial(); break;
			case 0x70: dec_l_one_r32l_partial(); break;
			case 0x80: subs_l_two_r32l_partial(); break;
			case 0x90: subs_l_four_r32l_partial(); break;
			case 0xd0: case 0xd8: dec_w_two_r16l_partial(); break;
			case 0xf0: dec_l_two_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x1c: {
			cmp_b_r8h_r8l_partial();
			break;
		}
		case 0x1d: {
			cmp_w_r16h_r16l_partial();
			break;
		}
		case 0x1e: {
			subx_b_r8h_r8l_partial();
			break;
		}
		case 0x1f: {
			switch(inst_state & 0xf8) {
			case 0x00: case 0x08: das_b_r8l_partial(); break;
			case 0x80: case 0x90: case 0xa0: case 0xb0: case 0xc0: case 0xd0: case 0xe0: case 0xf0: cmp_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: {
			mov_b_abs8_r8u_partial();
			break;
		}
		case 0x30: case 0x31: case 0x32: case 0x33: case 0x34: case 0x35: case 0x36: case 0x37: case 0x38: case 0x39: case 0x3a: case 0x3b: case 0x3c: case 0x3d: case 0x3e: case 0x3f: {
			mov_b_r8u_abs8_partial();
			break;
		}
		case 0x40: {
			bt_rel8_partial();
			break;
		}
		case 0x41: {
			bf_rel8_partial();
			break;
		}
		case 0x42: {
			bhi_rel8_partial();
			break;
		}
		case 0x43: {
			bls_rel8_partial();
			break;
		}
		case 0x44: {
			bcc_rel8_partial();
			break;
		}
		case 0x45: {
			bcs_rel8_partial();
			break;
		}
		case 0x46: {
			bne_rel8_partial();
			break;
		}
		case 0x47: {
			beq_rel8_partial();
			break;
		}
		case 0x48: {
			bvc_rel8_partial();
			break;
		}
		case 0x49: {
			bvs_rel8_partial();
			break;
		}
		case 0x4a: {
			bpl_rel8_partial();
			break;
		}
		case 0x4b: {
			bmi_rel8_partial();
			break;
		}
		case 0x4c: {
			bge_rel8_partial();
			break;
		}
		case 0x4d: {
			blt_rel8_partial();
			break;
		}
		case 0x4e: {
			bgt_rel8_partial();
			break;
		}
		case 0x4f: {
			ble_rel8_partial();
			break;
		}
		case 0x50: {
			mulxu_b_r8h_r16l_partial();
			break;
		}
		case 0x51: {
			divxu_b_r8h_r16l_partial();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxu_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxu_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x54: {
			switch(inst_state & 0xff) {
			case 0x70: rts_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x55: {
			bsr_rel8_partial();
			break;
		}
		case 0x56: {
			switch(inst_state & 0xff) {
			case 0x70: rte_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x57: {
			switch(inst_state & 0xcf) {
			case 0x00: trapa_imm2_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x58: {
			switch(inst_state & 0xff) {
			case 0x00: bt_rel16_partial(); break;
			case 0x10: bf_rel16_partial(); break;
			case 0x20: bhi_rel16_partial(); break;
			case 0x30: bls_rel16_partial(); break;
			case 0x40: bcc_rel16_partial(); break;
			case 0x50: bcs_rel16_partial(); break;
			case 0x60: bne_rel16_partial(); break;
			case 0x70: beq_rel16_partial(); break;
			case 0x80: bvc_rel16_partial(); break;
			case 0x90: bvs_rel16_partial(); break;
			case 0xa0: bpl_rel16_partial(); break;
			case 0xb0: bmi_rel16_partial(); break;
			case 0xc0: bge_rel16_partial(); break;
			case 0xd0: blt_rel16_partial(); break;
			case 0xe0: bgt_rel16_partial(); break;
			case 0xf0: ble_rel16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x59: {
			switch(inst_state & 0x8f) {
			case 0x00: jmp_r32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5a: {
			jmp_abs24e_partial();
			break;
		}
		case 0x5b: {
			jmp_abs8i_partial();
			break;
		}
		case 0x5c: {
			switch(inst_state & 0xff) {
			case 0x00: bsr_rel16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5d: {
			switch(inst_state & 0x8f) {
			case 0x00: jsr_r32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x5e: {
			jsr_abs24e_partial();
			break;
		}
		case 0x5f: {
			jsr_abs8i_partial();
			break;
		}
		case 0x60: {
			bset_r8h_r8l_partial();
			break;
		}
		case 0x61: {
			bnot_r8h_r8l_partial();
			break;
		}
		case 0x62: {
			bclr_r8h_r8l_partial();
			break;
		}
		case 0x63: {
			btst_r8h_r8l_partial();
			break;
		}
		case 0x64: {
			or_w_r16h_r16l_partial();
			break;
		}
		case 0x65: {
			xor_w_r16h_r16l_partial();
			break;
		}
		case 0x66: {
			and_w_r16h_r16l_partial();
			break;
		}
		case 0x67: {
			switch(inst_state & 0x80) {
			case 0x00: bst_imm3_r8l_partial(); break;
			case 0x80: bist_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x68: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ih_r8l_partial(); break;
			case 0x80: mov_b_r8l_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x69: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ih_r16l_partial(); break;
			case 0x80: mov_w_r16l_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6a: {
			switch(inst_state & 0xff) {
			case 0x00: case 0x01: case 0x02: case 0x03: case 0x04: case 0x05: case 0x06: case 0x07: case 0x08: case 0x09: case 0x0a: case 0x0b: case 0x0c: case 0x0d: case 0x0e: case 0x0f: mov_b_abs16_r8l_partial(); break;
			case 0x10: dispatch_6a10_partial(); break;
			case 0x18: dispatch_6a18_partial(); break;
			case 0x20: case 0x21: case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28: case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2e: case 0x2f: mov_b_abs32_r8l_partial(); break;
			case 0x30: dispatch_6a30_partial(); break;
			case 0x38: dispatch_6a38_partial(); break;
			case 0x40: case 0x41: case 0x42: case 0x43: case 0x44: case 0x45: case 0x46: case 0x47: case 0x48: case 0x49: case 0x4a: case 0x4b: case 0x4c: case 0x4d: case 0x4e: case 0x4f: movfpe_abs16_r8l_partial(); break;
			case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: mov_b_r8l_abs16_partial(); break;
			case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: mov_b_r8l_abs32_partial(); break;
			case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: movtpe_r8l_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_abs16_r16l_partial(); break;
			case 0x20: mov_w_abs32_r16l_partial(); break;
			case 0x80: mov_w_r16l_abs16_partial(); break;
			case 0xa0: mov_w_r16l_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6c: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32ph_r8l_partial(); break;
			case 0x80: mov_b_r8l_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32ph_r16l_partial(); break;
			case 0x80: mov_w_r16l_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6e: {
			switch(inst_state & 0x80) {
			case 0x00: mov_b_r32d16h_r8l_partial(); break;
			case 0x80: mov_b_r8l_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x80) {
			case 0x00: mov_w_r32d16h_r16l_partial(); break;
			case 0x80: mov_w_r16l_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x80) {
			case 0x00: bset_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x80) {
			case 0x00: bnot_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x80) {
			case 0x00: bclr_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x80) {
			case 0x00: btst_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x80) {
			case 0x00: bor_imm3_r8l_partial(); break;
			case 0x80: bior_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x80) {
			case 0x00: bxor_imm3_r8l_partial(); break;
			case 0x80: bixor_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x80) {
			case 0x00: band_imm3_r8l_partial(); break;
			case 0x80: biand_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x80) {
			case 0x00: bld_imm3_r8l_partial(); break;
			case 0x80: bild_imm3_r8l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7800_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x79: {
			switch(inst_state & 0xf0) {
			case 0x00: mov_w_imm16_r16l_partial(); break;
			case 0x10: add_w_imm16_r16l_partial(); break;
			case 0x20: cmp_w_imm16_r16l_partial(); break;
			case 0x30: sub_w_imm16_r16l_partial(); break;
			case 0x40: or_w_imm16_r16l_partial(); break;
			case 0x50: xor_w_imm16_r16l_partial(); break;
			case 0x60: and_w_imm16_r16l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7a: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_imm32_r32l_partial(); break;
			case 0x10: add_l_imm32_r32l_partial(); break;
			case 0x20: cmp_l_imm32_r32l_partial(); break;
			case 0x30: sub_l_imm32_r32l_partial(); break;
			case 0x40: or_l_imm32_r32l_partial(); break;
			case 0x50: xor_l_imm32_r32l_partial(); break;
			case 0x60: and_l_imm32_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7b: {
			switch(inst_state & 0xff) {
			case 0x5c: dispatch_7b5c_partial(); break;
			case 0xd4: dispatch_7bd4_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7c: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7c00_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7d: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_7d00_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x7e: {
			dispatch_7e00_partial();
			break;
		}
		case 0x7f: {
			dispatch_7f00_partial();
			break;
		}
		case 0x80: case 0x81: case 0x82: case 0x83: case 0x84: case 0x85: case 0x86: case 0x87: case 0x88: case 0x89: case 0x8a: case 0x8b: case 0x8c: case 0x8d: case 0x8e: case 0x8f: {
			add_b_imm8_r8u_partial();
			break;
		}
		case 0x90: case 0x91: case 0x92: case 0x93: case 0x94: case 0x95: case 0x96: case 0x97: case 0x98: case 0x99: case 0x9a: case 0x9b: case 0x9c: case 0x9d: case 0x9e: case 0x9f: {
			addx_b_imm8_r8u_partial();
			break;
		}
		case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xa4: case 0xa5: case 0xa6: case 0xa7: case 0xa8: case 0xa9: case 0xaa: case 0xab: case 0xac: case 0xad: case 0xae: case 0xaf: {
			cmp_b_imm8_r8u_partial();
			break;
		}
		case 0xb0: case 0xb1: case 0xb2: case 0xb3: case 0xb4: case 0xb5: case 0xb6: case 0xb7: case 0xb8: case 0xb9: case 0xba: case 0xbb: case 0xbc: case 0xbd: case 0xbe: case 0xbf: {
			subx_b_imm8_r8u_partial();
			break;
		}
		case 0xc0: case 0xc1: case 0xc2: case 0xc3: case 0xc4: case 0xc5: case 0xc6: case 0xc7: case 0xc8: case 0xc9: case 0xca: case 0xcb: case 0xcc: case 0xcd: case 0xce: case 0xcf: {
			or_b_imm8_r8u_partial();
			break;
		}
		case 0xd0: case 0xd1: case 0xd2: case 0xd3: case 0xd4: case 0xd5: case 0xd6: case 0xd7: case 0xd8: case 0xd9: case 0xda: case 0xdb: case 0xdc: case 0xdd: case 0xde: case 0xdf: {
			xor_b_imm8_r8u_partial();
			break;
		}
		case 0xe0: case 0xe1: case 0xe2: case 0xe3: case 0xe4: case 0xe5: case 0xe6: case 0xe7: case 0xe8: case 0xe9: case 0xea: case 0xeb: case 0xec: case 0xed: case 0xee: case 0xef: {
			and_b_imm8_r8u_partial();
			break;
		}
		case 0xf0: case 0xf1: case 0xf2: case 0xf3: case 0xf4: case 0xf5: case 0xf6: case 0xf7: case 0xf8: case 0xf9: case 0xfa: case 0xfb: case 0xfc: case 0xfd: case 0xfe: case 0xff: {
			mov_b_imm8_r8u_partial();
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x01: {
		switch(inst_state & 0xffff) {
		case 0x00: state_reset_partial(); break;
		case 0x01: state_irq_partial(); break;
		case 0x03: state_dma_partial(); break;
		}
		break;
	}
	case 0x02: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ih_r32l_partial(); break;
			case 0x80: mov_l_r32l_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x00: mov_l_abs16_r32l_partial(); break;
			case 0x20: mov_l_abs32_r32l_partial(); break;
			case 0x80: mov_l_r32l_abs16_partial(); break;
			case 0xa0: mov_l_r32l_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32ph_r32l_partial(); break;
			case 0x80: mov_l_r32l_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x88) {
			case 0x00: mov_l_r32d16h_r32l_partial(); break;
			case 0x80: mov_l_r32l_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x0f) {
			case 0x00: dispatch_01007800_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x03: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xf8) {
			case 0x20: mov_l_r32d32hh_r32l_partial(); break;
			case 0xa0: mov_l_r32l_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x07: {
		switch((inst_state >> 8) & 0xff) {
		case 0x69: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ih_ccr_partial(); break;
			case 0x80: stc_w_ccr_r32ih_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x00: ldc_w_abs16_ccr_partial(); break;
			case 0x20: ldc_w_abs32_ccr_partial(); break;
			case 0x80: stc_w_ccr_abs16_partial(); break;
			case 0xa0: stc_w_ccr_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6d: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32ph_ccr_partial(); break;
			case 0x80: stc_w_ccr_pr32h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6f: {
			switch(inst_state & 0x8f) {
			case 0x00: ldc_w_r32d16h_ccr_partial(); break;
			case 0x80: stc_w_ccr_r32d16h_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x78: {
			switch(inst_state & 0x8f) {
			case 0x00: dispatch_01407800_partial(); break;
			case 0x80: dispatch_01407880_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x08: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0x20: ldc_w_r32d32hh_ccr_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x09: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6b: {
			switch(inst_state & 0xff) {
			case 0xa0: stc_w_ccr_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0e: {
		switch((inst_state >> 8) & 0xff) {
		case 0x50: {
			mulxs_b_r8h_r16l_partial();
			break;
		}
		case 0x52: {
			switch(inst_state & 0x08) {
			case 0x00: mulxs_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x0f: {
		switch((inst_state >> 8) & 0xff) {
		case 0x51: {
			divxs_b_r8h_r16l_partial();
			break;
		}
		case 0x53: {
			switch(inst_state & 0x08) {
			case 0x00: divxs_w_r16h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x11: {
		switch((inst_state >> 8) & 0xff) {
		case 0x64: {
			switch(inst_state & 0x88) {
			case 0x00: or_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x65: {
			switch(inst_state & 0x88) {
			case 0x00: xor_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x66: {
			switch(inst_state & 0x88) {
			case 0x00: and_l_r32h_r32l_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x12: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs16_partial(); break;
			case 0x80: bior_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs16_partial(); break;
			case 0x80: bixor_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs16_partial(); break;
			case 0x80: biand_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs16_partial(); break;
			case 0x80: bild_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x13: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs16_partial(); break;
			case 0x80: bist_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs16_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x14: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs32_partial(); break;
			case 0x80: bior_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs32_partial(); break;
			case 0x80: bixor_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs32_partial(); break;
			case 0x80: biand_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs32_partial(); break;
			case 0x80: bild_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x15: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs32_partial(); break;
			case 0x80: bist_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs32_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x16: {
		switch((inst_state >> 8) & 0xff) {
		case 0x6a: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_b_r32d32hh_r8l_partial(); break;
			case 0xa0: mov_b_r8l_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x6b: {
			switch(inst_state & 0xf0) {
			case 0x20: mov_w_r32d32hh_r16l_partial(); break;
			case 0xa0: mov_w_r16l_r32d32hh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x17: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_b_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x18: {
		switch((inst_state >> 8) & 0xff) {
		case 0x59: {
			switch(inst_state & 0xff) {
			case 0x8f: eepmov_w_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x19: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_r32ihh_partial(); break;
			case 0x80: bior_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_r32ihh_partial(); break;
			case 0x80: bixor_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_r32ihh_partial(); break;
			case 0x80: biand_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_r32ihh_partial(); break;
			case 0x80: bild_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1a: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_r32ihh_partial(); break;
			case 0x80: bist_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_r32ihh_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1b: {
		switch((inst_state >> 8) & 0xff) {
		case 0x63: {
			switch(inst_state & 0x0f) {
			case 0x00: btst_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x73: {
			switch(inst_state & 0x8f) {
			case 0x00: btst_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x74: {
			switch(inst_state & 0x8f) {
			case 0x00: bor_imm3_abs8_partial(); break;
			case 0x80: bior_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x75: {
			switch(inst_state & 0x8f) {
			case 0x00: bxor_imm3_abs8_partial(); break;
			case 0x80: bixor_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x76: {
			switch(inst_state & 0x8f) {
			case 0x00: band_imm3_abs8_partial(); break;
			case 0x80: biand_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x77: {
			switch(inst_state & 0x8f) {
			case 0x00: bld_imm3_abs8_partial(); break;
			case 0x80: bild_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	case 0x1c: {
		switch((inst_state >> 8) & 0xff) {
		case 0x60: {
			switch(inst_state & 0x0f) {
			case 0x00: bset_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x61: {
			switch(inst_state & 0x0f) {
			case 0x00: bnot_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x62: {
			switch(inst_state & 0x0f) {
			case 0x00: bclr_r8h_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x67: {
			switch(inst_state & 0x8f) {
			case 0x00: bst_imm3_abs8_partial(); break;
			case 0x80: bist_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x70: {
			switch(inst_state & 0x8f) {
			case 0x00: bset_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x71: {
			switch(inst_state & 0x8f) {
			case 0x00: bnot_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		case 0x72: {
			switch(inst_state & 0x8f) {
			case 0x00: bclr_imm3_abs8_partial(); break;
			default: illegal(); break;
			}
			break;
		}
		default: illegal(); break;
		}
		break;
	}
	}
}
