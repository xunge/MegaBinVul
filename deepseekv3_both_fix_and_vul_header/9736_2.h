#include <stdint.h>
#include <sys/types.h>

typedef uint64_t xfs_daddr_t;
typedef uint32_t uint;
typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;
typedef uint64_t xfs_ino_t;
typedef uint32_t xfs_agino_t;
typedef uint32_t xfs_agnumber_t;
typedef uint32_t xfs_agblock_t;

#define NULLFSINO ((xfs_ino_t)-1)
#define XFS_INO_TO_AGNO(mp, i) ((xfs_agnumber_t)((i) >> (mp)->m_sb.sb_agblklog))
#define XFS_INO_TO_AGINO(mp, i) ((xfs_agino_t)(i))
#define XFS_AGINO_TO_AGBNO(mp, i) ((xfs_agblock_t)((i) >> (mp)->m_sb.sb_inopblog))
#define XFS_AGINO_TO_INO(mp, a, i) ((xfs_ino_t)(((a) << (mp)->m_sb.sb_agblklog) | (i)))
#define XFS_INODE_CLUSTER_SIZE(mp) ((mp)->m_inode_cluster_size)
#define XFS_INO_TO_OFFSET(mp, i) ((int)((i) & ((1 << (mp)->m_sb.sb_inopblog) - 1)))
#define XFS_AGB_TO_DADDR(mp, a, b) ((xfs_daddr_t)(((a) * (mp)->m_sb.sb_agblocks + (b)) << (mp)->m_sb.sb_blocklog))
#define XFS_FSB_TO_BB(mp, b) ((b) << (mp)->m_sb.sb_blocklog)
#define XFS_ERROR(e) (-(e))
#define EINVAL 22
#define CE_ALERT 1
#define XFS_IGET_UNTRUSTED (1 << 0)
#define DEBUG 1

struct xfs_imap {
    xfs_daddr_t im_blkno;
    uint32_t im_len;
    uint16_t im_boffset;
};

struct xfs_sb {
    uint32_t sb_agcount;
    uint32_t sb_agblocks;
    uint64_t sb_dblocks;
    uint32_t sb_blocklog;
    uint32_t sb_inopblog;
    uint32_t sb_inodelog;
    uint32_t sb_agblklog;
    uint32_t sb_blocksize;
    uint32_t sb_inopblock;
};

struct xfs_mount {
    struct xfs_sb m_sb;
    uint32_t m_inode_cluster_size;
    uint32_t m_inoalign_mask;
};

int xfs_imap_lookup(xfs_mount_t *mp, xfs_trans_t *tp, xfs_agnumber_t agno, xfs_agino_t agino, xfs_agblock_t agbno, xfs_agblock_t *chunk_agbno, xfs_agblock_t *offset_agbno, uint flags);
xfs_agblock_t xfs_daddr_to_agbno(xfs_mount_t *mp, xfs_daddr_t daddr);
void xfs_fs_cmn_err(int level, xfs_mount_t *mp, const char *fmt, ...);
void xfs_stack_trace(void);
void ASSERT(int expr);