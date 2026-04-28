#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint64_t u64;
typedef unsigned long mfn_t;

struct cpumask {
    unsigned long bits[1];
};
typedef struct cpumask cpumask_t;

struct domain {
    cpumask_t *dirty_cpumask;
};

struct vcpu {
    struct domain *domain;
};

struct page_info {
    union {
        struct {
            unsigned long type_info;
        } inuse;
    } u;
};

typedef struct {
    unsigned long val;
} l1_pgentry_t;

#define PGT_type_mask 0x7
#define PGT_l1_page_table 1
#define MMU_NORMAL_PT_UPDATE 0
#define UVMF_FLUSHTYPE_MASK 0x3
#define UVMF_TLB_FLUSH 1
#define UVMF_INVLPG 2
#define UVMF_LOCAL 0
#define UVMF_ALL 1
#define XSM_TARGET 0

#define EINVAL 22

extern int perfc_incr(int);
extern l1_pgentry_t l1e_from_intpte(u64);
extern int xsm_update_va_mapping(int, struct domain *, struct domain *, l1_pgentry_t);
extern l1_pgentry_t *map_guest_l1e(unsigned long, mfn_t *);
extern struct page_info *get_page_from_mfn(mfn_t, struct domain *);
extern int page_lock(struct page_info *);
extern void put_page(struct page_info *);
extern void page_unlock(struct page_info *);
extern int mod_l1_entry(l1_pgentry_t *, l1_pgentry_t, unsigned long, int, struct vcpu *, struct domain *);
extern void unmap_domain_page(l1_pgentry_t *);
extern void flush_tlb_local(void);
extern void flush_tlb_mask(cpumask_t *);
extern void paging_invlpg(struct vcpu *, unsigned long);
extern void flush_tlb_one_mask(cpumask_t *, unsigned long);
extern cpumask_t *this_cpu(cpumask_t *);
extern int vcpumask_to_pcpumask(struct domain *, const void *, cpumask_t *);
extern struct vcpu *current;
extern int calls_to_update_va;
extern cpumask_t *scratch_cpumask;

#define const_guest_handle_from_ptr(ptr, type) ((const void *)(ptr))
#define mfn_x(mfn) ((unsigned long)(mfn))
#define unlikely(cond) (cond)