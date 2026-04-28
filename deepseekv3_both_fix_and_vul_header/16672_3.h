#include <sys/stat.h>
#include <stdbool.h>
#include <stddef.h>

#define AE_IFDIR S_IFDIR
#define G_FILE_TYPE_UNKNOWN 0
#define G_FILE_TYPE_DIRECTORY 1
#define G_FILE_QUERY_INFO_NOFOLLOW_SYMLINKS 0
#define FALSE false
#define TRUE true

typedef struct _GFile GFile;
typedef int GFileType;
typedef bool gboolean;

typedef struct _AutoarExtractor AutoarExtractor;
struct _AutoarExtractor {
    GFile *new_prefix;
    GFile *destination_dir;
};

GFileType g_file_query_file_type(GFile *file, int flags, void *cancellable);
bool g_file_equal(GFile *file1, GFile *file2);
GFile* g_file_get_parent(GFile *file);
GFile* g_object_ref(GFile *file);

#define g_autoptr(type) type* __attribute__((cleanup(g_autoptr_cleanup)))
static inline void g_autoptr_cleanup(GFile **ptr) { if (*ptr) g_object_ref(*ptr); }