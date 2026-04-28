#include <stddef.h>

typedef struct _cairo_surface cairo_surface_t;
typedef int gint;
#define FALSE 0

struct _GSManagerPrivate {
    void* bg;
};

struct _GSManager {
    struct _GSManagerPrivate *priv;
};

typedef struct _GSManager GSManager;
typedef struct _GSWindow GSWindow;
typedef struct _GdkDisplay GdkDisplay;
typedef struct _GdkScreen GdkScreen;
typedef struct _GdkWindow GdkWindow;

void mate_bg_load_from_preferences(void* bg);
void gs_debug(const char* format, ...);
void gs_window_set_background_surface(GSWindow* window, cairo_surface_t* surface);
GdkDisplay* gs_window_get_display(GSWindow* window);
GdkWindow* gs_window_get_gdk_window(GSWindow* window);
cairo_surface_t* mate_bg_create_surface(void* bg, GdkWindow* window, int width, int height, int is_root);
GdkScreen* gdk_display_get_default_screen(GdkDisplay* display);
GdkWindow* gdk_screen_get_root_window(GdkScreen* screen);
int gdk_window_get_scale_factor(GdkWindow* window);
void* gdk_x11_screen_get_xscreen(GdkScreen* screen);
int WidthOfScreen(void* xscreen);
int HeightOfScreen(void* xscreen);
void cairo_surface_destroy(cairo_surface_t* surface);