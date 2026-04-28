#include <stdint.h>
#include <stddef.h>
#include <errno.h>

#define GNTST_okay 0
#define GNTMAP_device_map (1 << 0)
#define GNTMAP_host_map (1 << 1)

struct page {
    unsigned long flags;
};

static inline unsigned long page_to_pfn(struct page *page) { return 0; }
static inline void *pfn_to_kaddr(unsigned long pfn) { return NULL; }
static inline int PageHighMem(struct page *page) { return 0; }
#define BUG_ON(cond) do { if (cond) {} } while (0)
#define pr_debug(fmt, ...) do {} while (0)

struct gnttab_map_grant_ref {
    uint64_t host_addr;
    uint32_t flags;
    uint32_t ref;
    uint32_t domid;
    int32_t handle;
    int32_t status;
    uint64_t dev_bus_addr;
};

struct gnttab_unmap_grant_ref {
    uint64_t host_addr;
    uint32_t handle;
    uint64_t dev_bus_addr;
    int32_t status;
};

struct gntdev_grant_map {
    int count;
    int index;
    unsigned int flags;
    struct page **pages;
    struct gnttab_map_grant_ref *map_ops;
    struct gnttab_unmap_grant_ref *unmap_ops;
    struct gnttab_map_grant_ref *kmap_ops;
    struct gnttab_unmap_grant_ref *kunmap_ops;
    struct {
        uint32_t ref;
        uint32_t domid;
    } *grants;
};

extern int use_ptemod;
extern void gnttab_set_map_op(struct gnttab_map_grant_ref *op, unsigned long addr, unsigned int flags, uint32_t ref, uint32_t domid);
extern void gnttab_set_unmap_op(struct gnttab_unmap_grant_ref *op, unsigned long addr, unsigned int flags, int32_t handle);
extern int gnttab_map_refs(struct gnttab_map_grant_ref *map_ops, struct gnttab_map_grant_ref *kmap_ops, struct page **pages, unsigned int count);