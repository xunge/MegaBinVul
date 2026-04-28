#include <stdint.h>
#include <string.h>

#define STATIC static
#define ASSERT(expr) ((void)0)
#define XFS_ATTR_LEAF_MAPSIZE 3
#define XFS_LBSIZE(mp) (mp->m_sb.sb_blocksize)
#define XFS_DA_LOGRANGE(leaf, ptr, size) (ptr), (size)
#define XFS_ATTR_LOCAL 0x01
#define XFS_ATTR_INCOMPLETE 0x02
#define XFS_DA_OP_RENAME 0x01

typedef struct xfs_attr_leaf_entry xfs_attr_leaf_entry_t;

struct xfs_buf {
    void *b_addr;
};

struct xfs_attr3_icleaf_hdr {
    uint16_t count;
    uint16_t usedbytes;
    uint16_t firstused;
    struct {
        uint16_t base;
        uint16_t size;
    } freemap[XFS_ATTR_LEAF_MAPSIZE];
};

struct xfs_da_args {
    uint32_t hashval;
    uint8_t namelen;
    uint16_t valuelen;
    uint32_t flags;
    uint32_t op_flags;
    uint32_t index;
    uint32_t index2;
    uint64_t blkno;
    uint64_t blkno2;
    uint64_t rmtblkno;
    uint32_t rmtblkcnt;
    uint32_t rmtvaluelen;
    char *name;
    char *value;
    struct xfs_trans *trans;
};

struct xfs_trans {
    struct xfs_mount *t_mountp;
};

struct xfs_mount {
    struct {
        uint32_t sb_blocksize;
    } m_sb;
};

struct xfs_attr_leafblock {
    uint8_t data[0];
};

struct xfs_attr_leaf_entry {
    uint16_t nameidx;
    uint32_t hashval;
    uint8_t flags;
};

struct xfs_attr_leaf_name_local {
    uint8_t namelen;
    uint16_t valuelen;
    uint8_t nameval[1];
};

struct xfs_attr_leaf_name_remote {
    uint8_t namelen;
    uint32_t valuelen;
    uint32_t valueblk;
    uint8_t name[1];
};

static inline uint16_t cpu_to_be16(uint16_t x) { return x; }
static inline uint32_t cpu_to_be32(uint32_t x) { return x; }
static inline uint16_t be16_to_cpu(uint16_t x) { return x; }
static inline uint32_t be32_to_cpu(uint32_t x) { return x; }

static inline struct xfs_attr_leaf_entry *
xfs_attr3_leaf_entryp(struct xfs_attr_leafblock *leaf)
{
    return (struct xfs_attr_leaf_entry *)((char *)leaf + sizeof(struct xfs_attr3_icleaf_hdr));
}

static inline struct xfs_attr_leaf_name_local *
xfs_attr3_leaf_name_local(struct xfs_attr_leafblock *leaf, int idx)
{
    return (struct xfs_attr_leaf_name_local *)
        ((char *)leaf + be16_to_cpu(xfs_attr3_leaf_entryp(leaf)[idx].nameidx));
}

static inline struct xfs_attr_leaf_name_remote *
xfs_attr3_leaf_name_remote(struct xfs_attr_leafblock *leaf, int idx)
{
    return (struct xfs_attr_leaf_name_remote *)
        ((char *)leaf + be16_to_cpu(xfs_attr3_leaf_entryp(leaf)[idx].nameidx));
}

static inline void *
xfs_attr3_leaf_name(struct xfs_attr_leafblock *leaf, int idx)
{
    return (xfs_attr3_leaf_entryp(leaf)[idx].flags & XFS_ATTR_LOCAL) ?
        (void *)xfs_attr3_leaf_name_local(leaf, idx) :
        (void *)xfs_attr3_leaf_name_remote(leaf, idx);
}

static inline size_t xfs_attr3_leaf_hdr_size(struct xfs_attr_leafblock *leaf)
{
    return sizeof(struct xfs_attr3_icleaf_hdr);
}

static inline size_t xfs_attr_leaf_entsize(struct xfs_attr_leafblock *leaf, int idx)
{
    if (xfs_attr3_leaf_entryp(leaf)[idx].flags & XFS_ATTR_LOCAL) {
        return sizeof(struct xfs_attr_leaf_name_local) - 1 +
               xfs_attr3_leaf_name_local(leaf, idx)->namelen +
               be16_to_cpu(xfs_attr3_leaf_name_local(leaf, idx)->valuelen);
    } else {
        return sizeof(struct xfs_attr_leaf_name_remote) - 1 +
               xfs_attr3_leaf_name_remote(leaf, idx)->namelen;
    }
}

static inline int xfs_attr_leaf_newentsize(int namelen, int valuelen, int blocksize, int *local) { return 0; }
static inline int xfs_attr3_rmt_blocks(struct xfs_mount *mp, int valuelen) { return 0; }
static inline void xfs_trans_log_buf(struct xfs_trans *tp, struct xfs_buf *bp, void *ptr, size_t size) {}
static inline uint32_t XFS_ATTR_NSP_ARGS_TO_ONDISK(uint32_t flags) { return flags; }
static inline void trace_xfs_attr_leaf_add_work(struct xfs_da_args *args) {}