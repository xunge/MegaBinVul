#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define TRUE true
#define FALSE false

typedef void* gpointer;
typedef char gchar;
typedef bool gboolean;
typedef uint32_t guint;

typedef struct TCMUService1HandlerManager1 TCMUService1HandlerManager1;
typedef struct GDBusMethodInvocation GDBusMethodInvocation;
typedef struct GVariant GVariant;

struct tcmur_handler {
    int _is_dbus_handler;
    void *opaque;
};

struct dbus_info {
    guint watcher_id;
};

struct tcmur_handler *find_handler_by_subtype(gchar *subtype);
void dbus_unexport_handler(struct tcmur_handler *handler);
void tcmur_unregister_dbus_handler(struct tcmur_handler *handler);
GVariant* g_variant_new(const char *format, ...);
void g_dbus_method_invocation_return_value(GDBusMethodInvocation *invocation, GVariant *value);
void g_bus_unwatch_name(guint watcher_id);
void g_free(void *ptr);