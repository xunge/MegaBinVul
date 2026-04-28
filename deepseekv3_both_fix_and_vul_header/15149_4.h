#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

struct descriptor_table {
    uint16_t limit;
    uint64_t base;
};

struct kvm_vcpu {
    struct {
        uint64_t cr2;
        uint64_t cr3;
        uint64_t shadow_efer;
        uint64_t cr0;
        uint64_t cr4;
        unsigned long irq_pending[8];
        unsigned long irq_summary;
        int mp_state;
    } arch;
    struct kvm *kvm;
    unsigned long requests;
    int vcpu_id;
};

struct kvm {
    void *slots_lock;
};

struct kvm_sregs {
    struct {
        uint16_t limit;
        uint64_t base;
    } idt, gdt;
    uint64_t cr2;
    uint64_t cr3;
    uint64_t cr0;
    uint64_t cr4;
    uint64_t cr8;
    uint64_t efer;
    uint64_t apic_base;
    uint64_t interrupt_bitmap;
    struct {
        uint16_t selector;
        uint64_t base;
    } cs, ds, es, fs, gs, ss, tr, ldt;
};

struct kvm_x86_ops {
    void (*set_idt)(struct kvm_vcpu *, struct descriptor_table *);
    void (*set_gdt)(struct kvm_vcpu *, struct descriptor_table *);
    void (*set_efer)(struct kvm_vcpu *, uint64_t);
    void (*decache_cr4_guest_bits)(struct kvm_vcpu *);
    void (*set_cr0)(struct kvm_vcpu *, uint64_t);
    void (*set_cr4)(struct kvm_vcpu *, uint64_t);
    void (*set_irq)(struct kvm_vcpu *, int);
};

enum {
    KVM_REQ_TRIPLE_FAULT,
    KVM_MP_STATE_RUNNABLE,
    VCPU_SREG_CS,
    VCPU_SREG_DS,
    VCPU_SREG_ES,
    VCPU_SREG_FS,
    VCPU_SREG_GS,
    VCPU_SREG_SS,
    VCPU_SREG_TR,
    VCPU_SREG_LDTR,
    X86_CR0_PE
};

#define PAGE_SHIFT 12
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static inline void set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}

static inline int find_first_bit(const unsigned long *addr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (addr[i / (sizeof(unsigned long) * 8)] & (1UL << (i % (sizeof(unsigned long) * 8)))) {
            return i;
        }
    }
    return size;
}

static inline void __set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}

extern struct kvm_x86_ops *kvm_x86_ops;

void vcpu_load(struct kvm_vcpu *vcpu);
void vcpu_put(struct kvm_vcpu *vcpu);
void down_read(void *lock);
void up_read(void *lock);
void kvm_set_cr8(struct kvm_vcpu *vcpu, uint64_t cr8);
void kvm_set_apic_base(struct kvm_vcpu *vcpu, uint64_t apic_base);
bool is_long_mode(struct kvm_vcpu *vcpu);
bool is_pae(struct kvm_vcpu *vcpu);
void load_pdptrs(struct kvm_vcpu *vcpu, uint64_t cr3);
void kvm_mmu_reset_context(struct kvm_vcpu *vcpu);
bool irqchip_in_kernel(struct kvm *kvm);
void kvm_pic_clear_isr_ack(struct kvm *kvm);
void kvm_set_segment(struct kvm_vcpu *vcpu, void *seg, int seg_type);
uint64_t kvm_rip_read(struct kvm_vcpu *vcpu);
bool gfn_to_memslot(struct kvm *kvm, uint64_t gfn);