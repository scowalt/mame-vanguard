
#include <string>
#include <mutex>
#include <emu.h>
#include "ManagedWrapper.h"
#include "../src/frontend/mame/mame.h"
unsigned char ManagedWrapper::PEEK(std::string domain, long long addr)
{
	return mame_machine_manager::instance()->machine()->device(domain.c_str())->memory().space().read_byte(addr);
	
}

void ManagedWrapper::POKE(std::string domain, long long addr, unsigned char val)
{
	mame_machine_manager::instance()->machine()->device(domain.c_str())->memory().space().write_byte(addr, val);
}

long long ManagedWrapper::GetMemorySize(std::string domain)
{
	return (long long)mame_machine_manager::instance()->machine()->root_device().memregion(domain.c_str())->bytes();
}

int ManagedWrapper::GetByteWidth(std::string domain)
{
	return (int)mame_machine_manager::instance()->machine()->root_device().memregion(domain.c_str())->bytewidth();
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
	if (mame_machine_manager::instance()->machine()->root_device().memregion(domain.c_str())->endianness() == ENDIANNESS_BIG)
		return true;
	else return false;
}
