#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;

#define NULL ((void *)0)

#define ATTR_SIZE       (1 << 0)
#define ATTR_UID        (1 << 1)
#define ATTR_GID        (1 << 2)
#define ATTR_MODE       (1 << 3)
#define ATTR_ATIME      (1 << 4)
#define ATTR_MTIME      (1 << 5)
#define ATTR_CTIME      (1 << 6)

#define CAP_FOWNER      0
#define CAP_FSETID      0

#define XFS_QMOPT_UQUOTA        (1 << 0)
#define XFS_QMOPT_GQUOTA        (1 << 1)
#define XFS_QMOPT_FORCE_RES     (1 << 2)
#define XFS_ATTR_NOACL          (1 << 0)
#define XFS_ILOCK_EXCL          (1 << 0)
#define XFS_ILOG_CORE           (1 << 0)
#define XFS_MOUNT_WSYNC         (1 << 0)

#define ASSERT(expr) do { } while (0)
#define XFS_STATS_INC(mp, counter) do { } while (0)

typedef struct { int val; } kuid_t;
typedef struct { int val; } kgid_t;

#define GLOBAL_ROOT_UID ((kuid_t){0})
#define GLOBAL_ROOT_GID ((kgid_t){0})

#define uid_eq(a, b) ((a).val == (b).val)
#define gid_eq(a, b) ((a).val == (b).val)

struct xfs_mres {
    int tr_ichange;
};

static inline struct xfs_mres *M_RES(struct xfs_mount *mp) 
{
    static struct xfs_mres res;
    return &res;
}

struct xfs_mount {
    unsigned int m_flags;
    struct xfs_mres *M_RES;
    struct {
        unsigned int sb_versionnum;
    } m_sb;
};

struct xfs_inode {
    struct xfs_mount *i_mount;
    struct {
        unsigned int di_uid;
        unsigned int di_gid;
    } i_d;
    struct xfs_dquot *i_udquot;
    struct xfs_dquot *i_gdquot;
};

struct inode {
    kuid_t i_uid;
    kgid_t i_gid;
    mode_t i_mode;
};

struct iattr {
    unsigned int ia_valid;
    kuid_t ia_uid;
    kgid_t ia_gid;
    mode_t ia_mode;
};

struct xfs_dquot;

static inline struct inode *VFS_I(struct xfs_inode *ip) { return (struct inode *)ip; }
static inline int xfs_kuid_to_uid(kuid_t uid) { return uid.val; }
static inline int xfs_kgid_to_gid(kgid_t gid) { return gid.val; }
static inline int xfs_get_projid(struct xfs_inode *ip) { return 0; }
static inline int capable(int cap) { return 1; }
static inline int xfs_sb_version_has_pquotino(struct xfs_mount *mp) { return 0; }

#define XFS_IS_QUOTA_ON(mp) (0)
#define XFS_IS_UQUOTA_ON(mp) (0)
#define XFS_IS_GQUOTA_ON(mp) (0)
#define XFS_IS_QUOTA_RUNNING(mp) (0)
#define XFS_IS_PQUOTA_ON(mp) (0)

int xfs_qm_vop_dqalloc(struct xfs_inode *ip, int uid, int gid, int projid, int flags, 
                      struct xfs_dquot **udqp, struct xfs_dquot **gdqp, void *null);
int xfs_trans_alloc(struct xfs_mount *mp, void *res, int blocks, int logres, int flags, struct xfs_trans **tpp);
void xfs_ilock(struct xfs_inode *ip, int lockflags);
void xfs_trans_ijoin(struct xfs_trans *tp, struct xfs_inode *ip, int flags);
int xfs_qm_vop_chown_reserve(struct xfs_trans *tp, struct xfs_inode *ip, 
                            struct xfs_dquot *udqp, struct xfs_dquot *gdqp, 
                            void *null, int flags);
struct xfs_dquot *xfs_qm_vop_chown(struct xfs_trans *tp, struct xfs_inode *ip, 
                                  struct xfs_dquot **dqp, struct xfs_dquot *newdquot);
void xfs_setattr_mode(struct xfs_inode *ip, struct iattr *iattr);
void xfs_setattr_time(struct xfs_inode *ip, struct iattr *iattr);
void xfs_trans_log_inode(struct xfs_trans *tp, struct xfs_inode *ip, int flags);
void xfs_trans_set_sync(struct xfs_trans *tp);
int xfs_trans_commit(struct xfs_trans *tp);
void xfs_trans_cancel(struct xfs_trans *tp);
void xfs_iunlock(struct xfs_inode *ip, int lockflags);
void xfs_qm_dqrele(struct xfs_dquot *dqp);
int posix_acl_chmod(struct inode *inode, mode_t mode);