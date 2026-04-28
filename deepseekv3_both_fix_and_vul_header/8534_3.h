#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _rdpSettings {
    int ServerMode;
} rdpSettings;

typedef struct _rdpTransport {
    // transport fields
} rdpTransport;

typedef struct _freerdp {
    // freerdp fields
} freerdp;

typedef struct _SecBuffer {
    unsigned long cbBuffer;
    unsigned long BufferType;
    void* pvBuffer;
} SecBuffer;

typedef struct _SecHandle {
    unsigned long dwLower;
    unsigned long dwUpper;
} SecHandle;

typedef struct _rdpCredssp {
    freerdp* instance;
    rdpSettings* settings;
    int server;
    rdpTransport* transport;
    unsigned int send_seq_num;
    unsigned int recv_seq_num;
    SecBuffer negoToken;
    SecBuffer pubKeyAuth;
    SecBuffer authInfo;
    SecHandle context;
    char* SspiModule;
} rdpCredssp;

#define ZeroMemory(ptr, size) memset(ptr, 0, size)
#define _T(x) x
#define TCHAR char
#define LPTSTR char*
#define BYTE unsigned char
#define HKEY void*
#define LONG int
#define DWORD unsigned int
#define ERROR_SUCCESS 0
#define KEY_READ 0
#define KEY_WOW64_64KEY 0
#define HKEY_LOCAL_MACHINE NULL

static void SecInvalidateHandle(SecHandle* handle) {
    handle->dwLower = 0;
    handle->dwUpper = 0;
}

static LONG RegOpenKeyEx(HKEY hKey, const char* lpSubKey, DWORD ulOptions, DWORD samDesired, HKEY* phkResult) {
    return ERROR_SUCCESS;
}

static LONG RegQueryValueEx(HKEY hKey, const char* lpValueName, DWORD* lpReserved, DWORD* lpType, BYTE* lpData, DWORD* lpcbData) {
    return ERROR_SUCCESS;
}

static LONG RegCloseKey(HKEY hKey) {
    return ERROR_SUCCESS;
}

static int _tprintf(const char* format, ...) {
    return printf(format);
}