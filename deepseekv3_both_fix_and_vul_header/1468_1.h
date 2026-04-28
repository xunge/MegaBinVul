#include <stdbool.h>

struct mmu_gather {
    bool vma_huge;
    bool vma_exec;
    bool vma_pfn;
};

struct vm_area_struct {
    unsigned long vm_flags;
};

#define VM_EXEC 0x00000004
#define VM_PFNMAP 0x00001000
#define VM_MIXEDMAP 0x00002000
#define VM_HUGETLB 0x00004000

static inline bool is_vm_hugetlb_page(struct vm_area_struct *vma) {
    return !!(vma->vm_flags & VM_HUGETLB);
}