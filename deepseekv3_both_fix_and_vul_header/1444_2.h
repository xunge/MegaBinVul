#include <stdint.h>
#include <string.h>

#define EINVAL 22
#define ENOENT 2

#define APIC_DEST_SELF 0
#define APIC_DEST_PHYSICAL 0
#define APIC_DM_FIXED 0

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef uint32_t u32;

struct kvm_vcpu_hv_synic {
    u32 sint[16]; // Assuming 16 elements as a reasonable default
};

struct kvm_vcpu {
    int vcpu_id;
    struct {
        void* apic;
    } arch;
    void* kvm;
};

struct kvm_lapic_irq {
    int shorthand;
    int dest_mode;
    int delivery_mode;
    int vector;
    int level;
};

static inline struct kvm_vcpu* hv_synic_to_vcpu(struct kvm_vcpu_hv_synic* synic) { return 0; }
static int synic_get_sint_vector(int sint) { return 0; }
static int synic_read_sint(struct kvm_vcpu_hv_synic* synic, u32 sint) { return 0; }
static int kvm_irq_delivery_to_apic(void* kvm, void* apic, struct kvm_lapic_irq* irq, void* dest_map) { return 0; }
static void trace_kvm_hv_synic_set_irq(int vcpu_id, u32 sint, int vector, int ret) {}