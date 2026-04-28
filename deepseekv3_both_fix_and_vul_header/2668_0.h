#include <string.h>

typedef struct fz_context fz_context;
typedef struct fz_device fz_device;
typedef struct fz_xml fz_xml;
typedef struct xps_document xps_document;
typedef struct xps_resource xps_resource;

struct xps_document {
    fz_device *dev;
    int opacity_top;
};