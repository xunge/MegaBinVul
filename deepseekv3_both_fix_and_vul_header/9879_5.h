#include <stddef.h>
#include <stdint.h>

#define HPAGE_PMD_MASK (~(HPAGE_PMD_SIZE-1))
#define HPAGE_PMD_SIZE (1UL << 21)
#define VM_BUG_ON(cond) ((void)0)
#define CONFIG_NUMA 1
#define GFP_KERNEL 0
#define ENOMEM 12
#define BUG_ON(cond) ((void)0)
#define unlikely(x) (x)
#define smp_wmb() ((void)0)
#define VM_HUGEPAGE (1UL << 15)
#define VM_NOHUGEPAGE (1UL << 16)

typedef struct { int lock; } spinlock_t;

struct mm_struct {
    spinlock_t page_table_lock;
    void *mmap_sem;
    int nr_ptes;
};
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    void *anon_vma;
    void *vm_ops;
    void *vm_file;
    void *vm_page_prot;
};
struct page {
    int dummy;
};
typedef struct { int dummy; } pgd_t;
typedef struct { int dummy; } pud_t;
typedef struct { int dummy; } pmd_t;
typedef struct { int dummy; } pte_t;
typedef struct { int dummy; } pgtable_t;

static inline pgd_t *pgd_offset(struct mm_struct *mm, unsigned long addr) { return NULL; }
static inline pud_t *pud_offset(pgd_t *pgd, unsigned long addr) { return NULL; }
static inline pmd_t *pmd_offset(pud_t *pud, unsigned long addr) { return NULL; }
static inline pte_t *pte_offset_map(pmd_t *pmd, unsigned long addr) { return NULL; }
static inline spinlock_t *pte_lockptr(struct mm_struct *mm, pmd_t *pmd) { return NULL; }

static inline int pgd_present(pgd_t pgd) { return 0; }
static inline int pud_present(pud_t pud) { return 0; }
static inline int pmd_present(pmd_t pmd) { return 0; }
static inline int pmd_trans_huge(pmd_t pmd) { return 0; }
static inline int pmd_none(pmd_t pmd) { return 1; }

static inline void set_pmd_at(struct mm_struct *mm, unsigned long addr, pmd_t *pmdp, pmd_t pmd) {}
static inline pmd_t pmdp_clear_flush_notify(struct vm_area_struct *vma, unsigned long addr, pmd_t *pmd) { return (pmd_t){0}; }
static inline pmd_t mk_pmd(struct page *page, void *prot) { return (pmd_t){0}; }
static inline pmd_t pmd_mkwrite(pmd_t pmd) { return pmd; }
static inline pmd_t pmd_mkdirty(pmd_t pmd) { return pmd; }
static inline pmd_t pmd_mkhuge(pmd_t pmd) { return pmd; }
static inline pmd_t maybe_pmd_mkwrite(pmd_t pmd, struct vm_area_struct *vma) { return pmd; }

static inline void pte_unmap(pte_t *pte) {}
static inline pgtable_t pmd_pgtable(pmd_t pmd) { return (pgtable_t){0}; }

static inline void __SetPageUptodate(struct page *page) {}
static inline int page_count(struct page *page) { return 0; }
static inline int page_mapcount(struct page *page) { return 0; }

static inline int is_linear_pfn_mapping(struct vm_area_struct *vma) { return 0; }
static inline int is_pfn_mapping(struct vm_area_struct *vma) { return 0; }

static inline void up_read(void *sem) {}
static inline void down_write(void *sem) {}
static inline void up_write(void *sem) {}

static inline void spin_lock(spinlock_t *lock) { lock->lock = 1; }
static inline void spin_unlock(spinlock_t *lock) { lock->lock = 0; }

static inline void anon_vma_lock(void *vma) {}
static inline void anon_vma_unlock(void *vma) {}

static inline void put_page(struct page *page) {}
static inline struct page *alloc_hugepage_vma(int defrag, struct vm_area_struct *vma, unsigned long addr) { return NULL; }
static inline int mem_cgroup_newpage_charge(struct page *page, struct mm_struct *mm, int gfp) { return 0; }
static inline void mem_cgroup_uncharge_page(struct page *page) {}
static inline void page_add_new_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long addr) {}
static inline void update_mmu_cache(struct vm_area_struct *vma, unsigned long addr, pte_t pte) {}
static inline void prepare_pmd_huge_pte(pgtable_t pgtable, struct mm_struct *mm) {}

static inline int __collapse_huge_page_isolate(struct vm_area_struct *vma, unsigned long addr, pte_t *pte) { return 0; }
static inline void __collapse_huge_page_copy(pte_t *pte, struct page *new_page, struct vm_area_struct *vma, unsigned long addr, spinlock_t *ptl) {}
static inline struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr) { return NULL; }

static inline void *ERR_PTR(int error) { return (void *)(intptr_t)error; }

static int khugepaged_defrag(void) { return 0; }
static int khugepaged_always(void) { return 0; }
static int khugepaged_test_exit(struct mm_struct *mm) { return 0; }
static int khugepaged_pages_collapsed = 0;

/* Add missing entry variable */
static pte_t entry;