#include <stdlib.h>

typedef struct fz_context fz_context;
typedef struct fz_matrix fz_matrix;
typedef struct fz_rect fz_rect;
typedef struct fz_xml fz_xml;
typedef struct xps_document xps_document;
typedef struct xps_resource xps_resource;
typedef struct {
    int abort;
} cookie_t;

struct xps_document {
    cookie_t *cookie;
};