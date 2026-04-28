#include <stddef.h>
#include <stdint.h>

typedef uint16_t domid_t;
typedef int16_t s16;

#define PAGE_SHIFT 12
#define unlikely(x) (x)
#define likely(x) (x)
#define XENLOG_INFO 0
#define XENLOG_WARNING 0
#define TRC_MEM_PAGE_GRANT_UNMAP 0
#define GNTST_bad_handle 0
#define GNTST_permission_denied 0
#define GNTST_general_error 0
#define GNTST_okay 0
#define GNTMAP_device_map (1 << 0)
#define GNTMAP_host_map (1 << 1)
#define GNTMAP_readonly (1 << 2)
#define GNTPIN_devw_mask (1 << 0)
#define GNTPIN_devr_mask (1 << 1)
#define GNTPIN_hstw_mask (1 << 2)
#define GNTPIN_hstr_mask (1 << 3)
#define GNTPIN_devw_inc 1
#define GNTPIN_devr_inc 1
#define GNTPIN_hstw_inc 1
#define GNTPIN_hstr_inc 1
#define MAPKIND_WRITE (1 << 0)
#define IOMMUF_readable (1 << 0)
#define XSM_HOOK 0

struct domain {
    struct grant_table *grant_table;
};

struct grant_table {
    unsigned int maptrack_limit;
    struct maptrack_entry *maptrack;
};

struct active_grant_entry {
    unsigned long frame;
    unsigned int pin;
};

struct maptrack_entry {
    uint16_t flags;
    domid_t domid;
    unsigned int ref;
};

struct gnttab_unmap_common {
    unsigned long dev_bus_addr;
    unsigned long frame;
    unsigned long host_addr;
    unsigned long new_addr;
    uint32_t handle;
    uint16_t flags;
    domid_t domid;
    int status;
    struct domain *rd;
    struct maptrack_entry *map;
};

#define gdprintk(level, fmt, ...) 
#define TRACE_1D(event, dom) 
#define PIN_FAIL(label, err, fmt, ...) goto label
#define ASSERT(x) 
#define domain_crash(d) 
#define read_atomic(p) (*(p))
#define rcu_lock_domain_by_id(dom) NULL
#define rcu_unlock_domain(d) 
#define active_entry_acquire(gt, ref) NULL
#define active_entry_release(act) 
#define grant_read_lock(gt) 
#define grant_read_unlock(gt) 
#define double_gt_lock(lgt, rgt) 
#define double_gt_unlock(lgt, rgt) 
#define maptrack_entry(gt, handle) ((gt)->maptrack[(handle)])
#define replace_grant_host_mapping(addr, frame, new_addr, flags) 0
#define gnttab_need_iommu_mapping(d) 0
#define mapkind(gt, d, frame) 0
#define iommu_unmap_page(d, frame) 0
#define iommu_map_page(d, f1, f2, flags) 0
#define gnttab_mark_dirty(d, frame) 
#define xsm_grant_unmapref(hook, ld, rd) 0

extern struct {
    struct domain *domain;
} *current;