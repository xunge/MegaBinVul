#include <stddef.h>

struct mmu_gather {
    int fullmm;
    void **array;
    size_t nr_pxds;
    size_t nr_ptes;
    void *mm;
};

typedef void *pud_t;

void tlb_flush_mmu(struct mmu_gather *tlb, int a, int b);
void pud_free(void *mm, pud_t *pud);