#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct {
    uint8_t infolen;
    uint8_t has_cmap;
    uint8_t type;
    uint16_t cmap_start;
    uint16_t cmap_n_colors;
    uint8_t cmap_bpp;
    uint16_t x_origin;
    uint16_t y_origin;
    uint16_t width;
    uint16_t height;
    uint8_t bpp;
    uint8_t flags;
} TGAHeader;

typedef struct {
    void *data;
    size_t size;
} IOBuffer;

typedef struct {
    TGAHeader *hdr;
    IOBuffer *in;
    gboolean skipped_info;
    void *cmap;
    size_t cmap_size;
    gboolean prepared;
    void (*pfunc)(void *, void *, void *);
    void *pbuf;
    void *udata;
} TGAContext;

#define TGA_INTERLEAVE_MASK 0xc0
#define TGA_INTERLEAVE_NONE 0x00

#define TGA_TYPE_PSEUDOCOLOR 1
#define TGA_TYPE_RLE_PSEUDOCOLOR 9
#define TGA_TYPE_TRUECOLOR 2
#define TGA_TYPE_RLE_TRUECOLOR 10
#define TGA_TYPE_GRAYSCALE 3
#define TGA_TYPE_RLE_GRAYSCALE 11

#define LE16(x) (x)

typedef struct {
    int domain;
    int code;
    char *message;
} GError;

#define GDK_PIXBUF_ERROR 0
#define GDK_PIXBUF_ERROR_INSUFFICIENT_MEMORY 0
#define GDK_PIXBUF_ERROR_CORRUPT_IMAGE 0
#define GDK_PIXBUF_ERROR_UNKNOWN_TYPE 0

static void g_set_error_literal(GError **err, int domain, int code, const char *message) {
    if (err) {
        *err = malloc(sizeof(GError));
        (*err)->domain = domain;
        (*err)->code = code;
        (*err)->message = strdup(message);
    }
}

static void *g_try_malloc(size_t size) {
    return malloc(size);
}

static void g_memmove(void *dest, const void *src, size_t n) {
    memmove(dest, src, n);
}

static IOBuffer *io_buffer_free_segment(IOBuffer *in, size_t size, GError **err) {
    // Simplified implementation
    if (in->size < size) return NULL;
    in->data = (char *)in->data + size;
    in->size -= size;
    return in;
}