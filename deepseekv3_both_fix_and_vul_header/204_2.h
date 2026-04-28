#include <stddef.h>

typedef struct _GVfsBackend GVfsBackend;
typedef struct _GVfsBackendAdmin GVfsBackendAdmin;
typedef struct _GVfsJob GVfsJob;
typedef struct _GVfsJobQueryInfo GVfsJobQueryInfo;
typedef struct _GFile GFile;
typedef struct _GFileInfo GFileInfo;
typedef struct _GFileAttributeMatcher GFileAttributeMatcher;
typedef struct _GError GError;
typedef struct _GCancellable GCancellable;
typedef int GFileQueryInfoFlags;
typedef int gboolean;

#define G_VFS_BACKEND_ADMIN(backend) ((GVfsBackendAdmin*)backend)
#define G_VFS_JOB(job) ((GVfsJob*)job)
#define TRUE 1
#define FALSE 0

#define G_FILE_ATTRIBUTE_ACCESS_CAN_READ "access::can-read"
#define G_FILE_ATTRIBUTE_ACCESS_CAN_WRITE "access::can-write"
#define G_FILE_ATTRIBUTE_ACCESS_CAN_DELETE "access::can-delete"
#define G_FILE_ATTRIBUTE_ACCESS_CAN_RENAME "access::can-rename"

struct _GVfsJobQueryInfo {
    char *attributes;
    GVfsJob *job;
};

struct _GVfsJob {
    GCancellable *cancellable;
};

static gboolean check_permission(GVfsBackendAdmin *self, GVfsJob *job);
static void complete_job(GVfsJob *job, GError *error);
static GFile* g_file_new_for_path(const char *path);
static GFileInfo* g_file_query_info(GFile *file, const char *attributes, GFileQueryInfoFlags flags, GCancellable *cancellable, GError **error);
static void g_object_unref(void *object);
static void g_file_info_set_attribute_boolean(GFileInfo *info, const char *attribute, gboolean value);
static void g_file_info_copy_into(GFileInfo *src, GFileInfo *dest);