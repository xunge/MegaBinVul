#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef int32_t gint;
typedef bool gboolean;

#define FALSE false
#define TRUE true
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)

typedef struct {
    guint8 type;
    gboolean has_cmap;
    guint8 cmap_bpp;
    guint16 cmap_n_colors;
    guint8 bpp;
    guint16 width;
    guint16 height;
    guint8 flags;
} TGAHeader;

typedef struct {
    void* pixels;
    int rowstride;
    int width;
    int height;
} GdkPixbuf;

typedef struct {
    int domain;
    int code;
    char* message;
} GError;

typedef struct {
    TGAHeader *hdr;
    gboolean run_length_encoded;
    guint cmap_size;
    GdkPixbuf *pbuf;
    unsigned char *pptr;
    gint rowstride;
    guint pbuf_bytes;
    guint completed_lines;
    void (*sfunc)(gint*, gint*, void*);
    void *udata;
} TGAContext;

#define TGA_TYPE_RLE_PSEUDOCOLOR 9
#define TGA_TYPE_RLE_TRUECOLOR 10
#define TGA_TYPE_RLE_GRAYSCALE 11
#define TGA_TYPE_PSEUDOCOLOR 1
#define TGA_TYPE_GRAYSCALE 3
#define TGA_TYPE_TRUECOLOR 2
#define TGA_ORIGIN_UPPER 0x20

#define LE16(x) (x)
#define GDK_PIXBUF_ERROR 0
#define GDK_PIXBUF_ERROR_INSUFFICIENT_MEMORY 1
#define _(x) x

static void g_set_error_literal(GError** err, int domain, int code, const char* message) {}
static GdkPixbuf* get_contiguous_pixbuf(guint w, guint h, gboolean alpha) { return NULL; }