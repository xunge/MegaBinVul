#include <stdio.h>
#include <stdlib.h>

#define DEBUG(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)

#define GTK_RESPONSE_OK 1
#define RESPONSE_RUN 1
#define RESPONSE_MARK_TRUSTED 2
#define TRUE 1
#define FALSE 0
#define NAUTILUS_METADATA_KEY_DESKTOP_FILE_TRUSTED "metadata::trusted"

typedef int gboolean;
typedef struct _GtkDialog GtkDialog;
typedef struct _GdkScreen GdkScreen;
typedef struct _GtkWidget GtkWidget;
typedef struct _GtkWindow GtkWindow;
typedef struct _GFile GFile;
typedef struct _NautilusFile NautilusFile;
typedef struct _GError GError;
typedef struct _GClosure GClosure;

#define GTK_WIDGET(w) ((GtkWidget*)(w))

typedef struct {
    GtkWindow *parent_window;
    NautilusFile *file;
} ActivateParametersDesktop;

void nautilus_file_set_metadata(NautilusFile *file, const char *key, const char *value, const char *default_value);
void nautilus_file_mark_desktop_file_executable(GFile *file, GtkWindow *parent, gboolean show_error, GError **error, GClosure *done_callback);
void nautilus_file_invalidate_all_attributes(NautilusFile *file);
GFile* nautilus_file_get_location(NautilusFile *file);
char* nautilus_file_get_uri(NautilusFile *file);
void nautilus_launch_desktop_file(GdkScreen *screen, const char *uri, const char *working_directory, GtkWindow *parent_window);
void nautilus_file_mark_desktop_file_trusted(GFile *file, GtkWindow *parent, gboolean show_error, GError **error, GClosure *done_callback);
void gtk_widget_destroy(GtkWidget *widget);
GdkScreen* gtk_widget_get_screen(GtkWidget *widget);
void g_free(void *ptr);
void g_object_unref(void *object);
void activate_parameters_desktop_free(ActivateParametersDesktop *parameters);