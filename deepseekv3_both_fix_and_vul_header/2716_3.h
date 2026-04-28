#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define X86_CR4_OSXSAVE 0x00040000
#define KVM_NR_INTERRUPTS 256
#define VCPU_EXREG_CR3 (1 << 0)
#define VCPU_SREG_CS 0
#define VCPU_SREG_DS 1
#define VCPU_SREG_ES 2
#define VCPU_SREG_FS 3
#define VCPU_SREG_GS 4
#define VCPU_SREG_SS 5
#define VCPU_SREG_TR 6
#define VCPU_SREG_LDTR 7
#define KVM_MP_STATE_RUNNABLE 0
#define KVM_REQ_EVENT 0
#define EINVAL 22

typedef unsigned long ulong;
typedef uint16_t u16;
typedef uint64_t u64;

struct srcu_struct {
    int dummy;
};

struct kvm_vcpu {
    struct kvm *kvm;
    struct {
        unsigned long regs_avail;
        unsigned long cr0;
        unsigned long cr2;
        unsigned long cr3;
        unsigned long cr4;
        unsigned long efer;
        unsigned long apic_base;
        unsigned long mp_state;
        void *walk_mmu;
    } arch;
};

struct kvm {
    struct srcu_struct srcu;
};

struct kvm_sregs {
    struct {
        u16 selector;
        u64 base;
        u16 limit;
    } cs, ds, es, fs, gs, ss, tr, ldt;
    struct {
        u16 limit;
        u64 base;
    } idt, gdt;
    u64 cr0;
    u64 cr2;
    u64 cr3;
    u64 cr4;
    u64 cr8;
    u64 efer;
    u64 apic_base;
    u64 interrupt_bitmap;
};

struct desc_ptr {
    unsigned short size;
    unsigned long address;
};

struct kvm_x86_ops {
    void (*set_idt)(struct kvm_vcpu *vcpu, struct desc_ptr *dt);
    void (*set_gdt)(struct kvm_vcpu *vcpu, struct desc_ptr *dt);
    void (*set_efer)(struct kvm_vcpu *vcpu, u64 efer);
    void (*set_cr0)(struct kvm_vcpu *vcpu, u64 cr0);
    void (*set_cr4)(struct kvm_vcpu *vcpu, u64 cr4);
};

extern struct kvm_x86_ops *kvm_x86_ops;

#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void __set_bit(int nr, volatile unsigned long *addr) {
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

static inline bool guest_cpuid_has_xsave(struct kvm_vcpu *vcpu) { return false; }
static inline bool is_long_mode(struct kvm_vcpu *vcpu) { return false; }
static inline bool is_pae(struct kvm_vcpu *vcpu) { return false; }
static inline bool is_protmode(struct kvm_vcpu *vcpu) { return false; }
static inline bool kvm_vcpu_is_bsp(struct kvm_vcpu *vcpu) { return false; }
static inline int kvm_read_cr0(struct kvm_vcpu *vcpu) { return 0; }
static inline int kvm_read_cr3(struct kvm_vcpu *vcpu) { return 0; }
static inline int kvm_read_cr4(struct kvm_vcpu *vcpu) { return 0; }
static inline int kvm_rip_read(struct kvm_vcpu *vcpu) { return 0; }
static inline void kvm_set_cr8(struct kvm_vcpu *vcpu, u64 cr8) {}
static inline void kvm_set_apic_base(struct kvm_vcpu *vcpu, u64 apic_base) {}
static inline void kvm_update_cpuid(struct kvm_vcpu *vcpu) {}
static inline void kvm_set_segment(struct kvm_vcpu *vcpu, void *sreg, int seg) {}
static inline void kvm_queue_interrupt(struct kvm_vcpu *vcpu, int vec, bool soft) {}
static inline void kvm_mmu_reset_context(struct kvm_vcpu *vcpu) {}
static inline void load_pdptrs(struct kvm_vcpu *vcpu, void *mmu, unsigned long cr3) {}
static inline void update_cr8_intercept(struct kvm_vcpu *vcpu) {}
static inline void kvm_make_request(int req, struct kvm_vcpu *vcpu) {}
static inline int srcu_read_lock(struct srcu_struct *srcu) { return 0; }
static inline void srcu_read_unlock(struct srcu_struct *srcu, int idx) {}