#include <stdint.h>

#define STATIC static
#define XFS_ATTR_FORK 0
#define XFS_DAENTER_SPACE_RES(mp, fork) 0
#define XFS_B_TO_FSB(mp, b) 0
#define XFS_NEXTENTADD_SPACE_RES(mp, e, f) 0

typedef uint32_t uint;

struct xfs_sb {
    int sb_blocksize;
};

struct xfs_mount {
    struct xfs_sb m_sb;
};

struct xfs_inode {
    struct xfs_mount *i_mount;
};

int xfs_attr_leaf_newentsize(int namelen, int valuelen, int blocksize, int *local);