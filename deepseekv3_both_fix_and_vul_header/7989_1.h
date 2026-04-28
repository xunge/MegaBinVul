#include <stddef.h>

struct mm_struct;
struct task_struct;

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_flags;
};

#define VM_FAULT_BADMAP 0
#define VM_FAULT_BADACCESS 1
#define VM_GROWSDOWN 0x00000100
#define PAGE_MASK (~(0x1000UL - 1))

#define unlikely(x) (x)

static struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr);
static int handle_mm_fault(struct mm_struct *mm, struct vm_area_struct *vma, unsigned long address, unsigned int flags);
static int expand_stack(struct vm_area_struct *vma, unsigned long address);