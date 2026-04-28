typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;
typedef struct _GdkMonitor GdkMonitor;
typedef struct _GdkScreen GdkScreen;

typedef struct _GSWindowPrivate GSWindowPrivate;
typedef struct _GSWindow GSWindow;

struct _GtkWidget {
    void *unused;
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

struct _GtkWidgetClass {
    void (*unrealize)(GtkWidget *widget);
};

extern struct _GtkWidgetClass *gs_window_parent_class;

static void monitor_geometry_notify(GdkMonitor *monitor, GtkWidget *widget) {}
static void screen_size_changed(GdkScreen *screen, GtkWidget *widget) {}
GdkScreen *gtk_window_get_screen(GtkWindow *window) { return 0; }
void g_signal_handlers_disconnect_by_func(void *instance, void *func, void *user_data) {}

#define GS_WINDOW(widget) ((GSWindow *)(widget))
#define GTK_WINDOW(widget) ((GtkWindow *)(widget))
#define GTK_WIDGET_CLASS(class) ((struct _GtkWidgetClass *)(class))