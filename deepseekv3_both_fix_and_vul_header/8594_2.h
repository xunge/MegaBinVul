#include <stddef.h>
#include <stdint.h>
#include <errno.h>

struct vm_area_struct {
    unsigned long vm_flags;
    struct mm_struct *vm_mm;
};

struct mm_struct;
struct dev_pagemap;
struct page {
    int mapping;
};

typedef struct { 
    unsigned long val; 
} pmd_t;
typedef struct { 
    unsigned long val; 
} pte_t;
typedef struct { 
    unsigned long val; 
} swp_entry_t;
typedef struct { 
    int dummy; 
} spinlock_t;

#define FOLL_MIGRATION (1 << 0)
#define FOLL_NUMA (1 << 1)
#define FOLL_WRITE (1 << 2)
#define FOLL_GET (1 << 3)
#define FOLL_DUMP (1 << 4)
#define FOLL_SPLIT (1 << 5)
#define FOLL_TOUCH (1 << 6)
#define FOLL_MLOCK (1 << 7)
#define VM_LOCKED (1 << 8)

#define unlikely(x) (x)
#define likely(x) (x)
#define ERR_PTR(x) ((void*)(intptr_t)(x))

static inline int pmd_bad(pmd_t pmd) { return 0; }
static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, 
                                        unsigned long address, spinlock_t **ptl) { return NULL; }
static inline int pte_present(pte_t pte) { return 0; }
static inline int pte_none(pte_t pte) { return 0; }
static inline swp_entry_t pte_to_swp_entry(pte_t pte) { return (swp_entry_t){0}; }
static inline int is_migration_entry(swp_entry_t entry) { return 0; }
static inline void pte_unmap_unlock(pte_t *ptep, spinlock_t *ptl) {}
static inline void migration_entry_wait(struct mm_struct *mm, pmd_t *pmd, 
                                      unsigned long address) {}
static inline int pte_protnone(pte_t pte) { return 0; }
static inline int pte_write(pte_t pte) { return 0; }
static inline struct page *vm_normal_page(struct vm_area_struct *vma, 
                                        unsigned long address, pte_t pte) { return NULL; }
static inline int pte_devmap(pte_t pte) { return 0; }
static inline struct dev_pagemap *get_dev_pagemap(unsigned long pfn, 
                                                struct dev_pagemap *pgmap) { return NULL; }
static inline struct page *pte_page(pte_t pte) { return NULL; }
static inline unsigned long pte_pfn(pte_t pte) { return 0; }
static inline int is_zero_pfn(unsigned long pfn) { return 0; }
static inline int follow_pfn_pte(struct vm_area_struct *vma, 
                               unsigned long address, pte_t *ptep, 
                               unsigned int flags) { return 0; }
static inline void get_page(struct page *page) {}
static inline int PageTransCompound(struct page *page) { return 0; }
static inline void lock_page(struct page *page) {}
static inline int split_huge_page(struct page *page) { return 0; }
static inline void unlock_page(struct page *page) {}
static inline void put_page(struct page *page) {}
static inline void put_dev_pagemap(struct dev_pagemap *pgmap) {}
static inline int pte_dirty(pte_t pte) { return 0; }
static inline int PageDirty(struct page *page) { return 0; }
static inline void set_page_dirty(struct page *page) {}
static inline void mark_page_accessed(struct page *page) {}
static inline void lru_add_drain(void) {}
static inline int trylock_page(struct page *page) { return 0; }
static inline void mlock_vma_page(struct page *page) {}
static inline struct page *no_page_table(struct vm_area_struct *vma, 
                                       unsigned int flags) { return NULL; }