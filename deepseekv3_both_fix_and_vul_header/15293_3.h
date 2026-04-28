#include <stdint.h>
#include <stddef.h>

typedef struct _GObject {
    void *g_type_instance;
} GObject;

typedef struct _GObjectClass {
    void (*dispose)(GObject *object);
} GObjectClass;

typedef struct _DBusGConnection DBusGConnection;
typedef struct _GHashTable GHashTable;
typedef struct _GConfClient GConfClient;
typedef struct _GSList GSList;

typedef uint32_t guint;
typedef int gboolean;
typedef void (*GFunc)(void*, void*);

#define TRUE 1
#define FALSE 0
#define NULL ((void*)0)

typedef struct {
    gboolean disposed;
    DBusGConnection *bus;
    GHashTable *pending_changes;
    guint read_connections_id;
    GConfClient *client;
    guint conf_notify_id;
    GSList *connections;
} NMAGConfSettingsPrivate;

#define NMA_GCONF_SETTINGS_GET_PRIVATE(obj) ((NMAGConfSettingsPrivate*)0)
#define GCONF_PATH_CONNECTIONS ""
#define G_OBJECT_CLASS(klass) ((GObjectClass*)(klass))

extern GObjectClass *nma_gconf_settings_parent_class;

static inline void dbus_g_connection_unref(DBusGConnection *bus) {}
static inline void g_hash_table_destroy(GHashTable *hash_table) {}
static inline guint g_source_remove(guint tag) { return 0; }
static inline void gconf_client_notify_remove(GConfClient *client, guint cnxn) {}
static inline void gconf_client_remove_dir(GConfClient *client, const char *dir, void* unused) {}
static inline void g_slist_foreach(GSList *list, GFunc func, void* user_data) {}
static inline void g_slist_free(GSList *list) {}
static inline void g_object_unref(void *object) {}