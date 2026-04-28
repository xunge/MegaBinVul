#include <stddef.h>
#include <stdint.h>

#define EBUSY 16
#define ENOMEM 12

struct page;
struct dev_pagemap;

struct vm_area_struct {
    struct mm_struct *vm_mm;
};

struct mm_struct;

struct follow_page_context {
    struct dev_pagemap *pgmap;
    unsigned long page_mask;
};

typedef struct { unsigned long pmd; } pmd_t;
typedef struct { unsigned long pud; } pud_t;
typedef struct { unsigned long pgd; } pgd_t;
typedef struct { unsigned long pte; } pte_t;
typedef struct { unsigned long pd; } hugepd_t;
typedef struct { int lock; } spinlock_t;

#define HPAGE_PMD_NR (1 << (21 - 12))
#define PMD_SHIFT 21
#define PAGE_SHIFT 12

#define FOLL_MIGRATION (1 << 0)
#define FOLL_NUMA (1 << 1)
#define FOLL_SPLIT_PMD (1 << 2)

#define VM_BUG_ON(cond) ((void)0)
#define likely(x) (x)
#define unlikely(x) (x)

static inline void *ERR_PTR(long error) { return (void *)error; }

#define pmd_offset(pud, addr) ((pmd_t *)(pud))
#define pmd_val(x) ((x).pmd)
#define __hugepd(x) ((hugepd_t) { (x) })
#define pmd_page(x) ((struct page *)NULL)
#define pmd_lock(mm, pmd) ((spinlock_t *)NULL)
#define pmd_present(x) (0)
#define pmd_none(x) (0)
#define pmd_huge(x) (0)
#define pmd_devmap(x) (0)
#define pmd_trans_huge(x) (0)
#define pmd_trans_unstable(pmd) (0)
#define pmd_protnone(x) (0)
#define is_pmd_migration_entry(x) (0)
#define thp_migration_supported() (0)
#define is_vm_hugetlb_page(x) (0)
#define is_huge_zero_page(x) (0)
#define is_hugepd(x) (0)

#define READ_ONCE(x) (x)

static inline struct page *no_page_table(struct vm_area_struct *vma, unsigned int flags) { return NULL; }
static inline struct page *follow_huge_pmd(struct mm_struct *mm, unsigned long address, pmd_t *pmd, unsigned int flags) { return NULL; }
static inline struct page *follow_huge_pd(struct vm_area_struct *vma, unsigned long address, hugepd_t hugepd, unsigned int flags, int pdshift) { return NULL; }
static inline void pmd_migration_entry_wait(struct mm_struct *mm, pmd_t *pmd) {}
static inline struct page *follow_devmap_pmd(struct vm_area_struct *vma, unsigned long address, pmd_t *pmd, unsigned int flags, struct dev_pagemap **pgmap) { return NULL; }
static inline struct page *follow_page_pte(struct vm_area_struct *vma, unsigned long address, pmd_t *pmd, unsigned int flags, struct dev_pagemap **pgmap) { return NULL; }
static inline void split_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd, unsigned long address) {}
static inline int pte_alloc(struct mm_struct *mm, pmd_t *pmd) { return 0; }
static inline struct page *follow_trans_huge_pmd(struct vm_area_struct *vma, unsigned long address, pmd_t *pmd, unsigned int flags) { return NULL; }
static inline void spin_unlock(spinlock_t *lock) {}