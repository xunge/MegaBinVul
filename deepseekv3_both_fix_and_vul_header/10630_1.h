#include <string>
#include <stdexcept>

typedef struct _GUID {
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
} UUID;

typedef unsigned char* RPC_WSTR;
typedef unsigned long RPC_STATUS;

#define MAX_PATH 260
#define ERROR_ALREADY_EXISTS 183

class Win32Exception : public std::runtime_error {
public:
    Win32Exception(const char* msg) : std::runtime_error(msg) {}
};

std::wstring GetUniqueTempDirectoryPrefix();
unsigned long GetLastError();
int CreateDirectory(const wchar_t*, void*);
unsigned long GetTempPath(unsigned long, wchar_t*);
RPC_STATUS UuidCreate(UUID*);
RPC_STATUS UuidToString(const UUID*, RPC_WSTR*);
RPC_STATUS RpcStringFree(RPC_WSTR*);