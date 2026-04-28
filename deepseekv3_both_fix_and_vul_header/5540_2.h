#include <stdint.h>
#include <errno.h>
#include <stddef.h>

#define STATIC static
#define ASSERT(expr) ((void)0)
#define trace_xfs_attr_node_addname(args) ((void)0)
#define trace_xfs_attr_node_replace(args) ((void)0)

#define XFS_ATTR_LEAF_MAGIC 0x5841324C
#define XFS_DA_OP_RENAME (1 << 0)
#define XFS_ATTR_INCOMPLETE (1 << 1)
#define ATTR_REPLACE (1 << 0)
#define ATTR_CREATE (1 << 1)
#define ENOATTR ENOENT

typedef struct xfs_da_args xfs_da_args_t;
typedef struct xfs_da_state xfs_da_state_t;
typedef struct xfs_da_state_blk xfs_da_state_blk_t;
typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_mount xfs_mount_t;
typedef struct xfs_trans xfs_trans_t;
typedef struct xfs_bmap_free xfs_bmap_free_t;

struct xfs_da_args {
    xfs_inode_t *dp;
    uint32_t flags;
    uint32_t op_flags;
    uint32_t index;
    uint32_t index2;
    uint64_t blkno;
    uint64_t blkno2;
    uint64_t rmtblkno;
    uint64_t rmtblkno2;
    uint32_t rmtblkcnt;
    uint32_t rmtblkcnt2;
    uint32_t rmtvaluelen;
    uint32_t rmtvaluelen2;
    xfs_trans_t *trans;
    xfs_bmap_free_t *flist;
    void *firstblock;
};

struct xfs_da_state {
    xfs_da_args_t *args;
    xfs_mount_t *mp;
    uint32_t blocksize;
    uint32_t node_ents;
    struct {
        int active;
        xfs_da_state_blk_t *blk;
    } path;
    int inleaf;
};

struct xfs_da_state_blk {
    uint32_t magic;
    void *bp;
};

struct xfs_inode {
    xfs_mount_t *i_mount;
};

struct xfs_mount {
    struct {
        uint32_t sb_blocksize;
    } m_sb;
    uint32_t m_attr_node_ents;
};

extern xfs_da_state_t *xfs_da_state_alloc(void);
extern void xfs_da_state_free(xfs_da_state_t *state);
extern int xfs_da3_node_lookup_int(xfs_da_state_t *state, int *retval);
extern int xfs_attr3_leaf_add(void *bp, xfs_da_args_t *args);
extern void xfs_bmap_init(xfs_bmap_free_t *flist, void *firstblock);
extern int xfs_attr3_leaf_to_node(xfs_da_args_t *args);
extern int xfs_bmap_finish(xfs_trans_t **trans, xfs_bmap_free_t *flist, int *committed);
extern void xfs_bmap_cancel(xfs_bmap_free_t *flist);
extern void xfs_trans_ijoin(xfs_trans_t *trans, xfs_inode_t *dp, int flags);
extern int xfs_trans_roll(xfs_trans_t **trans, xfs_inode_t *dp);
extern int xfs_da3_split(xfs_da_state_t *state);
extern void xfs_da3_fixhashpath(xfs_da_state_t *state, void *path);
extern int xfs_attr_rmtval_set(xfs_da_args_t *args);
extern int xfs_attr3_leaf_flipflags(xfs_da_args_t *args);
extern int xfs_attr_rmtval_remove(xfs_da_args_t *args);
extern int xfs_attr3_leaf_remove(void *bp, xfs_da_args_t *args);
extern int xfs_da3_join(xfs_da_state_t *state);
extern int xfs_attr3_leaf_clearflag(xfs_da_args_t *args);