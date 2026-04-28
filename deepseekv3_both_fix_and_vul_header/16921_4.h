#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

typedef int32_t DWORD;
typedef uint16_t WORD;
typedef void* HANDLE;
typedef void* HDC;
typedef void* HENHMETAFILE;
typedef void* HMETAFILE;
typedef unsigned char* LPBYTE;
typedef unsigned char BYTE;

typedef struct {
    int32_t left;
    int32_t top;
    int32_t right;
    int32_t bottom;
} RECTL;

typedef struct {
    DWORD iType;
    DWORD nSize;
    RECTL rclBounds;
    RECTL rclFrame;
    DWORD dSignature;
    DWORD nVersion;
    DWORD nBytes;
    DWORD nRecords;
    WORD nHandles;
    WORD sReserved;
    DWORD nDescription;
    DWORD offDescription;
    DWORD nPalEntries;
    int32_t szlDevice;
    int32_t szlMillimeters;
} ENHMETAHEADER;

typedef struct {
    int mm;
    int xExt;
    int yExt;
    HMETAFILE hMF;
} METAFILEPICT;

typedef struct _SMALL_RECT {
    int16_t Left;
    int16_t Top;
    int16_t Right;
    int16_t Bottom;
} SMALL_RECT;

typedef long ssize_t;

#define MM_ANISOTROPIC 8
#define INVALID_HANDLE_VALUE ((HANDLE)(intptr_t)-1)
#define GENERIC_READ 0x80000000
#define OPEN_EXISTING 3
#define FILE_ATTRIBUTE_NORMAL 0x80

static void* GetEnhMetaFile(const char* path) { return NULL; }
static void GetEnhMetaFileHeader(HENHMETAFILE h, DWORD size, ENHMETAHEADER* emfh) {}
static HMETAFILE GetMetaFile(const char* path) { return NULL; }
static DWORD GetMetaFileBitsEx(HMETAFILE h, DWORD size, void* bits) { return 0; }
static void DeleteMetaFile(HMETAFILE h) {}
static void* AcquireQuantumMemory(size_t size, size_t elem) { return malloc(size * elem); }
static char* DestroyString(char* str) { free(str); return NULL; }
static HDC GetDC(void* hwnd) { return NULL; }
static HENHMETAFILE SetWinMetaFileBits(DWORD size, void* bits, HDC hdc, METAFILEPICT* mp) { return NULL; }
static void ReleaseDC(void* hwnd, HDC hdc) {}
static HANDLE CreateFile(const char* path, DWORD access, DWORD share, void* sec, DWORD disp, DWORD flags, HANDLE temp) { return INVALID_HANDLE_VALUE; }
static DWORD GetFileSize(HANDLE h, DWORD* high) { return 0; }
static void CloseHandle(HANDLE h) {}
static void ReadFile(HANDLE h, void* buf, DWORD size, DWORD* read, void* overlapped) {}