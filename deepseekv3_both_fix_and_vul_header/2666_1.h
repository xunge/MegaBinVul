#include <string.h>

typedef struct fz_context fz_context;
typedef struct fz_device fz_device;
typedef struct fz_xml fz_xml;
typedef struct fz_tree fz_tree;

typedef struct {
    float viewbox_w;
    float viewbox_h;
    float fontsize;
    struct {
        float a, b, c, d, e, f;
    } transform;
} svg_state;

typedef struct {
    fz_tree *idmap;
} svg_document;

void svg_parse_common(fz_context *ctx, svg_document *doc, fz_xml *root, svg_state *state);
float svg_parse_length(const char *str, float viewbox, float fontsize);
void fz_pre_translate(void *mat, float x, float y);
fz_xml *fz_tree_lookup(fz_context *ctx, fz_tree *tree, const char *key);
const char *fz_xml_tag(fz_xml *xml);
char *fz_xml_att(fz_xml *xml, const char *att);
void fz_warn(fz_context *ctx, const char *fmt, ...);
void svg_run_use_symbol(fz_context *ctx, fz_device *dev, svg_document *doc, fz_xml *root, fz_xml *linked, svg_state *state);
void svg_run_element(fz_context *ctx, fz_device *dev, svg_document *doc, fz_xml *root, svg_state *state);