#include <stdlib.h>
#include <string.h>

typedef struct fz_context fz_context;
typedef struct fz_xml fz_xml;
typedef struct xps_document xps_document;
typedef struct xps_part {
    void *data;
} xps_part;
typedef struct xps_resource {
    fz_xml *base_xml;
} xps_resource;

enum {
    FZ_ERROR_TRYLATER,
    FZ_ERROR_GENERIC
};

#define fz_try(ctx) if (1)
#define fz_always(ctx) if (1)
#define fz_catch(ctx) if (0)

void xps_resolve_url(fz_context *ctx, xps_document *doc, char *part_name, char *base_uri, char *source_att, int size);
xps_part *xps_read_part(fz_context *ctx, xps_document *doc, char *part_name);
void xps_drop_part(fz_context *ctx, xps_document *doc, xps_part *part);
fz_xml *fz_parse_xml(fz_context *ctx, void *data, int options);
void fz_drop_xml(fz_context *ctx, fz_xml *xml);
int fz_xml_is_tag(fz_xml *xml, const char *name);
const char *fz_xml_tag(fz_xml *xml);
void fz_throw(fz_context *ctx, int error_code, const char *message);
void fz_rethrow_if(fz_context *ctx, int error_code);
void fz_strlcpy(char *dst, const char *src, int n);
xps_resource *xps_parse_resource_dictionary(fz_context *ctx, xps_document *doc, char *part_uri, fz_xml *xml);