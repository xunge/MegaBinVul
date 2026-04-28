#include <stddef.h>

typedef struct _GVfsBackend GVfsBackend;
typedef struct _GCancellable GCancellable;
typedef struct _GVfsJob {
    GCancellable *cancellable;
} GVfsJob;
typedef struct _GVfsJobQueryInfoRead {
    const char *attributes;
} GVfsJobQueryInfoRead;
typedef void* GVfsBackendHandle;
typedef struct _GFileInfo GFileInfo;
typedef struct _GFileInputStream GFileInputStream;
typedef struct _GError GError;
typedef struct _GFileAttributeMatcher GFileAttributeMatcher;

#define G_VFS_JOB(obj) ((GVfsJob*)(obj))

static GFileInfo* g_file_input_stream_query_info(GFileInputStream* stream, const char* attributes, GCancellable* cancellable, GError** error);
static void g_file_info_copy_into(GFileInfo* src, GFileInfo* dest);
static void g_object_unref(void* object);
static void fix_file_info(GFileInfo *info);
static void complete_job(GVfsJob *job, GError *error);