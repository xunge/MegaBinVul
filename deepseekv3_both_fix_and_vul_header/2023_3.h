#include <stdio.h>
#include <stdlib.h>

typedef struct _GdkPixbuf GdkPixbuf;
typedef struct _GError GError;
typedef struct _GifContext GifContext;
typedef struct _GdkPixbufAnimation GdkPixbufAnimation;

typedef int gint;
typedef void* gpointer;
typedef int gboolean;

#define TRUE 1
#define FALSE 0
#define g_free free
#define g_object_ref(p) 
#define g_object_unref(p) 
#define g_return_val_if_fail(expr, val) if (!(expr)) return (val)
#define g_set_error_literal(err, domain, code, msg) 
#define GDK_PIXBUF_ANIMATION(x) ((GdkPixbufAnimation*)(x))
#define _(x) x

struct _GifContext {
    FILE *file;
    GError **error;
    gboolean stop_after_first_frame;
    GdkPixbufAnimation *animation;
    char *buf;
};

struct _GdkPixbufAnimation {
    void *frames;
};

enum {
    GDK_PIXBUF_ERROR,
    GDK_PIXBUF_ERROR_INSUFFICIENT_MEMORY,
    GDK_PIXBUF_ERROR_CORRUPT_IMAGE
};

static GifContext* new_context(void) { return NULL; }
static gint gif_main_loop(GifContext* context) { return 0; }
static GdkPixbuf* gdk_pixbuf_animation_get_static_image(GdkPixbufAnimation* anim) { return NULL; }