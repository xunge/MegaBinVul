#include <stdint.h>
#include <stddef.h>

#define NULLFSINO ((xfs_ino_t)-1)
#define XFS_ERROR(e) (e)
#define ASSERT(expr) ((void)0)
#define IRELE(ip) ((void)0)
#define STATIC static

typedef int64_t __int64_t;
typedef uint64_t xfs_ino_t;
typedef unsigned int uint;

struct xfs_inode;
struct xfs_quotainfo;

#define XFS_IS_UQUOTA_ON(mp) (0)
#define XFS_IS_OQUOTA_ON(mp) (0)
#define XFS_IS_GQUOTA_ON(mp) (0)
#define XFS_SB_VERSIONNUM (0)
#define XFS_SB_UQUOTINO (0)
#define XFS_SB_GQUOTINO (0)
#define XFS_SB_QFLAGS (0)
#define XFS_QMOPT_SBVERSION (0)
#define XFS_QMOPT_UQUOTA (0)
#define XFS_QMOPT_GQUOTA (0)
#define XFS_QMOPT_PQUOTA (0)

struct xfs_sb {
    xfs_ino_t sb_uquotino;
    xfs_ino_t sb_gquotino;
};

struct xfs_mount {
    struct xfs_sb m_sb;
    struct xfs_quotainfo *m_quotainfo;
};
typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_inode xfs_inode_t;

struct xfs_quotainfo {
    xfs_inode_t *qi_uquotaip;
    xfs_inode_t *qi_gquotaip;
};

static inline int xfs_sb_version_hasquota(struct xfs_sb *sb) { return 0; }
static inline int xfs_iget(xfs_mount_t *mp, void *p, xfs_ino_t ino, int a, int b, xfs_inode_t **ip, ...) { return 0; }
static inline int xfs_qm_qino_alloc(xfs_mount_t *mp, xfs_inode_t **ip, __int64_t sbflags, uint flags) { return 0; }