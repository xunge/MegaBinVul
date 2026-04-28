#include <stdbool.h>
#include <stdint.h>
#include <linux/types.h>

typedef unsigned long gpa_t;
typedef uint32_t u32;

struct kvm_vcpu_stats {
    int mmio_exits;
};

struct kvm_vcpu {
    struct {
        struct x86_emulate_ctxt *emulate_ctxt;
        bool l1tf_flush_l1d;
        bool write_fault_to_shadow_pgtable;
        bool emulate_regs_need_sync_from_vcpu;
        bool emulate_regs_need_sync_to_vcpu;
        unsigned long rip;
        unsigned long rflags;
        unsigned long guest_debug;
        struct {
            int count;
            bool in;
        } pio;
        bool mmio_needed;
        bool mmio_is_write;
        void (*complete_userspace_io)(struct kvm_vcpu *);
        struct kvm_vcpu_stats stat;
        struct {
            struct {
                bool direct;
            } root_role;
        } *mmu;
    } arch;
    bool mmio_needed;
    bool mmio_is_write;
    struct kvm_vcpu_stats stat;
    unsigned long guest_debug;
};

struct x86_emulate_ctxt {
    int mode;
    unsigned long eip;
    unsigned long _eip;
    unsigned long eflags;
    bool have_exception;
    struct {
        int vector;
        unsigned long address;
    } exception;
    bool gpa_available;
    gpa_t gpa_val;
    int interruptibility;
    bool is_branch;
    bool tf;
};

#define EMULTYPE_NO_DECODE          0x01
#define EMULTYPE_TRAP_UD            0x02
#define EMULTYPE_TRAP_UD_FORCED     0x04
#define EMULTYPE_VMWARE_GP          0x08
#define EMULTYPE_SKIP               0x10
#define EMULTYPE_COMPLETE_USER_EXIT 0x20
#define EMULTYPE_PF                 0x40

#define EMULATION_OK                0
#define EMULATION_FAILED            1
#define EMULATION_INTERCEPTED       2
#define EMULATION_RESTART           3

#define UD_VECTOR                   6
#define GP_VECTOR                   13

#define X86EMUL_MODE_PROT64         4
#define X86_EFLAGS_RF               0x00010000
#define X86_EFLAGS_IF               0x00000200

#define EXCPT_TRAP                  1
#define PERF_COUNT_HW_INSTRUCTIONS  0
#define PERF_COUNT_HW_BRANCH_INSTRUCTIONS 1

#define KVM_GUESTDBG_SINGLESTEP     0x00000001
#define KVM_REQ_EVENT               0x00000001

static inline bool unlikely(bool expr) { return expr; }
static inline void WARN_ON_ONCE(bool condition) { (void)condition; }

#define static_call(func) func
#define static_call_cond(func) func

unsigned long kvm_x86_get_rflags(struct kvm_vcpu *vcpu);
void kvm_x86_update_emulated_instruction(struct kvm_vcpu *vcpu);

void kvm_clear_exception_queue(struct kvm_vcpu *vcpu);
int x86_decode_emulated_instruction(struct kvm_vcpu *vcpu, int emulation_type, void *insn, int insn_len);
bool kvm_can_emulate_insn(struct kvm_vcpu *vcpu, int emulation_type, void *insn, int insn_len);
void kvm_queue_exception(struct kvm_vcpu *vcpu, int vector);
void kvm_queue_exception_e(struct kvm_vcpu *vcpu, int vector, int error_code);
bool reexecute_instruction(struct kvm_vcpu *vcpu, gpa_t cr2_or_gpa, bool write_fault_to_spt, int emulation_type);
int handle_emulation_failure(struct kvm_vcpu *vcpu, int emulation_type);
int inject_emulated_exception(struct kvm_vcpu *vcpu);
bool is_vmware_backdoor_opcode(struct x86_emulate_ctxt *ctxt);
void kvm_rip_write(struct kvm_vcpu *vcpu, unsigned long rip);
void kvm_set_rflags(struct kvm_vcpu *vcpu, unsigned long rflags);
bool retry_instruction(struct x86_emulate_ctxt *ctxt, gpa_t cr2_or_gpa, int emulation_type);
void emulator_invalidate_register_cache(struct x86_emulate_ctxt *ctxt);
int x86_emulate_insn(struct x86_emulate_ctxt *ctxt);
void complete_emulated_pio(struct kvm_vcpu *vcpu);
void complete_emulated_mmio(struct kvm_vcpu *vcpu);
void toggle_interruptibility(struct kvm_vcpu *vcpu, int interruptibility);
void kvm_pmu_trigger_event(struct kvm_vcpu *vcpu, int event);
int kvm_vcpu_do_singlestep(struct kvm_vcpu *vcpu);
void __kvm_set_rflags(struct kvm_vcpu *vcpu, unsigned long rflags);
void kvm_make_request(int req, struct kvm_vcpu *vcpu);

int exception_type(int vector);