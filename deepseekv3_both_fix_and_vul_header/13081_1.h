#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct _GError GError;
typedef struct _GHashTable GHashTable;

typedef struct FlatpakContext {
    GHashTable *persistent;
} FlatpakContext;

void* g_hash_table_insert(GHashTable *hash_table, void *key, void *value);
char* g_strdup(const char *str);
void* GINT_TO_POINTER(int i);

gboolean flatpak_validate_path_characters(const char *path, GError **error);