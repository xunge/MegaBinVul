#include <stdint.h>

typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;
typedef uint64_t xfs_ino_t;
typedef struct xfs_inode xfs_inode_t;
typedef unsigned int uint;

int xfs_iget(xfs_mount_t *mp, xfs_trans_t *tp, xfs_ino_t ino, uint flags, uint lock_flags, xfs_inode_t **ipp, ...);
void xfs_trans_ijoin(xfs_trans_t *tp, xfs_inode_t *ip, uint lock_flags);