#include <stddef.h>

typedef struct _GSManager GSManager;
typedef struct _GSManagerPrivate GSManagerPrivate;
typedef struct _GdkDisplay GdkDisplay;
typedef struct _GdkMonitor GdkMonitor;
typedef struct _GdkScreen GdkScreen;
typedef void* gpointer;
typedef struct _GList GList;

struct _GSManagerPrivate {
    GList *windows;
};

struct _GSManager {
    GSManagerPrivate *priv;
};

#define GS_IS_MANAGER(obj) (1)
#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
#define g_assert(expr) do { if (!(expr)) return; } while (0)
#define G_CALLBACK(func) ((void (*)(void))(func))

void gs_manager_create_windows_for_display(GSManager *manager, GdkDisplay *display);
void on_display_monitor_added(GdkDisplay *display, GdkMonitor *monitor, gpointer user_data);
void on_display_monitor_removed(GdkDisplay *display, GdkMonitor *monitor, gpointer user_data);
void on_screen_monitors_changed(GdkScreen *screen, gpointer user_data);
GdkDisplay* gdk_display_get_default(void);
GdkScreen* gdk_display_get_default_screen(GdkDisplay *display);
void g_signal_connect(gpointer instance, const char *signal, void (*handler)(void), gpointer data);