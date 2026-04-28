#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;
typedef uint32_t u32;

struct super_block {
    void *s_fs_info;
};

typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_inode xfs_inode_t;
typedef struct inode inode;

#define XFS_IGET_UNTRUSTED 0
#define XFS_ILOCK_SHARED   0
#define ESTALE             0
#define EINVAL             0
#define ENOENT             0

struct xfs_inode {
    struct {
        u32 di_gen;
    } i_d;
};

#define XFS_M(sb) ((xfs_mount_t *)(sb)->s_fs_info)
#define VFS_I(ip) ((inode *)(ip))
#define ERR_PTR(err) ((void *)(intptr_t)(err))

static inline int xfs_iget(xfs_mount_t *mp, void *null, u64 ino, int untrusted, int lock, xfs_inode_t **ip, ...) { return 0; }
static inline void xfs_iput_new(xfs_inode_t *ip, int lock) {}
static inline void xfs_iunlock(xfs_inode_t *ip, int lock) {}