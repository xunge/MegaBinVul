#include <stddef.h>

typedef struct {
    unsigned long pgd;
} pgd_t;

typedef struct {
    unsigned long pud;
} pud_t;

typedef struct {
    unsigned long pmd;
} pmd_t;

typedef struct mm_walk {
    int (*pte_hole)(unsigned long, unsigned long, struct mm_walk *);
    int (*pmd_entry)(pmd_t *, unsigned long, unsigned long, struct mm_walk *);
    int (*pte_entry)(pmd_t *, unsigned long, unsigned long, struct mm_walk *);
    void *mm;
} mm_walk_t;

static pmd_t *pmd_offset(pud_t *pud, unsigned long addr);
static int pmd_none(pmd_t pmd);
static unsigned long pmd_addr_end(unsigned long addr, unsigned long end);
static int pmd_none_or_clear_bad(pmd_t *pmd);
static void split_huge_page_pmd(void *mm, pmd_t *pmd);
static int walk_pte_range(pmd_t *pmd, unsigned long addr, unsigned long end, struct mm_walk *walk);