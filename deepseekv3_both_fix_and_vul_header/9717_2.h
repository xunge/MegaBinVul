#include <stdint.h>
#include <string.h>

#define STATIC static
#define __user

typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_ifork xfs_ifork_t;
typedef uint64_t xfs_bmbt_rec_t;

struct fsxattr {
    uint32_t fsx_xflags;
    uint32_t fsx_extsize;
    uint32_t fsx_nextents;
    uint32_t fsx_projid;
};

#define XFS_ILOCK_SHARED   1
#define XFS_IFEXTENTS      1
#define EFAULT             14

struct xfs_dinode {
    uint32_t di_nextents;
    uint32_t di_anextents;
    int32_t di_extsize;
    uint32_t di_projid;
};

struct xfs_sb {
    uint32_t sb_blocklog;
};

struct xfs_ifork {
    int if_flags;
    int if_bytes;
};

struct xfs_inode {
    struct xfs_dinode i_d;
    struct xfs_ifork i_df;
    struct xfs_ifork *i_afp;
    struct xfs_mount *i_mount;
};

struct xfs_mount {
    struct xfs_sb m_sb;
};

static inline int copy_to_user(void *to, const void *from, unsigned long n)
{
    memcpy(to, from, n);
    return 0;
}

static inline void xfs_ilock(xfs_inode_t *ip, int flags) {}
static inline void xfs_iunlock(xfs_inode_t *ip, int flags) {}
static inline uint32_t xfs_ip2xflags(xfs_inode_t *ip) { return 0; }