#include <stdbool.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

typedef void* gpointer;
typedef char gchar;
typedef int gboolean;
typedef unsigned int guint;

struct tcmur_handler {
    void *opaque;
};

struct dbus_info {
    guint watcher_id;
};

typedef struct {
    // Dummy structure for TCMUService1HandlerManager1
} TCMUService1HandlerManager1;

typedef struct {
    // Dummy structure for GDBusMethodInvocation
} GDBusMethodInvocation;

static struct tcmur_handler *find_handler_by_subtype(gchar *subtype);
void dbus_unexport_handler(struct tcmur_handler *handler);
void tcmur_unregister_handler(struct tcmur_handler *handler);
void g_bus_unwatch_name(guint watcher_id);
void g_free(void *ptr);
void* g_variant_new(const char *format, ...);
void g_dbus_method_invocation_return_value(GDBusMethodInvocation *invocation, void *variant);