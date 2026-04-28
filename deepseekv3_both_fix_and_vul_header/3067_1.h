#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define PAGE_SIZE 4096
#define PAGE_SHIFT 12
#define KVM_MEMORY_SLOTS 32
#define KVM_PRIVATE_MEM_SLOTS 4
#define KVM_MEM_MAX_NR_PAGES (1UL << 31)
#define KVM_NR_PAGE_SIZES 4
#define GFP_KERNEL 0
#define EINVAL 22
#define EEXIST 17
#define ENOMEM 12
#define VERIFY_WRITE 1

typedef uint64_t gfn_t;

struct kvm_userspace_memory_region {
    uint32_t slot;
    uint32_t flags;
    uint64_t guest_phys_addr;
    uint64_t memory_size;
    uint64_t userspace_addr;
};

struct lpage_info {
    int write_count;
};

struct kvm_memory_slot {
    gfn_t base_gfn;
    unsigned long npages;
    unsigned long *rmap;
    unsigned long *dirty_bitmap;
    struct lpage_info *lpage_info[KVM_NR_PAGE_SIZES - 1];
    unsigned long userspace_addr;
    unsigned int flags;
    int user_alloc;
    uint32_t id;
};

struct kvm_memslots {
    int nmemslots;
    int generation;
    struct kvm_memory_slot memslots[KVM_MEMORY_SLOTS + KVM_PRIVATE_MEM_SLOTS];
};

struct kvm {
    struct kvm_memslots *memslots;
    void *srcu;
};

#define KVM_MEM_LOG_DIRTY_PAGES (1UL << 0)
#define KVM_MEMSLOT_INVALID (1UL << 1)

#define KVM_HPAGE_GFN_SHIFT(x) (PAGE_SHIFT + (x) * 9)
#define KVM_PAGES_PER_HPAGE(x) (1UL << KVM_HPAGE_GFN_SHIFT(x))

static int largepages_enabled = 1;

static inline int access_ok(int type, unsigned long addr, unsigned long size) {
    return 1;
}

static void *vzalloc(unsigned long size) {
    return calloc(1, size);
}

static void vfree(void *addr) {
    free(addr);
}

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static void kfree(void *addr) {
    free(addr);
}

static void synchronize_srcu_expedited(void *srcu) {
}

static void rcu_assign_pointer(void *p, void *v) {
    *(void **)p = v;
}

static int kvm_arch_prepare_memory_region(struct kvm *kvm, struct kvm_memory_slot *new,
                                         struct kvm_memory_slot old,
                                         struct kvm_userspace_memory_region *mem,
                                         int user_alloc) {
    return 0;
}

static void kvm_arch_commit_memory_region(struct kvm *kvm,
                                        struct kvm_userspace_memory_region *mem,
                                        struct kvm_memory_slot old,
                                        int user_alloc) {
}

static void kvm_arch_flush_shadow(struct kvm *kvm) {
}

static int kvm_iommu_map_pages(struct kvm *kvm, struct kvm_memory_slot *slot) {
    return 0;
}

static int kvm_create_dirty_bitmap(struct kvm_memory_slot *slot) {
    return 0;
}

static void kvm_free_physmem_slot(struct kvm_memory_slot *free, struct kvm_memory_slot *dont) {
}