#include <stddef.h>
#include <stdint.h>

typedef struct xfs_attr_list_context xfs_attr_list_context_t;
typedef struct attrlist_cursor_kern attrlist_cursor_kern_t;
typedef struct xfs_attr_sf_sort xfs_attr_sf_sort_t;
typedef struct xfs_attr_shortform xfs_attr_shortform_t;
typedef struct xfs_attr_sf_entry xfs_attr_sf_entry_t;
typedef struct xfs_inode xfs_inode_t;

struct xfs_attr_list_context {
    xfs_inode_t *dp;
    attrlist_cursor_kern_t *cursor;
    int bufsize;
    int seen_enough;
    int (*put_listent)(struct xfs_attr_list_context *,
                      uint8_t, void *, int, int, void *);
};

struct attrlist_cursor_kern {
    uint32_t hashval;
    uint32_t blkno;
    uint32_t offset;
    int initted;
};

struct xfs_attr_sf_sort {
    uint32_t hash;
    uint8_t *name;
    uint8_t namelen;
    uint8_t valuelen;
    uint8_t flags;
    int entno;
};

struct xfs_attr_sf_entry {
    uint8_t namelen;
    uint8_t valuelen;
    uint8_t flags;
    uint8_t nameval[1];
};

struct xfs_attr_shortform {
    struct {
        uint8_t count;
    } hdr;
    struct xfs_attr_sf_entry list[1];
};

struct xfs_inode {
    struct {
        uint64_t if_bytes;
        union {
            void *if_data;
        } if_u1;
    } *i_afp;
    void *i_mount;
};

#define XFS_ISRESET_CURSOR(cursor) ((cursor)->hashval == 0 && \
                                   (cursor)->blkno == 0 && \
                                   (cursor)->offset == 0)
#define XFS_ATTR_SF_ENTSIZE(sfe) \
    (sizeof(struct xfs_attr_sf_entry) + (sfe)->namelen + (sfe)->valuelen)
#define XFS_ATTR_SF_NEXTENTRY(sfe) \
    ((xfs_attr_sf_entry_t *)((char *)(sfe) + XFS_ATTR_SF_ENTSIZE(sfe)))

#define ASSERT(expr) ((void)0)
#define trace_xfs_attr_list_sf(context) ((void)0)
#define trace_xfs_attr_list_sf_all(context) ((void)0)
#define XFS_ERRLEVEL_LOW 0
#define XFS_CORRUPTION_ERROR(str, level, mp, ptr) ((void)0)
#define KM_SLEEP 0
#define KM_NOFS 0
#define EFSCORRUPTED 5
#define unlikely(expr) (expr)

void *kmem_alloc(size_t size, int flags);
void kmem_free(void *ptr);
uint32_t xfs_da_hashname(uint8_t *name, int namelen);
void xfs_sort(void *base, size_t nel, size_t width,
             int (*compar)(const void *, const void *));
int xfs_attr_shortform_compare(const void *a, const void *b);