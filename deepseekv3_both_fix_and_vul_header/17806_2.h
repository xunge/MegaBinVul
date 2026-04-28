#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define BOOL bool
#define BYTE uint8_t
#define FALSE false
#define TRUE true
#define PRIx32 "x"

typedef struct WLog WLog;
typedef struct rdpSettings rdpSettings;
typedef struct rdpContext rdpContext;
typedef struct ORDER_INFO ORDER_INFO;
typedef struct rdpPrimaryUpdate rdpPrimaryUpdate;
typedef struct rdpUpdate rdpUpdate;
typedef struct wStream wStream;

struct rdpUpdate {
    rdpContext* context;
    rdpPrimaryUpdate* primary;
    WLog* log;
    BOOL (*SetBounds)(rdpContext*, void*);
};

struct rdpContext {
    rdpSettings* settings;
};

struct ORDER_INFO {
    BYTE orderType;
    uint32_t fieldFlags;
    void* bounds;
    BOOL deltaCoordinates;
};

struct rdpPrimaryUpdate {
    ORDER_INFO order_info;
    struct {
        BYTE bRop;
    } dstblt, patblt, scrblt, multi_dstblt, multi_patblt, multi_scrblt, memblt, mem3blt;
    struct {
        // placeholder for other order types
    } opaque_rect, draw_nine_grid, multi_opaque_rect, multi_draw_nine_grid, 
      line_to, polyline, save_bitmap, glyph_index, fast_index, fast_glyph,
      polygon_sc, polygon_cb, ellipse_sc, ellipse_cb;
    BOOL (*DstBlt)(rdpContext*, void*);
    BOOL (*PatBlt)(rdpContext*, void*);
    BOOL (*ScrBlt)(rdpContext*, void*);
    BOOL (*OpaqueRect)(rdpContext*, void*);
    BOOL (*DrawNineGrid)(rdpContext*, void*);
    BOOL (*MultiDstBlt)(rdpContext*, void*);
    BOOL (*MultiPatBlt)(rdpContext*, void*);
    BOOL (*MultiScrBlt)(rdpContext*, void*);
    BOOL (*MultiOpaqueRect)(rdpContext*, void*);
    BOOL (*MultiDrawNineGrid)(rdpContext*, void*);
    BOOL (*LineTo)(rdpContext*, void*);
    BOOL (*Polyline)(rdpContext*, void*);
    BOOL (*MemBlt)(rdpContext*, void*);
    BOOL (*Mem3Blt)(rdpContext*, void*);
    BOOL (*SaveBitmap)(rdpContext*, void*);
    BOOL (*GlyphIndex)(rdpContext*, void*);
    BOOL (*FastIndex)(rdpContext*, void*);
    BOOL (*FastGlyph)(rdpContext*, void*);
    BOOL (*PolygonSC)(rdpContext*, void*);
    BOOL (*PolygonCB)(rdpContext*, void*);
    BOOL (*EllipseSC)(rdpContext*, void*);
    BOOL (*EllipseCB)(rdpContext*, void*);
};

#define WLOG_ERROR 0
#define WLOG_WARN 1
#define WLOG_DEBUG 2

#define ORDER_TYPE_CHANGE 0x01
#define ORDER_BOUNDS 0x04
#define ORDER_ZERO_BOUNDS_DELTAS 0x08
#define ORDER_DELTA_COORDINATES 0x10

#define ORDER_TYPE_DSTBLT 0
#define ORDER_TYPE_PATBLT 1
#define ORDER_TYPE_SCRBLT 2
#define ORDER_TYPE_OPAQUE_RECT 3
#define ORDER_TYPE_DRAW_NINE_GRID 4
#define ORDER_TYPE_MULTI_DSTBLT 5
#define ORDER_TYPE_MULTI_PATBLT 6
#define ORDER_TYPE_MULTI_SCRBLT 7
#define ORDER_TYPE_MULTI_OPAQUE_RECT 8
#define ORDER_TYPE_MULTI_DRAW_NINE_GRID 9
#define ORDER_TYPE_LINE_TO 10
#define ORDER_TYPE_POLYLINE 11
#define ORDER_TYPE_MEMBLT 12
#define ORDER_TYPE_MEM3BLT 13
#define ORDER_TYPE_SAVE_BITMAP 14
#define ORDER_TYPE_GLYPH_INDEX 15
#define ORDER_TYPE_FAST_INDEX 16
#define ORDER_TYPE_FAST_GLYPH 17
#define ORDER_TYPE_POLYGON_SC 18
#define ORDER_TYPE_POLYGON_CB 19
#define ORDER_TYPE_ELLIPSE_SC 20
#define ORDER_TYPE_ELLIPSE_CB 21

#define IFCALLRESULT(default, func, ...) (func ? func(__VA_ARGS__) : default)

static const uint8_t PRIMARY_DRAWING_ORDER_FIELD_BYTES[22];

static const char* primary_order_string(BYTE orderType);
static BOOL check_primary_order_supported(WLog* log, rdpSettings* settings, BYTE orderType, const char* orderName);
static BOOL update_read_field_flags(wStream* s, uint32_t* fieldFlags, BYTE flags, uint8_t fieldBytes);
static BOOL update_read_bounds(wStream* s, void* bounds);
static BOOL read_primary_order(WLog* log, const char* orderName, wStream* s, ORDER_INFO* orderInfo, rdpPrimaryUpdate* primary);
static const char* gdi_rop3_code_string(BYTE bRop);
static uint32_t gdi_rop3_code(BYTE bRop);