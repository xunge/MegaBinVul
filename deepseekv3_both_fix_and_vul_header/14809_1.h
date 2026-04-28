#include <stdint.h>
#include <stddef.h>

typedef unsigned char guchar;
typedef unsigned int guint;
typedef int gint;
typedef size_t gsize;
typedef int gboolean;
#define TRUE 1
#define FALSE 0
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)

typedef struct {
    guchar r;
    guchar g;
    guchar b;
    guchar a;
} TGAColor;

typedef struct {
    TGAColor *cols;
} ColorMap;

typedef struct {
    guchar *data;
    gsize size;
} Buffer;

typedef struct {
    gint n_channels;
    gsize bytes;
} PixelBuffer;

typedef struct {
    Buffer *in;
    ColorMap *cmap;
    PixelBuffer *pbuf;
    guchar *pptr;
    gsize pbuf_bytes;
    gsize pbuf_bytes_done;
    gboolean done;
} TGAContext;

static void write_rle_data(TGAContext *ctx, const TGAColor *color, guint *rle_num);
static const TGAColor *colormap_get_color(ColorMap *cmap, guchar index);