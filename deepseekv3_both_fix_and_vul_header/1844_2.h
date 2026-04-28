#include <errno.h>

struct vm_operations_struct {
    void (*open)(struct vm_area_struct *);
};

struct vm_area_struct {
    unsigned long vm_flags;
    void *vm_private_data;
    const struct vm_operations_struct *vm_ops;
};

struct file {
    void *private_data;
};

extern const struct vm_operations_struct mon_bin_vm_ops;
extern void mon_bin_vma_open(struct vm_area_struct *vma);

#define VM_WRITE 0x00000002
#define VM_MAYWRITE 0x00000020  
#define VM_DONTEXPAND 0x00004000
#define VM_DONTDUMP 0x00008000
#define EPERM 1