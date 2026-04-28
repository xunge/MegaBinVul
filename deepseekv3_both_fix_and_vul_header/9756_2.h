#include <stdint.h>

typedef uint64_t xfs_ino_t;
typedef uint32_t xfs_agnumber_t;
typedef uint32_t xfs_agblock_t;
typedef uint32_t xfs_agino_t;
typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;
typedef struct xfs_buf xfs_buf_t;
typedef struct xfs_btree_cur xfs_btree_cur_t;
typedef struct xfs_inobt_rec_incore xfs_inobt_rec_incore_t;
typedef unsigned int uint;
typedef unsigned short ushort;

#define NULLFSINO ((xfs_ino_t)-1)
#define XFS_ERROR(e) (-(e))
#define EINVAL 22
#define CE_ALERT 1

#define XFS_IGET_BULKSTAT 0x1
#define XFS_LOOKUP_LE 1
#define XFS_BTREE_NOERROR 0

struct xfs_sb {
    uint32_t sb_agcount;
    uint32_t sb_agblocks;
    uint64_t sb_dblocks;
    uint32_t sb_blocksize;
    uint32_t sb_inopblock;
    uint32_t sb_inodelog;
    uint32_t sb_blocklog;
};

struct xfs_mount {
    struct xfs_sb m_sb;
    uint32_t m_inoalign_mask;
};

struct xfs_imap {
    uint64_t im_blkno;
    uint64_t im_len;
    ushort im_boffset;
};

struct xfs_inobt_rec_incore {
    xfs_agino_t ir_startino;
};

#define XFS_INO_TO_AGNO(mp, i) ((xfs_agnumber_t)((i) >> 32))
#define XFS_INO_TO_AGINO(mp, i) ((xfs_agino_t)(i))
#define XFS_AGINO_TO_AGBNO(mp, i) ((xfs_agblock_t)((i) >> (mp)->m_sb.sb_inodelog))
#define XFS_AGINO_TO_INO(mp, a, i) (((xfs_ino_t)(a) << 32 | (i)))
#define XFS_INODE_CLUSTER_SIZE(mp) ((mp)->m_sb.sb_blocksize)
#define XFS_INO_TO_OFFSET(mp, i) ((int)((i) & ((1 << (mp)->m_sb.sb_inodelog) - 1)))
#define XFS_AGB_TO_DADDR(mp, a, b) ((uint64_t)((a) * (mp)->m_sb.sb_agblocks + (b)) * (mp)->m_sb.sb_blocksize)
#define XFS_FSB_TO_BB(mp, b) ((uint64_t)(b) * ((mp)->m_sb.sb_blocksize / 512))

void xfs_fs_cmn_err(int level, struct xfs_mount *mp, const char *fmt, ...);
void xfs_stack_trace(void);
void ASSERT(int expr);
int xfs_daddr_to_agbno(struct xfs_mount *mp, uint64_t daddr);
int xfs_ialloc_read_agi(struct xfs_mount *mp, struct xfs_trans *tp, xfs_agnumber_t agno, struct xfs_buf **agbp);
struct xfs_btree_cur *xfs_inobt_init_cursor(struct xfs_mount *mp, struct xfs_trans *tp, struct xfs_buf *agbp, xfs_agnumber_t agno);
int xfs_inobt_lookup(struct xfs_btree_cur *cur, xfs_agino_t agino, int dir, int *stat);
int xfs_inobt_get_rec(struct xfs_btree_cur *cur, struct xfs_inobt_rec_incore *rec, int *stat);
void xfs_trans_brelse(struct xfs_trans *tp, struct xfs_buf *bp);
void xfs_btree_del_cursor(struct xfs_btree_cur *cur, int error);