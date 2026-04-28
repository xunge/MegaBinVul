#include <stdint.h>
#include <string.h>

struct xfs_da_args {
    struct xfs_trans *trans;
    struct xfs_inode *dp;
    int blkno;
    int blkno2;
    int index;
    int index2;
    uint32_t rmtblkno;
    uint32_t rmtvaluelen;
    uint32_t valuelen;
};

struct xfs_attr_leafblock {
    char data[1];
};

struct xfs_attr_leaf_entry {
    uint32_t hashval;
    uint16_t nameidx;
    uint8_t flags;
    uint8_t pad;
};

struct xfs_attr_leaf_name_remote {
    uint32_t valueblk;
    uint32_t valuelen;
    uint8_t namelen;
    char name[1];
};

struct xfs_attr_leaf_name_local {
    uint16_t valuelen;
    uint8_t namelen;
    char nameval[1];
};

typedef struct xfs_attr_leaf_name_local xfs_attr_leaf_name_local_t;

struct xfs_buf {
    void *b_addr;
};

struct xfs_attr3_icleaf_hdr {
    uint32_t count;
};

struct xfs_trans;
struct xfs_inode;

#define DEBUG 1
#define XFS_ATTR_INCOMPLETE (1 << 0)
#define XFS_ATTR_LOCAL (1 << 1)
#define ASSERT(cond) ((void)0)
#define trace_xfs_attr_leaf_flipflags(args) ((void)0)
#define XFS_DA_LOGRANGE(leaf, ptr, size) (ptr)

static inline uint32_t be32_to_cpu(uint32_t x) { return x; }
static inline uint32_t cpu_to_be32(uint32_t x) { return x; }

struct xfs_attr_leaf_entry *xfs_attr3_leaf_entryp(struct xfs_attr_leafblock *leaf) { return (void *)leaf->data; }
struct xfs_attr_leaf_name_remote *xfs_attr3_leaf_name_remote(struct xfs_attr_leafblock *leaf, int index) { return (void *)leaf->data; }
struct xfs_attr_leaf_name_local *xfs_attr3_leaf_name_local(struct xfs_attr_leafblock *leaf, int index) { return (void *)leaf->data; }
void xfs_attr3_leaf_hdr_from_disk(struct xfs_attr3_icleaf_hdr *to, struct xfs_attr_leafblock *from) { to->count = 0; }
int xfs_attr3_leaf_read(struct xfs_trans *tp, struct xfs_inode *dp, int blkno, int bblks, struct xfs_buf **bpp) { return 0; }
void xfs_trans_log_buf(struct xfs_trans *tp, struct xfs_buf *bp, void *range) {}
int xfs_trans_roll(struct xfs_trans **tpp, struct xfs_inode *dp) { return 0; }