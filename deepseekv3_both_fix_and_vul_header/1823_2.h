#include <stddef.h>
#include <stdbool.h>

#define FOLL_GET    0x01
#define FOLL_PIN    0x02
#define FOLL_WRITE  0x04
#define FOLL_NUMA   0x08
#define FOLL_MIGRATION 0x10
#define FOLL_DUMP   0x20
#define FOLL_TOUCH  0x40

#define _PAGE_PRESENT   0x001
#define _PAGE_RW        0x002
#define _PAGE_DIRTY     0x004
#define _PAGE_PROTNONE  0x008

#define EINVAL      22
#define EFAULT      14
#define EMLINK      31
#define ENOMEM      12

struct page {
    unsigned long flags;
};

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct;
struct dev_pagemap;

typedef struct { unsigned long pmd; } pmd_t;
typedef struct { unsigned long pte; } pte_t;
typedef struct { unsigned long entry; } swp_entry_t;
typedef struct { int lock; } spinlock_t;

#define ERR_PTR(err) ((void *)(long)(err))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))
#define unlikely(x) (x)
#define likely(x) (x)
#define WARN_ON_ONCE(cond) (cond)
#define VM_BUG_ON_PAGE(cond, page) do { } while (0)

static inline int PageAnon(struct page *page) { return page->flags & 0x01; }
static inline int PageAnonExclusive(struct page *page) { return page->flags & 0x02; }
static inline int PageDirty(struct page *page) { return page->flags & 0x04; }

static inline int pmd_bad(pmd_t pmd) { return 0; }
static inline pte_t *pte_offset_map_lock(struct mm_struct *mm, pmd_t *pmd, unsigned long address, spinlock_t **ptl) { return NULL; }
static inline void pte_unmap_unlock(pte_t *pte, spinlock_t *ptl) {}
static inline int pte_present(pte_t pte) { return pte.pte & _PAGE_PRESENT; }
static inline int pte_write(pte_t pte) { return pte.pte & _PAGE_RW; }
static inline int pte_dirty(pte_t pte) { return pte.pte & _PAGE_DIRTY; }
static inline int pte_none(pte_t pte) { return !pte.pte; }
static inline int pte_protnone(pte_t pte) { return pte.pte & _PAGE_PROTNONE; }
static inline struct page *vm_normal_page(struct vm_area_struct *vma, unsigned long addr, pte_t pte) { return NULL; }
static inline bool can_follow_write_pte(pte_t pte, struct page *page, struct vm_area_struct *vma, unsigned int flags) { return false; }
static inline bool pte_devmap(pte_t pte) { return false; }
static inline swp_entry_t pte_to_swp_entry(pte_t pte) { return (swp_entry_t){0}; }
static inline bool is_migration_entry(swp_entry_t entry) { return false; }
static inline void migration_entry_wait(struct mm_struct *mm, pmd_t *pmd, unsigned long address) {}
static inline bool gup_must_unshare(unsigned int flags, struct page *page) { return false; }
static inline bool try_grab_page(struct page *page, unsigned int flags) { return true; }
static inline void unpin_user_page(struct page *page) {}
static inline int arch_make_page_accessible(struct page *page) { return 0; }
static inline void set_page_dirty(struct page *page) { page->flags |= 0x04; }
static inline void mark_page_accessed(struct page *page) {}
static inline struct page *no_page_table(struct vm_area_struct *vma, unsigned int flags) { return NULL; }
static inline int follow_pfn_pte(struct vm_area_struct *vma, unsigned long address, pte_t *ptep, unsigned int flags) { return 0; }
static inline struct dev_pagemap *get_dev_pagemap(unsigned long pfn, struct dev_pagemap *pgmap) { return NULL; }
static inline bool is_zero_pfn(unsigned long pfn) { return false; }
static inline struct page *pte_page(pte_t pte) { return NULL; }
static inline unsigned long pte_pfn(pte_t pte) { return 0; }