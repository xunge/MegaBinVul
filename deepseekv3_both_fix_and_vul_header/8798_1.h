#include <stdint.h>
#include <stddef.h>
#include <string.h>

struct xfs_buf {
    void *b_addr;
};

struct xfs_mount {
    void *m_attr_geo;
};

struct xfs_inode {
    struct xfs_mount *i_mount;
};

struct xfs_attr_list_context {
    struct xfs_inode *dp;
    struct attrlist_cursor_kern *cursor;
    int resynch;
    int dupcnt;
    int (*put_listent)(struct xfs_attr_list_context *, int, char *, int, int, void *);
    int (*put_value)(void);
    int seen_enough;
};

struct attrlist_cursor_kern {
    int initted;
    uint32_t hashval;
    int offset;
};

struct xfs_attr_leafblock;
struct xfs_attr3_icleaf_hdr {
    int count;
};

struct xfs_attr_leaf_entry {
    uint32_t hashval;
    int flags;
    #define XFS_ATTR_INCOMPLETE (1 << 0)
    #define XFS_ATTR_LOCAL      (1 << 1)
};

typedef struct xfs_attr_leaf_name_local {
    uint16_t valuelen;
    uint16_t namelen;
    char nameval[1];
} xfs_attr_leaf_name_local_t;

typedef struct xfs_attr_leaf_name_remote {
    uint32_t valueblk;
    uint32_t valuelen;
    uint16_t namelen;
    char name[1];
} xfs_attr_leaf_name_remote_t;

typedef struct xfs_da_args {
    void *geo;
    struct xfs_inode *dp;
    int whichfork;
    int valuelen;
    int rmtvaluelen;
    void *value;
    uint32_t rmtblkno;
    int rmtblkcnt;
} xfs_da_args_t;

#define XFS_ATTR_FORK 0
#define KM_SLEEP   0x0001u
#define KM_NOFS    0x0002u

#define be16_to_cpu(x) __builtin_bswap16(x)
#define be32_to_cpu(x) __builtin_bswap32(x)

static inline void *kmem_alloc(size_t size, unsigned int flags) { return NULL; }
static inline void kmem_free(void *ptr) {}

static inline void xfs_attr3_leaf_hdr_from_disk(void *geo, struct xfs_attr3_icleaf_hdr *ichdr, struct xfs_attr_leafblock *leaf) {}
static inline struct xfs_attr_leaf_entry *xfs_attr3_leaf_entryp(struct xfs_attr_leafblock *leaf) { return NULL; }
static inline xfs_attr_leaf_name_local_t *xfs_attr3_leaf_name_local(struct xfs_attr_leafblock *leaf, int i) { return NULL; }
static inline xfs_attr_leaf_name_remote_t *xfs_attr3_leaf_name_remote(struct xfs_attr_leafblock *leaf, int i) { return NULL; }
static inline int xfs_attr3_rmt_blocks(struct xfs_mount *mp, int valuelen) { return 0; }
static inline int xfs_attr_rmtval_get(struct xfs_da_args *args) { return 0; }

#define trace_xfs_attr_list_leaf(context)
#define trace_xfs_attr_list_notfound(context)
#define trace_xfs_attr_list_leaf_end(context)