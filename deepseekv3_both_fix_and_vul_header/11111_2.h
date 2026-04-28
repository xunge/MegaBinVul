#include <stdint.h>
#include <string.h>

struct xfs_buf;

typedef struct xfs_inode xfs_inode_t;
typedef struct xfs_attr_shortform xfs_attr_shortform_t;
typedef struct xfs_attr_sf_entry xfs_attr_sf_entry_t;
typedef struct xfs_da_args xfs_da_args_t;
typedef struct xfs_ifork xfs_ifork_t;
typedef uint64_t xfs_dablk_t;

struct xfs_attr_sf_entry {
    uint8_t namelen;
    uint8_t valuelen;
    uint8_t flags;
    char nameval[];
};

struct xfs_attr_shortform {
    struct {
        uint16_t totsize;
        uint8_t count;
    } hdr;
    xfs_attr_sf_entry_t list[];
};

struct xfs_ifork {
    union {
        void *if_data;
    } if_u1;
    xfs_ifork_t *i_afp;
};

struct xfs_inode {
    xfs_ifork_t *i_afp;
};

struct xfs_da_args {
    xfs_inode_t *dp;
    void *geo;
    void *firstblock;
    void *dfops;
    int total;
    int whichfork;
    void *trans;
    int op_flags;
    char *name;
    int namelen;
    void *value;
    int valuelen;
    uint32_t hashval;
    int flags;
    int index;
};

#define KM_SLEEP 0
#define XFS_ATTR_FORK 0
#define EIO 5
#define ENOATTR 61
#define ENOSPC 28
#define XFS_DA_OP_OKNOENT 0

#define be16_to_cpu(x) (x)
#define ASSERT(x) ((void)0)
#define trace_xfs_attr_sf_to_leaf(x) ((void)0)

#define XFS_ATTR_NSP_ONDISK_TO_ARGS(x) (x)
#define XFS_ATTR_SF_NEXTENTRY(sfe) \
    ((xfs_attr_sf_entry_t *)((char *)(sfe) + sizeof(xfs_attr_sf_entry_t) + (sfe)->namelen + (sfe)->valuelen))

void *kmem_alloc(size_t size, int flags);
void kmem_free(void *ptr);
int xfs_idata_realloc(xfs_inode_t *dp, int size, int fork);
int xfs_bmap_local_to_extents_empty(xfs_inode_t *dp, int fork);
int xfs_da_grow_inode(xfs_da_args_t *args, xfs_dablk_t *blkno);
int xfs_attr3_leaf_create(xfs_da_args_t *args, xfs_dablk_t blkno, struct xfs_buf **bpp);
int xfs_da_shrink_inode(xfs_da_args_t *args, xfs_dablk_t blkno, struct xfs_buf *bp);
int xfs_attr3_leaf_lookup_int(struct xfs_buf *bp, xfs_da_args_t *args);
int xfs_attr3_leaf_add(struct xfs_buf *bp, xfs_da_args_t *args);
uint32_t xfs_da_hashname(const char *name, int len);