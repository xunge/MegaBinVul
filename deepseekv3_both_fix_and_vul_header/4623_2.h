#include <stddef.h>

typedef struct _cairo_surface cairo_surface_t;

typedef struct _RsvgFilterPrimitive RsvgFilterPrimitive;
typedef struct _RsvgFilterContext RsvgFilterContext;
typedef struct _RsvgDrawingCtx RsvgDrawingCtx;
typedef struct _RsvgFilterPrimitiveImage RsvgFilterPrimitiveImage;
typedef struct _RsvgNode RsvgNode;

struct _RsvgFilterPrimitiveImage {
    struct {
        char *str;
    } *href;
};

struct _RsvgFilterContext {
    RsvgDrawingCtx *ctx;
    double *paffine;
    int width;
    int height;
};

struct _RsvgDrawingCtx {
    void *defs;
};

RsvgNode *rsvg_defs_lookup(void *defs, const char *str);
struct {
    double *affine;
} *rsvg_current_state(RsvgDrawingCtx *ctx);
cairo_surface_t *rsvg_get_surface_of_node(RsvgDrawingCtx *ctx, RsvgNode *drawable, int width, int height);