#include <stdlib.h>
#include <string.h>

#define NM_SSH_KEY_TUNNEL_MTU "tunnel-mtu"
#define NM_SSH_KEY_PORT "port"
#define NM_SSH_KEY_EXTRA_OPTS "extra-opts"
#define NM_SSH_KEY_REMOTE_DEV "remote-dev"
#define NM_SSH_KEY_TAP_DEV "tap-dev"
#define NM_SSH_KEY_REMOTE_USERNAME "remote-username"
#define YES "yes"

typedef struct _GHashTable GHashTable;
typedef struct _GtkWidget GtkWidget;
typedef struct _GtkBuilder GtkBuilder;
typedef struct _GError GError;
typedef struct _GObject GObject;
typedef char gchar;

unsigned int g_str_hash(const void *v);
int g_str_equal(const void *v1, const void *v2);
void g_free(void *data);
void g_return_val_if_fail(int expr, void *val);
GObject* G_OBJECT(GtkWidget *widget);
void* g_object_get_data(GObject *object, const char *key);
GtkWidget* GTK_WIDGET(void *obj);
void* gtk_builder_get_object(GtkBuilder *builder, const char *name);
int gtk_toggle_button_get_active(void *toggle_button);
void* GTK_TOGGLE_BUTTON(GtkWidget *widget);
int gtk_spin_button_get_value_as_int(void *spin_button);
void* GTK_SPIN_BUTTON(GtkWidget *widget);
const char* gtk_entry_get_text(void *entry);
void* GTK_ENTRY(GtkWidget *widget);
char* g_strdup(const char *str);
char* g_strdup_printf(const char *format, ...);
GHashTable* g_hash_table_new_full(unsigned int (*hash_func)(const void*),
                                 int (*key_equal_func)(const void*, const void*),
                                 void (*key_destroy_func)(void*),
                                 void (*value_destroy_func)(void*));
void g_hash_table_insert(GHashTable *hash_table, void *key, void *value);