#include <stddef.h>

typedef void* GDBusConnection;
typedef char gchar;
typedef void* gpointer;
typedef void* GCallback;
typedef void* GVariant;

#define TRUE 1
#define FALSE 0
#define G_CALLBACK(func) ((GCallback)(func))

struct tcmur_handler {
    void *opaque;
};

struct dbus_info {
    GDBusConnection *connection;
    void *register_invocation;
};

void tcmur_register_handler(struct tcmur_handler *handler);
void dbus_export_handler(struct tcmur_handler *handler, GCallback callback);
void on_dbus_check_config(void);
void g_dbus_method_invocation_return_value(void *invocation, GVariant *parameters);
GVariant *g_variant_new(const char *format_string, ...);