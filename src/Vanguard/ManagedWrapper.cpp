#include <string>
#include <mutex>
#include <emu.h>
#include "ManagedWrapper.h"
#include "../src/frontend/mame/mame.h"
#include "UnmanagedWrapper.h"
#include "screen.h"
#include "debug/dvmemory.h"
#include <modules/render/aviwrite.h>
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
			return mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum).read_byte(addr);
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
			mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum).write_byte(addr, val);
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
			//int returnValue = ((((mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum).data_width() / 24) * (mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum).addr_width()))) * 1024 * 1024); //Can't get the device memory map's actual size afaik so I'll just pretend its size is its bytewidth times its address width
			//printf("%s size is %i (0x%x)\n", region.c_str(), returnValue, returnValue);
			//if (returnValue < 1)
			//{
			//	return 1;
			//}
			//else return returnValue;
			address_space& space = mame_machine_manager::instance()->machine()->device(devicename.c_str())->memory().space(spacenum);
			return true ? space.addrmask() + 1 : space.logaddrmask() + 1;
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
	if (mame_machine_manager::instance()->machine()->system().name != NULL)
		mame_machine_manager::instance()->machine()->immediate_save(filename.c_str());
	else return;
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
