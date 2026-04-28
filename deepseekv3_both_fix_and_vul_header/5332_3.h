#include <limits.h>
#include <stdint.h>
#include <stddef.h>

typedef void* TIFF;
typedef unsigned int uint32;
typedef unsigned char guchar;
typedef int gint;
typedef int gboolean;
typedef unsigned long GType;

#define TIFFTAG_IMAGEWIDTH 0
#define TIFFTAG_IMAGELENGTH 1
#define ORIENTATION_TOPLEFT 1
#define TRUE 1
#define FALSE 0
#define NULL ((void*)0)

typedef struct {
    void* parent_instance;
    TIFF *tiff;
} TiffDocument;

typedef struct {
    int index;
} EvPage;

typedef struct {
    EvPage *page;
    int rotation;
} EvRenderContext;

typedef struct {
    void* parent_class;
} EvDocumentClass;

typedef struct {
    void* parent_instance;
} EvDocument;

typedef struct {
    void* dummy;
} GdkPixbuf;

typedef void (*GdkPixbufDestroyNotify)(guchar* pixels, void* data);

#define TIFF_DOCUMENT(obj) ((TiffDocument*)(obj))
#define GDK_COLORSPACE_RGB 0
#define GDK_INTERP_BILINEAR 0

int TIFFSetDirectory(TIFF* tiff, int directory);
int TIFFGetField(TIFF* tiff, int tag, ...);
int TIFFReadRGBAImageOriented(TIFF* tiff, int width, int height, uint32* raster, int orientation, int stop);

GType tiff_document_get_type(void);
void tiff_document_get_resolution(TiffDocument *tiff_document, float *x_res, float *y_res);
void push_handlers(void);
void pop_handlers(void);
void* g_try_malloc(size_t size);
void g_free(void* ptr);
void g_object_unref(void* object);
void ev_render_context_compute_scaled_size(EvRenderContext *rc, int width, int height, int *scaled_width, int *scaled_height);
GdkPixbuf* gdk_pixbuf_new_from_data(const guchar *data, int colorspace, gboolean has_alpha, int bits_per_sample, int width, int height, int rowstride, GdkPixbufDestroyNotify destroy_fn, void *user_data);
GdkPixbuf* gdk_pixbuf_scale_simple(const GdkPixbuf *src, int dest_width, int dest_height, int interp_type);
GdkPixbuf* gdk_pixbuf_rotate_simple(const GdkPixbuf *src, int angle);