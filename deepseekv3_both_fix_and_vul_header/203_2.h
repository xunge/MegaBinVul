#include <stddef.h>

typedef struct _GVfsBackend GVfsBackend;
typedef struct _GVfsJob GVfsJob;
typedef struct _GVfsJobQueryInfoWrite GVfsJobQueryInfoWrite;
typedef void* GVfsBackendHandle;
typedef void* GFileInfo;
typedef void* GFileAttributeMatcher;
typedef void* GFileOutputStream;
typedef void* GError;
typedef void* GCancellable;

struct _GVfsJobQueryInfoWrite {
    char *attributes;
};

struct _GVfsJob {
    GCancellable *cancellable;
};

#define G_VFS_JOB(job) ((GVfsJob*)(job))