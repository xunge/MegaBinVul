#include <stdint.h>
#include <stddef.h>

typedef void *xfs_failaddr_t;
#define __this_address ((xfs_failaddr_t)1)

typedef unsigned char uuid_t[16];

struct xfs_perag {
    uint32_t pag_agno;
};

struct xfs_sb {
    uuid_t sb_meta_uuid;
    uint64_t sb_dblocks;
};

struct xfs_mount {
    struct xfs_sb m_sb;
};

struct xfs_buf {
    struct xfs_mount *b_mount;
    struct xfs_perag *b_pag;
};

struct xfs_agf {
    uuid_t agf_uuid;
    uint64_t agf_lsn;
    uint32_t agf_magicnum;
    uint32_t agf_versionnum;
    uint32_t agf_freeblks;
    uint32_t agf_length;
    uint32_t agf_flfirst;
    uint32_t agf_fllast;
    uint32_t agf_flcount;
    uint32_t agf_levels[4];
    uint32_t agf_rmap_blocks;
    uint32_t agf_seqno;
    uint32_t agf_btreeblks;
    uint32_t agf_refcount_blocks;
    uint32_t agf_refcount_level;
    uint32_t agf_longest;
};

#define XFS_BUF_TO_AGF(bp) ((struct xfs_agf *)(bp))
#define XFS_BTREE_MAXLEVELS 9
#define XFS_BTNUM_BNO 0
#define XFS_BTNUM_CNT 1
#define XFS_BTNUM_RMAP 2

static inline int xfs_sb_version_hascrc(struct xfs_sb *sb) { return 0; }
static inline int xfs_sb_version_hasrmapbt(struct xfs_sb *sb) { return 0; }
static inline int xfs_sb_version_haslazysbcount(struct xfs_sb *sb) { return 0; }
static inline int xfs_sb_version_hasreflink(struct xfs_sb *sb) { return 0; }
static inline int xfs_verify_magic(struct xfs_buf *bp, uint32_t magic) { return 0; }
static inline int xfs_log_check_lsn(struct xfs_mount *mp, uint64_t lsn) { return 0; }
static inline uint32_t xfs_agfl_size(struct xfs_mount *mp) { return 0; }
static inline int XFS_AGF_GOOD_VERSION(uint32_t version) { return 0; }
static inline int uuid_equal(const uuid_t *u1, const uuid_t *u2) { return 0; }
static inline uint32_t be32_to_cpu(uint32_t x) { return x; }
static inline uint64_t be64_to_cpu(uint64_t x) { return x; }