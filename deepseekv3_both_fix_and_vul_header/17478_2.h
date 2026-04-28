#include <string.h>
#include <stddef.h>
#include <stdint.h>

typedef struct _GList {
    void *data;
    struct _GList *next;
} GList;

typedef struct _GdkPixbuf {
    int dummy;
} GdkPixbuf;

typedef struct _GdkPixbufAnimationIter {
    int dummy;
} GdkPixbufAnimationIter;

typedef struct _GdkPixbufGifAnim GdkPixbufGifAnim;
typedef struct _GdkPixbufGifAnimIter GdkPixbufGifAnimIter;
typedef struct _GdkPixbufFrame GdkPixbufFrame;

#define GDK_PIXBUF_GIF_ANIM_ITER(obj) ((GdkPixbufGifAnimIter *)obj)
#define GDK_COLORSPACE_RGB 0
#define TRUE 1
#define FALSE 0
#define MIN(a,b) ((a) < (b) ? (a) : (b))

typedef int gboolean;
typedef uint8_t guchar;
typedef size_t gsize;

enum {
    GDK_PIXBUF_FRAME_RETAIN,
    GDK_PIXBUF_FRAME_DISPOSE,
    GDK_PIXBUF_FRAME_REVERT
};

struct _GdkPixbufFrame {
    int x_offset;
    int y_offset;
    int width;
    int height;
    int action;
    void *data;
};

struct _GdkPixbufGifAnim {
    int width;
    int height;
    GList *frames;
    GdkPixbuf *last_frame_data;
    GdkPixbuf *last_frame_revert_data;
    GdkPixbufFrame *last_frame;
};

struct _GdkPixbufGifAnimIter {
    GdkPixbufAnimationIter parent_instance;
    GdkPixbufGifAnim *gif_anim;
    GList *current_frame;
};

static GList* g_list_last(GList *list) { return NULL; }
static GList* g_list_find(GList *list, void *data) { return NULL; }
static void* g_list_nth_data(GList *list, unsigned int n) { return NULL; }
static GdkPixbuf* gdk_pixbuf_new(int colorspace, gboolean has_alpha, int bits_per_sample, int width, int height) { return NULL; }
static int gdk_pixbuf_get_rowstride(GdkPixbuf *pixbuf) { return 0; }
static guchar* gdk_pixbuf_get_pixels(GdkPixbuf *pixbuf) { return NULL; }
static void gdk_pixbuf_copy_area(GdkPixbuf *src_pixbuf, int src_x, int src_y, int width, int height, GdkPixbuf *dest_pixbuf, int dest_x, int dest_y) {}
static int g_size_checked_mul(gsize *dest, gsize a, gsize b) { return 0; }
static void composite_frame(GdkPixbufGifAnim *anim, GdkPixbufFrame *frame) {}