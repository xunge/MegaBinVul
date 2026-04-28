#include <stdint.h>

#define asmlinkage
typedef uint32_t register_t;

struct cpu_user_regs {
    uint64_t x16;
    uint32_t r12;
    uint32_t cpsr;
};

union hsr {
    struct {
        uint32_t ec:6;
        uint32_t len:1;
        uint32_t iss:25;
    };
    struct {
        uint32_t :6;
        uint32_t :1;
        uint32_t :25;
        uint32_t ti:1;
    } wfi_wfe;
    uint32_t bits;
};

#define READ_SYSREG32(reg) (0)
#define ESR_EL2 (0)
#define HSR_EC_WFI_WFE 1
#define HSR_EC_CP15_32 2
#define HSR_EC_CP15_64 3
#define HSR_EC_CP14_32 4
#define HSR_EC_CP14_DBG 5
#define HSR_EC_CP 6
#define HSR_EC_SMC32 7
#define HSR_EC_HVC32 8
#define HSR_EC_HVC64 9
#define HSR_EC_SMC64 10
#define HSR_EC_SYSREG 11
#define HSR_EC_INSTR_ABORT_LOWER_EL 12
#define HSR_EC_DATA_ABORT_LOWER_EL 13

struct domain {
    int dummy;
};

struct vcpu {
    struct domain *domain;
};

extern struct vcpu *current;

void enter_hypervisor_head(struct cpu_user_regs *regs);
void inject_undef_exception(struct cpu_user_regs *regs, uint32_t len);
void inject_undef32_exception(struct cpu_user_regs *regs);
void inject_undef64_exception(struct cpu_user_regs *regs, uint32_t len);
void advance_pc(struct cpu_user_regs *regs, union hsr hsr);
void vcpu_yield(void);
void vcpu_block_unless_event_pending(struct vcpu *vcpu);
void do_cp15_32(struct cpu_user_regs *regs, union hsr hsr);
void do_cp15_64(struct cpu_user_regs *regs, union hsr hsr);
void do_cp14_32(struct cpu_user_regs *regs, union hsr hsr);
void do_cp14_dbg(struct cpu_user_regs *regs, union hsr hsr);
void do_cp(struct cpu_user_regs *regs, union hsr hsr);
void do_debug_trap(struct cpu_user_regs *regs, uint32_t iss);
void do_trap_psci(struct cpu_user_regs *regs);
void do_trap_hypercall(struct cpu_user_regs *regs, void *arg1, uint32_t iss);
void do_sysreg(struct cpu_user_regs *regs, union hsr hsr);
void do_trap_instr_abort_guest(struct cpu_user_regs *regs, union hsr hsr);
void do_trap_data_abort_guest(struct cpu_user_regs *regs, union hsr hsr);
void do_unexpected_trap(const char *msg, struct cpu_user_regs *regs);
int is_64bit_domain(struct domain *d);
int is_32bit_domain(struct domain *d);
int psr_mode_is_32bit(uint32_t cpsr);
int check_conditional_instr(struct cpu_user_regs *regs, union hsr hsr);
void printk(const char *fmt, ...);

#define CONFIG_ARM_64
#define NDEBUG
#define PRIx32 "x"