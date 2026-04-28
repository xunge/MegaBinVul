#include <stddef.h>
#include <stdint.h>

typedef unsigned long gfn_t;

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define KVM_MEM_SLOTS_NUM 32
#define KVM_MEM_MAX_NR_PAGES (1UL << 31)
#define KVM_MEMORY_SLOTS 32
#define KVM_NR_PAGE_SIZES 3
#define CONFIG_S390 0
#define GFP_KERNEL 0
#define VERIFY_WRITE 1
#define EINVAL 22
#define EEXIST 17
#define ENOMEM 12

#define KVM_MEM_LOG_DIRTY_PAGES (1UL << 0)
#define KVM_MEMSLOT_INVALID (1UL << 1)

#define KVM_HPAGE_GFN_SHIFT(x) (PAGE_SHIFT + (x * 9))
#define KVM_PAGES_PER_HPAGE(x) (1UL << KVM_HPAGE_GFN_SHIFT(x))

struct kvm_userspace_memory_region {
    unsigned long memory_size;
    unsigned long guest_phys_addr;
    unsigned long userspace_addr;
    unsigned long slot;
    unsigned long flags;
};

struct kvm_memory_slot {
    unsigned long base_gfn;
    unsigned long npages;
    unsigned long flags;
    unsigned long id;
    void *dirty_bitmap;
    void *rmap;
    void *lpage_info[KVM_NR_PAGE_SIZES-1];
    int user_alloc;
    unsigned long userspace_addr;
};

struct kvm_memslots {
    struct kvm_memory_slot memslots[KVM_MEMORY_SLOTS];
};

struct srcu_struct {
    int dummy;
};

struct kvm {
    struct kvm_memslots *memslots;
    struct srcu_struct srcu;
};

struct lpage_info {
    int write_count;
};

#define __user

static inline struct kvm_memory_slot *id_to_memslot(struct kvm_memslots *slots, unsigned long id)
{
    return &slots->memslots[id];
}

static int largepages_enabled = 1;

static void *vzalloc(unsigned long size) { return NULL; }
static void *kmemdup(const void *src, size_t len, int gfp) { return NULL; }
static void kfree(const void *objp) {}
static int access_ok(int type, const void *addr, unsigned long size) { return 1; }
static void synchronize_srcu_expedited(struct srcu_struct *sp) {}
static int kvm_create_dirty_bitmap(struct kvm_memory_slot *slot) { return 0; }
static void update_memslots(struct kvm_memslots *slots, struct kvm_memory_slot *new) {}
static void kvm_arch_flush_shadow(struct kvm *kvm) {}
static int kvm_arch_prepare_memory_region(struct kvm *kvm, struct kvm_memory_slot *new,
                                         struct kvm_memory_slot old, struct kvm_userspace_memory_region *mem,
                                         int user_alloc) { return 0; }
static int kvm_iommu_map_pages(struct kvm *kvm, struct kvm_memory_slot *slot) { return 0; }
static void kvm_arch_commit_memory_region(struct kvm *kvm, struct kvm_userspace_memory_region *mem,
                                         struct kvm_memory_slot old, int user_alloc) {}
static void kvm_free_physmem_slot(struct kvm_memory_slot *old, struct kvm_memory_slot *new) {}
static void rcu_assign_pointer(void *p, void *v) {}