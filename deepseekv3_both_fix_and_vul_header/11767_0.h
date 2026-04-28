#include <stdint.h>
#include <stddef.h>

#define BOOL int
#define TRUE 1
#define FALSE 0
#define BYTE uint8_t
#define UINT32 uint32_t

#define PACKET_COMPRESSED 0x20

typedef struct _ZGFX_CONTEXT ZGFX_CONTEXT;
typedef struct _wStream wStream;

struct _ZGFX_CONTEXT {
    BYTE* OutputBuffer;
    UINT32 OutputCount;
    BYTE* pbInputCurrent;
    BYTE* pbInputEnd;
    int cBitsRemaining;
    int cBitsCurrent;
    UINT32 BitsCurrent;
    BYTE* HistoryBuffer;
    UINT32 HistoryIndex;
    UINT32 HistoryBufferSize;
    BYTE bits;
};

struct _wStream {
    BYTE* buffer;
    size_t pointer;
    size_t length;
};

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
void Stream_Seek(wStream* stream, size_t offset);
size_t Stream_GetRemainingLength(wStream* stream);
void zgfx_GetBits(ZGFX_CONTEXT* zgfx, int nbits);
void zgfx_history_buffer_ring_write(ZGFX_CONTEXT* zgfx, const BYTE* pSrcData, size_t cbSrcData);
void zgfx_history_buffer_ring_read(ZGFX_CONTEXT* zgfx, UINT32 distance, BYTE* pDstData, size_t cbDstData);
void CopyMemory(void* dest, const void* src, size_t length);