#include <stdint.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <wchar.h>

typedef unsigned int UINT;
typedef uint32_t UINT32;
typedef wchar_t WCHAR;

typedef struct _STREAM STREAM;
typedef struct _IRP IRP;
typedef struct _PARALLEL_DEVICE PARALLEL_DEVICE;

struct _IRP {
    STREAM* input;
    STREAM* output;
    int IoStatus;
    int (*Complete)(IRP* irp);
    struct {
        unsigned int id_sequence;
    } *devman;
};

struct _PARALLEL_DEVICE {
    int id;
    int file;
    char* path;
};

#define ERROR_INVALID_DATA 1
#define CHANNEL_RC_NO_MEMORY 2
#define STATUS_ACCESS_DENIED 3
#define CP_UTF8 4
#define TAG "parallel"

int Stream_SafeSeek(STREAM* stream, int offset);
size_t Stream_GetRemainingLength(STREAM* stream);
void Stream_Read_UINT32(STREAM* stream, UINT32 value);
void* Stream_Pointer(STREAM* stream);
void Stream_Write_UINT32(STREAM* stream, UINT32 value);
void Stream_Write_UINT8(STREAM* stream, uint8_t value);
int ConvertFromUnicode(int codePage, int flags, WCHAR* src, int srcSize, char** dst, int dstSize, void* null1, void* null2);
void WLog_ERR(const char* tag, const char* message);