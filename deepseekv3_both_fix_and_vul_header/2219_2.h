#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int guint;
typedef unsigned long gulong;
typedef unsigned char guchar;
typedef char gchar;
typedef long glong;
typedef unsigned short gushort;
typedef unsigned int L_CARD32;
typedef int gint;
typedef int gint32;
typedef double gdouble;

typedef struct {
    gulong l_bytes_per_line;
    gint l_pixmap_width;
    gint l_pixmap_height;
    gint l_pixmap_depth;
    gulong l_red_mask;
    gulong l_green_mask;
    gulong l_blue_mask;
    gint l_colormap_entries;
    gint l_ncolors;
    gint l_bitmap_bit_order;
    gint l_bitmap_unit;
    gint l_byte_order;
} L_XWDFILEHEADER;

typedef struct {
    gulong pixel;
    gushort red;
    gushort green;
    gushort blue;
    guchar flags;
    guchar pad;
} L_XWDCOLOR;

typedef struct {
    gulong *pixels;
    guchar *red;
    guchar *green;
    guchar *blue;
    gint size;
} PIXEL_MAP;

typedef struct {
    /* Minimal GimpPixelRgn structure definition */
    gint dummy;
} GimpPixelRgn;

typedef struct _GimpDrawable GimpDrawable;
typedef struct _GError GError;

#define G_FILE_ERROR 0
#define G_FILE_ERROR_FAILED 0
#define GIMP_INDEXED 0
#define GIMP_RGB 0
#define XWD_DEBUG 0

void* g_malloc(size_t size);
void g_free(void* ptr);
void g_set_error(GError** err, int domain, int code, const char* format, ...);
const char* _(const char* str);
const char* gimp_filename_to_utf8(const char* filename);
gint32 create_new_image(const gchar* filename, gint width, gint height, gint type, 
                       gint32* layer_ID, GimpDrawable** drawable, GimpPixelRgn* pixel_rgn);
gint gimp_tile_height(void);
void set_bw_color_table(gint32 image_ID);
void set_color_table(gint32 image_ID, L_XWDFILEHEADER* xwdhdr, L_XWDCOLOR* xwdcolmap);
void set_pixelmap(gint ncols, L_XWDCOLOR* xwdcolmap, PIXEL_MAP* pixel_map);
gint get_pixelmap(L_CARD32 pixelval, PIXEL_MAP* pixel_map, guchar* r, guchar* g, guchar* b);
void gimp_progress_update(gdouble progress);
void gimp_pixel_rgn_set_rect(GimpPixelRgn* pixel_rgn, guchar* data, 
                            gint x, gint y, gint width, gint height);
void g_message(const char* message);
void gimp_drawable_flush(GimpDrawable* drawable);