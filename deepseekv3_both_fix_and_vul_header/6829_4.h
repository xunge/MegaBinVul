#include <string.h>

typedef struct pdf_obj pdf_obj;
typedef struct pdf_document pdf_document;
typedef struct fz_context fz_context;
typedef struct fz_display_list fz_display_list;
typedef struct fz_device fz_device;
typedef struct fz_text fz_text;
typedef struct fz_colorspace fz_colorspace;

typedef struct {
    float a, b, c, d, e, f;
} fz_matrix;

typedef struct {
    float x, y;
} fz_point;

typedef struct {
    float x0, y0, x1, y1;
} fz_rect;

typedef struct {
    float descent;
} fz_font;

typedef struct {
    int col_size;
    float font_size;
    float col[4];
} da_rec;

typedef struct {
    da_rec da_rec;
    fz_font *font;
} font_info;

typedef struct pdf_page {
    pdf_obj *obj;
} pdf_page;

typedef struct pdf_annot {
    pdf_obj *obj;
    pdf_page *page;
} pdf_annot;

typedef enum {
    PDF_NAME_Resources,
    PDF_NAME_Contents,
    PDF_NAME_DA,
    PDF_NAME_Rect
} PDF_NAME;

#define fz_var(x) (void)(x)
#define fz_try(ctx) if (1)
#define fz_always(ctx) if (1)
#define fz_catch(ctx) if (0)

pdf_obj* pdf_dict_get(fz_context *ctx, pdf_obj *obj, PDF_NAME name);
char* pdf_to_str_buf(fz_context *ctx, pdf_obj *obj);
void pdf_to_rect(fz_context *ctx, pdf_obj *obj, fz_rect *rect);
void pdf_page_transform(fz_context *ctx, pdf_page *page, void *null, fz_matrix *ctm);
void get_font_info(fz_context *ctx, pdf_document *doc, pdf_obj *dr, char *da, font_info *font_rec);
fz_text* layout_text(fz_context *ctx, font_info *font_rec, char *contents, float x, float y);
fz_display_list* fz_new_display_list(fz_context *ctx, void *null);
fz_device* fz_new_list_device(fz_context *ctx, fz_display_list *dlist);
void fz_fill_text(fz_context *ctx, fz_device *dev, fz_text *text, fz_matrix *ctm, fz_colorspace *cs, float *col, float alpha, void *null);
void fz_close_device(fz_context *ctx, fz_device *dev);
void fz_transform_rect(fz_rect *rect, fz_matrix *ctm);
void pdf_set_annot_appearance(fz_context *ctx, pdf_document *doc, pdf_annot *annot, fz_rect *rect, fz_display_list *dlist);
void fz_drop_device(fz_context *ctx, fz_device *dev);
void fz_drop_display_list(fz_context *ctx, fz_display_list *dlist);
void font_info_fin(fz_context *ctx, font_info *font_rec);
void fz_drop_text(fz_context *ctx, fz_text *text);
void fz_drop_colorspace(fz_context *ctx, fz_colorspace *cs);
void fz_rethrow(fz_context *ctx);
fz_colorspace* fz_device_gray(fz_context *ctx);
fz_colorspace* fz_device_rgb(fz_context *ctx);
fz_colorspace* fz_device_cmyk(fz_context *ctx);