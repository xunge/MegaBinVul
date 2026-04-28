#include <stddef.h>
#include <sys/types.h>

typedef struct {
    unsigned long pgprot;
} pte_t;

struct hstate {
    unsigned long mask;
    unsigned long size;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
};

struct mm_struct;

struct mm_walk {
    struct vm_area_struct *vma;
    struct mm_struct *mm;
    int (*hugetlb_entry)(pte_t *pte, unsigned long hmask, unsigned long addr, unsigned long next, struct mm_walk *walk);
    int (*pte_hole)(unsigned long addr, unsigned long next, struct mm_walk *walk);
};

static struct hstate *hstate_vma(struct vm_area_struct *vma);
static unsigned long hugetlb_entry_end(struct hstate *h, unsigned long addr, unsigned long end);
static pte_t *huge_pte_offset(struct mm_struct *mm, unsigned long addr, unsigned long sz);