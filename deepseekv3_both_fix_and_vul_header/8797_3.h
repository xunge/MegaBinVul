#include <stdint.h>
#include <stddef.h>

typedef uint32_t u32;

#define INTR_INFO_INTR_TYPE_MASK 0x700
#define INTR_TYPE_NMI_INTR 0x200
#define INTR_INFO_DELIVER_CODE_MASK 0x800
#define INTR_INFO_VECTOR_MASK 0xff
#define VECTORING_INFO_VALID_MASK 0x80000000
#define PFERR_RSVD_MASK 0x10
#define UD_VECTOR 6
#define AC_VECTOR 17
#define DB_VECTOR 1
#define BP_VECTOR 3
#define DR6_RTM 0x4000
#define DR6_RESERVED 0xffff0ff0
#define DR6_FIXED_1 0xffff0ff0
#define KVM_EXIT_INTERNAL_ERROR 2
#define KVM_INTERNAL_ERROR_SIMUL_EX 1
#define KVM_EXIT_DEBUG 4
#define KVM_EXIT_EXCEPTION 1
#define KVM_GUESTDBG_SINGLESTEP 1
#define KVM_GUESTDBG_USE_HW_BP 2
#define EMULTYPE_TRAP_UD 1
#define VM_EXIT_INTR_ERROR_CODE 0x4402
#define EXIT_QUALIFICATION 0x6400
#define GUEST_DR7 0x681A
#define VM_EXIT_INSTRUCTION_LEN 0x440C
#define GUEST_CS_BASE 0x6800

enum emulation_result {
    EMULATE_DONE,
    EMULATE_DO_MMIO,
    EMULATE_FAIL
};

struct kvm_vcpu {
    struct kvm_run *run;
    unsigned long guest_debug;
    struct {
        unsigned long dr6;
        unsigned long event_exit_inst_len;
    } arch;
};

struct vcpu_vmx {
    u32 idt_vectoring_info;
    u32 exit_intr_info;
    struct {
        int vm86_active;
    } rmode;
    struct kvm_vcpu vcpu;
};

struct debug_arch {
    unsigned long dr6;
    unsigned long dr7;
    unsigned long pc;
    u32 exception;
};

struct kvm_run {
    int exit_reason;
    union {
        struct {
            u32 exception;
            u32 error_code;
        } ex;
        struct {
            struct debug_arch arch;
        } debug;
        struct {
            u32 suberror;
            u32 ndata;
            u32 data[3];
        } internal;
    };
};

#define BUG_ON(condition) do { if (condition) {} } while (0)
#define enable_ept 0

static inline struct vcpu_vmx *to_vmx(struct kvm_vcpu *vcpu) { return (struct vcpu_vmx *)vcpu; }
static inline int is_machine_check(u32 intr_info) { return 0; }
static inline int is_no_device(u32 intr_info) { return 0; }
static inline int is_invalid_opcode(u32 intr_info) { return 0; }
static inline int is_page_fault(u32 intr_info) { return 0; }
static inline int is_guest_mode(struct kvm_vcpu *vcpu) { return 0; }
static inline int rmode_exception(struct kvm_vcpu *vcpu, u32 ex_no) { return 0; }
static inline int handle_machine_check(struct kvm_vcpu *vcpu) { return 0; }
static inline int handle_rmode_exception(struct kvm_vcpu *vcpu, u32 ex_no, u32 error_code) { return 0; }
static inline void vmx_fpu_activate(struct kvm_vcpu *vcpu) {}
static inline void kvm_queue_exception(struct kvm_vcpu *vcpu, int vector) {}
static inline void kvm_queue_exception_e(struct kvm_vcpu *vcpu, int vector, u32 error_code) {}
static inline enum emulation_result emulate_instruction(struct kvm_vcpu *vcpu, int emul_type) { return EMULATE_DONE; }
static inline u32 vmcs_read32(unsigned long field) { return 0; }
static inline unsigned long vmcs_readl(unsigned long field) { return 0; }
static inline void trace_kvm_page_fault(unsigned long cr2, u32 error_code) {}
static inline int kvm_event_needs_reinjection(struct kvm_vcpu *vcpu) { return 0; }
static inline void kvm_mmu_unprotect_page_virt(struct kvm_vcpu *vcpu, unsigned long cr2) {}
static inline int kvm_mmu_page_fault(struct kvm_vcpu *vcpu, unsigned long cr2, u32 error_code, void *insn, int insn_len) { return 0; }
static inline void skip_emulated_instruction(struct kvm_vcpu *vcpu) {}
static inline unsigned long kvm_rip_read(struct kvm_vcpu *vcpu) { return 0; }