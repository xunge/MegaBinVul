#include <stddef.h>
#include <stdbool.h>

struct mm_struct;
struct vm_area_struct {
    unsigned long vm_flags;
    unsigned long vm_page_prot;
};
struct mem_cgroup;
struct page;
typedef struct { unsigned long pte; } pte_t;
typedef struct { unsigned long pmd; } pmd_t;
typedef struct { int lock; } spinlock_t;

#define VM_FAULT_SIGBUS 0
#define VM_FAULT_SIGSEGV 1
#define VM_FAULT_OOM 2
#define VM_SHARED 0x00000001
#define VM_WRITE 0x00000002
#define FAULT_FLAG_WRITE 0x01
#define GFP_KERNEL 0
#define MM_ANONPAGES 0

static inline int check_stack_guard_page(struct vm_area_struct *vma, unsigned long address) { return 0; }
static inline int mm_forbids_zeropage(struct mm_struct *mm) { return 0; }
static inline unsigned long my_zero_pfn(unsigned long address) { return 0; }
static inline pte_t pte_mkspecial(pte_t pte) { return pte; }
static inline pte_t pte_mkwrite(pte_t pte) { return pte; }
static inline pte_t pte_mkdirty(pte_t pte) { return pte; }
static inline pte_t mk_pte(struct page *page, unsigned long prot) { return (pte_t){0}; }
static inline pte_t pfn_pte(unsigned long pfn, unsigned long prot) { return (pte_t){0}; }
static inline int pte_none(pte_t pte) { return 0; }
static inline void pte_unmap(pte_t *pte) {}
static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long address, spinlock_t **ptl) { return NULL; }
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline void set_pte_at(struct mm_struct *mm, unsigned long address, pte_t *ptep, pte_t pte) {}
static inline void update_mmu_cache(struct vm_area_struct *vma, unsigned long address, pte_t *pte) {}
static inline int anon_vma_prepare(struct vm_area_struct *vma) { return 0; }
static inline int unlikely(int x) { return x; }
static inline struct page *alloc_zeroed_user_highpage_movable(struct vm_area_struct *vma, unsigned long address) { return NULL; }
static inline int mem_cgroup_try_charge(struct page *page, struct mm_struct *mm, int gfp, struct mem_cgroup **memcg) { return 0; }
static inline void __SetPageUptodate(struct page *page) {}
static inline void inc_mm_counter_fast(struct mm_struct *mm, int counter) {}
static inline void page_add_new_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long address) {}
static inline void mem_cgroup_commit_charge(struct page *page, struct mem_cgroup *memcg, bool lrucare) {}
static inline void lru_cache_add_active_or_unevictable(struct page *page, struct vm_area_struct *vma) {}
static inline void mem_cgroup_cancel_charge(struct page *page, struct mem_cgroup *memcg) {}
static inline void page_cache_release(struct page *page) {}