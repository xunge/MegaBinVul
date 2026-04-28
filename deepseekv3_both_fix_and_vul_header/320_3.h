#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
typedef char gchar;
typedef int gint;
typedef size_t gsize;
typedef void* GVariant;
typedef void* GKeyFile;
typedef void* GHashTable;
typedef void* GError;

#define FALSE 0
#define TRUE 1

struct _GKeyfileSettingsBackend {
    GKeyFile *keyfile;
    GHashTable *system_locks;
};
typedef struct _GKeyfileSettingsBackend GKeyfileSettingsBackend;

static gboolean convert_path(GKeyfileSettingsBackend *kfsb, const gchar *key, gchar **group, gchar **name);
static gboolean group_name_matches(const gchar *group1, const gchar *group2);
static gboolean g_hash_table_contains(GHashTable *hash_table, const gchar *key);
static gchar* g_variant_print(GVariant *value, gboolean type_annotate);
static void g_key_file_set_value(GKeyFile *key_file, const gchar *group_name, const gchar *key, const gchar *value);
static void g_variant_unref(GVariant *value);
static GVariant* g_variant_ref_sink(GVariant *value);
static void g_free(void *ptr);
static gchar** g_key_file_get_groups(GKeyFile *key_file, gsize *length);
static void g_key_file_remove_group(GKeyFile *key_file, const gchar *group_name, GError **error);
static void g_strfreev(gchar **str_array);
static void g_key_file_remove_key(GKeyFile *key_file, const gchar *group_name, const gchar *key, GError **error);