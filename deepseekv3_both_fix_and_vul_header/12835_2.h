#include <locale.h>
#include <new>
#include <cwchar>

#define _UNIX
#define SFX_MODULE
#define _WIN_ALL
#define NM 260
#define RARX_SUCCESS 0
#define RARX_MEMORY 1
#define RARX_FATAL 2
#define MSG_NULL 0
#define ASIZE(x) (sizeof(x)/sizeof(x[0]))
#define SEM_NOALIGNMENTFAULTEXCEPT 0
#define SEM_FAILCRITICALERRORS 0
#define SEM_NOOPENFILEERRORBOX 0

enum POWER_MODE {
    POWERMODE_KEEP
};

typedef wchar_t wchar;

class CommandData {
public:
    wchar_t Command[2];
    bool ConfigDisabled;
    bool AllYes;
    int MsgStream;
    POWER_MODE Shutdown;
    bool AbsoluteLinks;
    const char* LogName;
    const char* ErrlogCharset;
    bool Sound;

    void ParseCommandLine(bool, int, char**);
    void ReadConfig();
    void ParseEnvVar();
    void ParseDone();
    void AddArcName(wchar_t*);
    bool IsSwitch(char);
    void OutHelp(int);
    void OutTitle();
    void ProcessCommand();
};

class ErrHandler {
public:
    static bool MainExit;
    static bool IsShutdownEnabled();
    static void SetSignalHandlers(bool);
    static void SetSilent(bool);
    static void SetErrorCode(int);
    static int GetErrorCode();
    static void MemoryErrorMsg();
} ErrHandler;

void InitConsole();
void InitLogOptions(const char*, const char*);
void uiInit(bool);
void Shutdown(POWER_MODE);
void CharToWide(const char*, wchar_t*, size_t);
void SetErrorMode(unsigned int);
void GetModuleFileName(void*, wchar_t*, size_t);

typedef int RAR_EXIT;

int etoupper(int c);