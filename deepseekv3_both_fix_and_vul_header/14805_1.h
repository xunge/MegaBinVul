#include <stdint.h>
#include <stddef.h>

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
    void* data;
    size_t size;
} IOBuffer;

typedef struct {
    uint8_t cmap_bpp;
    uint16_t cmap_n_colors;
} TGAHeader;

typedef struct {
    IOBuffer* in;
    TGAHeader* hdr;
    void* cmap;
    guint cmap_size;
} TGAContext;

typedef struct _GError GError;

#define FALSE 0
#define TRUE 1
#define GDK_PIXBUF_ERROR 0
#define GDK_PIXBUF_ERROR_CORRUPT_IMAGE 0
#define GDK_PIXBUF_ERROR_INSUFFICIENT_MEMORY 0

#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)
#define g_set_error_literal(err, domain, code, msg) 
#define _(x) x
#define LE16(x) (x)