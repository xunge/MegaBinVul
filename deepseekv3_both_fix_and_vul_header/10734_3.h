#include <stdbool.h>
#include <stdint.h>

#define X86EMUL_EXCEPTION 1
#define X86EMUL_OKAY 0
#define DBG_LEVEL_1 1
#define VM_EVENT_X86_CR4 4
#define CR4 4
#define XCR_XFEATURE_ENABLED_MASK 0
#define XSTATE_PKRU (1 << 9)

#define X86_CR4_PAE (1UL << 5)
#define X86_CR4_PCIDE (1UL << 17)
#define X86_CR4_PSE (1UL << 4)
#define X86_CR4_PGE (1UL << 7)
#define X86_CR4_SMEP (1UL << 20)
#define X86_CR4_PKE (1UL << 22)

#define unlikely(x) (x)
#define ASSERT(x) ((void)0)

typedef uint8_t bool_t;

struct monitor {
    unsigned long write_ctrlreg_enabled;
};

struct vm_event {
    struct {
        struct {
            int cr4;
        } do_write;
        unsigned long cr4;
    } write_data;
};

struct hvm_vcpu {
    unsigned long guest_cr[8];
};

struct arch_vcpu {
    struct hvm_vcpu hvm_vcpu;
    struct vm_event *vm_event;
    unsigned long xcr0_accum;
};

struct arch_domain {
    struct monitor monitor;
};

struct vcpu {
    struct arch_vcpu arch;
    struct {
        struct arch_domain arch;
    } *domain;
};

struct vcpu *current;

unsigned long hvm_cr4_guest_valid_bits(struct vcpu *v, int unused);
bool hvm_long_mode_active(struct vcpu *v);
void HVM_DBG_LOG(int level, const char *fmt, ...);
void hvm_update_cr(struct vcpu *v, int cr, unsigned long value);
bool nestedhvm_vmswitch_in_progress(struct vcpu *v);
bool nestedhvm_vcpu_in_guestmode(struct vcpu *v);
void paging_update_nestedmode(struct vcpu *v);
void paging_update_paging_modes(struct vcpu *v);
unsigned long monitor_ctrlreg_bitmask(unsigned int index);
bool hvm_monitor_crX(unsigned int cr, unsigned long new, unsigned long old);
unsigned long get_xcr0(void);
int handle_xsetbv(unsigned int xcr, unsigned long value);