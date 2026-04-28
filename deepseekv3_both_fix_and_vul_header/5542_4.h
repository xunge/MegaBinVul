#include <stdint.h>
#include <string.h>

typedef uint32_t __be32;
typedef uint16_t __be16;

struct xfs_buf {
    void *b_addr;
};

struct xfs_inode {
    void *i_mount;
};

struct xfs_attr_list_context {
    struct attrlist_cursor_kern *cursor;
    int resynch;
    int dupcnt;
    int (*put_listent)(struct xfs_attr_list_context *, int, uint8_t *, int, int, void *);
    int put_value;
    struct xfs_inode *dp;
    int seen_enough;
};

struct attrlist_cursor_kern {
    int initted;
    __be32 hashval;
    int offset;
};

struct xfs_attr3_icleaf_hdr {
    int count;
};

struct xfs_attr_leafblock {
    uint8_t data[1];
};

struct xfs_attr_leaf_entry {
    __be32 hashval;
    uint16_t flags;
};

typedef struct xfs_attr_leaf_name_local {
    __be16 valuelen;
    uint8_t namelen;
    uint8_t nameval[1];
} xfs_attr_leaf_name_local_t;

typedef struct xfs_attr_leaf_name_remote {
    __be32 valueblk;
    __be32 valuelen;
    uint8_t namelen;
    uint8_t name[1];
} xfs_attr_leaf_name_remote_t;

typedef struct xfs_da_args {
    struct xfs_inode *dp;
    int whichfork;
    int valuelen;
    int rmtvaluelen;
    void *value;
    __be32 rmtblkno;
    int rmtblkcnt;
} xfs_da_args_t;

#define XFS_ATTR_INCOMPLETE (1 << 0)
#define XFS_ATTR_LOCAL (1 << 1)
#define XFS_ATTR_FORK 1
#define KM_SLEEP 0x0001u
#define KM_NOFS 0x0010u

static inline uint32_t be32_to_cpu(__be32 x) { return x; }
static inline uint16_t be16_to_cpu(__be16 x) { return x; }

static inline void trace_xfs_attr_list_leaf(struct xfs_attr_list_context *context) {}
static inline void trace_xfs_attr_list_notfound(struct xfs_attr_list_context *context) {}
static inline void trace_xfs_attr_list_leaf_end(struct xfs_attr_list_context *context) {}

static inline void xfs_attr3_leaf_hdr_from_disk(struct xfs_attr3_icleaf_hdr *ichdr, struct xfs_attr_leafblock *leaf) {}
static inline struct xfs_attr_leaf_entry *xfs_attr3_leaf_entryp(struct xfs_attr_leafblock *leaf) { return (struct xfs_attr_leaf_entry *)leaf->data; }
static inline xfs_attr_leaf_name_local_t *xfs_attr3_leaf_name_local(struct xfs_attr_leafblock *leaf, int i) { return (xfs_attr_leaf_name_local_t *)((char *)leaf + sizeof(struct xfs_attr_leafblock)); }
static inline xfs_attr_leaf_name_remote_t *xfs_attr3_leaf_name_remote(struct xfs_attr_leafblock *leaf, int i) { return (xfs_attr_leaf_name_remote_t *)((char *)leaf + sizeof(struct xfs_attr_leafblock)); }
static inline int xfs_attr3_rmt_blocks(void *i_mount, int valuelen) { return 0; }
static inline int xfs_attr_rmtval_get(xfs_da_args_t *args) { return 0; }

void *kmem_alloc(size_t size, int flags);
void kmem_free(void *ptr);