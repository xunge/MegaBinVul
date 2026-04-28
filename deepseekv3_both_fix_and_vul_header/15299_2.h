#include <stdlib.h>

typedef struct _GSList {
    void *data;
    struct _GSList *next;
} GSList;

typedef struct _NMAGConfSettings {
    int dummy;  // Placeholder for private data offset
} NMAGConfSettings;

typedef struct _NMAGConfSettingsPrivate {
    void *client;
    GSList *connections;
} NMAGConfSettingsPrivate;

typedef struct _NMAGConfConnection NMAGConfConnection;

#define NMA_GCONF_SETTINGS_GET_PRIVATE(obj) ((NMAGConfSettingsPrivate*)((char*)(obj) + sizeof(NMAGConfSettings)))

GSList* nm_gconf_get_all_connections(void* client);
NMAGConfConnection* nma_gconf_connection_new(void* client, const char* dir);
void add_connection_real(NMAGConfSettings* settings, NMAGConfConnection* connection);
void g_free(void* ptr);
GSList* g_slist_free(GSList* list);
GSList* g_slist_reverse(GSList* list);