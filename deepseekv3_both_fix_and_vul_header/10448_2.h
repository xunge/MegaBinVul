#include <sys/types.h>
#include <sys/xattr.h>
#include <stdlib.h>
#include <string.h>

typedef struct XattrOperations XattrOperations;

struct XattrOperations {
    ssize_t (*listxattr)(void *ctx, const char *path, const char *name,
                         void *value, size_t size);
};

typedef struct FsContext {
    XattrOperations **xops;
} FsContext;

XattrOperations *get_xattr_operations(XattrOperations **xops, const char *name);

int local_opendir_nofollow(FsContext *ctx, const char *path);
int flistxattrat_nofollow(int dirfd, const char *filename, void *value, size_t size);
void close_preserve_errno(int fd);

char *g_path_get_dirname(const char *path);
char *g_path_get_basename(const char *path);
void g_free(void *ptr);
void *g_malloc(size_t size);