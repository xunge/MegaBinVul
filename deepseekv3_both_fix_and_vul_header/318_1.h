#include <stdlib.h>

typedef struct _GObject {
    void *dummy;
} GObject;

typedef struct _GKeyFile GKeyFile;
typedef struct _GPermission GPermission;
typedef struct _GFileMonitor GFileMonitor;
typedef struct _GFile GFile;
typedef struct _GHashTable GHashTable;

typedef struct _GObjectClass {
    void (*finalize)(GObject *object);
} GObjectClass;

typedef struct _GKeyfileSettingsBackend GKeyfileSettingsBackend;
struct _GKeyfileSettingsBackend {
    GObject parent_instance;
    GKeyFile *keyfile;
    GKeyFile *system_keyfile;
    GPermission *permission;
    GFileMonitor *file_monitor;
    GFile *file;
    GFileMonitor *dir_monitor;
    GFile *dir;
    char *root_group;
    char *prefix;
    GHashTable *system_locks;
    char *defaults_dir;
};

#define G_TYPE_KEYFILE_SETTINGS_BACKEND 0
#define G_KEYFILE_SETTINGS_BACKEND(object) ((GKeyfileSettingsBackend*)(object))
#define G_OBJECT_CLASS(klass) ((GObjectClass*)(klass))

static GObjectClass *g_keyfile_settings_backend_parent_class = NULL;

static void g_key_file_free(GKeyFile *keyfile) {}
static void g_key_file_unref(GKeyFile *keyfile) {}
static void g_object_unref(void *object) {}
static void g_file_monitor_cancel(GFileMonitor *monitor) {}
static void g_free(void *ptr) {}
static void g_hash_table_unref(GHashTable *hash_table) {}