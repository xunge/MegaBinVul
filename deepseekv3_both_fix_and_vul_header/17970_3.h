#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define __user
#define IS_ERR(x) (0)
#define PTR_ERR(x) (0)

struct file {
    void *private_data;
};

struct mutex {
    int dummy;
};

typedef struct {
    int counter;
} atomic_t;

struct kvm {
    struct {
        void *vpic;
        void *vpit;
        struct {
            uint64_t flags;
        } xen_hvm_config;
        int64_t kvmclock_offset;
    } arch;
    struct mutex lock;
    struct mutex slots_lock;
    struct mutex irq_lock;
    atomic_t online_vcpus;
};

struct kvm_pic {
    struct {
        int dummy;
    } dev_master;
    struct {
        int dummy;
    } dev_slave;
    struct {
        int dummy;
    } dev_eclr;
};

struct kvm_pit_state {
    int dummy;
};

struct kvm_pit_state2 {
    int dummy;
};

struct kvm_pit_config {
    uint32_t flags;
};

struct kvm_irq_level {
    uint32_t irq;
    uint32_t level;
    int32_t status;
};

struct kvm_irqchip {
    int dummy;
};

struct kvm_reinject_control {
    int dummy;
};

struct kvm_xen_hvm_config {
    uint64_t flags;
};

struct kvm_clock_data {
    uint64_t clock;
    uint32_t flags;
    uint8_t pad[32];
};

typedef uint64_t u64;
typedef int64_t s64;
typedef int32_t __s32;

#define ENOTTY 25
#define EFAULT 14
#define EEXIST 17
#define EINVAL 22
#define ENOMEM 12
#define ENXIO 6

#define KVM_SET_TSS_ADDR 0x4471
#define KVM_SET_IDENTITY_MAP_ADDR 0x4472
#define KVM_SET_NR_MMU_PAGES 0x4473
#define KVM_GET_NR_MMU_PAGES 0x4474
#define KVM_CREATE_IRQCHIP 0x4475
#define KVM_CREATE_PIT 0x4476
#define KVM_CREATE_PIT2 0x4477
#define KVM_IRQ_LINE_STATUS 0x4478
#define KVM_IRQ_LINE 0x4479
#define KVM_GET_IRQCHIP 0x4480
#define KVM_SET_IRQCHIP 0x4481
#define KVM_GET_PIT 0x4482
#define KVM_SET_PIT 0x4483
#define KVM_GET_PIT2 0x4484
#define KVM_SET_PIT2 0x4485
#define KVM_REINJECT_CONTROL 0x4486
#define KVM_XEN_HVM_CONFIG 0x4487
#define KVM_SET_CLOCK 0x4488
#define KVM_GET_CLOCK 0x4489

#define KVM_PIT_SPEAKER_DUMMY 1
#define KVM_USERSPACE_IRQ_SOURCE_ID 0
#define KVM_PIO_BUS 0

#define smp_wmb() __asm__ __volatile__("": : :"memory")

static inline int atomic_read(const atomic_t *v) { return v->counter; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }
static inline void *memdup_user(const void *src, size_t len) { return NULL; }
static inline void kfree(const void *objp) {}
static inline void local_irq_disable() {}
static inline void local_irq_enable() {}
static inline uint64_t get_kernel_ns() { return 0; }
static inline int mutex_lock(struct mutex *lock) { return 0; }
static inline void mutex_unlock(struct mutex *lock) {}
static inline int kvm_vm_ioctl_set_tss_addr(struct kvm *kvm, unsigned long arg) { return 0; }
static inline int kvm_vm_ioctl_set_identity_map_addr(struct kvm *kvm, u64 addr) { return 0; }
static inline int kvm_vm_ioctl_set_nr_mmu_pages(struct kvm *kvm, unsigned long arg) { return 0; }
static inline int kvm_vm_ioctl_get_nr_mmu_pages(struct kvm *kvm) { return 0; }
static inline struct kvm_pic *kvm_create_pic(struct kvm *kvm) { return NULL; }
static inline int kvm_ioapic_init(struct kvm *kvm) { return 0; }
static inline void kvm_io_bus_unregister_dev(struct kvm *kvm, int bus, void *dev) {}
static inline int kvm_setup_default_irq_routing(struct kvm *kvm) { return 0; }
static inline void kvm_ioapic_destroy(struct kvm *kvm) {}
static inline void kvm_destroy_pic(struct kvm *kvm) {}
static inline void *kvm_create_pit(struct kvm *kvm, uint32_t flags) { return NULL; }
static inline int irqchip_in_kernel(struct kvm *kvm) { return 0; }
static inline int kvm_set_irq(struct kvm *kvm, int source, uint32_t irq, uint32_t level) { return 0; }
static inline int kvm_vm_ioctl_get_irqchip(struct kvm *kvm, struct kvm_irqchip *chip) { return 0; }
static inline int kvm_vm_ioctl_set_irqchip(struct kvm *kvm, struct kvm_irqchip *chip) { return 0; }
static inline int kvm_vm_ioctl_get_pit(struct kvm *kvm, struct kvm_pit_state *ps) { return 0; }
static inline int kvm_vm_ioctl_set_pit(struct kvm *kvm, struct kvm_pit_state *ps) { return 0; }
static inline int kvm_vm_ioctl_get_pit2(struct kvm *kvm, struct kvm_pit_state2 *ps2) { return 0; }
static inline int kvm_vm_ioctl_set_pit2(struct kvm *kvm, struct kvm_pit_state2 *ps2) { return 0; }
static inline int kvm_vm_ioctl_reinject(struct kvm *kvm, struct kvm_reinject_control *control) { return 0; }