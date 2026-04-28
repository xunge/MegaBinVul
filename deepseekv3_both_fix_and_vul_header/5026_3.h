#include <stdint.h>
#include <stddef.h>

typedef struct _GSManager GSManager;
typedef struct _GSWindow GSWindow;
typedef struct _GSManagerPrivate GSManagerPrivate;
typedef struct _cairo_surface cairo_surface_t;
typedef void* gpointer;
typedef int gint;

#define FALSE 0

struct _GSManagerPrivate {
    gpointer bg;
};

struct _GSManager {
    GSManagerPrivate *priv;
};

typedef void GdkDisplay;
typedef void GdkScreen;

void mate_bg_load_from_preferences(gpointer bg);
cairo_surface_t *mate_bg_create_surface(gpointer bg, void *window, int width, int height, int flag);
GdkDisplay *gs_window_get_display(GSWindow *window);
void *gs_window_get_gdk_window(GSWindow *window);
void gs_window_set_background_surface(GSWindow *window, cairo_surface_t *surface);
void gs_debug(const char *format, ...);
GdkScreen *gdk_display_get_default_screen(GdkDisplay *display);
int gdk_window_get_scale_factor(void *window);
void *gdk_screen_get_root_window(GdkScreen *screen);
void *gdk_x11_screen_get_xscreen(GdkScreen *screen);
int WidthOfScreen(void *xscreen);
int HeightOfScreen(void *xscreen);
void cairo_surface_destroy(cairo_surface_t *surface);