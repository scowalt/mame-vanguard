
class ManagedWrapper
{
public:
	static unsigned char PEEK(std::string memclass, std::string device, long long addr, int indexnum, std::string devicename);
	static void POKE(std::string memclass, std::string device, long long addr, unsigned char val, int indexnum, std::string devicename);
	static long long GetMemorySize(std::string memclass, std::string region, int indexnum, std::string devicename);
	static int GetByteWidth(std::string memclass, std::string region, int indexnum, std::string devicename);
	static void ACTIVATELUA();
	static std::string GetMemoryDomain(int indexnum);
	static std::string GetDomainClass(int indexnum);
	static bool IsBigEndian(std::string memclass, std::string region, int indexnum, std::string devicename);
	static int GetCPUSpaceNumber(int indexnum);
	static std::string GetDeviceName(int indexnum);
	static void SaveSaveState(std::string filename);
	static void LoadSaveState(std::string filename);
	static int GetTotalNumOfRegionsAndShares();
	static int GetTotalNumOfRegionsAndSharesMinusMainCPUSpaces();
	static std::string GetGameName();
	static void Resume(bool threadon);
	static void RenderStartAVI(std::string filename);
	static void RenderStopAVI();
	static void RenderStartMNG(std::string filename);
	static void RenderStopMNG();
	static void RenderIMAGE(std::string filename);
	static void RenderStartWAV(std::string filename);
	static void RenderStopWAV();
	static void LOADGAME(std::string filename, std::string gamename);
	static void CATCHGAME(std::string rom);
	static bool IsZipARom(std::string filename);
	static std::string GETROMFILENAME(int indexnum);
	static void SETROMFILENAME(std::string stringtoset);
	static void LOADROM(std::string rompath, std::string shortgamename);
	static void SAVEROM(std::string rompath);
	static int COLLECTTOTALROMS();
	static std::string GetShortGameName();
};
