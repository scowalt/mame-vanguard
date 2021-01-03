
class ManagedWrapper
{
public:
	static unsigned char PEEK(std::string device, long long addr);
	static void POKE(std::string device, long long addr, unsigned char val);
	static long long GetMemorySize(std::string region);
	static int GetByteWidth(std::string region);
	static void ACTIVATELUA();
	static std::string GetDevice(int devnum);
	static std::string GetMemRegion(int regionnum);
	static bool IsBigEndian(std::string region);
	static void SaveSaveState(std::string filename);
	static void LoadSaveState(std::string filename);
	static std::string GetGameName();
};
