#include <stddef.h>

typedef struct _NMAGConfSettings NMAGConfSettings;
typedef struct _NMAGConfSettingsPrivate NMAGConfSettingsPrivate;
typedef struct _NMAGConfConnection NMAGConfConnection;
typedef struct _NMExportedConnection NMExportedConnection;
typedef struct _NMSettings NMSettings;

#define NMA_GCONF_SETTINGS_GET_PRIVATE(obj) ((NMAGConfSettingsPrivate*)0)
#define NM_EXPORTED_CONNECTION(obj) ((NMExportedConnection*)0)
#define NM_SETTINGS(obj) ((NMSettings*)0)
#define NM_CONNECTION_SCOPE_USER 0

typedef void (*GCallback)(void);
#define g_return_if_fail(expr) do { if (!(expr)) return; } while (0)
#define G_CALLBACK(f) ((GCallback)(f))

struct _NMAGConfSettingsPrivate {
    void* connections;
    void* bus;
};

void connection_new_secrets_requested_cb(NMAGConfConnection *connection, void *user_data);
void connection_removed(NMAGConfConnection *connection, void *user_data);
void nm_settings_signal_new_connection(NMSettings *settings, NMExportedConnection *connection);
void nm_exported_connection_register_object(NMExportedConnection *connection, int scope, void *bus);
void dbus_g_connection_unref(void *bus);
void* g_slist_prepend(void *list, void *data);
void g_signal_connect(void *instance, const char *signal, GCallback handler, void *data);