#include <stdbool.h>
#include <stddef.h>

struct mm_struct;
struct vm_area_struct;

struct mm_struct {
    struct vm_area_struct *mmap;
    unsigned long map_count;
    unsigned long highest_vm_end;
    void *mm_rb;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct vm_area_struct *vm_next;
    struct vm_area_struct *vm_prev;
    unsigned long vm_flags;
};

#define VM_GROWSDOWN 0x00000100
#define VM_GROWSUP   0x00000200

void vma_rb_erase(struct vm_area_struct *vma, void *mm_rb);
void vma_gap_update(struct vm_area_struct *vma);
unsigned long vm_end_gap(struct vm_area_struct *vma);
void vmacache_invalidate(struct mm_struct *mm);