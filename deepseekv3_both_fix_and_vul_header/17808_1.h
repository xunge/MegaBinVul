#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef int BOOL;

#define CBR2_PERSISTENT_KEY_PRESENT 0x01
#define CBR2_HEIGHT_SAME_AS_WIDTH 0x02
#define CBR2_DO_NOT_CACHE 0x04
#define CBR2_NO_BITMAP_COMPRESSION_HDR 0x08
#define BITMAP_CACHE_WAITING_LIST_INDEX 0x7FFF

static const UINT16 CBR2_BPP[] = {0, 8, 16, 24, 32};

struct _CACHE_BITMAP_V2_ORDER {
    UINT16 cacheId;
    UINT16 flags;
    UINT16 bitmapBpp;
    UINT32 key1;
    UINT32 key2;
    UINT16 bitmapWidth;
    UINT16 bitmapHeight;
    UINT32 bitmapLength;
    UINT16 cacheIndex;
    UINT16 cbCompFirstRowSize;
    UINT16 cbCompMainBodySize;
    UINT16 cbScanWidth;
    UINT16 cbUncompressedSize;
    BYTE* bitmapDataStream;
    BOOL compressed;
};

typedef struct _CACHE_BITMAP_V2_ORDER CACHE_BITMAP_V2_ORDER;

struct _rdpUpdate {
    void* context;
};

typedef struct _rdpUpdate rdpUpdate;

struct _wStream {
    size_t length;
    size_t pointer;
    BYTE* buffer;
};

typedef struct _wStream wStream;

size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT16(wStream* s, UINT16* val);
void Stream_Read_UINT32(wStream* s, UINT32* val);
void Stream_Read(wStream* s, void* buf, size_t len);
BOOL update_read_2byte_unsigned(wStream* s, UINT16* val);
BOOL update_read_4byte_unsigned(wStream* s, UINT32* val);
void free_cache_bitmap_v2_order(void* context, CACHE_BITMAP_V2_ORDER* order);