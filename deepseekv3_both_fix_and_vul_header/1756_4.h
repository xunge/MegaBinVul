#include <stddef.h>

struct vm_area_struct;
struct kvm;

struct page {
    void *zone_device_data;
};

struct vm_fault {
    struct vm_area_struct *vma;
    unsigned long address;
    struct page *page;
};

struct kvmppc_uvmem_page_pvt {
    struct kvm *kvm;
    unsigned long gpa;
};

typedef int vm_fault_t;
#define VM_FAULT_SIGBUS 0
#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)

int kvmppc_svm_page_out(struct vm_area_struct *vma, unsigned long address,
                       unsigned long end, int shift, struct kvm *kvm,
                       unsigned long gpa, ...);