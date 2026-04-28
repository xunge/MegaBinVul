#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef unsigned char BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef int BOOL;

#define ZGFX_SEGMENTED_SINGLE 0x3B
#define ZGFX_SEGMENTED_MULTIPART 0x3C
#define FALSE 0

struct _wStream {
    BYTE* buffer;
    size_t position;
    size_t length;
};

typedef struct _wStream wStream;

typedef struct _ZGFX_CONTEXT {
    BYTE* OutputBuffer;
    UINT32 OutputCount;
} ZGFX_CONTEXT;

wStream* Stream_New(BYTE* data, size_t size);
size_t Stream_GetRemainingLength(wStream* stream);
void Stream_Read_UINT8(wStream* stream, BYTE* value);
void Stream_Read_UINT16(wStream* stream, UINT16* value);
void Stream_Read_UINT32(wStream* stream, UINT32* value);
void Stream_Free(wStream* stream, BOOL bFreeBuffer);
void CopyMemory(void* dest, const void* src, size_t length);

int zgfx_decompress_segment(ZGFX_CONTEXT* zgfx, wStream* stream, UINT32 segmentSize);