#include <stdlib.h>
#include <setjmp.h>

typedef struct fz_context {
    jmp_buf jbuf;
} fz_context;

typedef struct fz_device fz_device;

typedef struct {
    float a, b, c, d, e, f;
} fz_matrix;

typedef struct {
    float x0, y0, x1, y1;
} fz_rect;

typedef struct fz_image {
    struct fz_image *mask;
    void *colorspace;
} fz_image;

typedef struct {
    int hidden;
} pdf_processor;

typedef struct pdf_gstate {
    fz_matrix ctm;
    int blendmode;
    struct {
        int kind;
        void *colorspace;
        float v[4];
        float alpha;
        void *color_params;
        void *pattern;
        int gstate_num;
        void *shade;
    } fill;
} pdf_gstate;

typedef struct pdf_run_processor {
    pdf_processor super;
    fz_device *dev;
    pdf_gstate *gstate;
    int gtop;
} pdf_run_processor;

typedef struct softmask_save {
    void *softmask;
} softmask_save;

enum {
    PDF_MAT_NONE,
    PDF_MAT_COLOR,
    PDF_MAT_PATTERN,
    PDF_MAT_SHADE,
    PDF_FILL
};

extern fz_rect fz_unit_rect;

#define fz_try(ctx) if (!setjmp((ctx)->jbuf))
#define fz_catch(ctx) else
#define fz_always(ctx) if (1)

void fz_begin_group(fz_context *ctx, fz_device *dev, fz_rect *bbox, void *unused, int isolated, int knockout, int blendmode, float alpha);
void fz_end_group(fz_context *ctx, fz_device *dev);
void fz_clip_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix *ctm, fz_rect *bbox);
void fz_pop_clip(fz_context *ctx, fz_device *dev);
void fz_rethrow(fz_context *ctx);
void fz_transform_rect(fz_rect *rect, fz_matrix *ctm);
fz_matrix *fz_pre_scale(fz_matrix *mat, float sx, float sy);
fz_matrix *fz_pre_translate(fz_matrix *mat, float tx, float ty);
void fz_fill_image_mask(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix *ctm, void *colorspace, float *color, float alpha, void *color_params);
void fz_fill_image(fz_context *ctx, fz_device *dev, fz_image *image, fz_matrix *ctm, float alpha, void *color_params);
void fz_fill_shade(fz_context *ctx, fz_device *dev, void *shade, fz_matrix *ctm, float alpha, void *color_params);

pdf_gstate *pdf_begin_group(fz_context *ctx, pdf_run_processor *pr, fz_rect *bbox, softmask_save *softmask);
void pdf_end_group(fz_context *ctx, pdf_run_processor *pr, softmask_save *softmask);
void pdf_show_pattern(fz_context *ctx, pdf_run_processor *pr, void *pattern, pdf_gstate *gstate, fz_rect *bbox, int what);
void pdf_show_image_imp(fz_context *ctx, pdf_run_processor *pr, fz_image *image, fz_matrix *ctm, fz_rect *bbox);