#include <stddef.h>
#include <string.h>

typedef unsigned long gfn_t;

#define KVM_MEM_SLOTS_NUM 1
#define KVM_MEMORY_SLOTS 1
#define KVM_MEM_MAX_NR_PAGES 1

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)

#define GFP_KERNEL 0
#define VERIFY_WRITE 1

#define EINVAL 1
#define EEXIST 2
#define ENOMEM 3

#define KVM_MEM_LOG_DIRTY_PAGES 1
#define KVM_MEMSLOT_INVALID 1

struct kvm_userspace_memory_region {
    unsigned long memory_size;
    unsigned long guest_phys_addr;
    unsigned long userspace_addr;
    unsigned long flags;
    int slot;
};

struct kvm_memory_slot {
    unsigned long base_gfn;
    unsigned long npages;
    unsigned long flags;
    void *dirty_bitmap;
    int user_alloc;
    unsigned long userspace_addr;
    int id;
    struct {
        int dummy;
    } arch;
};

struct kvm_memslots {
    struct kvm_memory_slot memslots[KVM_MEM_SLOTS_NUM];
};

struct kvm {
    struct kvm_memslots *memslots;
    struct {
        int dummy;
    } srcu;
};

#define __user

static inline int access_ok(int type, const void *addr, unsigned long size) { return 1; }
static inline struct kvm_memory_slot *id_to_memslot(struct kvm_memslots *slots, int id) { return &slots->memslots[id]; }
static inline int check_memory_region_flags(struct kvm_userspace_memory_region *mem) { return 0; }
#define kvm_for_each_memslot(slot, slots) \
    for ((slot) = &(slots)->memslots[0]; \
         (slot) < &(slots)->memslots[KVM_MEM_SLOTS_NUM]; \
         (slot)++)
static inline int kvm_arch_create_memslot(struct kvm_memory_slot *slot, unsigned long npages) { return 0; }
static inline int kvm_create_dirty_bitmap(struct kvm_memory_slot *slot) { return 0; }
static inline void update_memslots(struct kvm_memslots *slots, struct kvm_memory_slot *new) {}
static inline void kvm_arch_flush_shadow_memslot(struct kvm *kvm, struct kvm_memory_slot *slot) {}
static inline int kvm_arch_prepare_memory_region(struct kvm *kvm, struct kvm_memory_slot *new, struct kvm_memory_slot old, struct kvm_userspace_memory_region *mem, int user_alloc) { return 0; }
static inline int kvm_iommu_map_pages(struct kvm *kvm, struct kvm_memory_slot *slot) { return 0; }
static inline void kvm_iommu_unmap_pages(struct kvm *kvm, struct kvm_memory_slot *slot) {}
static inline void kvm_arch_commit_memory_region(struct kvm *kvm, struct kvm_userspace_memory_region *mem, struct kvm_memory_slot old, int user_alloc) {}
static inline void kvm_free_physmem_slot(struct kvm_memory_slot *old, struct kvm_memory_slot *new) {}

static inline void *kmemdup(const void *src, size_t len, int gfp) { 
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}
static inline void kfree(const void *objp) { free((void*)objp); }
static inline void rcu_assign_pointer(void *p, void *v) { *(void**)p = v; }
static inline void synchronize_srcu_expedited(void *sp) {}