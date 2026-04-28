#include <stdint.h>
#include <sys/types.h>
#include <assert.h>

typedef uint64_t xfs_ino_t;
typedef uint32_t xfs_agnumber_t;
typedef uint32_t xfs_agblock_t;
typedef uint32_t xfs_agino_t;
typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;
typedef unsigned int uint;

#define NULLFSINO ((xfs_ino_t)-1)
#define XFS_IGET_UNTRUSTED 0x1
#define XFS_IGET_BULKSTAT  0x2
#define EINVAL 22
#define CE_ALERT 1

#define XFS_ERROR(err) (err)
#define ASSERT(expr) assert(expr)

struct xfs_sb {
    uint32_t sb_agcount;
    uint32_t sb_agblocks;
    uint64_t sb_dblocks;
    uint32_t sb_blocklog;
    uint32_t sb_inopblock;
    uint32_t sb_inodelog;
    uint32_t sb_blocksize;
    uint32_t sb_inopcluster;
    uint32_t sb_agblklog;
    uint32_t sb_inopblog;
};

struct xfs_mount {
    struct xfs_sb m_sb;
    uint32_t m_inoalign_mask;
};

struct xfs_imap {
    uint64_t im_blkno;
    uint64_t im_len;
    uint16_t im_boffset;
};

#define XFS_INO_TO_AGNO(mp, i) \
    ((xfs_agnumber_t)((i) >> (mp)->m_sb.sb_agblklog))
#define XFS_INO_TO_AGINO(mp, i) \
    ((xfs_agino_t)((i) & ((1 << (mp)->m_sb.sb_agblklog) - 1)))
#define XFS_AGINO_TO_AGBNO(mp, i) \
    ((xfs_agblock_t)((i) >> (mp)->m_sb.sb_inopblog))
#define XFS_AGINO_TO_INO(mp, a, i) \
    (((xfs_ino_t)(a) << (mp)->m_sb.sb_agblklog) | (i))
#define XFS_INO_TO_OFFSET(mp, i) \
    ((int)((i) & ((mp)->m_sb.sb_inopblock - 1)))
#define XFS_AGB_TO_DADDR(mp, a, b) \
    ((uint64_t)((a) * (mp)->m_sb.sb_agblocks + (b)) << (mp)->m_sb.sb_blocklog)
#define XFS_FSB_TO_BB(mp, fsb) \
    ((uint64_t)(fsb) << (mp)->m_sb.sb_blocklog)
#define XFS_INODE_CLUSTER_SIZE(mp) \
    ((mp)->m_sb.sb_blocksize * (mp)->m_sb.sb_inopcluster)

int xfs_imap_lookup(struct xfs_mount *mp, struct xfs_trans *tp, xfs_agnumber_t agno,
                   xfs_agino_t agino, xfs_agblock_t agbno, xfs_agblock_t *chunk_agbno,
                   int *offset_agbno, uint flags);
void xfs_fs_cmn_err(int level, struct xfs_mount *mp, const char *fmt, ...);
void xfs_stack_trace(void);