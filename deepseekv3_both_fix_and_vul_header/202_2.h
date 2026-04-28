#include <stddef.h>

typedef struct _GVfsBackendAdmin GVfsBackendAdmin;
typedef struct _GVfsJob GVfsJob;
typedef struct _GVfsBackend GVfsBackend;
typedef struct _GVfsJobQueryInfo GVfsJobQueryInfo;
typedef struct _GFile GFile;
typedef struct _GFileInfo GFileInfo;
typedef struct _GError GError;
typedef struct _GFileAttributeMatcher GFileAttributeMatcher;
typedef struct _GCancellable GCancellable;
typedef int GFileQueryInfoFlags;
typedef int gboolean;

#define G_VFS_BACKEND_ADMIN(x) ((GVfsBackendAdmin*)x)
#define G_VFS_JOB(x) ((GVfsJob*)x)

struct _GVfsJobQueryInfo {
    char *attributes;
};

struct _GVfsJob {
    GCancellable *cancellable;
};

static gboolean check_permission(GVfsBackendAdmin *self, GVfsJob *job);
static void fix_file_info(GFileInfo *info);
static void complete_job(GVfsJob *job, GError *error);
static GFile* g_file_new_for_path(const char *path);
static GFileInfo* g_file_query_info(GFile *file, const char *attributes, GFileQueryInfoFlags flags, GCancellable *cancellable, GError **error);
static void g_object_unref(void *object);
static void g_file_info_copy_into(GFileInfo *src_info, GFileInfo *dest_info);