#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;

typedef struct _BITMAP_DATA_EX {
    UINT32 bpp;
    UINT16 width;
    UINT16 height;
    UINT32 length;
    BYTE* data;
    BYTE codecID;
} BITMAP_DATA_EX;

typedef struct _CACHE_BITMAP_V3_ORDER {
    UINT32 cacheId;
    UINT32 flags;
    UINT32 bpp;
    UINT16 cacheIndex;
    UINT32 key1;
    UINT32 key2;
    BITMAP_DATA_EX bitmapData;
} CACHE_BITMAP_V3_ORDER;

typedef struct _wStream wStream;

struct _wStream {
    size_t (*GetRemainingLength)(wStream* s);
    void (*Read_UINT16)(wStream* s, UINT16* val);
    void (*Read_UINT32)(wStream* s, UINT32* val);
    void (*Read_UINT8)(wStream* s, BYTE* val);
    void (*Seek_UINT8)(wStream* s);
    void (*Read)(wStream* s, void* buffer, size_t size);
};

typedef struct _rdpUpdate {
    void* log;
    void* context;
} rdpUpdate;

static const UINT32 CBR23_BPP[] = {0, 1, 2, 4, 8, 15, 16, 24, 32};

enum {
    WLOG_ERROR
};

void WLog_Print(void* log, int level, const char* fmt, ...);
void free_cache_bitmap_v3_order(void* context, CACHE_BITMAP_V3_ORDER* order);

size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT16(wStream* s, UINT16* val);
void Stream_Read_UINT32(wStream* s, UINT32* val);
void Stream_Read_UINT8(wStream* s, BYTE* val);
void Stream_Seek_UINT8(wStream* s);
void Stream_Read(wStream* s, void* buffer, size_t size);