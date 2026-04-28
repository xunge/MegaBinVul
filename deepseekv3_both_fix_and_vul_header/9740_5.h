#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

#define STATIC static
typedef uint64_t xfs_ino_t;
typedef uint64_t xfs_dqid_t;
typedef uint64_t xfs_daddr_t;
typedef unsigned int uint;
typedef int boolean_t;

typedef struct xfs_mount {
    struct {
        xfs_ino_t sb_uquotino;
        xfs_ino_t sb_gquotino;
    } m_sb;
} xfs_mount_t;

typedef struct xfs_inode {
    struct {
        uint32_t di_uid;
        uint32_t di_gid;
        uint32_t di_projid;
    } i_d;
} xfs_inode_t;

typedef struct xfs_dqtest xfs_dqtest_t;

#define __user

#define XFS_IS_QUOTA_RUNNING(mp) (1)
#define XFS_IS_UQUOTA_ON(mp) (1)
#define XFS_IS_OQUOTA_ON(mp) (1)
#define XFS_ILOCK_SHARED (1)
#define XFS_ERROR(err) (err)
#define EINVAL (22)
#define BULKSTAT_RV_NOTHING (0)
#define BULKSTAT_RV_DIDONE (1)
#define B_FALSE (0)
#define B_TRUE (1)

#define ASSERT(cond) ((void)0)
#define qdprintk(fmt, ...) ((void)0)

int xfs_iget(xfs_mount_t *mp, void *null, xfs_ino_t ino, int flags, uint lock_flags, xfs_inode_t **ip, ...);
void xfs_iput(xfs_inode_t *ip, uint lock_flags);
void xfs_qm_internalqcheck_get_dquots(xfs_mount_t *mp, xfs_dqid_t uid, xfs_dqid_t projid, xfs_dqid_t gid, xfs_dqtest_t **ud, xfs_dqtest_t **gd);
void xfs_qm_internalqcheck_dqadjust(xfs_inode_t *ip, xfs_dqtest_t *dq);