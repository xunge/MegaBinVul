#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef bool gboolean;
typedef double gdouble;
typedef int gint;
typedef unsigned char guchar;

#define FALSE false
#define TRUE true

typedef enum {
    CAIRO_FORMAT_ARGB32,
    CAIRO_FORMAT_A8
} cairo_format_t;

typedef struct {
    int width;
    int height;
    cairo_format_t format;
    int stride;
    unsigned char* data;
} cairo_surface_t;

typedef struct {
    cairo_surface_t* target;
} cairo_t;

static void cairo_surface_flush(cairo_surface_t* surface) {}
static int cairo_image_surface_get_width(cairo_surface_t* surface) { return surface->width; }
static int cairo_image_surface_get_height(cairo_surface_t* surface) { return surface->height; }
static cairo_format_t cairo_image_surface_get_format(cairo_surface_t* surface) { return surface->format; }
static int cairo_image_surface_get_stride(cairo_surface_t* surface) { return surface->stride; }
static unsigned char* cairo_image_surface_get_data(cairo_surface_t* surface) { return surface->data; }
static void cairo_surface_mark_dirty(cairo_surface_t* surface) {}

static cairo_t* cairo_create(cairo_surface_t* surface) { return NULL; }
static void cairo_set_source_surface(cairo_t* cr, cairo_surface_t* surface, int x, int y) {}
static void cairo_paint(cairo_t* cr) {}
static void cairo_destroy(cairo_t* cr) {}

static void* g_new0(size_t size, size_t count) {
    return calloc(count, size);
}

#define g_new0(type, count) ((type*)g_new0(sizeof(type), (count)))

static void g_free(void* ptr) {
    free(ptr);
}

static void g_assert(int condition) {
    assert(condition);
}

static void g_assert_not_reached() {
    assert(0);
}

static void box_blur_line(gint width, gint offset, const guchar *in, guchar *out, gint len, gint bpp) {}
static void gaussian_blur_line(const gdouble *matrix, gint len, const guchar *in, guchar *out, gint width, gint bpp) {}
static void make_gaussian_convolution_matrix(gdouble radius, gdouble **matrix, gint *matrix_len) {}
static gint compute_box_blur_width(gdouble radius) { return 0; }
static void get_column(guchar *col, const guchar *data, gint stride, gint bpp, gint height, gint x) {}
static void put_column(const guchar *col, guchar *data, gint stride, gint bpp, gint height, gint x) {}