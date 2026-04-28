#include <stdint.h>

typedef unsigned int UINT;
typedef uint32_t UINT32;
typedef uint64_t UINT64;

typedef struct _DRIVE_DEVICE DRIVE_DEVICE;
typedef struct _DRIVE_FILE DRIVE_FILE;
typedef struct _IRP IRP;

#define ERROR_INVALID_PARAMETER 1
#define ERROR_INVALID_DATA 2

#define STATUS_UNSUCCESSFUL 3

struct _IRP {
    void* input;
    void* output;
    int (*Complete)(IRP*);
    unsigned int FileId;
    int IoStatus;
};

UINT32 Stream_GetRemainingLength(void* stream);
void Stream_Read_UINT32(void* stream, UINT32 value);
void Stream_Read_UINT64(void* stream, UINT64 value);
void Stream_Seek(void* stream, int offset);
void* Stream_Pointer(void* stream);
void Stream_Write_UINT32(void* stream, UINT32 value);
void Stream_Write_UINT8(void* stream, unsigned char value);

DRIVE_FILE* drive_get_file_by_id(DRIVE_DEVICE* drive, unsigned int fileId);
int drive_file_seek(DRIVE_FILE* file, UINT64 offset);
int drive_file_write(DRIVE_FILE* file, void* buffer, UINT32 length);
int drive_map_windows_err(int error);
int GetLastError(void);