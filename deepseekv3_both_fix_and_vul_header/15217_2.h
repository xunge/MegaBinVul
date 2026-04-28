#include <math.h>
#include <string.h>
#include <stdlib.h>

typedef struct _PopplerPage PopplerPage;
typedef struct _OutputDevData OutputDevData;
typedef struct _CairoOutputDev CairoOutputDev;
typedef struct _cairo_surface cairo_surface_t;
typedef struct _cairo cairo_t;

#define CAIRO_FORMAT_ARGB32 0
#define guchar unsigned char
#define gboolean int

struct _PopplerPage {
    struct {
        int (*getRotate)(void);
        double (*getCropWidth)(void);
        double (*getCropHeight)(void);
    } *page;
    struct {
        CairoOutputDev *output_dev;
    } *document;
};

struct _CairoOutputDev {
    void (*setCairo)(cairo_t *cairo);
};

struct _OutputDevData {
    unsigned char *cairo_data;
    cairo_surface_t *surface;
    cairo_t *cairo;
};

void *gmalloc(size_t size);
cairo_surface_t *cairo_image_surface_create_for_data(void *data, int format, int width, int height, int stride);
cairo_t *cairo_create(cairo_surface_t *surface);