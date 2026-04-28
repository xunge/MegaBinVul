#include <stddef.h>

typedef struct _GSWindow GSWindow;
typedef struct _GdkDisplay GdkDisplay;
typedef struct _GdkMonitor GdkMonitor;
typedef struct _GdkScreen GdkScreen;
typedef int gboolean;
typedef void* GObject;

#define GS_TYPE_WINDOW (0)
#define GS_WINDOW(obj) ((GSWindow*)obj)
#define GTK_WINDOW_POPUP (0)
#define TRUE 1

GdkScreen* gdk_display_get_default_screen(GdkDisplay* display);
GObject* g_object_new(int type, ...);