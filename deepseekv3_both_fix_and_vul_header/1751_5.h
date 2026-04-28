#include <stdbool.h>
#include <stddef.h>

#define H_UNSUPPORTED 0x1000
#define H_P2 0x2000
#define H_P3 0x3000
#define H_PARAMETER 0x4000
#define H_SUCCESS 0
#define PAGE_SHIFT 12
#define KVMPPC_SECURE_INIT_START 0x1

struct kvm {
    struct {
        unsigned long secure_guest;
    } arch;
    void *mm;
    void *srcu;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
};

unsigned long gfn_to_hva(struct kvm *kvm, unsigned long gfn);
bool kvm_is_error_hva(unsigned long hva);
struct vm_area_struct *find_vma_intersection(void *mm, unsigned long start_addr, unsigned long end_addr);
bool kvmppc_svm_page_out(struct vm_area_struct *vma, unsigned long start, unsigned long end, unsigned long page_shift, struct kvm *kvm, unsigned long gpa, ...);

int srcu_read_lock(void *srcu);
void srcu_read_unlock(void *srcu, int idx);
void mmap_read_lock(void *mm);
void mmap_read_unlock(void *mm);