
class ManagedWrapper
{
public:
	static unsigned char PEEK(std::string memclass, std::string device, long long addr, int indexnum);
	static void POKE(std::string memclass, std::string device, long long addr, unsigned char val, int indexnum);
	static long long GetMemorySize(std::string memclass, std::string region, int indexnum);
	static int GetByteWidth(std::string memclass, std::string region, int indexnum);
	static void ACTIVATELUA();
	static std::string GetMemoryDomain(int indexnum);
	static std::string GetDomainClass(int indexnum);
	static bool IsBigEndian(std::string memclass, std::string region, int indexnum);
	static int GetCPUSpaceNumber(int indexnum);
	static void SaveSaveState(std::string filename);
	static void LoadSaveState(std::string filename);
	static int GetTotalNumOfRegionsAndShares();
	static int GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces();
	static std::string GetGameName();
	static void Resume(bool threadon);
};
