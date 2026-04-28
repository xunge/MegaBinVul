#include <stddef.h>

typedef struct _cairo cairo_t;
typedef struct _cairo_surface cairo_surface_t;

typedef struct _RsvgBbox {
    double x, y, width, height;
} RsvgBbox;

typedef struct _RsvgDrawingCtx {
    void *render;
    void *defs;
} RsvgDrawingCtx;

typedef struct _RsvgCairoRender {
    cairo_t *cr;
    cairo_t *initial_cr;
    struct _GList *cr_stack;
    struct _GList *surfaces_stack;
    struct _GList *bb_stack;
    RsvgBbox bbox;
    double offset_x;
    double offset_y;
} RsvgCairoRender;

typedef struct _RsvgClipPath {
    int units;
} RsvgClipPath;

typedef struct _RsvgState {
    unsigned char opacity;
    void *filter;
    void *mask;
    void *clip_path;
    int comp_op;
    int enable_background;
} RsvgState;

typedef struct _RsvgNode {
    int type;
} RsvgNode;

typedef struct _RsvgMask {
    // mask fields
} RsvgMask;

typedef struct _GList {
    void *data;
    struct _GList *next;
} GList;

typedef int gboolean;

#define RSVG_CAIRO_RENDER(x) ((RsvgCairoRender *)(x))
#define RSVG_NODE_TYPE(x) ((RsvgNode *)(x))->type
#define RSVG_NODE_TYPE_CLIP_PATH 1
#define RSVG_NODE_TYPE_MASK 2
#define RSVG_ENABLE_BACKGROUND_ACCUMULATE 1
#define CAIRO_OPERATOR_OVER 0

enum {
    objectBoundingBox
};

// Function prototypes
void cairo_identity_matrix(cairo_t *cr);
void cairo_set_source_surface(cairo_t *cr, cairo_surface_t *surface, double x, double y);
void cairo_set_operator(cairo_t *cr, int op);
void cairo_paint(cairo_t *cr);
void cairo_paint_with_alpha(cairo_t *cr, double alpha);
void cairo_destroy(cairo_t *cr);
cairo_surface_t *cairo_get_target(cairo_t *cr);
void cairo_surface_destroy(cairo_surface_t *surface);

void g_free(void *ptr);
GList *g_list_delete_link(GList *list, GList *link);

RsvgState *rsvg_current_state(RsvgDrawingCtx *ctx);
RsvgNode *rsvg_defs_lookup(void *defs, void *clip_path);
void rsvg_cairo_clip(RsvgDrawingCtx *ctx, RsvgClipPath *clip, RsvgBbox *bbox);
void rsvg_cairo_generate_mask(cairo_t *cr, RsvgMask *mask, RsvgDrawingCtx *ctx, RsvgBbox *bbox);
void rsvg_bbox_insert(RsvgBbox *dest, RsvgBbox *src);
cairo_surface_t *rsvg_filter_render(void *filter, cairo_surface_t *output, RsvgDrawingCtx *ctx, RsvgBbox *bbox, const char *str);