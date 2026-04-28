#include <stdlib.h>

typedef struct _GSList {
    void *data;
    struct _GSList *next;
} GSList;

typedef struct _GdkDisplay GdkDisplay;
typedef struct _GdkScreen GdkScreen;
typedef struct _GSManager GSManager;
typedef struct _GSManagerPrivate GSManagerPrivate;

struct _GSManager {
    GSManagerPrivate *priv;
};

struct _GSManagerPrivate {
    GSList *windows;
};

#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
#define GS_IS_MANAGER(obj) (1)

void on_display_monitor_removed(GdkDisplay *display, void *monitor, void *user_data);
void on_display_monitor_added(GdkDisplay *display, void *monitor, void *user_data);
void on_screen_monitors_changed(GdkScreen *screen, void *user_data);
void gs_window_destroy(void *data);
void g_signal_handlers_disconnect_by_func(void *instance, void *func, void *user_data);
GdkDisplay *gdk_display_get_default(void);
GdkScreen *gdk_display_get_default_screen(GdkDisplay *display);
void g_slist_free(GSList *list);