#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef uint16_t domid_t;
typedef int16_t s16;

struct domain {
    struct grant_table *grant_table;
};

struct grant_table {
    unsigned int maptrack_limit;
    struct grant_mapping *maptrack;
};

struct active_grant_entry {
    unsigned long frame;
};

struct grant_mapping {
    domid_t domid;
    unsigned int ref;
    unsigned int flags;
};

struct gnttab_unmap_common {
    unsigned long dev_bus_addr;
    unsigned int handle;
    int status;
    struct domain *rd;
    unsigned int ref;
    unsigned int flags;
    unsigned long frame;
    unsigned long host_addr;
    unsigned long new_addr;
    unsigned int readonly;
};

struct vcpu {
    struct domain *domain;
};

extern struct vcpu *current;
extern void gdprintk(int level, const char *fmt, ...);
extern void domain_crash(struct domain *d);
extern int xsm_grant_unmapref(int hook, struct domain *ld, struct domain *rd);
extern void TRACE_1D(int event, domid_t dom);
extern void grant_read_lock(struct grant_table *gt);
extern void grant_read_unlock(struct grant_table *gt);
extern struct domain *rcu_lock_domain_by_id(domid_t dom);
extern void rcu_unlock_domain(struct domain *d);
extern unsigned int nr_grant_entries(struct grant_table *gt);
extern struct active_grant_entry *active_entry_acquire(struct grant_table *gt, unsigned int ref);
extern void active_entry_release(struct active_grant_entry *act);
extern int replace_grant_host_mapping(unsigned long host_addr, unsigned long frame, unsigned long new_addr, unsigned int flags);
extern void put_maptrack_handle(struct grant_table *gt, unsigned int handle);
extern bool gnttab_need_iommu_mapping(struct domain *d);
extern void double_gt_lock(struct grant_table *lgt, struct grant_table *rgt);
extern unsigned int mapkind(struct grant_table *lgt, struct domain *rd, unsigned long frame);
extern int iommu_unmap_page(struct domain *d, unsigned long frame);
extern int iommu_map_page(struct domain *d, unsigned long frame, unsigned long mfn, unsigned int flags);
extern void double_gt_unlock(struct grant_table *lgt, struct grant_table *rgt);
extern void gnttab_mark_dirty(struct domain *d, unsigned long frame);

#define PAGE_SHIFT 12
#define unlikely(x) (x)
#define smp_rmb() __asm__ __volatile__("":::"memory")
#define XENLOG_INFO 0
#define XENLOG_WARNING 1
#define GNTST_bad_handle (-1)
#define GNTST_permission_denied (-2)
#define GNTST_general_error (-3)
#define GNTST_okay 0
#define GNTMAP_device_map (1U << 0)
#define GNTMAP_host_map (1U << 1)
#define GNTMAP_readonly (1U << 2)
#define MAPKIND_WRITE (1U << 0)
#define IOMMUF_readable (1U << 0)
#define TRC_MEM_PAGE_GRANT_UNMAP 0
#define XSM_HOOK 0

#define PIN_FAIL(label, err, fmt, ...) do { rc = err; goto label; } while (0)
#define read_atomic(ptr) (*(ptr))
#define maptrack_entry(gt, handle) ((gt)->maptrack[(handle)])