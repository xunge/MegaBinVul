#include <stddef.h>

typedef struct _NMAGConfSettings NMAGConfSettings;
typedef struct DBusGConnection DBusGConnection;
typedef struct _NMAGConfSettingsPrivate {
    DBusGConnection *bus;
} NMAGConfSettingsPrivate;
typedef void GObject;

#define NMA_TYPE_GCONF_SETTINGS (0)
#define NMA_GCONF_SETTINGS_GET_PRIVATE(obj) ((NMAGConfSettingsPrivate*)0)
#define NM_DBUS_PATH_SETTINGS "/org/freedesktop/NetworkManager/Settings"
#define G_OBJECT(obj) ((GObject*)(obj))

static inline void* g_object_new(int type, void* unused) { return NULL; }
static inline DBusGConnection* dbus_g_connection_ref(DBusGConnection* bus) { return bus; }
static inline void dbus_g_connection_register_g_object(DBusGConnection* bus, const char* path, GObject* obj) {}