#include <stdint.h>
#include <stdlib.h>

typedef struct _GList {
    void *data;
    struct _GList *next;
} GList;

typedef struct _RsvgBbox {
    double x, y, width, height;
} RsvgBbox;

typedef struct _RsvgDrawingCtx {
    void *render;
    void *defs;
} RsvgDrawingCtx;

typedef struct _RsvgCairoRender {
    void *cr;
    void *initial_cr;
    GList *surfaces_stack;
    GList *cr_stack;
    GList *bb_stack;
    RsvgBbox bbox;
    int offset_x;
    int offset_y;
} RsvgCairoRender;

typedef struct _RsvgState {
    uint8_t opacity;
    void *filter;
    void *mask;
    void *clip_path_ref;
    int comp_op;
    int enable_background;
} RsvgState;

typedef struct _RsvgClipPath {
    int units;
} RsvgClipPath;

typedef struct _RsvgNode {
    int type;
} RsvgNode;

typedef struct _RsvgMask {
    // dummy structure
} RsvgMask;

typedef int gboolean;
typedef void* cairo_t;
typedef void* cairo_surface_t;

#define RSVG_CAIRO_RENDER(obj) ((RsvgCairoRender *)obj)
#define RSVG_NODE_TYPE(obj) (((RsvgNode *)obj)->type)
#define RSVG_NODE_TYPE_MASK (1)
#define RSVG_ENABLE_BACKGROUND_ACCUMULATE (1)
#define CAIRO_OPERATOR_OVER (0)
#define FALSE (0)
#define TRUE (1)
#define objectBoundingBox (0)

static RsvgState *rsvg_current_state(RsvgDrawingCtx *ctx);
static void rsvg_cairo_clip(RsvgDrawingCtx *ctx, void *clip_path_ref, RsvgBbox *bbox);
static RsvgNode *rsvg_defs_lookup(void *defs, void *mask);
static void rsvg_cairo_generate_mask(cairo_t *cr, RsvgMask *mask, RsvgDrawingCtx *ctx, RsvgBbox *bbox);
static cairo_surface_t *rsvg_filter_render(void *filter, cairo_surface_t *output, RsvgDrawingCtx *ctx, RsvgBbox *bbox, const char *str);
static void rsvg_bbox_insert(RsvgBbox *dest, RsvgBbox *src);
static GList *g_list_delete_link(GList *list, GList *link_);
static void g_free(void *ptr);