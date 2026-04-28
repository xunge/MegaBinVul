#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define ICO_PNG_MAGIC 0x474E5089
#define ICO_MAXBUF 256
#define TRUE true
#define FALSE false

typedef int32_t gint32;
typedef uint32_t guint32;
typedef unsigned char guchar;
typedef char gchar;
typedef int gint;
typedef bool gboolean;

typedef struct {
    gint32 offset;
} IcoLoadInfo;

typedef struct {
    gint width;
    gint height;
} GimpDrawable;

typedef struct {
    gint dummy1;
    gint dummy2;
} GimpPixelRgn;

#define GIMP_RGBA_IMAGE 0
#define GIMP_NORMAL_MODE 0

gint32 ico_read_int32(FILE *fp, guint32 *first_bytes, gint count);
gboolean ico_read_png(FILE *fp, guint32 first_bytes, guchar *buffer, gint maxsize, gint *width, gint *height);
gboolean ico_read_icon(FILE *fp, guint32 first_bytes, guchar *buffer, gint maxsize, gint *width, gint *height);

gint32 gimp_layer_new(gint32 image, const gchar *name, gint width, gint height, gint type, gint opacity, gint mode);
void gimp_image_insert_layer(gint32 image, gint32 layer, gint position, gint parent);
GimpDrawable* gimp_drawable_get(gint32 layer);
void gimp_pixel_rgn_init(GimpPixelRgn *rgn, GimpDrawable *drawable, gint x, gint y, gint width, gint height, gboolean dirty, gboolean shadow);
void gimp_pixel_rgn_set_rect(GimpPixelRgn *rgn, const guchar *data, gint x, gint y, gint width, gint height);
void gimp_drawable_detach(GimpDrawable *drawable);

int g_snprintf(char *str, size_t size, const char *format, ...);
const char* _(const char *str);