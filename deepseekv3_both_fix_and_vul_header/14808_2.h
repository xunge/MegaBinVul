#include <stdint.h>
#include <stdlib.h>

#define gboolean int
#define TRUE 1
#define FALSE 0
#define gpointer void*
#define guint8 uint8_t
#define gsize size_t
#define g_free free
#define g_return_val_if_fail(cond, val) if (!(cond)) return (val)

typedef struct {
    int code;
    char *message;
} GError;

typedef struct {
    int width;
    int height;
} GdkPixbuf;

typedef struct {
    GdkPixbuf *pbuf;
    gpointer udata;
    void (*ufunc)(GdkPixbuf*, int, int, int, int, gpointer);
    gboolean run_length_encoded;
    struct {
        guint8 flags;
    } *hdr;
    struct {
        guint8 *cols;
    } *cmap;
    struct {
        gsize size;
    } *in;
} TGAContext;

typedef struct {
    gsize size;
} IOBuffer;

#define TGA_ORIGIN_UPPER 0x20

static IOBuffer* io_buffer_free_segment(IOBuffer *buf, gsize size, GError **err);
static void io_buffer_free(IOBuffer *buf);
static void pixbuf_flip_vertically(GdkPixbuf *pbuf);
static void g_object_unref(void *obj);