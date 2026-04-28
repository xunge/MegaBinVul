#include <stddef.h>
#include <stdbool.h>

#define VM_FAULT_SIGBUS 0
#define VM_FAULT_OOM 1
#define FAULT_FLAG_WRITE 0x01
#define GFP_KERNEL 0
#define MM_ANONPAGES 0
#define VM_WRITE 0x02

typedef unsigned long pte_t;
typedef unsigned long pmd_t;
typedef unsigned long spinlock_t;
typedef unsigned int gfp_t;

struct mm_struct;
struct page;
struct anon_vma;

typedef unsigned long pgprot_t;

struct vm_area_struct {
    unsigned long vm_flags;
    pgprot_t vm_page_prot;
};

#define unlikely(x) (x)

static inline pte_t pte_mkspecial(pte_t pte) { return pte; }
static inline pte_t pfn_pte(unsigned long pfn, pgprot_t prot) { return pfn | prot; }
static inline int pte_none(pte_t pte) { return pte == 0; }
static inline spinlock_t *pte_lockptr(struct mm_struct *mm, pmd_t *pmd) { return NULL; }
static inline void spin_lock(spinlock_t *lock) {}
static inline void pte_unmap(pte_t *pte) {}
static inline int anon_vma_prepare(struct vm_area_struct *vma) { return 0; }
static inline struct page *alloc_zeroed_user_highpage_movable(struct vm_area_struct *vma, unsigned long address) { return NULL; }
static inline void __SetPageUptodate(struct page *page) {}
static inline int mem_cgroup_newpage_charge(struct page *page, struct mm_struct *mm, gfp_t gfp) { return 0; }
static inline pte_t mk_pte(struct page *page, pgprot_t prot) { return (pte_t)page | prot; }
static inline pte_t pte_mkwrite(pte_t pte) { return pte | 0x100; }
static inline pte_t pte_mkdirty(pte_t pte) { return pte | 0x200; }
static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long address, spinlock_t **ptl) { return NULL; }
static inline void inc_mm_counter_fast(struct mm_struct *mm, int counter) {}
static inline void page_add_new_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long address) {}
static inline void set_pte_at(struct mm_struct *mm, unsigned long address, pte_t *ptep, pte_t pte) {}
static inline void update_mmu_cache(struct vm_area_struct *vma, unsigned long address, pte_t *pte) {}
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline void mem_cgroup_uncharge_page(struct page *page) {}
static inline void page_cache_release(struct page *page) {}
static inline unsigned long my_zero_pfn(unsigned long address) { return 0; }
static inline int check_stack_guard_page(struct vm_area_struct *vma, unsigned long address) { return 0; }