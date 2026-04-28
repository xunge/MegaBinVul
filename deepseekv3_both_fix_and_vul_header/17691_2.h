#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>

typedef uint32_t UINT32;
typedef uint64_t UINT64;
typedef uint8_t UINT8;
typedef unsigned int UINT;
typedef uint32_t DWORD;
typedef void* HANDLE;

#define ERROR_INVALID_DATA 13
#define CHANNEL_RC_OK 0
#define STATUS_SUCCESS 0
#define WLOG_DEBUG 0

typedef struct {
    void* input;
    void* output;
    UINT32 IoStatus;
} IRP;

typedef struct {
    char* name;
} DEVICE;

typedef struct {
    HANDLE hComm;
    DEVICE device;
    void* log;
} SERIAL_DEVICE;

void WLog_Print(void* log, int level, const char* fmt, ...);
UINT32 Stream_GetRemainingLength(void* stream);
void Stream_Read_UINT32(void* stream, UINT32 val);
void Stream_Read_UINT64(void* stream, UINT64 val);
void Stream_Seek(void* stream, UINT32 offset);
void* Stream_Pointer(void* stream);
void Stream_Write_UINT32(void* stream, UINT32 val);
void Stream_Write_UINT8(void* stream, UINT8 val);
int CommWriteFile(HANDLE hFile, void* lpBuffer, DWORD nNumberOfBytesToWrite, DWORD* lpNumberOfBytesWritten, void* lpOverlapped);
DWORD GetLastError();
UINT32 _GetLastErrorToIoStatus(SERIAL_DEVICE* serial);