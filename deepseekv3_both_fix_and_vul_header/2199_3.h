#include <stdio.h>
#include <stddef.h>

typedef void* NPP;

typedef int NPError;
typedef int NPNVariable;
typedef int NPNToolkitType;

#define NPW_TOOLKIT 0
#define NPNVGtk2 0
#define NPERR_NO_ERROR 0
#define NPERR_INVALID_INSTANCE_ERROR 1
#define NPERR_GENERIC_ERROR 2
#define NPERR_INVALID_PARAM 3
#define None 0L

#define NPNVxDisplay 1
#define NPNVxtAppContext 2
#define NPNVToolkit 3
#define NPNVnetscapeWindow 4
#define NPNVSupportsXEmbedBool 5
#define NPNVWindowNPObject 6
#define NPNVPluginElementNPObject 7
#define NPNVprivateModeBool 8
#define NPNVsupportsAdvancedKeyHandling 9

#define D(x) x
#define bug printf
#define npw_printf printf
#define PLUGIN_INSTANCE(x) ((PluginInstance*)(x))
#define USE_XPCOM 0
#define ALLOW_WINDOWLESS_PLUGINS 0

typedef unsigned long GdkNativeWindow;
typedef struct _GdkWindow GdkWindow;

typedef struct PluginInstance {
    GdkWindow* browser_toplevel;
} PluginInstance;

extern void* x_display;
extern void* XtDisplayToApplicationContext(void* display);
extern NPError g_NPN_GetValue_real(NPP instance, NPNVariable variable, void* value);
extern const char* string_of_NPNVariable(NPNVariable variable);
extern int thread_check(void);
extern GdkWindow* gdk_window_foreign_new(GdkNativeWindow xid);
extern unsigned long GDK_WINDOW_XWINDOW(GdkWindow* window);

#if USE_XPCOM
typedef struct nsIServiceManager nsIServiceManager;
#define NS_GetServiceManager(x) 0
#define NS_FAILED(x) (x)
#endif