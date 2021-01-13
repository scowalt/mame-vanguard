#include <string>
#include <mutex>
#include <emu.h>
#include "ManagedWrapper.h"
#include "../src/frontend/mame/mame.h"
#include "UnmanagedWrapper.h"
#include "screen.h"
#include "debug/dvmemory.h"
#include <modules/render/aviwrite.h>
#include "clifront.h"
#include <drivenum.h>
std::string romfilename;
std::string romfilenames[500];
int romcounter = 0;
unsigned char ManagedWrapper::PEEK(std::string memclass, std::string region, long long addr, int indexnum, std::string devicename)
{
	if (memclass == "Region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		unsigned char mem_content = 0;
		mem_content |= mregion.as_u8((BYTE8_XOR_LE(addr)) | (addr));

		return mem_content;

	}
	else if (memclass == "Shared")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		unsigned char mem_content = 0;
		u8* ptr = (u8*)mshare.ptr();
		mem_content |= ptr[((BYTE8_XOR_LE(addr)) | (addr))];

		return mem_content;
	}
	else if (memclass == "Space")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().has_space(spacenum))
		{
			address_space& space = mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum);
			offs_t address = static_cast<u32>(addr) & space.addrmask();
			u8 data = 0;
			address = address << (abs)(space.addr_shift());
			if (!space.device().memory().translate(space.spacenum(), TRANSLATE_READ_DEBUG, address))
				return 0;
			data = space.read_byte(address);
			//printf("value at address 0x%X is %X\n", address, data);
			return data;
		}
		else return NULL;
	}
	else return NULL;
}

void ManagedWrapper::POKE(std::string memclass, std::string region, long long addr, unsigned char val, int indexnum, std::string devicename)
{
	if (memclass == "Region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		mregion.base()[(BYTE8_XOR_LE(addr)) | (addr)] = val & 0xff;
	}
	else if (memclass == "Shared")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		u8* ptr = (u8*)mshare.ptr();
		ptr[(BYTE8_XOR_LE(addr)) | (addr)] = val & 0xff;
	}
	else if (memclass == "Space")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().has_space(spacenum))
		{
			address_space& space = mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum);
			offs_t address = static_cast<u32>(addr) & space.addrmask();
			address = address << (abs)(space.addr_shift());
			if (!space.device().memory().translate(space.spacenum(), TRANSLATE_READ_DEBUG, address))
				return;
			space.write_byte(address, val);
		}
	}
	else return;
}

long long ManagedWrapper::GetMemorySize(std::string memclass, std::string region, int indexnum, std::string devicename)
{
	if (memclass == "Region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		return mregion.bytes();
	}
	if (memclass == "Shared")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		return mshare.bytes();
	}
	if (memclass == "Space")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().has_space(spacenum))
		{
			
			address_space& space = mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum);
			unsigned long long maxaddr = (u64)(space.addrmask()) + 1;
			if (maxaddr < 8)
			{
				maxaddr = 0x100000000;
			}
			return maxaddr;
		}
		else return 0;
	}
	else return 0;
}

int ManagedWrapper::GetByteWidth(std::string memclass, std::string region, int indexnum, std::string devicename)
{
	if (memclass == "Region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		return mregion.bytewidth();
	}
	if (memclass == "Shared")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		return mshare.bytewidth();
	}
	if (memclass == "Space")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().has_space(spacenum))
			return (int)mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum).data_width() / 8;
		else return 0;
	}
	else return 0;
}

void ManagedWrapper::ACTIVATELUA()
{
	mame_machine_manager::instance()->start_luaengine();
}

