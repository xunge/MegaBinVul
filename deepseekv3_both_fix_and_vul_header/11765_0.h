#include <stddef.h>
#include <stdint.h>

typedef int BOOL;
typedef uint8_t BYTE;
typedef uint32_t UINT32;

#define FALSE 0
#define TRUE 1

#define PACKET_COMPRESSED 0x20

typedef struct _ZGFX_CONTEXT {
    BYTE* OutputBuffer;
    size_t OutputCount;
    BYTE* pbInputCurrent;
    BYTE* pbInputEnd;
    int cBitsRemaining;
    int cBitsCurrent;
    UINT32 BitsCurrent;
    BYTE* HistoryBuffer;
    size_t HistoryBufferSize;
    size_t HistoryIndex;
    BYTE bits;
} ZGFX_CONTEXT;

typedef struct _wStream {
    BYTE* buffer;
    size_t pointer;
    size_t length;
} wStream;

typedef struct {
    int prefixLength;
    int prefixCode;
    int tokenType;
    int valueBits;
    int valueBase;
} ZGFX_TOKEN_ENTRY;

extern const ZGFX_TOKEN_ENTRY ZGFX_TOKEN_TABLE[];

void Stream_Read_UINT8(wStream* stream, BYTE* val);
BYTE* Stream_Pointer(wStream* stream);
size_t Stream_GetRemainingLength(wStream* stream);
void Stream_Seek(wStream* stream, size_t offset);
void zgfx_GetBits(ZGFX_CONTEXT* zgfx, int nbits);
void zgfx_history_buffer_ring_write(ZGFX_CONTEXT* zgfx, const BYTE* pSrcData, size_t cbSrcData);
void zgfx_history_buffer_ring_read(ZGFX_CONTEXT* zgfx, UINT32 distance, BYTE* pDstData, size_t cbDstData);
void CopyMemory(void* dest, const void* src, size_t length);