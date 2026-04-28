#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <inttypes.h>
#include <limits.h>
#include <stdbool.h>

typedef struct DisplaySurface DisplaySurface;
typedef struct QXLInstance QXLInstance;
typedef struct SimpleSpiceDisplay SimpleSpiceDisplay;
typedef struct QXLDevSurfaceCreate QXLDevSurfaceCreate;

struct DisplaySurface {
    int width;
    int height;
};

struct QXLInstance {
    int id;
};

struct SimpleSpiceDisplay {
    DisplaySurface *ds;
    size_t bufsize;
    void *buf;
    QXLInstance qxl;
};

struct QXLDevSurfaceCreate {
    uint32_t format;
    uint32_t width;
    uint32_t height;
    int32_t stride;
    bool mouse_mode;
    uint32_t flags;
    uint32_t type;
    uintptr_t mem;
    uint32_t group_id;
};

#define SPICE_SURFACE_FMT_32_xRGB 0
#define MEMSLOT_GROUP_HOST 0
#define QXL_SYNC 0

void dprint(int level, const char *fmt, ...);
uint32_t surface_width(DisplaySurface *ds);
uint32_t surface_height(DisplaySurface *ds);
void g_free(void *ptr);
void *g_malloc(size_t size);
void qemu_spice_create_primary_surface(SimpleSpiceDisplay *ssd, int id, QXLDevSurfaceCreate *surface, int sync);