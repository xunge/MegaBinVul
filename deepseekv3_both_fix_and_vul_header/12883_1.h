#include <stdint.h>
#include <wchar.h>

typedef unsigned int UINT;
typedef uint8_t BYTE;
typedef uint32_t UINT32;
typedef wchar_t WCHAR;

#define ERROR_INVALID_PARAMETER 87
#define ERROR_INVALID_DATA 13
#define STATUS_UNSUCCESSFUL 0xC0000001
#define TAG 0

typedef struct _DRIVE_DEVICE DRIVE_DEVICE;
typedef struct _DRIVE_FILE DRIVE_FILE;
typedef struct _IRP IRP;
typedef struct _STREAM STREAM;

struct _IRP {
    STREAM* input;
    STREAM* output;
    UINT32 FileId;
    UINT (*Complete)(IRP* irp);
    UINT IoStatus;
};

UINT drive_map_windows_err(int err);