#include <stdint.h>
#include <errno.h>
#include <stddef.h>

typedef uint64_t kvm_pte_t;
typedef uint64_t u64;

struct hyp_page {
    unsigned long flags;
};

#define HOST_PAGE_PENDING_RECLAIM  (1UL << 0)
#define HOST_PAGE_NEED_POISONING   (1UL << 1)

#define PKVM_PAGE_OWNED            0
#define PAGE_SIZE                  4096
#define EPERM                      1

extern u64 hyp_pfn_to_phys(u64 pfn);
extern struct hyp_page *hyp_phys_to_page(u64 addr);
extern int hyp_zero_page(u64 addr);
extern void host_lock_component(void);
extern void host_unlock_component(void);
extern int kvm_pgtable_get_leaf(void *pgt, u64 addr, kvm_pte_t *pte, void *null);
extern int host_get_page_state(kvm_pte_t pte, ...);
extern int host_stage2_set_owner_locked(u64 addr, unsigned long size, int id);
extern void psci_mem_protect_dec(void);

struct {
    void *pgt;
} host_kvm;

extern int pkvm_host_id;