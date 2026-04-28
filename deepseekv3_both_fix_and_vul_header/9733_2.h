#include <stdint.h>
#include <errno.h>

#define STATIC static

typedef uint32_t xfs_agnumber_t;
typedef uint32_t xfs_agino_t;
typedef uint32_t xfs_agblock_t;

#define CE_ALERT 1
#define XFS_LOOKUP_EQ 1
#define XFS_IGET_UNTRUSTED (1 << 0)
#define XFS_IGET_BULKSTAT (1 << 1)
#define XFS_BTREE_NOERROR 0

struct xfs_mount;
struct xfs_trans;
struct xfs_buf;
struct xfs_btree_cur;

struct xfs_inobt_rec_incore {
    xfs_agino_t ir_startino;
    uint64_t ir_free;
};

#define XFS_IALLOC_INODES(mp) (1)
#define XFS_INOBT_MASK(n) (1ULL << (n))
#define XFS_AGINO_TO_AGBNO(mp, i) ((i) >> 3)

int xfs_ialloc_read_agi(struct xfs_mount *mp, struct xfs_trans *tp, xfs_agnumber_t agno, struct xfs_buf **agbp);
void xfs_fs_cmn_err(int level, struct xfs_mount *mp, const char *fmt, ...);
struct xfs_btree_cur *xfs_inobt_init_cursor(struct xfs_mount *mp, struct xfs_trans *tp, struct xfs_buf *agbp, xfs_agnumber_t agno);
int xfs_inobt_lookup(struct xfs_btree_cur *cur, xfs_agino_t startino, int flags, int *stat);
int xfs_inobt_get_rec(struct xfs_btree_cur *cur, struct xfs_inobt_rec_incore *rec, int *stat);
void xfs_trans_brelse(struct xfs_trans *tp, struct xfs_buf *bp);
void xfs_btree_del_cursor(struct xfs_btree_cur *cur, int error);