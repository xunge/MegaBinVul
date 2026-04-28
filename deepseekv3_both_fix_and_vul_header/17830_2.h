#include <stdint.h>
#include <stddef.h>

#define FALSE 0
#define TRUE 1
typedef int BOOL;
typedef uint8_t BYTE;
typedef uint16_t UINT16;

typedef struct rdpUpdate {
    struct rdpContext* context;
    struct rdpSecondaryUpdate* secondary;
    void* log;
} rdpUpdate;

typedef struct rdpContext {
    struct rdpSettings* settings;
} rdpContext;

typedef struct rdpSettings {
    int GlyphSupportLevel;
} rdpSettings;

typedef struct rdpSecondaryUpdate {
    BOOL (*CacheBitmap)(struct rdpContext*, void*);
    BOOL (*CacheBitmapV2)(struct rdpContext*, void*);
    BOOL (*CacheBitmapV3)(struct rdpContext*, void*);
    BOOL (*CacheColorTable)(struct rdpContext*, void*);
    BOOL (*CacheGlyph)(struct rdpContext*, void*);
    BOOL (*CacheGlyphV2)(struct rdpContext*, void*);
    BOOL (*CacheBrush)(struct rdpContext*, void*);
} rdpSecondaryUpdate;

typedef struct wStream {
    size_t position;
    size_t (*GetRemainingLength)(struct wStream*);
    void (*Read_UINT16)(struct wStream*, UINT16*);
    void (*Read_UINT8)(struct wStream*, BYTE*);
    size_t (*GetPosition)(struct wStream*);
    void (*Seek)(struct wStream*, size_t);
} wStream;

typedef struct CACHE_BITMAP_ORDER CACHE_BITMAP_ORDER;
typedef struct CACHE_BITMAP_V2_ORDER CACHE_BITMAP_V2_ORDER;
typedef struct CACHE_BITMAP_V3_ORDER CACHE_BITMAP_V3_ORDER;
typedef struct CACHE_COLOR_TABLE_ORDER CACHE_COLOR_TABLE_ORDER;
typedef struct CACHE_GLYPH_ORDER CACHE_GLYPH_ORDER;
typedef struct CACHE_GLYPH_V2_ORDER CACHE_GLYPH_V2_ORDER;
typedef struct CACHE_BRUSH_ORDER CACHE_BRUSH_ORDER;

enum {
    ORDER_TYPE_BITMAP_UNCOMPRESSED,
    ORDER_TYPE_CACHE_BITMAP_COMPRESSED,
    ORDER_TYPE_BITMAP_UNCOMPRESSED_V2,
    ORDER_TYPE_BITMAP_COMPRESSED_V2,
    ORDER_TYPE_BITMAP_COMPRESSED_V3,
    ORDER_TYPE_CACHE_COLOR_TABLE,
    ORDER_TYPE_CACHE_GLYPH,
    ORDER_TYPE_CACHE_BRUSH
};

enum {
    GLYPH_SUPPORT_NONE,
    GLYPH_SUPPORT_PARTIAL,
    GLYPH_SUPPORT_FULL,
    GLYPH_SUPPORT_ENCODE
};

enum {
    WLOG_ERROR,
    WLOG_WARN,
    WLOG_DEBUG
};

#define IFCALLRESULT(result, func, ...) (func ? func(__VA_ARGS__) : result)
#define PRIuz "zu"
#define PRIu16 "u"

const char* secondary_order_string(BYTE orderType);
BOOL check_secondary_order_supported(void* log, struct rdpSettings* settings, BYTE orderType, const char* name);
CACHE_BITMAP_ORDER* update_read_cache_bitmap_order(struct rdpUpdate* update, struct wStream* s, BOOL compressed, UINT16 extraFlags);
void free_cache_bitmap_order(struct rdpContext* context, CACHE_BITMAP_ORDER* order);
CACHE_BITMAP_V2_ORDER* update_read_cache_bitmap_v2_order(struct rdpUpdate* update, struct wStream* s, BOOL compressed, UINT16 extraFlags);
void free_cache_bitmap_v2_order(struct rdpContext* context, CACHE_BITMAP_V2_ORDER* order);
CACHE_BITMAP_V3_ORDER* update_read_cache_bitmap_v3_order(struct rdpUpdate* update, struct wStream* s, UINT16 extraFlags);
void free_cache_bitmap_v3_order(struct rdpContext* context, CACHE_BITMAP_V3_ORDER* order);
CACHE_COLOR_TABLE_ORDER* update_read_cache_color_table_order(struct rdpUpdate* update, struct wStream* s, UINT16 extraFlags);
void free_cache_color_table_order(struct rdpContext* context, CACHE_COLOR_TABLE_ORDER* order);
CACHE_GLYPH_ORDER* update_read_cache_glyph_order(struct rdpUpdate* update, struct wStream* s, UINT16 extraFlags);
void free_cache_glyph_order(struct rdpContext* context, CACHE_GLYPH_ORDER* order);
CACHE_GLYPH_V2_ORDER* update_read_cache_glyph_v2_order(struct rdpUpdate* update, struct wStream* s, UINT16 extraFlags);
void free_cache_glyph_v2_order(struct rdpContext* context, CACHE_GLYPH_V2_ORDER* order);
CACHE_BRUSH_ORDER* update_read_cache_brush_order(struct rdpUpdate* update, struct wStream* s, UINT16 extraFlags);
void free_cache_brush_order(struct rdpContext* context, CACHE_BRUSH_ORDER* order);
void WLog_Print(void* log, int level, const char* format, ...);