#include <stdint.h>
#include <stddef.h>

#define ATTR_RMTVALUE_MAPSIZE 1
#define DELAYSTARTBLOCK 0
#define HOLESTARTBLOCK 0
#define XFS_BMAPI_ATTRFORK 0
#define ATTR_KERNOVAL 0

struct xfs_bmbt_irec;
struct xfs_mount;
struct xfs_buf;
struct xfs_inode;

typedef uint64_t xfs_dablk_t;
typedef uint64_t xfs_fileoff_t;
typedef uint64_t xfs_daddr_t;
typedef uint64_t xfs_fsblock_t;

#define XFS_FSB_TO_DADDR(mp, b) 0
#define XFS_FSB_TO_BB(mp, b) 0

struct xfs_bmbt_irec {
    xfs_fsblock_t br_startblock;
    uint64_t br_blockcount;
};

struct xfs_mount {
    void *m_ddev_targp;
};

struct xfs_inode {
    struct xfs_mount *i_mount;
    uint64_t i_ino;
};

struct xfs_buf;

struct xfs_da_args {
    struct xfs_inode *dp;
    uint32_t flags;
    uint32_t rmtblkno;
    uint32_t rmtblkcnt;
    uint32_t rmtvaluelen;
    uint32_t valuelen;
    uint8_t *value;
};

extern void trace_xfs_attr_rmtval_get(struct xfs_da_args *args);
extern int xfs_bmapi_read(struct xfs_inode *dp, xfs_fileoff_t lblkno,
              int blkcnt, struct xfs_bmbt_irec *map, int *nmap, int flags);
extern int xfs_trans_read_buf(struct xfs_mount *mp, void *tp, void *target,
               xfs_daddr_t blkno, int blkcnt, int flags,
               struct xfs_buf **bpp, void *ops);
extern void xfs_buf_relse(struct xfs_buf *bp);
extern int xfs_attr_rmtval_copyout(struct xfs_mount *mp, struct xfs_buf *bp,
                    uint64_t ino, int *offset, int *valuelen,
                    uint8_t **dst);
extern void *xfs_attr3_rmt_buf_ops;

#define ASSERT(expr) ((void)0)