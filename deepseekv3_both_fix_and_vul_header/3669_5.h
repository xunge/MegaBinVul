#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>

#define STATIC static
#define XFS_ERROR(err) (-(err))

#define FSX_PROJID 0x0001
#define FSX_EXTSIZE 0x0002
#define FSX_XFLAGS 0x0004

#define XFS_MOUNT_RDONLY 0x0001
#define XFS_MOUNT_WSYNC 0x0002

#define XFS_IS_QUOTA_ON(mp) (0)
#define XFS_IS_QUOTA_RUNNING(mp) (0)
#define XFS_IS_PQUOTA_ON(mp) (0)
#define XFS_FORCED_SHUTDOWN(mp) (0)

#define XFS_QMOPT_PQUOTA 0
#define XFS_QMOPT_FORCE_RES 0

#define XFS_ILOCK_EXCL 0
#define XFS_ICHGTIME_CHG 0
#define XFS_ILOG_CORE 0

#define CAP_FOWNER 0
#define CAP_FSETID 0
#define CAP_LINUX_IMMUTABLE 0

#define MAXEXTLEN (1 << 24)
#define XFS_XFLAG_REALTIME 0x0001
#define XFS_DIFLAG_IMMUTABLE 0x0001
#define XFS_DIFLAG_APPEND 0x0002
#define XFS_XFLAG_IMMUTABLE 0x0001
#define XFS_XFLAG_APPEND 0x0002

typedef unsigned int xfs_extlen_t;
typedef unsigned int xfs_fsblock_t;

typedef struct xfs_inode {
    struct xfs_mount *i_mount;
    struct xfs_dquot *i_pdquot;
    struct {
        unsigned int di_uid;
        unsigned int di_gid;
        unsigned int di_projid;
        unsigned int di_nextents;
        unsigned int di_extsize;
        unsigned int di_flags;
        unsigned int di_mode;
        unsigned int di_version;
    } i_d;
    unsigned int i_delayed_blks;
} xfs_inode_t;

typedef struct xfs_mount {
    unsigned int m_flags;
    struct {
        unsigned int sb_blocklog;
        unsigned int sb_rextsize;
        unsigned int sb_blocksize;
        unsigned int sb_agblocks;
        unsigned int sb_rblocks;
        unsigned int sb_versionnum;
    } m_sb;
} xfs_mount_t;

typedef struct xfs_trans {
    int dummy;
} xfs_trans_t;

typedef struct xfs_dquot {
    int dummy;
} xfs_dquot_t;

typedef struct fsxattr {
    unsigned int fsx_projid;
    unsigned int fsx_extsize;
    unsigned int fsx_xflags;
} fsxattr_t;

#define trace_xfs_ioctl_setattr(ip)
#define xfs_sb_version_hasprojid32bit(sb) (0)
#define xfs_qm_vop_dqalloc(ip, uid, gid, projid, opt, udqp, gdqp, pdqp) (0)
#define xfs_trans_alloc(mp, type) ((struct xfs_trans *)0)
#define xfs_trans_reserve(tp, res, blocks, rtextents) (0)
#define xfs_ilock(ip, flags)
#define xfs_iunlock(ip, flags)
#define xfs_trans_ijoin(tp, ip, flags)
#define xfs_set_projid(ip, projid)
#define xfs_get_projid(ip) (0)
#define xfs_bump_ino_vers2(tp, ip)
#define xfs_set_diflags(ip, flags)
#define xfs_diflags_to_linux(ip)
#define xfs_trans_ichgtime(tp, ip, flags)
#define xfs_trans_log_inode(tp, ip, flags)
#define xfs_trans_set_sync(tp)
#define xfs_trans_commit(tp, flags) (0)
#define xfs_trans_cancel(tp, flags)
#define xfs_qm_vop_chown_reserve(tp, ip, udqp, gdqp, pdqp, flags) (0)
#define xfs_qm_vop_chown(tp, ip, olddquot, newdquot) ((struct xfs_dquot *)0)
#define xfs_qm_dqrele(dqp)
#define XFS_STATS_INC(x)
#define M_RES(mp) ((struct xfs_mres *)0)
#define VFS_I(ip) ((struct inode *)0)
#define inode_owner_or_capable(inode) (0)
#define capable(cap) (0)
#define capable_wrt_inode_uidgid(inode, cap) (0)
#define current_user_ns() (&init_user_ns)
#define init_user_ns (*(struct user_namespace *)0)
#define ASSERT(expr)
#define XFS_B_TO_FSB(mp, b) ((b) >> (mp)->m_sb.sb_blocklog)
#define XFS_IS_REALTIME_INODE(ip) (0)