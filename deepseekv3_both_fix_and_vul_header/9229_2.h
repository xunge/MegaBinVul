#include <stddef.h>

#define EINVAL 22
#define ENOMEM 12

struct mm_struct;
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct vm_area_struct *vm_next;
};

extern struct vm_area_struct *find_vma_prev(struct mm_struct *mm, unsigned long addr, struct vm_area_struct **pprev);
extern struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr);
extern int prctl_update_vma_anon_name(struct vm_area_struct *vma, struct vm_area_struct **pprev, 
                                     unsigned long start, unsigned long end, const char *name);

extern struct task_struct {
    struct mm_struct *mm;
} *current;

#define __user