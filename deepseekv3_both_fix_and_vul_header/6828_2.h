#include <stdlib.h>
#include <string.h>

typedef struct fz_context fz_context;
typedef struct pdf_document pdf_document;
typedef struct pdf_obj pdf_obj;
typedef struct pdf_annot {
    pdf_obj *obj;
    void *page;
    void *ap;
} pdf_annot;
typedef struct fz_display_list fz_display_list;
typedef struct fz_device fz_device;
typedef struct fz_text fz_text;
typedef struct fz_colorspace fz_colorspace;
typedef struct fz_path fz_path;
typedef struct fz_buffer fz_buffer;

typedef struct {
    float a, b, c, d, e, f;
} fz_matrix;

typedef struct {
    float x0, y0, x1, y1;
} fz_rect;

typedef struct {
    struct {
        int col_size;
        float col[4];
    } da_rec;
} font_info;

static const fz_matrix fz_identity = {1, 0, 0, 1, 0, 0};
static float logo_color[3] = {0, 0, 0};

enum {
    PDF_NAME_Root,
    PDF_NAME_AcroForm,
    PDF_NAME_DR,
    PDF_NAME_DA,
    PDF_NAME_Rect
};

extern pdf_obj *pdf_dict_getl(fz_context *ctx, pdf_obj *obj, ...);
extern pdf_obj *pdf_trailer(fz_context *ctx, pdf_document *doc);
extern void pdf_dict_putl_drop(fz_context *ctx, pdf_obj *obj, pdf_obj *val, ...);
extern pdf_obj *pdf_new_dict(fz_context *ctx, pdf_document *doc, int size);
extern void pdf_page_transform(fz_context *ctx, pdf_annot *annot, void *null, fz_matrix *page_ctm);
extern char *pdf_to_str_buf(fz_context *ctx, pdf_obj *obj);
extern pdf_obj *pdf_dict_get(fz_context *ctx, pdf_obj *obj, int name);
extern void pdf_to_rect(fz_context *ctx, pdf_obj *obj, fz_rect *rect);
extern fz_display_list *fz_new_display_list(fz_context *ctx, void *null);
extern fz_device *fz_new_list_device(fz_context *ctx, fz_display_list *dlist);
extern fz_path *fz_new_path(fz_context *ctx);
extern void draw_logo(fz_context *ctx, fz_path *path);
extern void fz_bound_path(fz_context *ctx, fz_path *path, void *null, const fz_matrix *matrix, fz_rect *rect);
extern void center_rect_within_rect(fz_rect *logo_bounds, fz_rect *rect, fz_matrix *logo_tm);
extern void fz_concat(fz_matrix *logo_tm, fz_matrix *logo_tm2, fz_matrix *page_ctm);
extern fz_colorspace *fz_device_rgb(fz_context *ctx);
extern void fz_fill_path(fz_context *ctx, fz_device *dev, fz_path *path, int flags, fz_matrix *matrix, fz_colorspace *cs, float *color, float alpha, void *null);
extern void get_font_info(fz_context *ctx, pdf_document *doc, pdf_obj *dr, char *da, font_info *font_rec);
extern fz_colorspace *fz_device_gray(fz_context *ctx);
extern fz_colorspace *fz_device_cmyk(fz_context *ctx);
extern fz_text *fit_text(fz_context *ctx, font_info *font_rec, char *text, fz_rect *rect);
extern void fz_fill_text(fz_context *ctx, fz_device *dev, fz_text *text, fz_matrix *matrix, fz_colorspace *cs, float *color, float alpha, void *null);
extern void fz_drop_text(fz_context *ctx, fz_text *text);
extern fz_buffer *fz_new_buffer(fz_context *ctx, int size);
extern void fz_append_printf(fz_context *ctx, fz_buffer *buf, const char *fmt, ...);
extern char *fz_string_from_buffer(fz_context *ctx, fz_buffer *buf);
extern void fz_close_device(fz_context *ctx, fz_device *dev);
extern void fz_transform_rect(fz_rect *rect, fz_matrix *matrix);
extern void pdf_set_annot_appearance(fz_context *ctx, pdf_document *doc, pdf_annot *annot, fz_rect *rect, fz_display_list *dlist);
extern void pdf_drop_xobject(fz_context *ctx, void *ap);
extern void insert_signature_appearance_layers(fz_context *ctx, pdf_document *doc, pdf_annot *annot);
extern void fz_drop_device(fz_context *ctx, fz_device *dev);
extern void fz_drop_display_list(fz_context *ctx, fz_display_list *dlist);
extern void font_info_fin(fz_context *ctx, font_info *font_rec);
extern void fz_drop_path(fz_context *ctx, fz_path *path);
extern void fz_drop_buffer(fz_context *ctx, fz_buffer *buf);

#define fz_var(x)
#define fz_try(ctx)
#define fz_always(ctx)
#define fz_catch(ctx)
#define fz_rethrow(ctx)