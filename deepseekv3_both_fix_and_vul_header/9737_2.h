#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define STATIC static
#define __user

typedef uint64_t xfs_ino_t;
typedef int64_t xfs_daddr_t;
typedef int64_t xfs_qcnt_t;
typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_dquot xfs_dquot_t;

#define XFS_IS_QUOTA_RUNNING(mp) (1)
#define XFS_IS_UQUOTA_ON(mp) (1)
#define XFS_IS_OQUOTA_ON(mp) (1)
#define XFS_IS_REALTIME_INODE(ip) (0)
#define XFS_ILOCK_EXCL (0)
#define BULKSTAT_RV_NOTHING (0)
#define BULKSTAT_RV_GIVEUP (1)
#define BULKSTAT_RV_DIDONE (2)
#define XFS_ERROR(err) (-(err))
#define ASSERT(expr) ((void)0)
#define IRELE(ip) ((void)0)

struct xfs_mount {
    struct {
        xfs_ino_t sb_uquotino;
        xfs_ino_t sb_gquotino;
    } m_sb;
};

struct xfs_inode {
    struct {
        uint64_t di_nblocks;
    } i_d;
    uint64_t i_delayed_blks;
};

int xfs_iget(xfs_mount_t *mp, void *null, xfs_ino_t ino, int flags, int lock_flags, xfs_inode_t **ipp, ...);
int xfs_qm_dqget_noattach(xfs_inode_t *ip, xfs_dquot_t **udqp, xfs_dquot_t **gdqp);
int xfs_qm_get_rtblks(xfs_inode_t *ip, xfs_qcnt_t *rtblks);
void xfs_qm_quotacheck_dqadjust(xfs_dquot_t *dqp, xfs_qcnt_t nblks, xfs_qcnt_t rtblks);
void xfs_qm_dqput(xfs_dquot_t *dqp);
void xfs_iput(xfs_inode_t *ip, int lock_flags);
void xfs_iunlock(xfs_inode_t *ip, int lock_flags);