typedef struct _GtkWidget GtkWidget;
typedef struct _GdkMonitor GdkMonitor;
typedef struct _GtkWindow GtkWindow;
typedef struct _GtkWidgetClass {
    void (*realize)(GtkWidget *widget);
} GtkWidgetClass;
typedef struct _GSWindowPrivate GSWindowPrivate;
typedef struct _GSWindow GSWindow;

struct _GtkWidget {
    int dummy;
};

struct _GtkWindow {
    struct _GtkWidget widget;
};

struct _GSWindow {
    struct _GtkWindow parent;
    GSWindowPrivate *priv;
};

struct _GSWindowPrivate {
    GdkMonitor *monitor;
};

extern GtkWidgetClass *gs_window_parent_class;

#define GS_WINDOW(obj) ((GSWindow *)(obj))
#define GTK_WIDGET_CLASS(klass) ((GtkWidgetClass *)(klass))
#define GTK_WINDOW(obj) ((GtkWindow *)(obj))
#define TRUE 1
#define FALSE 0

typedef void (*GCallback)(void);
#define G_CALLBACK(f) ((GCallback)(f))

static void monitor_geometry_notify(GdkMonitor *monitor, void *pspec, void *user_data) {}
static void screen_size_changed(void *screen, void *user_data) {}
static void widget_set_best_visual(GtkWidget *widget) {}
static void gs_window_override_user_time(GSWindow *window) {}
static void gs_window_move_resize_window(GSWindow *window, int move, int resize) {}
static void *gtk_window_get_screen(GtkWindow *window) { return 0; }
static void g_signal_connect(void *instance, const char *signal, GCallback callback, void *data) {}