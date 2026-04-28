#include <stdint.h>
#include <string.h>
#include <errno.h>

#define XFS_LBSIZE(mp) (1 << (mp)->m_sb.sb_blocklog)
#define XFS_ERROR(err) (-(err))
#define ASSERT(expr) ((void)0)

struct xfs_buf {
    void *b_addr;
};

struct xfs_mount {
    struct {
        unsigned int sb_blocklog;
    } m_sb;
};

struct xfs_inode {
    struct xfs_mount *i_mount;
};

struct xfs_da_args {
    struct xfs_inode *dp;
    int index;
    int namelen;
    char *name;
    int flags;
    int valuelen;
    void *value;
    int rmtvaluelen;
    uint32_t rmtblkno;
    int rmtblkcnt;
};

struct xfs_attr_leafblock {
};

struct xfs_attr3_icleaf_hdr {
    int count;
};

struct xfs_attr_leaf_entry {
    unsigned int flags;
};

struct xfs_attr_leaf_name_local {
    uint16_t valuelen;
    uint16_t namelen;
    char nameval[];
};

struct xfs_attr_leaf_name_remote {
    uint32_t valuelen;
    uint32_t valueblk;
    uint16_t namelen;
    char name[];
};

#define XFS_ATTR_LOCAL 0x01
#define ATTR_KERNOVAL 0x02

static inline uint16_t be16_to_cpu(uint16_t x) { return x; }
static inline uint32_t be32_to_cpu(uint32_t x) { return x; }

static inline struct xfs_attr_leaf_entry *
xfs_attr3_leaf_entryp(struct xfs_attr_leafblock *leaf) { return NULL; }

static inline struct xfs_attr_leaf_name_local *
xfs_attr3_leaf_name_local(struct xfs_attr_leafblock *leaf, int idx) { return NULL; }

static inline struct xfs_attr_leaf_name_remote *
xfs_attr3_leaf_name_remote(struct xfs_attr_leafblock *leaf, int idx) { return NULL; }

static inline void
xfs_attr3_leaf_hdr_from_disk(struct xfs_attr3_icleaf_hdr *to, struct xfs_attr_leafblock *from) {}

static inline int
xfs_attr3_rmt_blocks(struct xfs_mount *mp, int attrlen) { return 0; }