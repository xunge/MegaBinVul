#include <stddef.h>

typedef void* HMODULE;
typedef const char* LPCTSTR;
typedef void* PVOID;
typedef unsigned long ULONG;
typedef int BOOLEAN;
typedef int BOOL;

#define TEXT(x) x
#define LOAD_LIBRARY_SEARCH_SYSTEM32 0x00000800
#define TRUE 1

typedef BOOLEAN (*RTLGENRANDOM_FUNC)(PVOID, ULONG);

extern HMODULE LoadLibraryEx(LPCTSTR, int, unsigned int);
extern void* GetProcAddress(HMODULE, const char*);
extern BOOL FreeLibrary(HMODULE);
extern HMODULE LoadLibrary(LPCTSTR);