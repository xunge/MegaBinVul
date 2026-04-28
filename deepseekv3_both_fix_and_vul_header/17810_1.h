#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef bool BOOL;

#define BITMAP_CACHE_WAITING_LIST_INDEX 0xFFFF

#define CBR2_PERSISTENT_KEY_PRESENT 0x01
#define CBR2_HEIGHT_SAME_AS_WIDTH 0x02
#define CBR2_DO_NOT_CACHE 0x04
#define CBR2_NO_BITMAP_COMPRESSION_HDR 0x08

static const BYTE BPP_CBR2[] = {0, 1, 2, 3, 4, 5, 8, 15, 16, 24, 32};

typedef struct _wStream {
    size_t capacity;
    size_t position;
    BYTE* buffer;
} wStream;

typedef struct _CACHE_BITMAP_V2_ORDER {
    UINT16 cacheId;
    UINT16 flags;
    UINT16 bitmapWidth;
    UINT16 bitmapHeight;
    UINT32 bitmapLength;
    UINT16 cacheIndex;
    UINT16 bitmapBpp;
    UINT32 key1;
    UINT32 key2;
    UINT16 cbCompFirstRowSize;
    UINT16 cbCompMainBodySize;
    UINT16 cbScanWidth;
    UINT16 cbUncompressedSize;
    BYTE* bitmapDataStream;
    BOOL compressed;
} CACHE_BITMAP_V2_ORDER;

BOOL Stream_EnsureRemainingCapacity(wStream* s, size_t size);
void Stream_Write_UINT16(wStream* s, UINT16 value);
void Stream_Write_UINT32(wStream* s, UINT32 value);
void Stream_Write(wStream* s, const BYTE* data, size_t size);
size_t update_approximate_cache_bitmap_v2_order(CACHE_BITMAP_V2_ORDER* cache_bitmap_v2, BOOL compressed, UINT16* flags);
BOOL update_write_2byte_unsigned(wStream* s, UINT16 value);
BOOL update_write_4byte_unsigned(wStream* s, UINT32 value);