#include <stdlib.h>
#include <string.h>
#include <math.h>

#define FZ_MAX_COLORS 32

typedef struct fz_context fz_context;
typedef struct fz_device fz_device;
typedef struct fz_font fz_font;
typedef struct fz_text fz_text;
typedef struct fz_xml fz_xml;
typedef struct fz_colorspace fz_colorspace;
typedef struct xps_document xps_document;
typedef struct xps_resource xps_resource;

typedef struct {
    float a, b, c, d, e, f;
} fz_matrix;

typedef struct {
    float x0, y0, x1, y1;
} fz_rect;

struct xps_document {
    fz_device *dev;
    fz_colorspace *colorspace;
    float color[FZ_MAX_COLORS];
    float alpha;
};

char *fz_xml_att(fz_xml *node, const char *name);
fz_xml *fz_xml_down(fz_xml *node);
fz_xml *fz_xml_next(fz_xml *node);
int fz_xml_is_tag(fz_xml *node, const char *name);
const char *fz_xml_tag(fz_xml *node);
float fz_atof(const char *s);
void fz_warn(fz_context *ctx, const char *fmt, ...);
void fz_bound_text(fz_context *ctx, fz_text *text, void *font, fz_matrix *ctm, fz_rect *area);
void fz_fill_text(fz_context *ctx, fz_device *dev, fz_text *text, fz_matrix *ctm, fz_colorspace *colorspace, float *color, float alpha, void *bbox);
void fz_clip_text(fz_context *ctx, fz_device *dev, fz_text *text, fz_matrix *ctm, fz_rect *area);
void fz_pop_clip(fz_context *ctx, fz_device *dev);
void fz_drop_text(fz_context *ctx, fz_text *text);
void fz_drop_font(fz_context *ctx, fz_font *font);

fz_font *xps_lookup_font(fz_context *ctx, xps_document *doc, char *base_uri, char *font_uri, char *style);
void xps_parse_transform(fz_context *ctx, xps_document *doc, char *att, fz_xml *tag, fz_matrix *local_ctm, const fz_matrix *ctm);
void xps_clip(fz_context *ctx, xps_document *doc, fz_matrix *ctm, xps_resource *dict, char *att, fz_xml *tag);
fz_text *xps_parse_glyphs_imp(fz_context *ctx, xps_document *doc, fz_matrix *ctm, fz_font *font, float size, float x, float y, int sideways, int bidi, char *indices, char *unicode);
void xps_begin_opacity(fz_context *ctx, xps_document *doc, fz_matrix *ctm, fz_rect *area, char *mask_uri, xps_resource *dict, char *opacity_att, fz_xml *opacity_mask_tag);
void xps_parse_color(fz_context *ctx, xps_document *doc, char *base_uri, char *color_string, fz_colorspace **csp, float *samples);
void xps_set_color(fz_context *ctx, xps_document *doc, fz_colorspace *colorspace, float *samples);
void xps_parse_brush(fz_context *ctx, xps_document *doc, fz_matrix *ctm, fz_rect *area, char *base_uri, xps_resource *dict, fz_xml *root);
void xps_end_opacity(fz_context *ctx, xps_document *doc, char *mask_uri, xps_resource *dict, char *opacity_att, fz_xml *opacity_mask_tag);
void xps_resolve_resource_reference(fz_context *ctx, xps_document *doc, xps_resource *dict, char **attp, fz_xml **tagp, char **urip);