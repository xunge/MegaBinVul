#include <stddef.h>

struct mm_struct;
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
};

#define PAGE_MASK (~(0UL))
#define VM_LOCKED (1UL << 0)

struct vm_area_struct *find_vma_prev(struct mm_struct *mm, unsigned long addr, struct vm_area_struct **prev);
int expand_stack(struct vm_area_struct *vma, unsigned long address);
int populate_vma_page_range(struct vm_area_struct *vma, unsigned long start, unsigned long end, void *arg);