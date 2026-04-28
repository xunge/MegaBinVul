#include <stdint.h>
#include <stdlib.h>

typedef int gboolean;
typedef uint8_t guchar;
typedef unsigned int guint;
typedef uint16_t guint16;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} TGAColor;

typedef struct {
    guint size;
    TGAColor *cols;
} TGAColormap;

typedef struct {
    uint8_t cmap_bpp;
    uint16_t cmap_n_colors;
} TGAHeader;

typedef struct {
    guchar *data;
} IOBuffer;

typedef struct {
    TGAHeader *hdr;
    IOBuffer *in;
    guint cmap_size;
    TGAColormap *cmap;
} TGAContext;

#define FALSE 0
#define TRUE 1
#define LE16(x) (x)
#define GDK_PIXBUF_ERROR 0
#define GDK_PIXBUF_ERROR_CORRUPT_IMAGE 0
#define GDK_PIXBUF_ERROR_INSUFFICIENT_MEMORY 0

#define g_return_val_if_fail(expr, val) do { if (!(expr)) return (val); } while (0)
#define g_set_error_literal(err, domain, code, msg) do { if (err) *err = (GError*)1; } while (0)
#define g_try_malloc(size) malloc(size)
#define _(x) x

typedef void GError;

IOBuffer* io_buffer_free_segment(IOBuffer* in, guint size, GError** err);