#include <string.h>
#include <stdlib.h>

typedef struct xps_document xps_document;
typedef struct xps_resource xps_resource;
typedef struct fz_xml fz_xml;
typedef struct fz_matrix fz_matrix;
typedef struct fz_rect fz_rect;
typedef struct fz_colorspace fz_colorspace;
typedef struct fz_device fz_device;

#define FZ_MAX_COLORS 32

struct xps_document {
    fz_device *dev;
    float opacity[32];
    int opacity_top;
};

void fz_begin_mask(fz_device *dev, const fz_rect *area, int luminosity, const fz_colorspace *colorspace, const float *color);
void fz_end_mask(fz_device *dev);
float fz_atof(const char *s);
const char *fz_xml_tag(fz_xml *item);
char *fz_xml_att(fz_xml *item, const char *att);
void xps_parse_color(xps_document *doc, char *base_uri, char *string, fz_colorspace **colorspace, float *samples);
void xps_parse_brush(xps_document *doc, const fz_matrix *ctm, const fz_rect *area, char *base_uri, xps_resource *dict, fz_xml *root);

#define nelem(x) (sizeof(x)/sizeof((x)[0]))