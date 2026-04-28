#include <stdbool.h>
#include <string.h>

struct vm_area_struct;
struct page {
    void *zone_device_data;
};

struct kvm_arch {
    unsigned long lpid;
};

struct kvm {
    struct kvm_arch arch;
};

struct migrate_vma {
    struct vm_area_struct *vma;
    unsigned long start;
    unsigned long end;
    unsigned long *src;
    unsigned long *dst;
    void *pgmap_owner;
    unsigned long flags;
    struct page *fault_page;
};

struct kvmppc_uvmem_page_pvt {
    bool skip_page_out;
};

struct kvmppc_uvmem_pgmap;

extern struct kvmppc_uvmem_pgmap kvmppc_uvmem_pgmap;

#define U_SUCCESS 0
#define MIGRATE_VMA_SELECT_DEVICE_PRIVATE 0
#define MIGRATE_PFN_MIGRATE (1 << 0)
#define GFP_HIGHUSER 0

int migrate_vma_setup(struct migrate_vma *mig);
struct page *migrate_pfn_to_page(unsigned long pfn);
bool is_zone_device_page(struct page *page);
struct page *alloc_page_vma(unsigned int gfp, struct vm_area_struct *vma, unsigned long addr);
void lock_page(struct page *page);
void unlock_page(struct page *page);
void __free_page(struct page *page);
unsigned long page_to_pfn(struct page *page);
void migrate_vma_pages(struct migrate_vma *mig);
void migrate_vma_finalize(struct migrate_vma *mig);
int uv_page_out(unsigned long lpid, unsigned long pfn, unsigned long gpa, int flags, unsigned long page_shift);
bool kvmppc_gfn_is_uvmem_pfn(unsigned long gfn, struct kvm *kvm, void *arg);
unsigned long migrate_pfn(unsigned long pfn);