#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef int32_t gint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef unsigned char guchar;
typedef char gchar;
typedef int GError;
typedef int GFileError;
typedef size_t gsize;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct {
    void* unused;
} GimpDrawable;

typedef struct {
    void* unused;
} GimpPixelRgn;

#define GIMP_MAX_IMAGE_SIZE 32768
#define G_MAXSIZE SIZE_MAX
#define GIMP_RGB 0
#define GIMP_INDEXED 1
#define GIMP_RGB_IMAGE 0
#define GIMP_INDEXED_IMAGE 1
#define GIMP_NORMAL_MODE 0
#define G_FILE_ERROR 0
#define G_FILE_ERROR_FAILED 0

typedef struct {
    int manufacturer;
    int x1;
    int y1;
    int x2;
    int y2;
    int bytesperline;
    int bpp;
    int planes;
    unsigned char colormap[48];
} pcx_header_t;

static pcx_header_t pcx_header;
static const unsigned char mono[6] = {0, 0, 0, 255, 255, 255};

#define GUINT16_FROM_LE(x) (x)
#define _(x) x

#define g_new(type, size) ((type*)malloc((size)*sizeof(type)))
#define g_free(ptr) free(ptr)

FILE* g_fopen(const char* filename, const char* mode);
void g_set_error(GError** error, int domain, int code, const char* format, ...);
int g_file_error_from_errno(int errno_val);
char* gimp_filename_to_utf8(const char* filename);
char* g_strerror(int errno_val);
void gimp_progress_init_printf(const char* format, ...);
void pcx_header_from_buffer(unsigned char* buf);
void g_message(const char* format, ...);
gint32 gimp_image_new(gint32 width, gint32 height, gint32 type);
gint32 gimp_layer_new(gint32 image, const char* name, gint32 width, gint32 height, gint32 type, gint32 opacity, gint32 mode);
void gimp_image_set_filename(gint32 image, const char* filename);
void gimp_image_add_layer(gint32 image, gint32 layer, gint32 position);
void gimp_layer_set_offsets(gint32 layer, guint16 x, guint16 y);
GimpDrawable* gimp_drawable_get(gint32 layer);
void load_1(FILE* fd, gint32 width, gint32 height, guchar* dest, guint16 bytesperline);
void load_4(FILE* fd, gint32 width, gint32 height, guchar* dest, guint16 bytesperline);
void load_8(FILE* fd, gint32 width, gint32 height, guchar* dest, guint16 bytesperline);
void load_24(FILE* fd, gint32 width, gint32 height, guchar* dest, guint16 bytesperline);
void gimp_image_set_colormap(gint32 image, const guchar* cmap, gint32 num_colors);
void gimp_pixel_rgn_init(GimpPixelRgn* pixel_rgn, GimpDrawable* drawable, gint32 x, gint32 y, gint32 width, gint32 height, gboolean dirty, gboolean shadow);
void gimp_pixel_rgn_set_rect(GimpPixelRgn* pixel_rgn, guchar* data, gint32 x, gint32 y, gint32 width, gint32 height);
void gimp_drawable_flush(GimpDrawable* drawable);
void gimp_drawable_detach(GimpDrawable* drawable);