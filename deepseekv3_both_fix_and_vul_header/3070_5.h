#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TRUE true
#define FALSE false
typedef bool gboolean;

typedef enum {
    FR_OVERWRITE_ASK,
    FR_OVERWRITE_YES
} FrOverwrite;

typedef struct {
    void *data;
} FileData;

typedef struct {
    FrOverwrite overwrite;
    char *base_dir;
    bool junk_paths;
    void *destination;
    void *file_list;
} ExtractData;

typedef struct {
    void *cancellable;
} WindowPriv;

typedef struct {
    WindowPriv *priv;
} Window;

typedef struct {
    Window *window;
    ExtractData *edata;
    FileData *current_file;
    bool extract_all;
} OverwriteData;

typedef void GFile;
typedef void GtkWidget;
typedef void GtkWindow;
typedef void GtkDialog;

#define G_FILE_ATTRIBUTE_STANDARD_TYPE "standard::type"
#define G_FILE_ATTRIBUTE_STANDARD_NAME "standard::name"
#define G_FILE_ATTRIBUTE_STANDARD_DISPLAY_NAME "standard::display-name"
#define G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS 0
#define G_PRIORITY_DEFAULT 0
#define GTK_STOCK_DIALOG_WARNING "gtk-dialog-warning"
#define GTK_STOCK_OK "gtk-ok"
#define GTK_RESPONSE_OK 0
#define GTK_WINDOW(x) ((GtkWindow*)(x))
#define GTK_DIALOG(x) ((GtkDialog*)(x))
#define _(x) (x)

void query_info_ready_for_overwrite_dialog_cb(void *source, void *result, void *user_data);
void _fr_window_archive_extract_from_edata(void *window, ExtractData *edata);
void fr_window_show_error_dialog(void *window, void *dialog, void *parent, const char *message);
void fr_window_stop_batch(void *window);
char *_g_path_get_relative_basename_safe(char *path, const char *base_dir, bool junk_paths);
char *_g_path_get_relative_basename(char *path, const char *base_dir, bool junk_paths);
void _g_string_list_free(void *list);
GtkWidget *_gtk_message_dialog_new(GtkWindow *parent, int flags, const char *image_stock_id, const char *primary_text, const char *secondary_text, const char *first_button_text, int first_response_id, ...);
GFile *g_file_get_child(void *parent, const char *name);
void g_file_query_info_async(GFile *file, const char *attributes, int flags, int priority, void *cancellable, void *callback, void *user_data);
void g_object_unref(void *object);
void gtk_dialog_set_default_response(GtkDialog *dialog, int response);
void g_free(void *mem);