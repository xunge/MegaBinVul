#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;
typedef uint16_t UINT16;
typedef uint32_t UINT32;
typedef bool BOOL;
#define TRUE true
#define FALSE false

#define ARRAYSIZE(a) (sizeof(a) / sizeof(a[0]))
static const uint8_t BMF_BPP[] = {0, 1, 8, 16, 24, 32};
enum { BMF_8BPP = 2, BMF_16BPP = 3, BMF_32BPP = 5 };

#define WLOG_ERROR 0
#define PRIu32 "u"

typedef struct _CACHE_BRUSH_ORDER {
    BYTE index;
    BYTE bpp;
    BYTE cx;
    BYTE cy;
    BYTE style;
    BYTE length;
    BYTE data[256];
} CACHE_BRUSH_ORDER;

typedef struct _rdpUpdate {
    void* log;
    void* context;
} rdpUpdate;

typedef struct _wStream wStream;

void WLog_Print(void* log, int level, const char* format, ...);
void Stream_Read_UINT8(wStream* s, uint8_t* val);
void Stream_Read(wStream* s, void* buf, size_t size);
size_t Stream_GetRemainingLength(wStream* s);
void free_cache_brush_order(void* context, CACHE_BRUSH_ORDER* order);
BOOL update_decompress_brush(wStream* s, BYTE* data, size_t size, BYTE bpp);