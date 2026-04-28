#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

typedef struct MMDB_s {
    char *filename;
    uint64_t file_size;
    uint8_t *file_content;
} MMDB_s;

#define LOCAL static
#define MMDB_SUCCESS 0
#define MMDB_FILE_OPEN_ERROR 1
#define MMDB_IO_ERROR 2

typedef uint32_t DWORD;
typedef void* HANDLE;
typedef wchar_t* LPWSTR;

#define INVALID_HANDLE_VALUE ((HANDLE)(long)-1)
#define INVALID_FILE_SIZE ((DWORD)0xFFFFFFFF)
#define GENERIC_READ 0x80000000
#define FILE_SHARE_READ 0x00000001
#define OPEN_EXISTING 3
#define FILE_ATTRIBUTE_NORMAL 0x00000080
#define PAGE_READONLY 0x02
#define FILE_MAP_READ 0x0004

LPWSTR utf8_to_utf16(const char *utf8);
HANDLE CreateFileW(LPWSTR, DWORD, DWORD, void*, DWORD, DWORD, void*);
DWORD GetFileSize(HANDLE, void*);
HANDLE CreateFileMapping(HANDLE, void*, DWORD, DWORD, DWORD, LPWSTR);
void* MapViewOfFile(HANDLE, DWORD, DWORD, DWORD, size_t);
int CloseHandle(HANDLE);