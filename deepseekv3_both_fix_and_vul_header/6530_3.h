#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <limits.h>

#define GIMP_MAX_IMAGE_SIZE 100000
#define GBRUSH_MAGIC 0
#define GPATTERN_MAGIC 0
#define _O_BINARY 0
#define G_MAXSIZE SIZE_MAX
#define G_FILE_ERROR 0
#define G_FILE_ERROR_FAILED 1
#define GIMP_PARASITE_PERSISTENT 0
#define GIMP_NORMAL_MODE 0
#define TRUE 1
#define FALSE 0

typedef int32_t gint32;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guchar;
typedef size_t gsize;
typedef char gchar;
typedef int gint;
typedef float gfloat;

typedef struct {
    guint32 header_size;
    guint32 version;
    guint32 width;
    guint32 height;
    guint32 bytes;
    guint32 magic_number;
    guint32 spacing;
} BrushHeader;

typedef struct {
    guint32 header_size;
    guint32 version;
    guint32 width;
    guint32 height;
    guint32 bytes;
    guint32 magic_number;
} PatternHeader;

typedef struct {
    int width;
    int height;
} GimpDrawable;

typedef struct {
    int dummy;
} GimpPixelRgn;

typedef struct {
    int dummy;
} GimpParasite;

typedef struct {
    int dummy;
} GError;

typedef enum {
    GIMP_GRAY,
    GIMP_RGB
} GimpImageBaseType;

typedef enum {
    GIMP_GRAY_IMAGE,
    GIMP_RGBA_IMAGE
} GimpImageType;

static inline uint32_t g_ntohl(uint32_t x) {
    return ((x & 0xFF) << 24) | ((x & 0xFF00) << 8) | 
           ((x & 0xFF0000) >> 8) | ((x & 0xFF000000) >> 24);
}

static inline uint16_t GUINT16_FROM_BE(uint16_t x) {
    return ((x & 0xFF) << 8) | ((x & 0xFF00) >> 8);
}

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define G_BYTE_ORDER 1234
#else
#define G_BYTE_ORDER 4321
#endif

#define _(x) x
#define g_open open
#define g_set_error(err, domain, code, fmt, ...) fprintf(stderr, fmt, __VA_ARGS__)
#define g_file_error_from_errno(err) err
#define gimp_filename_to_utf8(x) x
#define g_strerror strerror
#define gimp_progress_init_printf(fmt, ...) printf(fmt, __VA_ARGS__)
#define g_message(...) fprintf(stderr, __VA_ARGS__)
#define g_new(type, size) malloc(size)
#define g_free free
#define gimp_any_to_utf8(x, y, fmt, ...) strdup(x)
#define g_strdup strdup
#define g_malloc malloc
#define gimp_image_new(w, h, t) 0
#define gimp_image_set_filename(id, name)
#define gimp_parasite_new(name, type, size, data) NULL
#define gimp_image_attach_parasite(id, parasite)
#define gimp_parasite_free(parasite)
#define gimp_layer_new(id, name, w, h, type, opacity, mode) 0
#define gimp_image_insert_layer(id, layer, pos, parent)
#define gimp_drawable_get(id) NULL
#define gimp_pixel_rgn_init(rgn, drawable, x, y, w, h, dirty, shadow)
#define gimp_pixel_rgn_set_rect(rgn, data, x, y, w, h)
#define gimp_invert(id)
#define gimp_drawable_flush(drawable)
#define gimp_progress_update(val)