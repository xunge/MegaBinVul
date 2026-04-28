#include <stddef.h>
#include <stdint.h>
#include <string.h>

#define ENOTTY 25
#define EFAULT 14
#define EEXIST 17
#define ENOMEM 12
#define ENXIO 6
#define EINVAL 22

#define GFP_KERNEL 0
#define KVM_PIO_BUS 0
#define KVM_USERSPACE_IRQ_SOURCE_ID 0
#define KVM_PIT_SPEAKER_DUMMY 0

#define KVM_SET_TSS_ADDR 0xAE01
#define KVM_SET_IDENTITY_MAP_ADDR 0xAE02
#define KVM_SET_NR_MMU_PAGES 0xAE03
#define KVM_GET_NR_MMU_PAGES 0xAE04
#define KVM_CREATE_IRQCHIP 0xAE05
#define KVM_CREATE_PIT 0xAE06
#define KVM_CREATE_PIT2 0xAE07
#define KVM_IRQ_LINE 0xAE08
#define KVM_IRQ_LINE_STATUS 0xAE09
#define KVM_GET_IRQCHIP 0xAE0A
#define KVM_SET_IRQCHIP 0xAE0B
#define KVM_GET_PIT 0xAE0C
#define KVM_SET_PIT 0xAE0D
#define KVM_GET_PIT2 0xAE0E
#define KVM_SET_PIT2 0xAE0F
#define KVM_REINJECT_CONTROL 0xAE10
#define KVM_XEN_HVM_CONFIG 0xAE11
#define KVM_SET_CLOCK 0xAE12
#define KVM_GET_CLOCK 0xAE13

typedef uint64_t u64;
typedef int64_t s64;
typedef int32_t __s32;

struct file {
    void *private_data;
};

struct kvm_arch {
    void *vpic;
    void *vpit;
    uint64_t kvmclock_offset;
    struct {
        uint32_t flags;
    } xen_hvm_config;
};

struct kvm {
    struct kvm_arch arch;
    void *lock;
    void *irq_lock;
    void *slots_lock;
};

struct kvm_pic {
    struct {
        int dev;
    };
};

struct kvm_irq_level {
    int irq;
    int level;
    int status;
};

struct kvm_pit_state {};
struct kvm_pit_state2 {};
struct kvm_pit_config {
    uint32_t flags;
};
struct kvm_reinject_control {};
struct kvm_xen_hvm_config {
    uint32_t flags;
};
struct kvm_clock_data {
    uint64_t clock;
    uint32_t flags;
    uint8_t pad[32];
};
struct kvm_irqchip {};

static inline void mutex_lock(void *lock) {}
static inline void mutex_unlock(void *lock) {}
static inline void smp_wmb() {}
static inline void local_irq_disable() {}
static inline void local_irq_enable() {}
static inline uint64_t get_kernel_ns() { return 0; }
static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline int copy_from_user(void *to, const void *from, size_t n) { return 0; }
static inline int copy_to_user(void *to, const void *from, size_t n) { return 0; }

static inline int kvm_vm_ioctl_set_tss_addr(struct kvm *kvm, unsigned long arg) { return 0; }
static inline int kvm_vm_ioctl_set_identity_map_addr(struct kvm *kvm, uint64_t addr) { return 0; }
static inline int kvm_vm_ioctl_set_nr_mmu_pages(struct kvm *kvm, unsigned long arg) { return 0; }
static inline int kvm_vm_ioctl_get_nr_mmu_pages(struct kvm *kvm) { return 0; }
static inline struct kvm_pic *kvm_create_pic(struct kvm *kvm) { return NULL; }
static inline int kvm_ioapic_init(struct kvm *kvm) { return 0; }
static inline void kvm_io_bus_unregister_dev(struct kvm *kvm, int bus, void *dev) {}
static inline int kvm_setup_default_irq_routing(struct kvm *kvm) { return 0; }
static inline void kvm_ioapic_destroy(struct kvm *kvm) {}
static inline void kvm_destroy_pic(struct kvm *kvm) {}
static inline int irqchip_in_kernel(struct kvm *kvm) { return 0; }
static inline int kvm_set_irq(struct kvm *kvm, int source, int irq, int level) { return 0; }
static inline int kvm_vm_ioctl_get_irqchip(struct kvm *kvm, struct kvm_irqchip *chip) { return 0; }
static inline int kvm_vm_ioctl_set_irqchip(struct kvm *kvm, struct kvm_irqchip *chip) { return 0; }
static inline int kvm_vm_ioctl_get_pit(struct kvm *kvm, struct kvm_pit_state *ps) { return 0; }
static inline int kvm_vm_ioctl_set_pit(struct kvm *kvm, struct kvm_pit_state *ps) { return 0; }
static inline int kvm_vm_ioctl_get_pit2(struct kvm *kvm, struct kvm_pit_state2 *ps2) { return 0; }
static inline int kvm_vm_ioctl_set_pit2(struct kvm *kvm, struct kvm_pit_state2 *ps2) { return 0; }
static inline int kvm_vm_ioctl_reinject(struct kvm *kvm, struct kvm_reinject_control *control) { return 0; }
static inline void *kvm_create_pit(struct kvm *kvm, uint32_t flags) { return NULL; }

#define __user