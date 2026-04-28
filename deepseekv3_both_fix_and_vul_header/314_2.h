typedef int gboolean;
typedef void* gpointer;

typedef struct _WriteManyData WriteManyData;
typedef struct _GKeyfileSettingsBackend GKeyfileSettingsBackend;
typedef struct _GHashTable GHashTable;

struct _WriteManyData {
    gboolean failed;
    GKeyfileSettingsBackend *kfsb;
};

struct _GKeyfileSettingsBackend {
    GHashTable *system_locks;
};

gboolean g_hash_table_contains(GHashTable *hash_table, gpointer key);
gboolean path_is_valid(GKeyfileSettingsBackend *kfsb, gpointer key);