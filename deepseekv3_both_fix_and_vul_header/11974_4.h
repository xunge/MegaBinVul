#include <stdlib.h>
#include <wchar.h>
#include <stdbool.h>

#define countof(array) (sizeof(array)/sizeof(array[0]))
#define FALSE false
#define TRUE true
#define KEY_EVENT 1
#define STD_INPUT_HANDLE -10

typedef unsigned long DWORD;
typedef const wchar_t* LPCWSTR;
typedef void* HANDLE;

struct KEY_EVENT_RECORD {
    bool bKeyDown;
    unsigned short wRepeatCount;
    struct {
        wchar_t UnicodeChar;
    } uChar;
};

struct INPUT_RECORD {
    unsigned short EventType;
    struct {
        struct KEY_EVENT_RECORD KeyEvent;
    } Event;
};

enum SrvAnsi_DumpEscMode { de_Report };

class SrvAnsi {
public:
    enum DumpEscMode { de_Report };
};

class SrvAnsiImpl {
public:
    static bool ReportString(LPCWSTR asRet);
    static void DumpKnownEscape(LPCWSTR asRet, int nLen, SrvAnsi::DumpEscMode mode);
};

size_t lstrlen(LPCWSTR str);
HANDLE GetStdHandle(int nStdHandle);
bool WriteConsoleInput(HANDLE hIn, INPUT_RECORD* pir, int nLen, DWORD* nWritten);