#include <errno.h>
#include <stdint.h>
#include <stddef.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef struct xfs_mount {
    /* dummy structure */
} xfs_mount_t;
typedef struct xfs_inode {
    struct {
        u32 di_gen;
    } i_d;
} xfs_inode_t;
typedef struct inode inode;
typedef struct super_block super_block;

#define ERR_PTR(err) ((void *)(long)(err))
#define ESTALE 116
#define ENOENT 2
#define XFS_IGET_UNTRUSTED 0
#define XFS_ILOCK_SHARED 0
#define XFS_M(sb) ((xfs_mount_t *)0)
#define xfs_iget(mp, null, ino, flags, lock, ip, arg) (0)
#define xfs_iput_new(ip, lock) do {} while(0)
#define xfs_iunlock(ip, lock) do {} while(0)
#define VFS_I(ip) ((inode *)0)