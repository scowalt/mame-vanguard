
#include <string>
#include <mutex>
#include <emu.h>
#include "ManagedWrapper.h"
#include "../src/frontend/mame/mame.h"
#include "UnmanagedWrapper.h"
unsigned char ManagedWrapper::PEEK(std::string memclass, std::string region, long long addr)
{
	if (memclass == "region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		unsigned char mem_content = 0;
		mem_content |= mregion.as_u8((BYTE8_XOR_LE(addr)) | (addr));

		return mem_content;

	}
	else if (memclass == "share")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		unsigned char mem_content = 0;
		u8* ptr = (u8*)mshare.ptr();
		mem_content |= ptr[((BYTE8_XOR_LE(addr)) | (addr))];

		return mem_content;
	}
	else if (memclass == "addrmap" && region != "screen")
	{
		return mame_machine_manager::instance()->machine()->device(region.c_str())->memory().space().read_byte(addr);
	}
	else return NULL;
}

void ManagedWrapper::POKE(std::string memclass, std::string region, long long addr, unsigned char val)
{
	if (memclass == "region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		mregion.base()[(BYTE8_XOR_LE(addr)) | (addr)] = val & 0xff;
	}
	else if (memclass == "share")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		u8* ptr = (u8*)mshare.ptr();
		ptr[(BYTE8_XOR_LE(addr)) | (addr)] = val & 0xff;
	}
	else if (memclass == "addrmap" && region != "screen")
	{
		mame_machine_manager::instance()->machine()->device(region.c_str())->memory().space().write_byte(addr, val);
	}
	else return;
}

long long ManagedWrapper::GetMemorySize(std::string memclass, std::string region)
{
	if (memclass == "region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		return mregion.bytes();
	}
	if (memclass == "share")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		return mshare.bytes();
	}
	if (memclass == "addrmap" && region != "screen")
	{

		return (long long)mame_machine_manager::instance()->machine()->root_device().memregion(region.c_str())->bytes(); //No way to get a device memory map's size afaik so I'll just fetch a memregion named after it
	}
	else return 0;
}

int ManagedWrapper::GetByteWidth(std::string memclass, std::string region)
{
	if (memclass == "region")
	{
		memory_region& mregion = *mame_machine_manager::instance()->machine()->root_device().memregion(region);
		return mregion.bytewidth();
	}
	if (memclass == "share")
	{
		memory_share& mshare = *mame_machine_manager::instance()->machine()->root_device().memshare(region);
		return mshare.bytewidth();
	}
	if (memclass == "addrmap" && region != "screen")
	{
		return (int)mame_machine_manager::instance()->machine()->root_device().memregion(region.c_str())->bytewidth();//No way to get a device memory map's byte width afaik so I'll just fetch a memregion named after it
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
	for (int i = 0; i < mame_machine_manager::instance()->machine()->root_device().subdevices().count(); ++i)
	{
		devicecounter += 1;
		deviceArray[devicecounter] = mame_machine_manager::instance()->machine()->root_device().subdevices().at(i);
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
		return deviceArray[indexnum - (regioncounter+sharecounter)].erase(0, 1);
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
	for (int i = 0; i < mame_machine_manager::instance()->machine()->root_device().subdevices().count(); ++i)
	{
		devicecounter += 1;
		deviceArray[devicecounter] = mame_machine_manager::instance()->machine()->root_device().subdevices().at(i);
	}

	if (regionArray[indexnum] != "")
	{
		return "region";
	}
	else if (shareArray[indexnum - regioncounter] != "")
	{
		return "share";
	}
	else if (deviceArray[indexnum - (regioncounter+sharecounter)] != "")
	{
		return "addrmap";
	}
	else return "";
}

bool ManagedWrapper::IsBigEndian(std::string memclass, std::string region)
{
	if (memclass == "region")
	{
		if (mame_machine_manager::instance()->machine()->system().name != NULL)
			if (mame_machine_manager::instance()->machine()->root_device().memregion(region.c_str())->endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}
	if (memclass == "share")
	{
		if (mame_machine_manager::instance()->machine()->system().name != NULL)
			if (mame_machine_manager::instance()->machine()->root_device().memshare(region.c_str())->endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}
	if (memclass == "addrmap" && region != "screen")
	{
		return false; //little endian for now
	}

	else return false;
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
	{
		*/mame_machine_manager::instance()->machine()->immediate_load(filename.c_str());
		UnmanagedWrapper::VANGUARD_LOADSTATE_DONE();
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
	for (int i = 0; i < mame_machine_manager::instance()->machine()->root_device().subdevices().count(); ++i)
	{
		devicecounter += 1;
	}
	return regioncounter + sharecounter; //expose no device address maps for now since the getbyte function causes issues with neogeo games
}

std::string ManagedWrapper::GetGameName()
{
	return mame_machine_manager::instance()->machine()->system().name;
}
