#include <stdint.h>
#include <string.h>

#define ASSERT(expr) ((void)0)
#define BBSIZE 512

typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_fsop_geom xfs_fsop_geom_t;
typedef struct xfs_sb xfs_sb_t;

struct xfs_sb {
    uint32_t sb_blocksize;
    uint32_t sb_rextsize;
    uint32_t sb_agblocks;
    uint32_t sb_agcount;
    uint32_t sb_logblocks;
    uint32_t sb_sectsize;
    uint16_t sb_inodesize;
    uint16_t sb_imax_pct;
    uint64_t sb_dblocks;
    uint64_t sb_rblocks;
    uint64_t sb_rextents;
    uint64_t sb_logstart;
    uint8_t sb_uuid[16];
    uint32_t sb_unit;
    uint32_t sb_width;
    uint32_t sb_logsectsize;
    uint32_t sb_logsunit;
};

struct xfs_mount {
    struct xfs_sb m_sb;
    uint32_t m_dirblksize;
};

struct xfs_fsop_geom {
    uint32_t blocksize;
    uint32_t rtextsize;
    uint32_t agblocks;
    uint32_t agcount;
    uint32_t logblocks;
    uint32_t sectsize;
    uint32_t inodesize;
    uint32_t imaxpct;
    uint64_t datablocks;
    uint64_t rtblocks;
    uint64_t rtextents;
    uint64_t logstart;
    uint8_t uuid[16];
    uint32_t sunit;
    uint32_t swidth;
    uint32_t version;
    uint32_t flags;
    uint32_t logsectsize;
    uint32_t rtsectsize;
    uint32_t dirblocksize;
    uint32_t logsunit;
};

#define XFS_FSOP_GEOM_VERSION 3
#define XFS_FSOP_GEOM_FLAGS_ATTR    (1 << 0)
#define XFS_FSOP_GEOM_FLAGS_NLINK   (1 << 1)
#define XFS_FSOP_GEOM_FLAGS_QUOTA   (1 << 2)
#define XFS_FSOP_GEOM_FLAGS_IALIGN  (1 << 3)
#define XFS_FSOP_GEOM_FLAGS_DALIGN  (1 << 4)
#define XFS_FSOP_GEOM_FLAGS_SHARED  (1 << 5)
#define XFS_FSOP_GEOM_FLAGS_EXTFLG  (1 << 6)
#define XFS_FSOP_GEOM_FLAGS_DIRV2   (1 << 7)
#define XFS_FSOP_GEOM_FLAGS_SECTOR  (1 << 8)
#define XFS_FSOP_GEOM_FLAGS_DIRV2CI (1 << 9)
#define XFS_FSOP_GEOM_FLAGS_LAZYSB  (1 << 10)
#define XFS_FSOP_GEOM_FLAGS_ATTR2   (1 << 11)
#define XFS_FSOP_GEOM_FLAGS_LOGV2   (1 << 12)

static inline int xfs_sb_version_hasattr(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasnlink(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasquota(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasalign(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasdalign(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasshared(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasextflgbit(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasdirv2(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hassector(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasasciici(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_haslazysbcount(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_hasattr2(xfs_sb_t *sb) { return 0; }
static inline int xfs_sb_version_haslogv2(xfs_sb_t *sb) { return 0; }