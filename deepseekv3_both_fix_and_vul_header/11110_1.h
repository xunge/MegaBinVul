#include <stdbool.h>

typedef unsigned long long xfs_ino_t;

struct xfs_perag;
struct xfs_inode;
struct xfs_mount;

#define XFS_INEW            (1 << 0)
#define XFS_IRECLAIM        (1 << 1)
#define XFS_IRECLAIMABLE    (1 << 2)
#define XFS_ISTALE          (1 << 3)
#define XFS_IDONTCACHE      (1 << 4)

#define XFS_IGET_CREATE     (1 << 0)
#define XFS_IGET_INCORE     (1 << 1)

#define XFS_INEW_BIT        0
#define XFS_IRECLAIM_RESET_FLAGS (XFS_INEW|XFS_IRECLAIM|XFS_IRECLAIMABLE|XFS_ISTALE|XFS_IDONTCACHE)

#define __xfs_iflags_test(ip, flag) ((ip)->i_flags & (flag))
#define xfs_iflags_clear(ip, flags) ((ip)->i_flags &= ~(flags))

#define VFS_I(ip)           ((struct inode *)(ip))
#define I_NEW               (1 << 0)

#define EAGAIN              (-11)
#define ENOENT              (-2)

#define __releases(x)

struct spinlock {
    // dummy definition
};

#define spin_lock(lock) 
#define spin_unlock(lock) 

#define rcu_read_lock() 
#define rcu_read_unlock() 

#define trace_xfs_iget_skip(ip) 
#define trace_xfs_iget_reclaim(ip) 
#define trace_xfs_iget_reclaim_fail(ip) 
#define trace_xfs_iget_hit(ip) 

#define XFS_STATS_INC(mp, stat) 

#define ASSERT(expr) 

struct rw_semaphore {
    // dummy definition
};
#define init_rwsem(sem) 
#define rwsem_is_locked(sem) (0)

#define wake_up_bit(addr, bit) 

#define igrab(inode) (1)

struct inode {
    unsigned long i_ino;
    unsigned int i_mode;
    unsigned long i_state;
    struct rw_semaphore i_rwsem;
};

struct xfs_inode {
    struct inode i_vnode;
    xfs_ino_t i_ino;
    struct xfs_mount *i_mount;
    unsigned int i_flags;
    struct spinlock i_flags_lock;
};

struct xfs_mount {
    // dummy definition
};