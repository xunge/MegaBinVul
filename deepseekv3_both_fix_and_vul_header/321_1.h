#include <stdlib.h>
#include <string.h>

typedef struct _GKeyFile GKeyFile;
typedef struct _GHashTable GHashTable;
typedef struct _GVariant GVariant;
typedef struct _GVariantType GVariantType;

typedef struct _GKeyfileSettingsBackend {
    GKeyFile *system_keyfile;
    GKeyFile *keyfile;
    GHashTable *system_locks;
} GKeyfileSettingsBackend;

typedef char gchar;
#define g_assert(expr) ((void)0)
#define g_free(ptr) free(ptr)
#define g_steal_pointer(pp) (*(pp))