#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define BLKIF_MAX_SEGMENTS_PER_REQUEST 11
#define GNTMAP_host_map (1 << 0)
#define GNTMAP_readonly (1 << 1)
#define BLKBACK_INVALID_HANDLE (-1)
#define ENOMEM 12
#define GFP_KERNEL 0
#define unlikely(x) (x)

typedef uint64_t phys_addr_t;

struct page {
    // dummy definition
};

struct gnttab_map_grant_ref {
    int status;
    int handle;
    int ref;
};

struct persistent_gnt {
    int gnt;
    int handle;
    struct page *page;
};

struct grant_page {
    int gref;
    struct page *page;
    struct persistent_gnt *persistent_gnt;
    int handle;
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
    int persistent_gnt_c;
    int free_pages;
};

extern int max_pgrants;

#define BUG_ON(condition) ((void)0)
#define pr_debug(fmt, ...) ((void)0)
#define pr_alert(fmt, ...) ((void)0)

static int gnttab_page_cache_get(int *free_pages, struct page **page);
static void gnttab_page_cache_put(int *free_pages, struct page **page, int count);
static void gnttab_set_map_op(struct gnttab_map_grant_ref *map, phys_addr_t addr, uint32_t flags, int gref, int domid);
static int gnttab_map_refs(struct gnttab_map_grant_ref *map, void *null, struct page **pages_to_gnt, int segs_to_map);
static phys_addr_t vaddr(struct page *page);
static struct persistent_gnt *get_persistent_gnt(struct xen_blkif_ring *ring, int gref);
static int add_persistent_gnt(struct xen_blkif_ring *ring, struct persistent_gnt *persistent_gnt);
static void *kmalloc(size_t size, int flags);
static void kfree(void *ptr);