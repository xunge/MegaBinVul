#include <stdint.h>
#include <inttypes.h>

struct cpu_user_regs {
    uint32_t cpsr;
};

struct reg_ctxt {
    uint64_t vttbr_el2;
};

struct domain {
    int is_32bit;
    int is_64bit;
};

struct vcpu {
    struct domain *domain;
};

#define CONFIG_ARM_64
#define CONFIG_ARM_32

#define PRIregister "lx"
#define BUG_ON(cond) do { if (cond) {} } while (0)

#define READ_SYSREG32(reg) (0)
#define READ_SYSREG64(reg) (0)
#define READ_SYSREG(reg) (0)
#define READ_CP32(reg) (0)

void print_xen_info(void);
void printk(const char *fmt, ...);
void show_registers_32(struct cpu_user_regs *regs, struct reg_ctxt *ctxt, int guest_mode, const struct vcpu *v);
void show_registers_64(struct cpu_user_regs *regs, struct reg_ctxt *ctxt, int guest_mode, const struct vcpu *v);
int smp_processor_id(void);
int is_32bit_domain(struct domain *d);
int is_64bit_domain(struct domain *d);
int psr_mode_is_32bit(uint32_t cpsr);
int usr_mode(struct cpu_user_regs *regs);