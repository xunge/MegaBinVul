#include <errno.h>
#include <stddef.h>

#define PAGE_SHIFT 12

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    void *vm_private_data;
    const void *vm_ops;
    unsigned long vm_page_prot;
};

struct uio_device {
    struct uio_info *info;
};

struct uio_info {
    struct uio_mem *mem;
};

struct uio_mem {
    unsigned long addr;
    size_t size;
};

struct vm_operations_struct;

extern const struct vm_operations_struct uio_physical_vm_ops;
extern int uio_find_mem_index(struct vm_area_struct *vma);
extern int remap_pfn_range(struct vm_area_struct *vma, unsigned long addr, unsigned long pfn, unsigned long size, unsigned long prot);
extern unsigned long pgprot_noncached(unsigned long prot);