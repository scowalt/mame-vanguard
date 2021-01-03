
#include <string>
#include <mutex>
#include <emu.h>
#include "ManagedWrapper.h"
#include "../src/frontend/mame/mame.h"
#include "UnmanagedWrapper.h"
unsigned char ManagedWrapper::PEEK(std::string domain, long long addr)
{
	if(mame_machine_manager::instance()->machine()->system().name != NULL)
		return mame_machine_manager::instance()->machine()->device(domain.c_str())->memory().space().read_byte(addr);
	else return NULL;
	
}

void ManagedWrapper::POKE(std::string domain, long long addr, unsigned char val)
{
	if (mame_machine_manager::instance()->machine()->system().name != NULL)
		mame_machine_manager::instance()->machine()->device(domain.c_str())->memory().space().write_byte(addr, val);
	else return;
}

long long ManagedWrapper::GetMemorySize(std::string domain)
{
	if (mame_machine_manager::instance()->machine()->system().name != NULL)
		return (long long)mame_machine_manager::instance()->machine()->root_device().memregion(domain.c_str())->bytes();
	else return NULL;
}

int ManagedWrapper::GetByteWidth(std::string domain)
{
	if (mame_machine_manager::instance()->machine()->system().name != NULL)
		return (int)mame_machine_manager::instance()->machine()->root_device().memregion(domain.c_str())->bytewidth();
	else return NULL;
}

void ManagedWrapper::ACTIVATELUA()
{
	mame_machine_manager::instance()->start_luaengine();
}

std::string ManagedWrapper::GetDevice(int devnum)
{
	return std::string();
}

std::string ManagedWrapper::GetMemRegion(int regionnum)
{
	return std::string();
}

bool ManagedWrapper::IsBigEndian(std::string domain)
{
	if (mame_machine_manager::instance()->machine()->system().name != NULL)
		if (mame_machine_manager::instance()->machine()->root_device().memregion(domain.c_str())->endianness() == ENDIANNESS_BIG)
			return true;
		else return false;
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
	if (mame_machine_manager::instance()->machine()->system().name != NULL)
	{
		mame_machine_manager::instance()->machine()->immediate_load(filename.c_str());
		UnmanagedWrapper::VANGUARD_LOADSTATE_DONE();
	}
	else return;
}

std::string ManagedWrapper::GetGameName()
{
	if (mame_machine_manager::instance()->machine()->system().name != NULL)
		return mame_machine_manager::instance()->machine()->system().name;
	else return "";
}
