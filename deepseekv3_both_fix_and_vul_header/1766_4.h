#include <stdbool.h>
#include <stddef.h>

typedef unsigned int vm_fault_t;

typedef struct {
    unsigned long pte;
} pte_t;

typedef struct {
    unsigned long pmd;
} pmd_t;

typedef struct {
    int lock;
} spinlock_t;

typedef unsigned long pgprot_t;

struct vm_fault {
    struct vm_area_struct *vma;
    unsigned long address;
    pte_t *pte;
    pte_t orig_pte;
    pmd_t *pmd;
    spinlock_t *ptl;
    unsigned int flags;
    struct page *page;
};

struct vm_area_struct {
    struct mm_struct *vm_mm;
    unsigned long vm_start;
    unsigned long vm_end;
    pgprot_t vm_page_prot;
    unsigned long vm_flags;
};

struct mm_struct {
    // Members omitted for brevity
};

struct page {
    unsigned long flags;
    struct dev_pagemap *pgmap;
    void *mapping;
    unsigned long private;
};

struct dev_pagemap {
    struct dev_pagemap_ops *ops;
};

struct dev_pagemap_ops {
    vm_fault_t (*migrate_to_ram)(struct vm_fault *vmf);
};

struct folio {
    struct page page;
    unsigned long flags;
    void *private;
};

struct swap_info_struct {
    unsigned long flags;
};

typedef struct {
    unsigned long val;
} swp_entry_t;

typedef unsigned int rmap_t;

#define RMAP_NONE 0
#define RMAP_EXCLUSIVE 1

#define VM_FAULT_OOM 0x0001
#define VM_FAULT_SIGBUS 0x0002
#define VM_FAULT_MAJOR 0x0004
#define VM_FAULT_WRITE 0x0008
#define VM_FAULT_HWPOISON 0x0010
#define VM_FAULT_RETRY 0x0020
#define VM_FAULT_ERROR (VM_FAULT_OOM | VM_FAULT_SIGBUS)

#define FAULT_FLAG_WRITE 0x01

#define GFP_KERNEL 0
#define GFP_HIGHUSER_MOVABLE 0

#define SWP_SYNCHRONOUS_IO (1 << 0)
#define SWP_STABLE_WRITES (1 << 1)

#define PGMAJFAULT 0
#define MM_ANONPAGES 0
#define MM_SWAPENTS 0

#define PageHWPoison(page) 0
#define PageAnonExclusive(page) 0
#define folio_test_anon(folio) 0
#define folio_test_mappedtodisk(folio) 0
#define folio_test_swapcache(folio) 0
#define folio_test_ksm(folio) 0
#define folio_test_lru(folio) 0
#define folio_test_writeback(folio) 0
#define folio_test_uptodate(folio) 0
#define folio_ref_count(folio) 0

#define __HAVE_ARCH_PTE_SWP_EXCLUSIVE

#define pte_unmap_same(vmf) 1
#define pte_same(a, b) 1
#define pte_swp_exclusive(pte) 0
#define pte_swp_soft_dirty(pte) 0
#define pte_swp_uffd_wp(pte) 0
#define pte_write(pte) 0

#define unlikely(x) x
#define likely(x) x
#define data_race(x) x

#define BUG_ON(condition) do { } while (0)
#define VM_BUG_ON(condition) do { } while (0)

static inline swp_entry_t pte_to_swp_entry(pte_t pte) { return (swp_entry_t){0}; }
static inline int non_swap_entry(swp_entry_t entry) { return 0; }
static inline int is_migration_entry(swp_entry_t entry) { return 0; }
static inline void migration_entry_wait(struct mm_struct *mm, pmd_t *pmd, unsigned long address) {}
static inline int is_device_exclusive_entry(swp_entry_t entry) { return 0; }
static inline int is_device_private_entry(swp_entry_t entry) { return 0; }
static inline int is_hwpoison_entry(swp_entry_t entry) { return 0; }
static inline int is_swapin_error_entry(swp_entry_t entry) { return 0; }
static inline int is_pte_marker_entry(swp_entry_t entry) { return 0; }

static inline struct page *pfn_swap_entry_to_page(swp_entry_t entry) { return NULL; }
static inline vm_fault_t remove_device_exclusive_entry(struct vm_fault *vmf) { return 0; }
static inline vm_fault_t handle_pte_marker(struct vm_fault *vmf) { return 0; }
static inline void print_bad_pte(struct vm_area_struct *vma, unsigned long addr, pte_t pte, void *arg) {}

