#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define BLKIF_MAX_SEGMENTS_PER_REQUEST 11
#define GNTMAP_host_map (1 << 0)
#define GNTMAP_readonly (1 << 1)
#define BLKBACK_INVALID_HANDLE (~0)
#define ENOMEM 12
#define GFP_KERNEL 0

typedef unsigned long phys_addr_t;

struct xen_blkif_ring;
struct page;

struct grant_page {
    struct page *page;
    struct persistent_gnt *persistent_gnt;
    unsigned long gref;
    unsigned long handle;
};

struct persistent_gnt {
    unsigned long gnt;
    unsigned long handle;
    struct page *page;
};

struct gnttab_map_grant_ref {
    unsigned long status;
    unsigned long handle;
    unsigned long ref;
};

struct xen_blkif {
    int domid;
    struct {
        int feature_gnt_persistent;
        int handle;
        int overflow_max_grants;
    } vbd;
};

struct xen_blkif_ring {
    struct xen_blkif *blkif;
    struct {
        int persistent_gnt_c;
    };
    struct {
        struct page *free_pages;
    };
};

extern int gnttab_map_refs(struct gnttab_map_grant_ref *map, void *unused, struct page **pages, int count);
extern void gnttab_set_map_op(struct gnttab_map_grant_ref *map, phys_addr_t addr, uint32_t flags, unsigned long gref, int domid);
extern int gnttab_page_cache_get(struct page **cache, struct page **page);
extern void gnttab_page_cache_put(struct page **cache, struct page **pages, int count);
extern int add_persistent_gnt(struct xen_blkif_ring *ring, struct persistent_gnt *gnt);
extern struct persistent_gnt *get_persistent_gnt(struct xen_blkif_ring *ring, unsigned long gref);
extern phys_addr_t vaddr(struct page *page);
extern int max_pgrants;

#define BUG_ON(condition) ((void)0)
#define unlikely(x) (x)
#define pr_debug(fmt, ...) ((void)0)
#define pr_alert(fmt, ...) ((void)0)
#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)