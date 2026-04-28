#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define TRUE true
#define FALSE false

typedef uint16_t UINT16;
typedef bool BOOL;

enum {
    UPDATE_TYPE_ORDERS,
    UPDATE_TYPE_BITMAP,
    UPDATE_TYPE_PALETTE,
    UPDATE_TYPE_SYNCHRONIZE
};

typedef struct rdpContext rdpContext;
typedef struct wStream wStream;
typedef struct BITMAP_UPDATE BITMAP_UPDATE;
typedef struct PALETTE_UPDATE PALETTE_UPDATE;

typedef struct rdpUpdate {
    rdpContext* context;
    void* log;
    BOOL (*BitmapUpdate)(rdpContext*, BITMAP_UPDATE*);
    BOOL (*Palette)(rdpContext*, PALETTE_UPDATE*);
    BOOL (*Synchronize)(rdpContext*);
} rdpUpdate;

#define TAG "UPDATE"
#define WLOG_ERR(tag, ...)
#define WLog_Print(log, level, ...)
#define WLOG_TRACE 0
#define UPDATE_TYPE_STRINGS NULL
#define PRIu16 "hu"

#define IFCALLRESULT(default, callback, ...) \
    (callback ? callback(__VA_ARGS__) : (default))