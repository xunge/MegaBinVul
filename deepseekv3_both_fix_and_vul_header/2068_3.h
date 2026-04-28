#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _GVariant GVariant;
typedef struct _GError {
    char* message;
} GError;
typedef struct _GVariantType GVariantType;
typedef struct _PolkitSubject PolkitSubject;
typedef struct _PolkitSystemBusName PolkitSystemBusName;
typedef struct _PolkitUnixProcess PolkitUnixProcess;

#define G_DBUS_CALL_FLAGS_NONE 0
#define G_VARIANT_TYPE(x) ((const GVariantType *) x)

const char* g_dbus_method_invocation_get_sender(GDBusMethodInvocation* context);
void* g_dbus_method_invocation_get_connection(GDBusMethodInvocation* context);
GVariant* g_dbus_connection_call_sync(void* connection, const char* bus_name, 
                                    const char* object_path, const char* interface_name,
                                    const char* method_name, GVariant* parameters,
                                    const GVariantType* reply_type, int flags,
                                    int timeout, void* cancellable, GError** error);
GVariant* g_variant_new(const char* format_string, ...);
void g_warning(const char* format, ...);
void g_error_free(GError* error);
void g_variant_get(GVariant* variant, const char* format_string, ...);
void g_variant_unref(GVariant* variant);

PolkitSubject* polkit_system_bus_name_new(const char* sender);
PolkitSubject* polkit_system_bus_name_get_process_sync(PolkitSystemBusName* name, 
                                                     void* cancellable, GError** error);
int polkit_unix_process_get_uid(PolkitUnixProcess* process);
void g_object_unref(void* object);

#define POLKIT_SYSTEM_BUS_NAME(obj) ((PolkitSystemBusName*)obj)
#define POLKIT_UNIX_PROCESS(obj) ((PolkitUnixProcess*)obj)