std::string ManagedWrapper::GetMemoryDomain(int indexnum)
{
	std::string regionArray[500];
	std::string shareArray[500];
	std::string deviceArray[500];
	int regioncounter = 0;
	int sharecounter = 0;
	int devicecounter = 0;
	for (auto i = mame_machine_manager::instance()->machine()->memory().regions().cbegin(); i != mame_machine_manager::instance()->machine()->memory().regions().cend(); ++i)
	{
		regioncounter += 1;
		regionArray[regioncounter] = i->first;
	}
	for (auto i = mame_machine_manager::instance()->machine()->memory().shares().cbegin(); i != mame_machine_manager::instance()->machine()->memory().shares().cend(); ++i)
	{
		sharecounter += 1;
		shareArray[sharecounter] = i->first;
	}
	for (device_memory_interface& memintf : memory_interface_enumerator(mame_machine_manager::instance()->machine()->root_device()))
	{
		for (int spacenum = 0; spacenum < memintf.max_space_count(); ++spacenum)
		{
			if (memintf.has_space(spacenum))
			{
				address_space& space(memintf.space(spacenum));
				devicecounter += 1;
				deviceArray[devicecounter] = space.name();
			}
		}
	}
	if (regionArray[indexnum] != "")
	{
		return regionArray[indexnum].erase(0, 1);
	}
	else if (shareArray[indexnum - regioncounter] != "")
	{
		return shareArray[indexnum - regioncounter].erase(0, 1);
	}
	else if (deviceArray[indexnum - (regioncounter+sharecounter)] != "")
	{
		return deviceArray[indexnum - (regioncounter + sharecounter)];
	}
	else return "";
}

std::string ManagedWrapper::GetDomainClass(int indexnum)
{
	std::string regionArray[500];
	std::string shareArray[500];
	std::string deviceArray[500];
	int regioncounter = 0;
	int sharecounter = 0;
	int devicecounter = 0;
	for (auto i = mame_machine_manager::instance()->machine()->memory().regions().cbegin(); i != mame_machine_manager::instance()->machine()->memory().regions().cend(); ++i)
	{
		regioncounter += 1;
		regionArray[regioncounter] = i->first;
	}
	for (auto i = mame_machine_manager::instance()->machine()->memory().shares().cbegin(); i != mame_machine_manager::instance()->machine()->memory().shares().cend(); ++i)
	{
		sharecounter += 1;
		shareArray[sharecounter] = i->first;
	}
	for (device_memory_interface& memintf : memory_interface_enumerator(mame_machine_manager::instance()->machine()->root_device()))
	{
		for (int spacenum = 0; spacenum < memintf.max_space_count(); ++spacenum)
		{
			if (memintf.has_space(spacenum))
			{
				address_space& space(memintf.space(spacenum));
				devicecounter += 1;
				deviceArray[devicecounter] = space.name();
			}
		}
	}

	if (regionArray[indexnum] != "")
	{
		return "Region";
	}
	else if (shareArray[indexnum - regioncounter] != "")
	{
		return "Shared";
	}
	else if (deviceArray[indexnum - (regioncounter+sharecounter)] != "")
	{
		return "Space";
	}
	else return "";
}

