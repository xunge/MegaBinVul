#include <stdbool.h>
#include <string.h>

struct vm_area_struct;
struct kvm;
struct page;

#define MIGRATE_VMA_SELECT_SYSTEM 0
#define MIGRATE_PFN_MIGRATE (1UL << 0)
#define MIGRATE_PFN_SHIFT 1

struct migrate_vma {
    struct vm_area_struct *vma;
    unsigned long start;
    unsigned long end;
    unsigned long *src;
    unsigned long *dst;
    unsigned long flags;
};

extern int migrate_vma_setup(struct migrate_vma *mig);
extern void migrate_vma_pages(struct migrate_vma *mig);
extern void migrate_vma_finalize(struct migrate_vma *mig);
extern struct page *migrate_pfn_to_page(unsigned long pfn);
extern unsigned long migrate_pfn(unsigned long pfn);
extern unsigned long page_to_pfn(struct page *page);

struct kvm {
    struct {
        unsigned long lpid;
    } arch;
};

extern struct page *kvmppc_uvmem_get_page(unsigned long gpa, struct kvm *kvm);
extern int uv_page_in(unsigned long lpid, unsigned long pfn, unsigned long gpa, int flags, unsigned long page_shift);