#include <stdint.h>

typedef uint32_t xfs_dahash_t;

struct xfs_buf {
    void *b_addr;
};

struct xfs_da_state_blk {
    uint32_t magic;
    struct xfs_buf *bp;
    xfs_dahash_t hashval;
    int index;
};

struct xfs_da_state_path {
    int active;
    struct xfs_da_state_blk blk[];
};

struct xfs_da_args {
    struct xfs_inode *dp;
    void *trans;
};

struct xfs_da_state {
    struct xfs_da_args *args;
};

struct xfs_da_intnode;
struct xfs_da_node_entry {
    uint32_t hashval;
};

struct xfs_da3_icnode_hdr {
    int count;
};

struct xfs_inode {
    struct xfs_dir_ops *d_ops;
};

struct xfs_dir_ops {
    void (*node_hdr_from_disk)(struct xfs_da3_icnode_hdr *hdr, struct xfs_da_intnode *node);
    struct xfs_da_node_entry *(*node_tree_p)(struct xfs_da_intnode *node);
};

#define XFS_ATTR_LEAF_MAGIC 0xfbee
#define XFS_DIR2_LEAFN_MAGIC 0xfebe
#define XFS_DA_NODE_MAGIC 0x3ffe

#define be32_to_cpu(x) (x)
#define cpu_to_be32(x) (x)
#define XFS_DA_LOGRANGE(a, b, c) 0

void trace_xfs_da_fixhashpath(struct xfs_da_args *args);
xfs_dahash_t xfs_attr_leaf_lasthash(struct xfs_buf *bp, int *count);
xfs_dahash_t xfs_dir2_leafn_lasthash(struct xfs_inode *dp, struct xfs_buf *bp, int *count);
xfs_dahash_t xfs_da3_node_lasthash(struct xfs_inode *dp, struct xfs_buf *bp, int *count);
void xfs_trans_log_buf(void *trans, struct xfs_buf *bp, int range);