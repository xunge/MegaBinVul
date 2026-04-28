#include <stdint.h>

#define STATIC static
#define ENOATTR 2
#define EEXIST 17
#define ENOSPC 28
#define ATTR_REPLACE (1 << 0)
#define ATTR_CREATE (1 << 1)

#define XFS_ATTR_SF_ENTSIZE_MAX 255
#define XFS_ATTR_SF_TOTSIZE(dp) 0
#define XFS_ATTR_SF_ENTSIZE_BYNAME(n, v) 0

#define ASSERT(expr) ((void)0)

typedef struct xfs_da_args {
    int flags;
    int namelen;
    int valuelen;
    void *dp;
} xfs_da_args_t;

void trace_xfs_attr_sf_addname(xfs_da_args_t *args);
int xfs_attr_shortform_lookup(xfs_da_args_t *args);
int xfs_attr_shortform_remove(xfs_da_args_t *args);
int xfs_attr_shortform_bytesfit(void *dp, int newsize);
void xfs_attr_shortform_add(xfs_da_args_t *args, int forkoff);