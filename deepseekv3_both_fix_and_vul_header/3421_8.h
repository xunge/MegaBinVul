#include <string.h>

typedef struct fz_matrix {
    float a, b, c, d, e, f;
} fz_matrix;

typedef struct fz_rect {
    float x0, y0, x1, y1;
} fz_rect;

typedef struct fz_stroke_state {
    int start_cap;
    int dash_cap;
    int end_cap;
    int linejoin;
    float miterlimit;
    float linewidth;
    float dash_phase;
    int dash_len;
    float dash_list[32];
} fz_stroke_state;

typedef struct fz_xml fz_xml;
typedef struct fz_path fz_path;
typedef struct fz_colorspace fz_colorspace;
typedef struct fz_device fz_device;
typedef struct xps_document xps_document;
typedef struct xps_resource xps_resource;

#define FZ_MAX_COLORS 32
#define FZ_LINEJOIN_MITER_XPS 0
#define FZ_LINEJOIN_ROUND 1
#define FZ_LINEJOIN_BEVEL 2

static const fz_matrix fz_identity = {1, 0, 0, 1, 0, 0};

char *fz_xml_att(fz_xml *item, const char *name);
fz_xml *fz_xml_down(fz_xml *item);
fz_xml *fz_xml_next(fz_xml *item);
const char *fz_xml_tag(fz_xml *item);
float fz_atof(const char *s);
fz_stroke_state *fz_new_stroke_state_with_dash_len(void *ctx, int len);
void fz_concat(fz_matrix *dst, const fz_matrix *one, const fz_matrix *two);
void fz_union_rect(fz_rect *dst, const fz_rect *src);
void fz_free_path(void *ctx, fz_path *path);
void fz_drop_stroke_state(void *ctx, fz_stroke_state *stroke);
void fz_bound_path(void *ctx, fz_path *path, fz_stroke_state *stroke, const fz_matrix *ctm, fz_rect *area);
void fz_fill_path(fz_device *dev, fz_path *path, int even_odd, const fz_matrix *ctm, fz_colorspace *colorspace, float *color, float alpha);
void fz_clip_path(fz_device *dev, fz_path *path, const fz_rect *rect, int even_odd, const fz_matrix *ctm);
void fz_pop_clip(fz_device *dev);
void fz_stroke_path(fz_device *dev, fz_path *path, fz_stroke_state *stroke, const fz_matrix *ctm, fz_colorspace *colorspace, float *color, float alpha);
void fz_clip_stroke_path(fz_device *dev, fz_path *path, const fz_rect *rect, fz_stroke_state *stroke, const fz_matrix *ctm);

void xps_resolve_resource_reference(xps_document *doc, xps_resource *dict, char **attp, fz_xml **tagp, char **urip);
void xps_parse_render_transform(xps_document *doc, char *text, fz_matrix *matrix);
void xps_parse_matrix_transform(xps_document *doc, fz_xml *root, fz_matrix *matrix);
void xps_clip(xps_document *doc, const fz_matrix *ctm, xps_resource *dict, char *clip_att, fz_xml *clip_tag);
fz_path *xps_parse_abbreviated_geometry(xps_document *doc, char *path, int *fill_rule);
fz_path *xps_parse_path_geometry(xps_document *doc, xps_resource *dict, fz_xml *root, int stroking, int *fill_rule);
void xps_add_link(xps_document *doc, const fz_rect *area, char *base_uri, char *navigate_uri_att);
void xps_begin_opacity(xps_document *doc, const fz_matrix *ctm, const fz_rect *area, char *opacity_mask_uri, xps_resource *dict, char *opacity_att, fz_xml *opacity_mask_tag);
void xps_parse_color(xps_document *doc, char *base_uri, char *string, fz_colorspace **csp, float *samples);
void xps_set_color(xps_document *doc, fz_colorspace *colorspace, float *samples);
void xps_parse_brush(xps_document *doc, const fz_matrix *ctm, const fz_rect *area, char *base_uri, xps_resource *dict, fz_xml *root);
void xps_end_opacity(xps_document *doc, char *base_uri, xps_resource *dict, char *opacity_att, fz_xml *opacity_mask_tag);
int xps_parse_line_cap(char *att);

struct xps_document {
    void *ctx;
    fz_device *dev;
    fz_colorspace *colorspace;
    float color[FZ_MAX_COLORS];
    float alpha;
};

void xps_parse_path(xps_document *doc, const fz_matrix *ctm, char *base_uri, xps_resource *dict, fz_xml *root);