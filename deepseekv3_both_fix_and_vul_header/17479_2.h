#include <stdlib.h>
#include <stdint.h>

typedef struct _LZWDecoder LZWDecoder;
typedef struct _GdkPixbufGifAnim GdkPixbufGifAnim;
typedef struct _GdkPixbufFrame GdkPixbufFrame;
typedef struct _GByteArray GByteArray;

#define GDK_COLORSPACE_RGB 0
#define GDK_PIXBUF_FRAME_REVERT 0
#define TRUE 1
#define FALSE 0

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint;
typedef size_t gsize;
typedef unsigned char guchar;

struct _GByteArray {
    guint8 *data;
    gsize len;
};

struct _GdkPixbufFrame {
    int width;
    int height;
    int x_offset;
    int y_offset;
    int interlace;
    guint8 lzw_code_size;
    guint8 transparent_index;
    guint8 *color_map;
    GByteArray *lzw_data;
    int action;
};

struct _GdkPixbufGifAnim {
    int width;
    int height;
    void *last_frame_data;
    void *last_frame_revert_data;
    GdkPixbufFrame *last_frame;
};

LZWDecoder* lzw_decoder_new(int code_size);
gsize lzw_decoder_feed(LZWDecoder *decoder, const guint8 *data, gsize len, guint8 *buffer, gsize buffer_size);
void* gdk_pixbuf_new(int colorspace, int has_alpha, int bits_per_sample, int width, int height);
void gdk_pixbuf_copy_area(void *src_pixbuf, int src_x, int src_y, int width, int height, void *dest_pixbuf, int dest_x, int dest_y);
guchar* gdk_pixbuf_get_pixels(void *pixbuf);
int gdk_pixbuf_get_rowstride(void *pixbuf);
void g_clear_object(void *object);
void* g_malloc(size_t size);
void g_free(void *ptr);

#define g_new(type, count) ((type*)g_malloc(sizeof(type) * (count)))