#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

#define GENERIC_READ 0x80000000
#define OPEN_EXISTING 3
#define FILE_ATTRIBUTE_NORMAL 0x80
#define INVALID_HANDLE_VALUE ((void*)-1)
#define MM_ANISOTROPIC 8
#define NULL ((void*)0)

typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef void* HANDLE;
typedef void* HDC;
typedef void* HENHMETAFILE;
typedef void* HMETAFILE;
typedef unsigned char BYTE;
typedef BYTE* LPBYTE;

typedef struct {
    int32_t mm;
    int32_t xExt;
    int32_t yExt;
    HMETAFILE hMF;
} METAFILEPICT;

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

typedef struct _SMALL_RECT {
    int16_t Left;
    int16_t Top;
    int16_t Right;
    int16_t Bottom;
} SMALL_RECT;