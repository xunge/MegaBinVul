#include <stdint.h>
#include <stddef.h>

typedef int p2m_query_t;
typedef struct { unsigned long val; } mfn_t;
typedef uint64_t u64;

#define PAGE_ORDER_1G 30
#define PAGE_ORDER_2M 21
#define PAGE_ORDER_4K 12

#define _mfn(x) ((mfn_t){ (x) })
#define mfn_x(x) ((x).val)

#define BUG_ON(condition) ((void)0)
#define ASSERT(condition) ((void)0)

#define unlikely(x) (x)
#define likely(x) (x)

#define TRC_MEM_POD_POPULATE 0
#define TRC_MEM_POD_SUPERPAGE_SPLINTER 0

#define P2M_ALLOC 0
#define p2m_populate_on_demand 0
#define p2m_ram_rw 1

#define PRIu32 "u"

struct domain {
    int is_dying;
    unsigned int domain_id;
    unsigned long tot_pages;
    struct domain *domain;
};

struct p2m_domain {
    struct domain *domain;
    struct {
        unsigned long count;
        unsigned long max_guest;
        long entry_count;
        int default_access;
    } pod;
    int default_access;
};

struct page_info;

struct task_struct {
    struct domain *domain;
};
extern struct task_struct *current;

extern int gfn_locked_by_me(struct p2m_domain *p2m, unsigned long gfn);
extern void pod_lock(struct p2m_domain *p2m);
extern void pod_unlock(struct p2m_domain *p2m);
extern void p2m_set_entry(struct p2m_domain *p2m, unsigned long gfn, mfn_t mfn, unsigned int order, int p2m_type, int access);
extern void p2m_pod_emergency_sweep(struct p2m_domain *p2m);
extern struct page_info *p2m_pod_cache_get(struct p2m_domain *p2m, unsigned int order);
extern mfn_t page_to_mfn(struct page_info *p);
extern void set_gpfn_from_mfn(unsigned long mfn, unsigned long gfn);
extern void paging_mark_dirty(struct domain *d, unsigned long mfn);
extern void __trace_var(int event, int cycles, int size, void *data);
extern void p2m_pod_check_last_super(struct p2m_domain *p2m, unsigned long gfn);
extern void domain_crash(struct domain *d);
extern int printk(const char *fmt, ...);

extern int tb_init_done;