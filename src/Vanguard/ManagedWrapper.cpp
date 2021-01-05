
#include <string>
#include <mutex>
#include <emu.h>
#include "ManagedWrapper.h"
#include "../src/frontend/mame/mame.h"
#include "UnmanagedWrapper.h"
unsigned char ManagedWrapper::PEEK(std::string memclass, std::string region, long long addr, int indexnum)
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
	else if (memclass == "addrmap")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(spacenum))
			return mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(spacenum).read_byte(addr);
		else return NULL;
	}
	else return NULL;
}

void ManagedWrapper::POKE(std::string memclass, std::string region, long long addr, unsigned char val, int indexnum)
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
	else if (memclass == "addrmap")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(spacenum))
			mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(spacenum).write_byte(addr, val);
	}
	else return;
}

long long ManagedWrapper::GetMemorySize(std::string memclass, std::string region, int indexnum)
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
	if (memclass == "addrmap")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(spacenum))
			return (long long)((((mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(spacenum).data_width() / 8) * (mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(spacenum).addr_width())))*1024*1024)/3; //Can't get the device memory map's actual size afaik so I'll just pretend its size is a third of its bytewidth times its address width
		else return 0;
	}
	else return 0;
}

int ManagedWrapper::GetByteWidth(std::string memclass, std::string region, int indexnum)
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
	if (memclass == "addrmap")
	{
		int spacenum = indexnum;
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(spacenum))
			return (int)mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(spacenum).data_width() / 8;
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
	int devicecounter = 0; //I put "devicecounter" but by device I actually mean address space of the maincpu device
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
	for (int i = 0; i < mame_machine_manager::instance()->machine()->device("maincpu")->memory().max_space_count(); i++)
	{
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(i))
		{
			devicecounter += 1;
			deviceArray[devicecounter] = std::string(mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(i).name());
			//printf("Current detected address space of maincpu is #%i: %s.\n", i, deviceArray[devicecounter].c_str());
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
	for (int i = 0; i < mame_machine_manager::instance()->machine()->device("maincpu")->memory().max_space_count(); ++i)
	{

		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(i))
		{
			devicecounter += 1;
			deviceArray[devicecounter] = mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(i).name();
		}
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

bool ManagedWrapper::IsBigEndian(std::string memclass, std::string region, int indexnum)
{
	if (memclass == "region")
	{
		if (mame_machine_manager::instance()->machine()->system().name != NULL)
			if (mame_machine_manager::instance()->machine()->root_device().memregion(region.c_str())->endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}
	else if (memclass == "share")
	{
		if (mame_machine_manager::instance()->machine()->system().name != NULL)
			if (mame_machine_manager::instance()->machine()->root_device().memshare(region.c_str())->endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}
	else if (memclass == "addrmap")
	{
		int spacenum = indexnum;

		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(spacenum))
			if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().space(spacenum).endianness() == ENDIANNESS_BIG)
				return true;
			else return false;
		else return false;
	}

	else return false;
}

int ManagedWrapper::GetCPUSpaceNumber(int indexnum)
{
	std::string regionArray[500];
	std::string shareArray[500];
	int deviceArray[500];
	int regioncounter = 0;
	int sharecounter = 0;
	int devicecounter = 0; //I put "devicecounter" but by device I actually mean address space of the maincpu device
	for (int i = 0; i < mame_machine_manager::instance()->machine()->device("maincpu")->memory().max_space_count(); i++)
	{
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(i))
		{
			devicecounter += 1;
			deviceArray[devicecounter] = i;
		}
	}
	if (deviceArray[indexnum - (regioncounter + sharecounter)] != NULL)
	{
		return deviceArray[indexnum - (regioncounter + sharecounter)];
	}
	else return 0;
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
	for (int i = 0; i < mame_machine_manager::instance()->machine()->device("maincpu")->memory().max_space_count(); ++i)
	{
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(i))
		{
			devicecounter += 1;
		}
	}
	return regioncounter + sharecounter + devicecounter; //
}

int ManagedWrapper::GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces()
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
	for (int i = 0; i < mame_machine_manager::instance()->machine()->device("maincpu")->memory().max_space_count(); ++i)
	{
		if (mame_machine_manager::instance()->machine()->device("maincpu")->memory().has_space(i))
		{
			devicecounter += 1;
		}
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
