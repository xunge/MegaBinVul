#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#define DELAYSTARTBLOCK (-1)
#define HOLESTARTBLOCK (-2)
#define XFS_ATTR_FORK 0
#define XFS_BMAPI_ATTRFORK 0
#define XFS_BMAPI_METADATA 0

#define ASSERT(cond) ((void)0)
#define XFS_FSB_TO_DADDR(mp, fsbno) ((xfs_daddr_t)(fsbno))
#define XFS_FSB_TO_BB(mp, fsbno) ((int)(fsbno))

typedef uint64_t xfs_daddr_t;
typedef uint64_t xfs_fileoff_t;
typedef uint32_t xfs_dablk_t;
typedef uint64_t xfs_filblks_t;

struct xfs_bmbt_irec {
    xfs_daddr_t br_startblock;
    xfs_fileoff_t br_blockcount;
};

struct xfs_buf_ops {
    /* dummy structure to satisfy compilation */
    int dummy;
};

struct xfs_buf {
    const struct xfs_buf_ops *b_ops;
};

extern struct xfs_buf_ops xfs_attr3_rmt_buf_ops;

struct xfs_mount;
struct xfs_inode;
struct xfs_trans;
struct xfs_bmap_free;

struct xfs_da_args {
    struct xfs_trans *trans;
    struct xfs_inode *dp;
    void *firstblock;
    struct xfs_bmap_free *flist;
    int total;
    uint8_t *value;
    int valuelen;
    int rmtvaluelen;
    xfs_dablk_t rmtblkno;
    int rmtblkcnt;
};

struct xfs_inode {
    struct xfs_mount *i_mount;
    uint64_t i_ino;
};

struct xfs_mount {
    void *m_ddev_targp;
};

extern void trace_xfs_attr_rmtval_set(struct xfs_da_args *args);
extern int xfs_attr3_rmt_blocks(struct xfs_mount *mp, int valuelen);
extern int xfs_bmap_first_unused(struct xfs_trans *tp, struct xfs_inode *ip, int count, xfs_fileoff_t *first_unused, int fork);
extern void xfs_bmap_init(struct xfs_bmap_free *flist, void *firstblock);
extern int xfs_bmapi_write(struct xfs_trans *tp, struct xfs_inode *ip, xfs_fileoff_t bno, xfs_filblks_t len, int flags, void *firstblock, int total, struct xfs_bmbt_irec *mval, int *nmap, struct xfs_bmap_free *flist);
extern int xfs_bmap_finish(struct xfs_trans **tp, struct xfs_bmap_free *flist, int *committed);
extern void xfs_bmap_cancel(struct xfs_bmap_free *flist);
extern void xfs_trans_ijoin(struct xfs_trans *tp, struct xfs_inode *ip, int flags);
extern int xfs_trans_roll(struct xfs_trans **tp, struct xfs_inode *ip);
extern int xfs_bmapi_read(struct xfs_inode *ip, xfs_fileoff_t bno, xfs_filblks_t len, struct xfs_bmbt_irec *mval, int *nmap, int flags);
extern struct xfs_buf *xfs_buf_get(void *target, xfs_daddr_t blkno, int len, int flags);
extern void xfs_attr_rmtval_copyin(struct xfs_mount *mp, struct xfs_buf *bp, uint64_t ino, int *offset, int *valuelen, uint8_t **src);
extern int xfs_bwrite(struct xfs_buf *bp);
extern void xfs_buf_relse(struct xfs_buf *bp);