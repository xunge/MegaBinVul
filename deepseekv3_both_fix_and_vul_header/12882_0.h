#include <stddef.h>
#include <stdint.h>

typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned int UINT32;

typedef struct _ZGFX_CONTEXT ZGFX_CONTEXT;
typedef struct _wStream wStream;

#define FALSE 0
#define TRUE 1
#define PACKET_COMPRESSED 0x01
#define UINT32_MAX (0xFFFFFFFFU)

struct _ZGFX_CONTEXT {
    BYTE* pbInputCurrent;
    BYTE* pbInputEnd;
    UINT32 cBitsRemaining;
    UINT32 cBitsCurrent;
    UINT32 BitsCurrent;
    UINT32 bits;
    BYTE HistoryBuffer[4096];
    UINT32 HistoryIndex;
    UINT32 HistoryBufferSize;
    BYTE OutputBuffer[65536];
    UINT32 OutputCount;
};

struct _wStream {
    BYTE* buffer;
    size_t pointer;
    size_t length;
};

typedef struct {
    UINT32 prefixCode;
    UINT32 prefixLength;
    UINT32 valueBase;
    UINT32 valueBits;
    UINT32 tokenType;
} ZGFX_TOKEN_ENTRY;

extern const ZGFX_TOKEN_ENTRY ZGFX_TOKEN_TABLE[];

void Stream_Read_UINT8(wStream* stream, BYTE* val);
BYTE* Stream_Pointer(wStream* stream);
void Stream_Seek(wStream* stream, size_t offset);
size_t Stream_GetRemainingLength(wStream* stream);
void zgfx_GetBits(ZGFX_CONTEXT* zgfx, UINT32 nbits);
void zgfx_history_buffer_ring_write(ZGFX_CONTEXT* zgfx, const BYTE* p, UINT32 count);
void zgfx_history_buffer_ring_read(ZGFX_CONTEXT* zgfx, UINT32 distance, BYTE* p, UINT32 count);
void CopyMemory(void* dest, const void* src, size_t length);