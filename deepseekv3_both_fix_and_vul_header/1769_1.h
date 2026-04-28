#include <stddef.h>
#include <string.h>

#define PAGE_SHIFT 12
#define PAGE_MASK (~(PAGE_SIZE - 1))
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define EINVAL 22
#define VM_SPECIAL 0x00000010

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
};

struct page;

struct migrate_vma {
    unsigned long start;
    unsigned long end;
    struct vm_area_struct *vma;
    unsigned long *src;
    unsigned long *dst;
    struct page *fault_page;
    unsigned long cpages;
    unsigned long npages;
};

int is_vm_hugetlb_page(struct vm_area_struct *vma);
int vma_is_dax(struct vm_area_struct *vma);
int is_device_private_page(struct page *page);
void migrate_vma_collect(struct migrate_vma *args);
void migrate_vma_unmap(struct migrate_vma *args);