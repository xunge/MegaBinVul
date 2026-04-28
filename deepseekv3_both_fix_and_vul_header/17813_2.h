#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef bool BOOL;

#define TRUE true
#define FALSE false

typedef struct _wStream {
    uint8_t* buffer;
    size_t position;
    size_t length;
} wStream;

typedef struct {
    uint8_t bpp;
    uint8_t codecID;
    uint16_t width;
    uint16_t height;
    uint32_t length;
    uint8_t* data;
} BITMAP_DATA_EX;

typedef struct {
    uint32_t cacheId;
    uint16_t cacheIndex;
    uint32_t key1;
    uint32_t key2;
    uint8_t bpp;
    uint8_t flags;
    BITMAP_DATA_EX bitmapData;
} CACHE_BITMAP_V3_ORDER;

extern const BYTE BPP_CBR23[];

BOOL Stream_EnsureRemainingCapacity(wStream* s, size_t size);
void Stream_Write_UINT16(wStream* s, uint16_t value);
void Stream_Write_UINT32(wStream* s, uint32_t value);
void Stream_Write_UINT8(wStream* s, uint8_t value);
void Stream_Write(wStream* s, const void* data, size_t length);
BOOL update_approximate_cache_bitmap_v3_order(CACHE_BITMAP_V3_ORDER* cache_bitmap_v3, UINT16* flags);