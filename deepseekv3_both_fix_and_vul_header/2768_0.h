#include <stddef.h>

struct vm_area_struct {
    struct anon_vma *anon_vma;
    const struct vm_operations_struct *vm_ops;
    struct file *vm_file;
};

struct anon_vma;
struct file;
struct vm_operations_struct;

void __vma_adjust_trans_huge(struct vm_area_struct *vma,
                            unsigned long start,
                            unsigned long end,
                            long adjust_next);