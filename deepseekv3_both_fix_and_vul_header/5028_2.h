#include <stddef.h>

typedef struct _GSManager GSManager;
typedef struct _GSManagerPrivate GSManagerPrivate;
typedef void* GdkDisplay;
typedef void* GdkMonitor;
typedef void* GdkScreen;
typedef void* gpointer;

struct _GSManager {
    GSManagerPrivate *priv;
};

struct _GSManagerPrivate {
    void *windows;
};

#define g_return_if_fail(expr) 
#define GS_IS_MANAGER(expr) 
#define g_assert(expr) 
#define gdk_display_get_default() NULL
#define g_signal_connect(instance, signal, callback, data) 
#define gdk_display_get_default_screen(display) NULL
#define G_CALLBACK(func) func

static void on_display_monitor_added(GdkDisplay *display, GdkMonitor *monitor, gpointer user_data);
static void on_display_monitor_removed(GdkDisplay *display, GdkMonitor *monitor, gpointer user_data);
static void on_screen_monitors_changed(GdkScreen *screen, gpointer user_data);
static void gs_manager_create_windows_for_display(GSManager *manager, GdkDisplay *display);