#define CLUSTER_MASK (~(CLUSTER_SIZE - 1))
#define CLUSTER_SIZE (1UL << 21)
#define PAGE_SIZE (1UL << 12)
#define SWAP_AGAIN 0
#define SWAP_MLOCK 1
#define VM_LOCKED 0x00002000

struct rw_semaphore {
    unsigned long count;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct mm_struct *vm_mm;
    unsigned long vm_flags;
};

struct mm_struct {
    struct rw_semaphore mmap_sem;
};

struct page {
    unsigned long index;
};

typedef struct {
    unsigned long pte;
} pte_t;

typedef struct {
    unsigned long pmd;
} pmd_t;

typedef struct {
    unsigned long lock;
} spinlock_t;

enum {
    MM_FILEPAGES
};

#define BUG_ON(condition) do { if (condition) abort(); } while (0)

static inline int pte_present(pte_t pte) { return 0; }
static inline struct page *vm_normal_page(struct vm_area_struct *vma, unsigned long address, pte_t pte) { return 0; }
static inline int PageAnon(struct page *page) { return 0; }
static inline void mlock_vma_page(struct page *page) {}
static inline int ptep_clear_flush_young_notify(struct vm_area_struct *vma, unsigned long address, pte_t *pte) { return 0; }
static inline void flush_cache_page(struct vm_area_struct *vma, unsigned long address, unsigned long pfn) {}
static inline unsigned long pte_pfn(pte_t pte) { return 0; }
static inline pte_t ptep_clear_flush(struct vm_area_struct *vma, unsigned long address, pte_t *pte) { return (pte_t){0}; }
static inline unsigned long linear_page_index(struct vm_area_struct *vma, unsigned long address) { return 0; }
static inline pte_t pgoff_to_pte(unsigned long pgoff) { return (pte_t){0}; }
static inline int pte_soft_dirty(pte_t pteval) { return 0; }
static inline void pte_file_mksoft_dirty(pte_t ptfile) {}
static inline void set_pte_at(struct mm_struct *mm, unsigned long address, pte_t *pte, pte_t ptfile) {}
static inline int pte_dirty(pte_t pteval) { return 0; }
static inline void set_page_dirty(struct page *page) {}
static inline void page_remove_rmap(struct page *page) {}
static inline void page_cache_release(struct page *page) {}
static inline void dec_mm_counter(struct mm_struct *mm, int counter) {}
static inline pmd_t *mm_find_pmd(struct mm_struct *mm, unsigned long address) { return 0; }
static inline void mmu_notifier_invalidate_range_start(struct mm_struct *mm, unsigned long start, unsigned long end) {}
static inline void mmu_notifier_invalidate_range_end(struct mm_struct *mm, unsigned long start, unsigned long end) {}
static inline int down_read_trylock(struct rw_semaphore *sem) { return 0; }
static inline void up_read(struct rw_semaphore *sem) {}
static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long address, spinlock_t **ptl) { return 0; }
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline void update_hiwater_rss(struct mm_struct *mm) {}