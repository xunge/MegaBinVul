#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  FLATPAK_FILESYSTEM_MODE_NONE
} FlatpakFilesystemMode;

typedef struct GHashTable GHashTable;
typedef struct GHashTableIter GHashTableIter;

typedef void* gpointer;
typedef const void* gconstpointer;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef uint32_t guint;
#define GPOINTER_TO_INT(p) ((int)(intptr_t)(p))

struct GHashTableIter {
    void *dummy1;
    void *dummy2;
    void *dummy3;
    int dummy4;
    int dummy5;
    void *dummy6;
};

typedef struct {
  guint shares;
  guint shares_valid;
  guint sockets;
  guint sockets_valid;
  guint devices;
  guint devices_valid;
  guint features;
  guint features_valid;
  GHashTable *env_vars;
  GHashTable *persistent;
  GHashTable *filesystems;
  GHashTable *session_bus_policy;
  GHashTable *system_bus_policy;
  GHashTable *generic_policy;
} FlatpakContext;

void g_hash_table_iter_init(struct GHashTableIter *iter, GHashTable *hash_table);
int g_hash_table_iter_next(struct GHashTableIter *iter, gpointer *key, gpointer *value);
void g_hash_table_insert(GHashTable *hash_table, gpointer key, gpointer value);
int g_hash_table_lookup_extended(GHashTable *hash_table, gconstpointer lookup_key, gpointer *orig_key, gpointer *value);
void g_hash_table_remove_all(GHashTable *hash_table);
void g_hash_table_iter_remove(struct GHashTableIter *iter);
char* g_strdup(const char *str);
int flatpak_filesystem_key_in_home(const char *key);
void flatpak_context_apply_generic_policy(FlatpakContext *context, char *key, const char *value);