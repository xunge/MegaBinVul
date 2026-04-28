#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>

typedef uint16_t UINT16;
typedef uint32_t UINT32;

typedef struct rdpUpdate {
    void* log;
    void* context;
} rdpUpdate;

typedef struct wStream wStream;

typedef struct BITMAP_DATA {
    // Add BITMAP_DATA fields here if needed
} BITMAP_DATA;

typedef struct BITMAP_UPDATE {
    UINT16 number;
    UINT16 count;
    BITMAP_DATA* rectangles;
} BITMAP_UPDATE;

enum {
    WLOG_TRACE
};

void WLog_Print(void* log, int level, const char* format, ...);
size_t Stream_GetRemainingLength(wStream* s);
void Stream_Read_UINT16(wStream* s, UINT16* val);
void free_bitmap_update(void* context, BITMAP_UPDATE* bitmapUpdate);
int update_read_bitmap_data(rdpUpdate* update, wStream* s, BITMAP_DATA* data);