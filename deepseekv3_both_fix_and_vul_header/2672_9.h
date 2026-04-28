#include <stdlib.h>
#include <string.h>

#define FZ_MAX_COLORS 32
#define FZ_LINEJOIN_MITER_XPS 0
#define FZ_LINEJOIN_ROUND 1
#define FZ_LINEJOIN_BEVEL 2

typedef struct fz_context fz_context;
typedef struct fz_device fz_device;
typedef struct fz_xml fz_xml;
typedef struct fz_path fz_path;
typedef struct fz_colorspace fz_colorspace;

typedef struct xps_document xps_document;
typedef struct xps_resource xps_resource;

struct xps_document {
    fz_device *dev;
    fz_colorspace *colorspace;
    float color[FZ_MAX_COLORS];
    float alpha;
};

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

char *fz_xml_att(fz_xml *node, const char *att);
fz_xml *fz_xml_down(fz_xml *node);
fz_xml *fz_xml_next(fz_xml *node);
int fz_xml_is_tag(fz_xml *node, const char *tag);
const char *fz_xml_tag(fz_xml *node);
float fz_atof(const char *s);
fz_stroke_state *fz_new_stroke_state_with_dash_len(fz_context *ctx, int dash_len);
int xps_parse_line_cap(const char *att);
void xps_resolve_resource_reference(fz_context *ctx, xps_document *doc, xps_resource *dict, char **att, fz_xml **tag, char **base_uri);
void xps_parse_transform(fz_context *ctx, xps_document *doc, char *att, fz_xml *tag, fz_matrix *local_ctm, const fz_matrix *ctm);
void xps_clip(fz_context *ctx, xps_document *doc, fz_matrix *ctm, xps_resource *dict, char *att, fz_xml *tag);
void fz_pop_clip(fz_context *ctx, fz_device *dev);
void fz_drop_path(fz_context *ctx, fz_path *path);
void fz_drop_stroke_state(fz_context *ctx, fz_stroke_state *stroke);

#define fz_try(ctx) do {
#define fz_always(ctx) } while(0); do {
#define fz_catch(ctx) } while(0); if(0)
#define fz_rethrow(ctx) 