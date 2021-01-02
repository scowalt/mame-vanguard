
class ManagedWrapper
{
public:
	static unsigned char PEEK(std::string domain, long long addr);
	static void POKE(std::string domain, long long addr, unsigned char val);
	static long long GetMemorySize(std::string domain);
	static int GetByteWidth(std::string domain);
	static void ACTIVATELUA();
	static std::string GetDevice(int devnum);
	static std::string GetMemRegion(int regionnum);
	static bool IsBigEndian(std::string domain);
};
