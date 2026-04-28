#include <assert.h>
#include <limits.h>
#include <stddef.h>
#include <stdint.h>

typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct wStream wStream;

typedef struct rdpRdg {
    void* tlsOut;
} rdpRdg;

typedef struct {
    uint8_t data[16];
} RdgPacketHeader;

int rdg_read_all(void* tlsOut, uint8_t* buffer, size_t size);
void Stream_Free(wStream* stream, BOOL freeBuffer);
wStream* Stream_New(void* buffer, size_t size);
uint8_t* Stream_Buffer(wStream* stream);
void Stream_Seek(wStream* stream, size_t offset);
void Stream_Read_UINT32(wStream* stream, uint32_t* value);
BOOL Stream_EnsureCapacity(wStream* stream, size_t size);
void Stream_SetLength(wStream* stream, size_t length);