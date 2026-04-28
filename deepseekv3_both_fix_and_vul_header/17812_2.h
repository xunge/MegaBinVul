#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

typedef uint8_t BYTE;
typedef uint8_t UINT8;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef bool BOOL;

#define WLOG_ERROR 0

typedef struct _BITMAP_DATA_EX
{
    UINT8 bpp;
    UINT8 codecID;
    UINT16 width;
    UINT16 height;
    UINT32 length;
    BYTE* data;
} BITMAP_DATA_EX;

typedef struct _CACHE_BITMAP_V3_ORDER
{
    UINT32 cacheId;
    UINT32 flags;
    UINT8 bpp;
    UINT16 cacheIndex;
    UINT32 key1;
    UINT32 key2;
    BITMAP_DATA_EX bitmapData;
} CACHE_BITMAP_V3_ORDER;

typedef struct _rdpUpdate
{
    void* context;
    void* log;
} rdpUpdate;

typedef struct _wStream
{
    size_t (*GetRemainingLength)(struct _wStream* s);
    void (*Read_UINT8)(struct _wStream* s, UINT8* val);
    void (*Read_UINT16)(struct _wStream* s, UINT16* val);
    void (*Read_UINT32)(struct _wStream* s, UINT32* val);
    void (*Seek_UINT8)(struct _wStream* s);
    void (*Read)(struct _wStream* s, void* data, size_t len);
} wStream;

static const UINT8 CBR23_BPP[] = {0, 1, 2, 4, 8, 15, 16, 24, 32};

static UINT8 get_cbr2_bpp(BYTE bitsPerPixelId, BOOL* rc)
{
    *rc = true;
    return CBR23_BPP[bitsPerPixelId];
}

static void WLog_Print(void* log, int level, const char* format, ...) {}

static size_t Stream_GetRemainingLength(wStream* s) { return 0; }
static void Stream_Read_UINT8(wStream* s, UINT8* val) {}
static void Stream_Read_UINT16(wStream* s, UINT16* val) {}
static void Stream_Read_UINT32(wStream* s, UINT32* val) {}
static void Stream_Seek_UINT8(wStream* s) {}
static void Stream_Read(wStream* s, void* data, size_t len) {}

static void free_cache_bitmap_v3_order(void* context, CACHE_BITMAP_V3_ORDER* order)
{
    if (order)
    {
        free(order->bitmapData.data);
        free(order);
    }
}