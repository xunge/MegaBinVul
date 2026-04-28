#include <stddef.h>

#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef void* gpointer;
typedef struct _GSList GSList;
typedef struct _GHashTable GHashTable;
typedef struct _GConfClient GConfClient;

typedef struct {
    void* parent;
} NMAGConfSettings;

typedef struct {
    GSList *connections;
    GConfClient *client;
    GHashTable *pending_changes;
} NMAGConfSettingsPrivate;

typedef struct {
    NMAGConfSettings *settings;
    char *path;
} ConnectionChangedInfo;

typedef struct {
    void* parent;
} NMAGConfConnection;

#define NMA_GCONF_SETTINGS_GET_PRIVATE(obj) ((NMAGConfSettingsPrivate*)((char*)(obj) + sizeof(NMAGConfSettings)))

NMAGConfConnection* nma_gconf_settings_get_by_path(NMAGConfSettings *settings, const char *path);
NMAGConfConnection* nma_gconf_connection_new(GConfClient *client, const char *path);
void add_connection_real(NMAGConfSettings *settings, NMAGConfConnection *connection);
gboolean nma_gconf_connection_changed(NMAGConfConnection *connection);
gboolean gconf_client_dir_exists(GConfClient *client, const char *path, void* unused);
GSList* g_slist_remove(GSList *list, void* data);
void g_hash_table_remove(GHashTable *hash_table, const void* key);