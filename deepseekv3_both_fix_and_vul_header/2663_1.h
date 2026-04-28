#include <stdlib.h>
#include <string.h>

typedef struct fz_context fz_context;
typedef struct fz_xml fz_xml;
typedef struct fz_font fz_font;
typedef struct fz_text fz_text;
typedef struct fz_link fz_link;
typedef struct fz_matrix { float a, b, c, d, e, f; } fz_matrix;
typedef struct fz_rect { float x0, y0, x1, y1; } fz_rect;
typedef struct xps_document xps_document;
typedef struct xps_resource xps_resource;

extern char *fz_xml_att(fz_xml *node, const char *att);
extern fz_xml *fz_xml_down(fz_xml *node);
extern fz_xml *fz_xml_find_down(fz_xml *node, const char *tag);
extern float fz_atof(const char *s);
extern void xps_resolve_resource_reference(fz_context *ctx, xps_document *doc, xps_resource *dict, char **att, fz_xml **tag, fz_xml **root);
extern void xps_parse_transform(fz_context *ctx, xps_document *doc, char *att, fz_xml *tag, fz_matrix *local_ctm, const fz_matrix *ctm);
extern fz_font *xps_lookup_font(fz_context *ctx, xps_document *doc, char *base_uri, char *font_uri_att, char *style_att);
extern fz_text *xps_parse_glyphs_imp(fz_context *ctx, xps_document *doc, fz_matrix *local_ctm, fz_font *font, float size, float originx, float originy, int is_sideways, int bidi_level, char *indices_att, char *unicode_att);
extern void fz_bound_text(fz_context *ctx, fz_text *text, fz_font *font, fz_matrix *ctm, fz_rect *area);
extern void fz_drop_text(fz_context *ctx, fz_text *text);
extern void fz_drop_font(fz_context *ctx, fz_font *font);
extern void xps_add_link(fz_context *ctx, xps_document *doc, fz_rect *area, char *base_uri, char *navigate_uri_att, fz_link **link);