#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>

#define NULLFSINO ((xfs_ino_t)-1)
#define XFS_ERROR(err) (err)
#define EINVAL 22

#define XFS_DQ_USER     (1 << 0)
#define XFS_DQ_GROUP    (1 << 1)
#define XFS_DQ_PROJ     (1 << 2)

#define qdprintk(fmt, ...)

typedef uint64_t xfs_ino_t;
typedef unsigned int uint;

struct xfs_sb {
    unsigned int sb_uquotino;
    unsigned int sb_gquotino;
    unsigned int m_qflags;
    unsigned int sb_features;
    int sb_versionnum;
};

struct xfs_mount {
    struct xfs_sb m_sb;
};

struct xfs_inode {
    // inode structure members
};

typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_mount xfs_mount_t;

#define IRELE(ip) 

static inline int xfs_sb_version_hasquota(struct xfs_sb *sb) {
    return 0;
}

static inline int xfs_iget(xfs_mount_t *mp, void *null, xfs_ino_t ino, int a, int b, xfs_inode_t **qip, ...) {
    return 0;
}

static inline int xfs_truncate_file(xfs_mount_t *mp, xfs_inode_t *ip) {
    return 0;
}