#include <stddef.h>

#define HPAGE_PMD_MASK (~(HPAGE_PMD_SIZE - 1))
#define HPAGE_PMD_SIZE ((1UL) << HPAGE_PMD_SHIFT)
#define HPAGE_PMD_SHIFT 21

#define VM_NO_THP 0x00040000

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    void *anon_vma;
    void *vm_ops;
    void *vm_file;
};

int khugepaged_enter(struct vm_area_struct *vma);
int is_linear_pfn_mapping(struct vm_area_struct *vma);
int is_pfn_mapping(struct vm_area_struct *vma);
#define VM_BUG_ON(cond) do { if (cond) {} } while (0)