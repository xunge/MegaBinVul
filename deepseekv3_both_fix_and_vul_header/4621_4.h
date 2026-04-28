#include <stdlib.h>
#include <string.h>

typedef struct _RsvgHandle RsvgHandle;
typedef struct _RsvgDrawingCtx RsvgDrawingCtx;
typedef struct _RsvgCairoRender RsvgCairoRender;
typedef struct _RsvgState RsvgState;
typedef struct _RsvgRender RsvgRender;
typedef struct _cairo cairo_t;

struct _RsvgHandle {
    struct {
        void *defs;
        char *base_uri;
        double dpi_x;
        double dpi_y;
    } *priv;
};

struct _RsvgRender {
    /* base render class */
};

struct RsvgMatrix {
    double xx; double yx;
    double xy; double yy;
    double x0; double y0;
};

struct _RsvgState {
    struct RsvgMatrix affine;
};

struct _RsvgDrawingCtx {
    RsvgRender *render;
    RsvgState *state;
    void *defs;
    char *base_uri;
    double dpi_x;
    double dpi_y;
    struct {
        struct {
            double width;
            double height;
        } rect;
    } vb;
    void *pango_context;
    void *drawsub_stack;
    void *ptrs;
    void *acquired_nodes;
};

struct _RsvgCairoRender {
    RsvgRender parent;
    double offset_x;
    double offset_y;
    void *bbox;
};

typedef struct {
    double width;
    double height;
    double em;
    double ex;
} RsvgDimensionData;

typedef struct RsvgMatrix cairo_matrix_t;

#define g_new(type, n) ((type*)malloc(sizeof(type) * (n)))
#define g_strdup(str) strdup(str)

void rsvg_handle_get_dimensions(RsvgHandle *handle, RsvgDimensionData *data);
void rsvg_cairo_transformed_image_bounding_box(cairo_matrix_t *affine, double width, double height, double *bbx0, double *bby0, double *bbx1, double *bby1);
RsvgCairoRender *rsvg_cairo_render_new(cairo_t *cr, double width, double height);
void rsvg_state_push(RsvgDrawingCtx *draw);
RsvgState *rsvg_current_state(RsvgDrawingCtx *draw);
void rsvg_bbox_init(void **bbox, cairo_matrix_t *affine);
void cairo_get_matrix(cairo_t *cr, cairo_matrix_t *matrix);
void cairo_matrix_multiply(cairo_matrix_t *result, const cairo_matrix_t *a, const cairo_matrix_t *b);
void cairo_matrix_init_scale(cairo_matrix_t *matrix, double sx, double sy);