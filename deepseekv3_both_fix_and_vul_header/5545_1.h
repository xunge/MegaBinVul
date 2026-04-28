#include <stdint.h>
#include <string.h>
#include <errno.h>

#define XFS_LBSIZE(mp) (1 << (mp)->m_sb.sb_blocklog)
#define XFS_ERROR(err) (-(err))
#define ENOATTR ENODATA
#define XFS_ATTR_INCOMPLETE (1 << 0)
#define XFS_ATTR_LOCAL (1 << 1)
#define ASSERT(expr) ((void)0)
#define be32_to_cpu(x) __builtin_bswap32(x)

struct xfs_buf {
    void *b_addr;
};

struct xfs_da_args {
    uint32_t hashval;
    uint32_t flags;
    uint32_t namelen;
    const char *name;
    uint32_t valuelen;
    uint32_t rmtvaluelen;
    uint32_t rmtblkno;
    uint32_t rmtblkcnt;
    uint32_t index;
    struct {
        struct {
            struct {
                int sb_blocklog;
            } m_sb;
        } *i_mount;
    } *dp;
};

struct xfs_attr_leafblock {
    uint8_t data[0];
};

struct xfs_attr3_icleaf_hdr {
    uint32_t count;
};

struct xfs_attr_leaf_entry {
    uint32_t hashval;
    uint16_t flags;
};

struct xfs_attr_leaf_name_local {
    uint16_t namelen;
    char nameval[0];
};

struct xfs_attr_leaf_name_remote {
    uint16_t namelen;
    uint32_t valuelen;
    uint32_t valueblk;
    char name[0];
};

typedef uint32_t xfs_dahash_t;

static inline void xfs_attr3_leaf_hdr_from_disk(struct xfs_attr3_icleaf_hdr *ichdr, struct xfs_attr_leafblock *leaf) {}
static inline struct xfs_attr_leaf_entry *xfs_attr3_leaf_entryp(struct xfs_attr_leafblock *leaf) { return NULL; }
static inline struct xfs_attr_leaf_name_local *xfs_attr3_leaf_name_local(struct xfs_attr_leafblock *leaf, int probe) { return NULL; }
static inline struct xfs_attr_leaf_name_remote *xfs_attr3_leaf_name_remote(struct xfs_attr_leafblock *leaf, int probe) { return NULL; }
static inline int xfs_attr_namesp_match(uint32_t a, uint32_t b) { return 0; }
static inline uint32_t xfs_attr3_rmt_blocks(void *mp, uint32_t len) { return 0; }
static inline void trace_xfs_attr_leaf_lookup(struct xfs_da_args *args) {}