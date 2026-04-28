#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef struct {
    char* message;
} GError;

typedef void* GtkWidget;
typedef void* GtkBuilder;
typedef void* GHashTable;
typedef void* GObject;
typedef void* GtkToggleButton;
typedef void* GtkSpinButton;
typedef void* GtkEntry;
typedef void* GtkWindow;
typedef void* gpointer;

typedef int gboolean;
#define TRUE 1
#define FALSE 0
typedef void (*GDestroyNotify)(void* data);
typedef long gdouble;

#define GTK_WIDGET(x) ((GtkWidget*)x)
#define GTK_BUILDER(x) ((GtkBuilder*)x)
#define GTK_TOGGLE_BUTTON(x) ((GtkToggleButton*)x)
#define GTK_SPIN_BUTTON(x) ((GtkSpinButton*)x)
#define GTK_ENTRY(x) ((GtkEntry*)x)
#define GTK_WINDOW(x) ((GtkWindow*)x)
#define G_OBJECT(x) ((GObject*)x)
#define G_CALLBACK(x) ((void(*)(void))x)

#define UIDIR ""
#define GETTEXT_PACKAGE ""
#define NM_SSH_KEY_PORT ""
#define NM_SSH_DEFAULT_PORT 0
#define NM_SSH_KEY_TUNNEL_MTU ""
#define NM_SSH_DEFAULT_MTU 0
#define NM_SSH_KEY_EXTRA_OPTS ""
#define NM_SSH_DEFAULT_EXTRA_OPTS ""
#define NM_SSH_KEY_REMOTE_DEV ""
#define NM_SSH_DEFAULT_REMOTE_DEV 0
#define NM_SSH_KEY_TAP_DEV ""
#define IS_YES(x) (0)
#define NM_SSH_KEY_REMOTE_USERNAME ""
#define NM_SSH_DEFAULT_REMOTE_USERNAME ""

char* g_strdup_printf(const char* format, ...);
void g_return_val_if_fail(void* expr, void* ret);
void g_warning(const char* format, ...);
void g_error_free(GError* error);
void g_object_unref(GObject* object);
void g_free(void* ptr);
GtkBuilder* gtk_builder_new(void);
void gtk_builder_set_translation_domain(GtkBuilder* builder, const char* domain);
gboolean gtk_builder_add_from_file(GtkBuilder* builder, const char* filename, GError** error);
GtkWidget* gtk_builder_get_object(GtkBuilder* builder, const char* name);
void gtk_window_set_modal(GtkWindow* window, gboolean modal);
void g_object_set_data_full(GObject* object, const char* key, gpointer data, GDestroyNotify destroy);
void g_assert(gpointer expr);
void g_signal_connect(GObject* instance, const char* signal, void (*handler)(), gpointer data);
const char* g_hash_table_lookup(GHashTable* hash_table, const char* key);
void gtk_toggle_button_set_active(GtkToggleButton* button, gboolean is_active);
void gtk_spin_button_set_value(GtkSpinButton* spinner, gdouble value);
void gtk_widget_set_sensitive(GtkWidget* widget, gboolean sensitive);
void gtk_entry_set_text(GtkEntry* entry, const char* text);

void port_toggled_cb(GtkToggleButton* button, gpointer user_data);
void tunmtu_toggled_cb(GtkToggleButton* button, gpointer user_data);
void extra_opts_toggled_cb(GtkToggleButton* button, gpointer user_data);
void remote_dev_toggled_cb(GtkToggleButton* button, gpointer user_data);
void remote_username_toggled_cb(GtkToggleButton* button, gpointer user_data);