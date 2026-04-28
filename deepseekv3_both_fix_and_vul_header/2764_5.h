#include <stddef.h>
#include <stdint.h>

#define HPAGE_PMD_MASK (~(1UL << 20))
#define HPAGE_PMD_SIZE (1UL << 20)
#define VM_BUG_ON(cond) ((void)0)
#define VM_HUGEPAGE (1 << 14)
#define VM_NOHUGEPAGE (1 << 15)
#define GFP_KERNEL 0
#define __GFP_OTHER_NODE 0
#define THP_COLLAPSE_ALLOC_FAILED 0
#define THP_COLLAPSE_ALLOC 0
#define ENOMEM 12
#define unlikely(x) (x)
#define BUG_ON(cond) ((void)0)

struct rw_semaphore {
    int dummy;
};

struct spinlock {
    int lock;
};
typedef struct spinlock spinlock_t;

struct mm_struct {
    struct rw_semaphore mmap_sem;
    spinlock_t page_table_lock;
    int nr_ptes;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    void *anon_vma;
    void *vm_ops;
    void *vm_file;
    unsigned long vm_page_prot;
};

struct page {
    int dummy;
};

typedef struct { int dummy; } pgd_t;
typedef struct { int dummy; } pud_t;
typedef struct { int dummy; } pmd_t;
typedef struct { int dummy; } pte_t;
typedef struct { int dummy; } pgtable_t;

static inline void up_read(struct rw_semaphore *sem) { }
static inline void down_write(struct rw_semaphore *sem) { }
static inline void up_write(struct rw_semaphore *sem) { }
static inline void spin_lock(spinlock_t *lock) { lock->lock = 1; }
static inline void spin_unlock(spinlock_t *lock) { lock->lock = 0; }
static inline void pte_unmap(pte_t *pte) { }
static inline void __SetPageUptodate(struct page *page) { }
static inline void put_page(struct page *page) { }
static inline void mem_cgroup_uncharge_page(struct page *page) { }
static inline int mem_cgroup_newpage_charge(struct page *page, struct mm_struct *mm, int gfp) { return 0; }
static inline void count_vm_event(int event) { }
static inline void smp_wmb(void) { }

static inline struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) { return NULL; }
static inline int khugepaged_test_exit(struct mm_struct *mm) { return 0; }
static inline int khugepaged_always() { return 0; }
static inline int is_vma_temporary_stack(struct vm_area_struct *vma) { return 0; }
static inline int is_linear_pfn_mapping(struct vm_area_struct *vma) { return 0; }
static inline int is_pfn_mapping(struct vm_area_struct *vma) { return 0; }
static inline int __collapse_huge_page_isolate(struct vm_area_struct *vma, unsigned long address, pte_t *pte) { return 0; }
static inline void __collapse_huge_page_copy(pte_t *pte, struct page *new_page, struct vm_area_struct *vma, unsigned long address, spinlock_t *ptl) { }
static inline struct page *alloc_hugepage_vma(int defrag, struct vm_area_struct *vma, unsigned long address, int node, int gfp) { return NULL; }
static inline int khugepaged_defrag() { return 0; }
static inline void anon_vma_lock(void *anon_vma) { }
static inline void anon_vma_unlock(void *anon_vma) { }
static inline void page_add_new_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long address) { }
static inline void update_mmu_cache(struct vm_area_struct *vma, unsigned long address, pte_t *ptep) { }
static inline void prepare_pmd_huge_pte(pgtable_t pgtable, struct mm_struct *mm) { }

#define pgd_offset(mm, addr) ((pgd_t *)NULL)
#define pud_offset(pgd, addr) ((pud_t *)NULL)
#define pmd_offset(pud, addr) ((pmd_t *)NULL)
#define pte_offset_map(pmd, addr) ((pte_t *)NULL)
#define pte_lockptr(mm, pmd) ((spinlock_t *)NULL)
#define pgd_present(pgd) (0)
#define pud_present(pud) (0)
#define pmd_present(pmd) (0)
#define pmd_trans_huge(pmd) (0)
#define pmd_none(pmd) (0)
#define pmdp_clear_flush_notify(vma, addr, pmd) ((pmd_t){0})
#define set_pmd_at(mm, addr, pmd, val) ((void)0)
#define mk_pmd(page, prot) ((pmd_t){0})
#define pmd_mkdirty(pmd) ((pmd_t){0})
#define maybe_pmd_mkwrite(pmd, vma) ((pmd_t){0})
#define pmd_mkhuge(pmd) ((pmd_t){0})
#define pmd_pgtable(pmd) ((pgtable_t){0})
#define page_count(page) (0)
#define page_mapcount(page) (0)

static int khugepaged_pages_collapsed;
pte_t *entry;