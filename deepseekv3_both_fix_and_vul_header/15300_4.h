#include <stddef.h>

typedef void* gpointer;
typedef struct _NMAGConfSettings NMAGConfSettings;
typedef struct _NMAGConfConnection NMAGConfConnection;
typedef struct _NMExportedConnection NMExportedConnection;
typedef struct _NMSettings NMSettings;
typedef struct _GSList GSList;
typedef void* DBusGConnection;

struct _NMAGConfSettingsPrivate {
    GSList *connections;
    DBusGConnection *bus;
};

typedef struct _NMAGConfSettingsPrivate NMAGConfSettingsPrivate;

#define NMA_GCONF_SETTINGS_GET_PRIVATE(obj) ((NMAGConfSettingsPrivate*)(obj))
#define G_CALLBACK(func) func
#define NM_EXPORTED_CONNECTION(conn) ((NMExportedConnection*)(conn))
#define NM_SETTINGS(settings) ((NMSettings*)(settings))
#define NM_CONNECTION_SCOPE_USER 0

void connection_new_secrets_requested_cb(NMAGConfConnection *connection, gpointer user_data);
void connection_removed(NMAGConfConnection *connection, gpointer user_data);
void nm_settings_signal_new_connection(NMSettings *settings, NMExportedConnection *connection);
void nm_exported_connection_register_object(NMExportedConnection *connection, int scope, DBusGConnection *bus);
void dbus_g_connection_unref(DBusGConnection *bus);

static inline void g_return_if_fail(int expr) { if (!expr) return; }
static inline GSList* g_slist_prepend(GSList *list, void *data) { return list; }
static inline void g_signal_connect(void *instance, const char *signal, void *handler, void *data) {}