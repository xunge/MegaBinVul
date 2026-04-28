#include <stdbool.h>

struct mmu_gather {
    bool fullmm;
    bool vma_pfn;
};

struct vm_area_struct;

#define CONFIG_MMU_GATHER_MERGE_VMAS 0

static inline bool IS_ENABLED(int config) {
    return false;
}

static inline void tlb_flush_mmu_tlbonly(struct mmu_gather *tlb) {
}