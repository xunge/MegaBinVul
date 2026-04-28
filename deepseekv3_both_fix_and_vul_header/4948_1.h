#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

typedef unsigned long gfn_t;
typedef unsigned long pfn_t;

#define PAGE_SHIFT 12
#define KERN_ERR "<3>"
#define KVM_MEM_READONLY 0x01

#define IOMMU_READ 0x01
#define IOMMU_WRITE 0x02
#define IOMMU_CACHE 0x04

struct kvm {
    struct {
        struct iommu_domain *iommu_domain;
        bool iommu_noncoherent;
    } arch;
};

struct kvm_memory_slot {
    gfn_t base_gfn;
    unsigned long npages;
    unsigned long flags;
};

struct iommu_domain;

unsigned long __gfn_to_hva_memslot(struct kvm_memory_slot *slot, gfn_t gfn);
unsigned long gfn_to_gpa(gfn_t gfn);
unsigned long pfn_to_hpa(pfn_t pfn);
unsigned long kvm_host_page_size(struct kvm *kvm, gfn_t gfn);
pfn_t kvm_pin_pages(struct kvm_memory_slot *slot, gfn_t gfn, unsigned long page_size);
bool is_error_noslot_pfn(pfn_t pfn);
int iommu_map(struct iommu_domain *domain, unsigned long iova, unsigned long paddr, size_t size, int prot);
unsigned long iommu_iova_to_phys(struct iommu_domain *domain, unsigned long iova);
void kvm_iommu_put_pages(struct kvm *kvm, gfn_t base_gfn, gfn_t end_gfn);
int printk(const char *fmt, ...);