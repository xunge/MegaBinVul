#include <stddef.h>

typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct _GFile GFile;
typedef struct _GCancellable GCancellable;
typedef struct _GError GError;
typedef struct _GFileEnumerator GFileEnumerator;
typedef struct _GFileInfo GFileInfo;

typedef enum {
    G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS
} GFileQueryInfoFlags;

typedef enum {
    G_FILE_TYPE_DIRECTORY
} GFileType;

#define G_FILE_ATTRIBUTE_STANDARD_NAME "standard::name"
#define G_FILE_ATTRIBUTE_STANDARD_TYPE "standard::type"

GFileEnumerator* g_file_enumerate_children(GFile*, const char*, GFileQueryInfoFlags, GCancellable*, GError**);
GFileInfo* g_file_enumerator_next_file(GFileEnumerator*, GCancellable*, GError**);
GFile* g_file_get_child(GFile*, const char*);
const char* g_file_info_get_name(GFileInfo*);
GFileType g_file_info_get_file_type(GFileInfo*);
gboolean g_file_delete(GFile*, GCancellable*, GError**);
void g_object_unref(void*);