#include <sys/types.h>
#include <stddef.h>

typedef unsigned long pud_t;
typedef unsigned long pmd_t;
typedef unsigned long pte_t;

struct vm_area_struct;

#define PAGE_SHIFT 12

static int pmd_trans_huge(pmd_t pmd) { return 0; }
static int mincore_huge_pmd(struct vm_area_struct *vma, pmd_t *pmd, unsigned long addr, unsigned long next, unsigned char *vec) { return 0; }
static int pmd_none_or_clear_bad(pmd_t *pmd) { return 0; }
static void mincore_unmapped_range(struct vm_area_struct *vma, unsigned long addr, unsigned long next, unsigned char *vec) {}
static void mincore_pte_range(struct vm_area_struct *vma, pmd_t *pmd, unsigned long addr, unsigned long next, unsigned char *vec) {}

static pmd_t *pmd_offset(pud_t *pud, unsigned long addr) { return NULL; }
static unsigned long pmd_addr_end(unsigned long addr, unsigned long end) { return 0; }