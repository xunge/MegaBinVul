#include <stdbool.h>

typedef struct _GDBusConnection GDBusConnection;
typedef char gchar;
typedef void* gpointer;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _GVariant GVariant;

#define FALSE false

struct tcmur_handler {
    char *subtype;
    void *opaque;
};

struct dbus_info {
    GDBusMethodInvocation *register_invocation;
};

char* g_strdup_printf(const char* format, ...);
GVariant* g_variant_new(const char* format_string, ...);
void g_dbus_method_invocation_return_value(GDBusMethodInvocation* invocation, GVariant* parameters);
void g_free(void* mem);
void tcmur_unregister_handler(struct tcmur_handler* handler);
void dbus_unexport_handler(struct tcmur_handler* handler);