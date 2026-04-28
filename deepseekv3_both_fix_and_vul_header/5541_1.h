#include <errno.h>
#include <stddef.h>

#define STATIC static
#define ENOATTR ENOENT

#define ATTR_REPLACE (1 << 0)
#define ATTR_CREATE (1 << 1)

#define XFS_DA_OP_RENAME (1 << 0)

typedef struct xfs_da_args xfs_da_args_t;
typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_buf xfs_buf_t;
typedef struct xfs_trans xfs_trans_t;
typedef struct xfs_bmap_free xfs_bmap_free_t;

struct xfs_da_args {
    xfs_trans_t *trans;
    xfs_inode_t *dp;
    int blkno;
    int blkno2;
    int index;
    int index2;
    int rmtblkno;
    int rmtblkno2;
    int rmtblkcnt;
    int rmtblkcnt2;
    int rmtvaluelen;
    int rmtvaluelen2;
    int flags;
    int op_flags;
    xfs_bmap_free_t *flist;
    void *firstblock;
};

struct xfs_bmap_free {
    int dummy;
};

#define trace_xfs_attr_leaf_addname(args)
#define trace_xfs_attr_leaf_replace(args)
#define xfs_attr3_leaf_read(trans, dp, blkno, i, bp) (0)
#define xfs_attr3_leaf_lookup_int(bp, args) (0)
#define xfs_trans_brelse(trans, bp)
#define xfs_attr3_leaf_add(bp, args) (0)
#define xfs_bmap_init(flist, firstblock)
#define xfs_attr3_leaf_to_node(args) (0)
#define xfs_bmap_finish(trans, flist, committed) (0)
#define xfs_bmap_cancel(flist)
#define xfs_trans_ijoin(trans, dp, i)
#define xfs_trans_roll(trans, dp) (0)
#define xfs_attr_node_addname(args) (0)
#define xfs_attr_rmtval_set(args) (0)
#define xfs_attr3_leaf_flipflags(args) (0)
#define xfs_attr_rmtval_remove(args) (0)
#define xfs_attr3_leaf_remove(bp, args)
#define xfs_attr_shortform_allfit(bp, dp) (0)
#define xfs_attr3_leaf_to_shortform(bp, args, forkoff) (0)
#define xfs_attr3_leaf_clearflag(args) (0)