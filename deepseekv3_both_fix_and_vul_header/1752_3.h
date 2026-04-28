#include <stdbool.h>
#include <stddef.h>

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12

struct mutex {
    // dummy definition
};

struct mm_struct {
    // dummy definition
};

struct kvm_memory_slot {
    unsigned long base_gfn;
    unsigned long npages;
    unsigned long userspace_addr;
};

struct kvm {
    struct mm_struct *mm;
    struct {
        struct mutex uvmem_lock;
    } arch;
};

struct vm_area_struct {
    unsigned long vm_end;
};

struct page {
    void *zone_device_data;
};

struct kvmppc_uvmem_page_pvt {
    bool skip_page_out;
    bool remove_gfn;
    unsigned long gpa;
};

extern int kvmppc_gfn_is_uvmem_pfn(unsigned long gfn, struct kvm *kvm, unsigned long *uvmem_pfn);
extern int __kvmppc_svm_page_out(struct vm_area_struct *vma, unsigned long start,
                                unsigned long end, unsigned long page_shift,
                                struct kvm *kvm, unsigned long gpa, ...);
extern void kvmppc_gfn_remove(unsigned long gfn, struct kvm *kvm);
extern struct vm_area_struct *vma_lookup(struct mm_struct *mm, unsigned long addr);
extern void mmap_read_lock(struct mm_struct *mm);
extern void mmap_read_unlock(struct mm_struct *mm);
extern struct page *pfn_to_page(unsigned long pfn);
extern void mutex_lock(struct mutex *lock);
extern void mutex_unlock(struct mutex *lock);
extern int pr_err(const char *fmt, ...);