static inline struct swap_info_struct *get_swap_device(swp_entry_t entry) { return NULL; }
static inline struct folio *swap_cache_get_folio(swp_entry_t entry, struct vm_area_struct *vma, unsigned long addr) { return NULL; }
static inline struct page *folio_file_page(struct folio *folio, unsigned long offset) { return NULL; }
static inline unsigned long swp_offset(swp_entry_t entry) { return 0; }
static inline unsigned long __swap_count(swp_entry_t entry) { return 0; }

static inline struct folio *vma_alloc_folio(unsigned int gfp, int order, struct vm_area_struct *vma, unsigned long addr, bool huge) { return NULL; }
static inline void __folio_set_locked(struct folio *folio) {}
static inline void __folio_set_swapbacked(struct folio *folio) {}
static inline int mem_cgroup_swapin_charge_folio(struct folio *folio, struct mm_struct *mm, unsigned int gfp, swp_entry_t entry) { return 0; }
static inline void mem_cgroup_swapin_uncharge_swap(swp_entry_t entry) {}
static inline void *get_shadow_from_swap_cache(swp_entry_t entry) { return NULL; }
static inline void workingset_refault(struct folio *folio, void *shadow) {}
static inline void folio_add_lru(struct folio *folio) {}
static inline void folio_set_swap_entry(struct folio *folio, swp_entry_t entry) {}
static inline void swap_readpage(struct page *page, bool synchronous, void *arg) {}

static inline struct page *swapin_readahead(swp_entry_t entry, unsigned int gfp, struct vm_fault *vmf) { return NULL; }
static inline struct folio *page_folio(struct page *page) { return NULL; }

static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long addr, spinlock_t **ptlp) { return NULL; }

static inline int folio_lock_or_retry(struct folio *folio, struct mm_struct *mm, unsigned int flags) { return 1; }

static inline unsigned long page_private(struct page *page) { return 0; }
static inline struct page *ksm_might_need_to_copy(struct page *page, struct vm_area_struct *vma, unsigned long addr) { return NULL; }
static inline void lru_add_drain(void) {}

static inline void cgroup_throttle_swaprate(struct page *page, unsigned int gfp) {}

static inline pte_t mk_pte(struct page *page, pgprot_t prot) { return (pte_t){0}; }
static inline pte_t maybe_mkwrite(pte_t pte, struct vm_area_struct *vma) { return pte; }
static inline pte_t pte_mkdirty(pte_t pte) { return pte; }
static inline void flush_icache_page(struct vm_area_struct *vma, struct page *page) {}
static inline pte_t pte_mksoft_dirty(pte_t pte) { return pte; }
static inline pte_t pte_mkuffd_wp(pte_t pte) { return pte; }
static inline pte_t pte_wrprotect(pte_t pte) { return pte; }

static inline void page_add_new_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long addr) {}
static inline void folio_add_lru_vma(struct folio *folio, struct vm_area_struct *vma) {}
static inline void page_add_anon_rmap(struct page *page, struct vm_area_struct *vma, unsigned long addr, rmap_t flags) {}
static inline void set_pte_at(struct mm_struct *mm, unsigned long addr, pte_t *ptep, pte_t pte) {}
static inline void arch_do_swap_page(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long addr, pte_t pte, pte_t orig_pte) {}

static inline void folio_unlock(struct folio *folio) {}
static inline void folio_put(struct folio *folio) {}

static inline vm_fault_t do_wp_page(struct vm_fault *vmf) { return 0; }
static inline void update_mmu_cache(struct vm_area_struct *vma, unsigned long addr, pte_t *pte) {}
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline void put_swap_device(struct swap_info_struct *si) {}

static inline void count_vm_event(int event) {}
static inline void count_memcg_event_mm(struct mm_struct *mm, int event) {}
static inline void inc_mm_counter_fast(struct mm_struct *mm, int counter) {}
static inline void dec_mm_counter_fast(struct mm_struct *mm, int counter) {}

static inline void swap_free(swp_entry_t entry) {}
static inline int should_try_to_free_swap(struct folio *folio, struct vm_area_struct *vma, unsigned int flags) { return 0; }
static inline void folio_free_swap(struct folio *folio) {}