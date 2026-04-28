#include <stdlib.h>
#include <wchar.h>

typedef void* HANDLE;
typedef int BOOL;
typedef unsigned long DWORD;
typedef wchar_t WCHAR;

#define FALSE 0
#define TRUE 1
#define M_SYSERR 0
#define M_ERR 0
#define ERROR_STARTUP_DATA 0

typedef struct {
    WCHAR *directory;
    WCHAR *options;
    WCHAR *std_input;
} STARTUP_DATA;

extern HANDLE exit_event;
extern DWORD PeekNamedPipeAsync(HANDLE pipe, int a, HANDLE* event);
extern DWORD ReadPipeAsync(HANDLE pipe, WCHAR* data, DWORD bytes, int a, HANDLE* event);
extern void MsgToEventLog(int type, const char* msg);
extern void ReturnLastError(HANDLE pipe, const WCHAR* msg);
extern void ReturnError(HANDLE pipe, DWORD error, const WCHAR* msg, int a, HANDLE* event);