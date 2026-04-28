#include <stdlib.h>
#include <float.h>

typedef struct fz_context fz_context;
typedef struct fz_device fz_device;
typedef struct fz_colorspace fz_colorspace;

typedef struct {
    float x0, y0, x1, y1;
} fz_rect;

typedef struct {
    float a, b, c, d, e, f;
} fz_matrix;

typedef struct pdf_xobject pdf_xobject;
typedef struct pdf_gstate pdf_gstate;
typedef struct pdf_run_processor pdf_run_processor;

typedef struct softmask_save {
    pdf_xobject *softmask;
    void *page_resources;
    fz_matrix ctm;
} softmask_save;

struct pdf_gstate {
    pdf_xobject *softmask;
    void *softmask_resources;
    fz_matrix softmask_ctm;
    fz_matrix ctm;
    int luminosity;
    float softmask_bc[4];
    struct {
        void *color_params;
    } fill;
    pdf_gstate *gstate;
    int gtop;
};

struct pdf_run_processor {
    pdf_gstate *gstate;
    int gtop;
    fz_device *dev;
    void *tos;
};

#define FZ_ERROR_TRYLATER 1
static const fz_rect fz_infinite_rect = { -FLT_MAX, -FLT_MAX, FLT_MAX, FLT_MAX };
static const fz_matrix fz_identity = { 1, 0, 0, 1, 0, 0 };

#define fz_try(ctx) if (1)
#define fz_always(ctx) if (1)
#define fz_catch(ctx) if (0)

static void fz_transform_rect(fz_rect *rect, const fz_matrix *matrix) {}
static void fz_begin_mask(fz_context *ctx, fz_device *dev, const fz_rect *bbox, int luminosity, fz_colorspace *colorspace, const float *bc, void *color_params) {}
static void fz_end_mask(fz_context *ctx, fz_device *dev) {}
static void fz_rethrow_if(fz_context *ctx, int error) {}
static void fz_drop_colorspace(fz_context *ctx, fz_colorspace *colorspace) {}
static fz_colorspace *fz_device_gray(fz_context *ctx) { return NULL; }

static void pdf_xobject_bbox(fz_context *ctx, pdf_xobject *xobj, fz_rect *bbox) {}
static void pdf_xobject_matrix(fz_context *ctx, pdf_xobject *xobj, fz_matrix *matrix) {}
static fz_colorspace *pdf_xobject_colorspace(fz_context *ctx, pdf_xobject *xobj) { return NULL; }
static void pdf_run_xobject(fz_context *ctx, pdf_run_processor *pr, pdf_xobject *xobj, void *resources, const fz_matrix *matrix, int is_softmask) {}

static void pdf_tos_save(fz_context *ctx, void *tos, fz_matrix *save) {}
static void pdf_tos_restore(fz_context *ctx, void *tos, fz_matrix *save) {}