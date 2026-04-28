#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char guchar;
typedef int gint;
typedef unsigned int guint;
typedef unsigned long gulong;
typedef int gint32;
typedef char gchar;
typedef unsigned int L_CARD32;
typedef double gdouble;

#define G_FILE_ERROR 0
#define G_FILE_ERROR_FAILED 1
#define GIMP_RGB 0

typedef struct {
    gint l_pixmap_width;
    gint l_pixmap_height;
    gulong l_red_mask;
    gulong l_green_mask;
    gulong l_blue_mask;
    gint l_colormap_entries;
    gint l_ncolors;
    gint l_bytes_per_line;
    gint l_bits_per_pixel;
    gint l_byte_order;
} L_XWDFILEHEADER;

typedef struct {
    gulong pixel;
    guchar red;
    guchar green;
    guchar blue;
} L_XWDCOLOR;

typedef struct {
    gint count;
    L_XWDCOLOR *colors;
} PIXEL_MAP;

typedef struct {
    gint width;
    gint height;
    gint bpp;
} GimpDrawable;

typedef struct {
    GimpDrawable *drawable;
    gint x;
    gint y;
    gint width;
    gint height;
} GimpPixelRgn;

typedef struct {
    int domain;
    int code;
    char *message;
} GError;

#define _(x) x

static void g_set_error(GError **error, int domain, int code, const char *format, ...) {}
static char *gimp_filename_to_utf8(const char *filename) { return (char*)filename; }
static gint32 create_new_image(const char *filename, gint width, gint height, gint type, gint32 *layer_ID, GimpDrawable **drawable, GimpPixelRgn *pixel_rgn) { return 0; }
static gint gimp_tile_height() { return 1; }
static void *g_malloc(size_t size) { return malloc(size); }
static void g_free(void *ptr) { free(ptr); }
static void set_pixelmap(gint ncols, L_XWDCOLOR *xwdcolmap, PIXEL_MAP *pixel_map) {}
static gint get_pixelmap(L_CARD32 pixelval, PIXEL_MAP *pixel_map, guchar *r, guchar *g, guchar *b) { return 0; }
static void gimp_progress_update(gdouble progress) {}
static void gimp_pixel_rgn_set_rect(GimpPixelRgn *pixel_rgn, guchar *data, gint x, gint y, gint width, gint height) {}
static void g_message(const char *message) {}
static void gimp_drawable_flush(GimpDrawable *drawable) {}