bool ManagedWrapper::IsBigEndian(std::string memclass, std::string region, int indexnum, std::string devicename)
{
	if (memclass == "Region")
	{
		if (mame_machine_manager::instance()->machine()->system().name != NULL)
			if (mame_machine_manager::instance()->machine()->root_device().memregion(region.c_str())->endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}
	else if (memclass == "Shared")
	{
		if (mame_machine_manager::instance()->machine()->system().name != NULL)
			if (mame_machine_manager::instance()->machine()->root_device().memshare(region.c_str())->endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}
	else if (memclass == "Space")
	{
		int spacenum = indexnum;

		if (mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().has_space(spacenum))
			if (mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum).endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}

	else return false;
}

int ManagedWrapper::GetCPUSpaceNumber(int indexnum)
{
	int deviceArray[500];
	int devicecounter = 0;
	for (device_memory_interface& memintf : memory_interface_enumerator(mame_machine_manager::instance()->machine()->root_device()))
	{
		for (int spacenum = 0; spacenum < memintf.max_space_count(); ++spacenum)
		{
			if (memintf.has_space(spacenum))
			{
				devicecounter += 1;
				deviceArray[devicecounter] = spacenum;
			}
		}
	}
	if (deviceArray[indexnum - (ManagedWrapper::GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces())] != NULL)
	{
		return deviceArray[indexnum - (ManagedWrapper::GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces())];
	}
	else return 0;
}

std::string ManagedWrapper::GetDeviceName(int indexnum)
{
	std::string deviceArray[500];
	int devicecounter = 0;
	for (device_memory_interface& memintf : memory_interface_enumerator(mame_machine_manager::instance()->machine()->root_device()))
	{
		for (int spacenum = 0; spacenum < memintf.max_space_count(); ++spacenum)
		{
			if (memintf.has_space(spacenum))
			{
				address_space& space(memintf.space(spacenum));
				devicecounter += 1;
				//printf("The following device has RAM: %s\n", space.device().tag());
				deviceArray[devicecounter] = std::string(space.device().tag()).erase(0, 1);
			}
		}
	}
	if (deviceArray[indexnum - (ManagedWrapper::GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces())] != "" && indexnum > ManagedWrapper::GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces())
	{
		return deviceArray[indexnum - (ManagedWrapper::GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces())];
	}
	else return "";
}

void ManagedWrapper::SaveSaveState(std::string filename)
{
	mame_machine_manager::instance()->machine()->schedule_save(filename.c_str());
}

void ManagedWrapper::LoadSaveState(std::string filename)
{
	printf("Savestate path is %s.\n", filename.c_str());
	/*if (mame_machine_manager::instance()->machine()->system().name != NULL)
	{*/
		mame_machine_manager::instance()->machine()->schedule_load(filename.c_str());
		printf("%s loaded.\n", filename.c_str());
	/*}
	else return;*/
}

int ManagedWrapper::GetTotalNumOfRegionsAndShares()
{
	int regioncounter = 0;
	int sharecounter = 0;
	int devicecounter = 0;
	for (auto i = mame_machine_manager::instance()->machine()->memory().regions().cbegin(); i != mame_machine_manager::instance()->machine()->memory().regions().cend(); ++i)
	{
		regioncounter += 1;
	}
	for (auto i = mame_machine_manager::instance()->machine()->memory().shares().cbegin(); i != mame_machine_manager::instance()->machine()->memory().shares().cend(); ++i)
	{
		if (mame_machine_manager::instance()->machine()->memory().shares().size() != 0)
			sharecounter += 1;
	}
	for (device_memory_interface& memintf : memory_interface_enumerator(mame_machine_manager::instance()->machine()->root_device()))
	{
		for (int spacenum = 0; spacenum < memintf.max_space_count(); ++spacenum)
		{
			if (memintf.has_space(spacenum))
			{
				devicecounter += 1;
			}
		}
	}
	return regioncounter + sharecounter + devicecounter; //
}

int ManagedWrapper::GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces()
{
	int regioncounter = 0;
	int sharecounter = 0;
	for (auto i = mame_machine_manager::instance()->machine()->memory().regions().cbegin(); i != mame_machine_manager::instance()->machine()->memory().regions().cend(); ++i)
	{
		regioncounter += 1;
	}
	for (auto i = mame_machine_manager::instance()->machine()->memory().shares().cbegin(); i != mame_machine_manager::instance()->machine()->memory().shares().cend(); ++i)
	{
		if (mame_machine_manager::instance()->machine()->memory().shares().size() != 0)
			sharecounter += 1;
	}
	
	return regioncounter + sharecounter; //
}

std::string ManagedWrapper::GetGameName()
{
	return std::string(mame_machine_manager::instance()->machine()->config().gamedrv().type.fullname());
}

void ManagedWrapper::Resume(bool threadon)
{
	if (threadon == false)
	{
		mame_machine_manager::instance()->machine()->pause();
	}
	if (threadon == true)
	{
		mame_machine_manager::instance()->machine()->resume();
	}
}

void ManagedWrapper::RenderStartAVI(std::string filename)
{
	//screen_device* const screen = screen_device_enumerator(mame_machine_manager::instance()->machine()->root_device()).first();
	mame_machine_manager::instance()->machine()->video().begin_recording(filename.c_str(), movie_recording::format::AVI);
}

void ManagedWrapper::RenderStopAVI()
{
	//screen_device* const screen = screen_device_enumerator(mame_machine_manager::instance()->machine()->root_device()).first();
	mame_machine_manager::instance()->machine()->video().end_recording();
}
void ManagedWrapper::RenderStartMNG(std::string filename)
{
	//screen_device* const screen = screen_device_enumerator(mame_machine_manager::instance()->machine()->root_device()).first();
	mame_machine_manager::instance()->machine()->video().begin_recording(filename.c_str(), movie_recording::format::MNG);
}

void ManagedWrapper::RenderStopMNG()
{
	//screen_device* const screen = screen_device_enumerator(mame_machine_manager::instance()->machine()->root_device()).first();
	mame_machine_manager::instance()->machine()->video().end_recording();
}

void ManagedWrapper::RenderIMAGE(std::string filename)
{
	emu_file file(filename.c_str(), OPEN_FLAG_WRITE | OPEN_FLAG_CREATE | OPEN_FLAG_CREATE_PATHS);
	screen_device* const screen = screen_device_enumerator(mame_machine_manager::instance()->machine()->root_device()).first();
	mame_machine_manager::instance()->machine()->video().save_snapshot(screen, file);
}

void ManagedWrapper::RenderStartWAV(std::string filename)
{
	mame_machine_manager::instance()->machine()->sound().start_recording(filename);
}

void ManagedWrapper::RenderStopWAV()
{
	mame_machine_manager::instance()->machine()->sound().stop_recording();
}

void ManagedWrapper::LOADGAME(std::string filename, std::string gamename)
{
	
}
void ManagedWrapper::CATCHGAME(std::string rom)
{
	if (romfilenames->find(rom) != std::string::npos) //check if the romfilepath is already in the romfilenames array
		return;
	if(rom.find(".7z") != std::string::npos || rom.find(".zip") != std::string::npos || rom.find(".7Z") != std::string::npos || rom.find(".ZIP") != std::string::npos) //make sure the file is an archive
	{
			if (rom != "..7z" && rom != "..zip") //check to make sure the file is real
			{
				if (rom.find(":") != std::string::npos) //check that there is a drive in the full path
				{
					SETROMFILENAME(rom);
					printf("Current game's rom is %s.\n", romfilename.c_str());
				}
			}
	}
}

bool ManagedWrapper::IsZipARom(std::string filename)
{
	return true; //this function does nothing
}

std::string ManagedWrapper::GETROMFILENAME(int indexnum)
{
	if (!romfilenames[indexnum].empty())
	{
		return romfilenames[indexnum];
	}
	else return " ";
}

void ManagedWrapper::SETROMFILENAME(std::string stringtoset)
{
	if(romfilename != stringtoset)
	{
		if(romfilenames->find(stringtoset) == std::string::npos)
		{
			romfilename = stringtoset;
			romcounter += 1;
			romfilenames[romcounter] = romfilename;
		}
	}
}

void ManagedWrapper::LOADROM(std::string rompath, std::string shortgamename)
{
	if (mame_machine_manager::instance()->machine()->config().gamedrv().name != shortgamename)
	{
		for (int i = 0; i < 500; i++)
		{
			romfilenames[i] = "";
		}
		emu_options& options = mame_machine_manager::instance()->options();
		std::string semicolon = ";"; //for some reason it has to be its own variable
		if (std::string(options.media_path()).find(rompath) == std::string::npos)
		{
			std::string mediapath = options.media_path() + semicolon + rompath;
			printf("New media path is %s.\n", mediapath.c_str());
			options.set_value(OPTION_MEDIAPATH, mediapath, OPTION_PRIORITY_DEFAULT);
			printf("Set mediapath.\n");
		}
		int i = driver_list::find(shortgamename.c_str());
		printf("Searching for %s.\n", shortgamename.c_str());
		if (i != -1)
		{
			printf("%i. This means the driver was FOUND.\n", i);
			mame_machine_manager::instance()->schedule_new_driver(driver_list::driver(i));
			printf("Scheduled the driver to run next.\n");
			mame_machine_manager::instance()->machine()->schedule_hard_reset();
			printf("Reset the machine.\n");
		}
	}
}

void ManagedWrapper::SAVEROM(std::string rompath)
{
}

int ManagedWrapper::COLLECTTOTALROMS()
{
	int romcounter = 0;
	for (int i = 0; i < 500; i++)
	{
		if (ManagedWrapper::GETROMFILENAME(i) != " ")
		{
			romcounter += 1;
		}
	}
	printf("Total roms: %i\n", romcounter);
	return romcounter;
}

std::string ManagedWrapper::GetShortGameName()
{
	return std::string(mame_machine_manager::instance()->machine()->config().gamedrv().name);
}

void ManagedWrapper::FLUSHROMCOUNTER()
{
	romcounter = 0;
}
