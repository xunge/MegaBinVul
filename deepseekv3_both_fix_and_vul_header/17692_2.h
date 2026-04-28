#include <stdint.h>
#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

typedef unsigned int UINT;
typedef uint32_t UINT32;
typedef uint32_t DWORD;

#define ERROR_INVALID_DATA 13
#define CHANNEL_RC_OK 0
#define STATUS_UNSUCCESSFUL 0xC0000001
#define STATUS_SUCCESS 0x00000000
#define GENERIC_READ 0x80000000
#define GENERIC_WRITE 0x40000000
#define OPEN_EXISTING 3
#define INVALID_HANDLE_VALUE ((void*)-1)
#define WLOG_DEBUG 0
#define WLOG_WARN 1

typedef void* HANDLE;

typedef struct _SERIAL_DEVICE {
    struct {
        char* name;
    } device;
    HANDLE hComm;
    void* log;
    uint32_t ServerSerialDriverId;
    int permissive;
} SERIAL_DEVICE;

typedef struct _IRP {
    void* input;
    void* output;
    uint32_t FileId;
    struct {
        uint32_t id;
    }* device;
    struct {
        uint32_t id_sequence;
    }* devman;
    uint32_t IoStatus;
} IRP;

void* CreateFile(const char*, DWORD, DWORD, void*, DWORD, DWORD, void*);
DWORD GetLastError(void);
void _comm_setServerSerialDriver(HANDLE, uint32_t);
void _comm_set_permissive(HANDLE, int);
void WLog_Print(void*, int, const char*, ...);
size_t Stream_GetRemainingLength(void*);
void Stream_Read_UINT32(void*, uint32_t*);
void Stream_Seek_UINT64(void*);
void Stream_Seek_UINT32(void*);
void Stream_Seek(void*, size_t);
void Stream_Write_UINT32(void*, uint32_t);
void Stream_Write_UINT8(void*, uint8_t);