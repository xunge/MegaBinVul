#include <stdlib.h>
#include <string.h>

typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef char gchar;
typedef size_t gsize;

#define G_FILE_CREATE_REPLACE_DESTINATION (1 << 0)
#define G_FILE_CREATE_PRIVATE (1 << 1)

typedef struct _GKeyFile GKeyFile;
typedef struct _GFile GFile;

typedef struct _GKeyfileSettingsBackend {
    GKeyFile *keyfile;
    GFile *file;
    gchar *digest;
} GKeyfileSettingsBackend;

void compute_checksum(gchar *digest, const gchar *contents, gsize length);
void g_free(void *ptr);
gchar* g_key_file_to_data(GKeyFile *keyfile, gsize *length, void* unused);
int g_file_replace_contents(GFile *file, const gchar *contents, gsize length,
                           const char *etag, gboolean make_backup,
                           int flags, void* unused1, void* unused2, void* unused3);