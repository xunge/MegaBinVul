#include <wchar.h>
#include <stdlib.h>
#include <limits>
#include <stdint.h>

typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef int BOOL;
#define FALSE 0
#define TRUE 1

typedef void* HANDLE;
#define STD_INPUT_HANDLE ((DWORD)-10)

typedef wchar_t WCHAR;
typedef char CHAR;

typedef struct _KEY_EVENT_RECORD {
    BOOL bKeyDown;
    WORD wRepeatCount;
    WORD wVirtualKeyCode;
    WORD wVirtualScanCode;
    union {
        WCHAR UnicodeChar;
        CHAR AsciiChar;
    } uChar;
    DWORD dwControlKeyState;
} KEY_EVENT_RECORD;

typedef struct _INPUT_RECORD {
    WORD EventType;
    union {
        KEY_EVENT_RECORD KeyEvent;
    } Event;
} INPUT_RECORD;

#define KEY_EVENT 0x0001

#define countof(array) (sizeof(array)/sizeof(array[0]))

enum DumpEvent { de_Report };

class CEAnsi {
public:
    BOOL ReportString(const wchar_t* asRet);
    void DumpKnownEscape(const wchar_t* asRet, size_t nLen, DumpEvent de);
};

typedef const wchar_t* LPCWSTR;

HANDLE GetStdHandle(DWORD nStdHandle);
BOOL WriteConsoleInput(HANDLE hConsoleInput, const INPUT_RECORD* lpBuffer, DWORD nLength, DWORD* lpNumberOfEventsWritten);