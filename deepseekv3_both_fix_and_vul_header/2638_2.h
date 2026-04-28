#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ActivateParameters {
    void *parent_window;
} ActivateParameters;

typedef struct _ActivateParametersDesktop {
    void *parent_window;
    void *file;
} ActivateParametersDesktop;

typedef struct _NautilusFile {
    int dummy;
} NautilusFile;

typedef void* GtkWidget;
typedef void* GdkScreen;
typedef void* GObject;
typedef void* gpointer;

#define RESPONSE_RUN 1
#define RESPONSE_MARK_TRUSTED 2
#define GTK_RESPONSE_CANCEL -6
#define GTK_RESPONSE_OK -5
#define GTK_MESSAGE_WARNING 1
#define GTK_BUTTONS_NONE 0
#define DEBUG(fmt, ...)

#define _(x) x
#define g_new0(type, size) ((type*)calloc(size, sizeof(type)))
#define g_free(ptr) free(ptr)
#define g_strdup_printf(fmt, ...) strdup("")
#define g_object_set(obj, ...)
#define g_signal_connect(obj, sig, cb, data)
#define gtk_widget_show(widget)
#define gtk_message_dialog_new(parent, flags, type, buttons, msg) NULL
#define gtk_dialog_add_button(dialog, text, response)
#define gtk_dialog_set_default_response(dialog, response)
#define gtk_widget_get_screen(widget) NULL
#define GTK_WIDGET(widget) widget
#define G_OBJECT(obj) obj
#define G_CALLBACK(func) func
#define g_object_add_weak_pointer(obj, ptr)

static int nautilus_file_is_trusted_link(NautilusFile *file) { return 0; }
static void* nautilus_file_ref(NautilusFile *file) { return NULL; }
static char* nautilus_file_get_display_name(NautilusFile *file) { return NULL; }
static int nautilus_file_can_set_permissions(NautilusFile *file) { return 0; }
static char* nautilus_file_get_uri(NautilusFile *file) { return NULL; }
static void nautilus_launch_desktop_file(GdkScreen *screen, char *uri, void *a, void *b) {}
static void untrusted_launcher_response_callback(GtkWidget *dialog, int response, void *data) {}