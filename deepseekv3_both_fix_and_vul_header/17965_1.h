#include <stdint.h>

typedef struct { unsigned long pmd; } pmd_t;
typedef struct { unsigned long pte; } pte_t;

struct mm_walk {
    void *private;
    void *mm;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
};

struct pagemapread;

#define PAGE_SIZE 4096
#define PM_NOT_PRESENT 0
typedef uint64_t u64;

static void split_huge_page_pmd(void *mm, pmd_t *pmd) {}
static struct vm_area_struct *find_vma(void *mm, unsigned long addr) { return 0; }
static int is_vm_hugetlb_page(struct vm_area_struct *vma) { return 0; }
static pte_t *pte_offset_map(pmd_t *pmd, unsigned long addr) { return 0; }
static u64 pte_to_pagemap_entry(pte_t pte) { return 0; }
static void pte_unmap(pte_t *pte) {}
static int add_to_pagemap(unsigned long addr, u64 pfn, struct pagemapread *pm) { return 0; }
static void cond_resched(void) {}