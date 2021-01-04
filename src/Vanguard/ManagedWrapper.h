
class ManagedWrapper
{
public:
	static unsigned char PEEK(std::string memclass, std::string device, long long addr);
	static void POKE(std::string memclass, std::string device, long long addr, unsigned char val);
	static long long GetMemorySize(std::string memclass, std::string region);
	static int GetByteWidth(std::string memclass, std::string region);
	static void ACTIVATELUA();
	static std::string GetMemoryDomain(int indexnum);
	static std::string GetDomainClass(int indexnum);
	static bool IsBigEndian(std::string memclass, std::string region);
	static void SaveSaveState(std::string filename);
	static void LoadSaveState(std::string filename);
	static int GetTotalNumOfRegionsAndShares();
	static std::string GetGameName();
};
