#include <stddef.h>

typedef unsigned long pmd_t;

struct mmu_gather {
    int fullmm;
    pmd_t **array;
    int nr_pxds;
    int nr_ptes;
    struct mm_struct *mm;
};

struct mm_struct {
    // mm_struct fields would be defined here
};

void tlb_flush_mmu(struct mmu_gather *tlb, int start, int end);
void pmd_free(struct mm_struct *mm, pmd_t *pmd);