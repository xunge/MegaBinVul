#include <stdint.h>
#include <string.h>

struct xfs_da_args {
    struct xfs_trans *trans;
    struct xfs_inode *dp;
    int blkno;
    int index;
    uint32_t hashval;
    int namelen;
    char *name;
    int rmtblkno;
    int rmtvaluelen;
    int valuelen;
};

struct xfs_attr_leafblock;
struct xfs_attr_leaf_entry {
    uint32_t hashval;
    uint16_t flags;
};
struct xfs_attr_leaf_name_remote {
    uint8_t namelen;
    char name[1];
    uint32_t valueblk;
    uint32_t valuelen;
};
struct xfs_buf {
    void *b_addr;
};
struct xfs_attr3_icleaf_hdr {
    int count;
};
struct xfs_attr_leaf_name_local {
    uint8_t namelen;
    char nameval[1];
};
typedef struct xfs_attr_leaf_name_local xfs_attr_leaf_name_local_t;
struct xfs_trans;
struct xfs_inode;

#define DEBUG 1
#define ASSERT(cond) ((void)0)
#define XFS_ATTR_INCOMPLETE 0x01
#define XFS_ATTR_LOCAL 0x02
#define be32_to_cpu(x) (x)
#define cpu_to_be32(x) (x)

#define trace_xfs_attr_leaf_clearflag(args) ((void)0)
#define XFS_DA_LOGRANGE(leaf, ptr, size) (0)

int xfs_attr3_leaf_read(struct xfs_trans *trans, struct xfs_inode *dp, int blkno, int flags, struct xfs_buf **bpp);
int xfs_trans_roll(struct xfs_trans **tpp, struct xfs_inode *dp);
void xfs_trans_log_buf(struct xfs_trans *tp, struct xfs_buf *bp, int range);
struct xfs_attr_leaf_entry *xfs_attr3_leaf_entryp(struct xfs_attr_leafblock *leaf);
void xfs_attr3_leaf_hdr_from_disk(struct xfs_attr3_icleaf_hdr *ichdr, struct xfs_attr_leafblock *leaf);
struct xfs_attr_leaf_name_local *xfs_attr3_leaf_name_local(struct xfs_attr_leafblock *leaf, int index);
struct xfs_attr_leaf_name_remote *xfs_attr3_leaf_name_remote(struct xfs_attr_leafblock *leaf, int index);