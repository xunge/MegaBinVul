#include <cstddef>
#include <cstdint>
#include <cwchar>

typedef void* HANDLE;
typedef void* HMODULE;
typedef unsigned long DWORD;
typedef const wchar_t* LPCTSTR;
typedef wchar_t TCHAR;
typedef void (*FARPROC)();

struct _MINIDUMP_EXCEPTION_INFORMATION {
    DWORD ThreadId;
    void* ExceptionPointers;
    int ClientPointers;
};

typedef int BOOL;
typedef unsigned int UINT;
typedef void* EXCEPTION_POINTERS;

#define MAX_PATH 260
#define MB_OK 0
#define MB_YESNO 4
#define IDYES 6
#define GENERIC_WRITE 0x40000000
#define FILE_SHARE_WRITE 0x00000002
#define CREATE_ALWAYS 2
#define FILE_ATTRIBUTE_NORMAL 0x00000080
#define INVALID_HANDLE_VALUE ((HANDLE)(-1))
#define LOAD_LIBRARY_SEARCH_SYSTEM32 0x00000800
#define MiniDumpNormal 0
#define TEXT(x) L##x

class MiniDumper {
public:
    bool writeDump(EXCEPTION_POINTERS* pExceptionInfo);
};

typedef BOOL (*MINIDUMPWRITEDUMP)(
    HANDLE hProcess,
    DWORD ProcessId,
    HANDLE hFile,
    int DumpType,
    const _MINIDUMP_EXCEPTION_INFORMATION* ExceptionParam,
    const void* UserStreamParam,
    const void* CallbackParam
);

extern LPCTSTR msgTitle;

extern "C" {
    HMODULE LoadLibraryEx(const wchar_t*, void*, unsigned long);
    HMODULE LoadLibrary(const wchar_t*);
    FARPROC GetProcAddress(HMODULE, const char*);
    DWORD GetModuleFileName(HMODULE, wchar_t*, DWORD);
    void PathRemoveFileSpec(wchar_t*);
    int wcscat_s(wchar_t*, const wchar_t*);
    int MessageBox(void*, const wchar_t*, const wchar_t*, UINT);
    HANDLE CreateFile(const wchar_t*, DWORD, DWORD, void*, DWORD, DWORD, void*);
    DWORD GetCurrentThreadId();
    HANDLE GetCurrentProcess();
    DWORD GetCurrentProcessId();
    DWORD GetLastError();
    BOOL CloseHandle(HANDLE);
    void FreeLibrary(HMODULE);
    int wsprintf(wchar_t*, const wchar_t*, ...);
}