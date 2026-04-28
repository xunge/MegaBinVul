#include <stdint.h>
#include <limits.h>
#include <stddef.h>

#define TIFFTAG_IMAGEWIDTH 256
#define TIFFTAG_IMAGELENGTH 257
#define TIFFTAG_ORIENTATION 274
#define CAIRO_FORMAT_RGB24 0

typedef struct _cairo_surface cairo_surface_t;
struct _cairo_user_data_key {
    int unused;
};
typedef struct _cairo_user_data_key cairo_user_data_key_t;
typedef void (*cairo_destroy_func_t)(void *data);
typedef unsigned char guchar;
typedef int gint;
typedef unsigned int guint32;
typedef unsigned char guint8;
typedef uint32_t uint32;

typedef struct {
    void *tiff;
} TiffDocument;
typedef struct {} EvDocument;
typedef struct {
    struct {
        int index;
    } *page;
    int rotation;
} EvRenderContext;

enum {
    ORIENTATION_TOPLEFT = 1
};

#define TIFF_DOCUMENT(obj) ((TiffDocument *)(obj))
#define TIFF_IS_DOCUMENT(obj) (1)
#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)

static inline guint8 TIFFGetR(guint32 pixel) { return (pixel >> 0) & 0xff; }
static inline guint8 TIFFGetG(guint32 pixel) { return (pixel >> 8) & 0xff; }
static inline guint8 TIFFGetB(guint32 pixel) { return (pixel >> 16) & 0xff; }
static inline guint8 TIFFGetA(guint32 pixel) { return (pixel >> 24) & 0xff; }

void push_handlers(void);
void pop_handlers(void);
void g_warning(const char *format, ...);
void *g_try_malloc(size_t n_bytes);
void g_free(void *mem);
int TIFFSetDirectory(void *tiff, int directory);
int TIFFGetField(void *tiff, int tag, ...);
int TIFFReadRGBAImageOriented(void *tiff, int width, int height, uint32_t *raster, int orientation, int stop);
void tiff_document_get_resolution(TiffDocument *tiff_document, float *x_res, float *y_res);
int cairo_format_stride_for_width(int format, int width);
cairo_surface_t *cairo_image_surface_create_for_data(void *data, int format, int width, int height, int stride);
void cairo_surface_set_user_data(cairo_surface_t *surface, const cairo_user_data_key_t *key, void *user_data, cairo_destroy_func_t destroy);
void cairo_surface_destroy(cairo_surface_t *surface);
void ev_render_context_compute_scaled_size(EvRenderContext *rc, int width, int height, int *scaled_width, int *scaled_height);
cairo_surface_t *ev_document_misc_surface_rotate_and_scale(cairo_surface_t *surface, int scaled_width, int scaled_height, int rotation);