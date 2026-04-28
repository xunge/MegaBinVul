#include <stdint.h>

struct vcpu {
    struct domain *domain;
    struct {
        uint64_t csselr;
        uint64_t cpacr;
        uint64_t contextidr;
        uint64_t tpidr_el0;
        uint64_t tpidrro_el0;
        uint64_t tpidr_el1;
        uint32_t cntkctl;
        uint32_t teecr;
        uint32_t teehbr;
        uint32_t joscr;
        uint32_t jmcr;
        uint64_t vbar;
        uint64_t ttbcr;
        uint64_t ttbr0;
        uint64_t ttbr1;
        uint32_t dacr;
        uint64_t par;
        uint64_t mair;
        uint64_t amair;
        uint32_t mair0;
        uint32_t mair1;
        uint32_t amair0;
        uint32_t amair1;
        uint32_t dfar;
        uint32_t ifar;
        uint32_t dfsr;
        uint64_t far;
        uint64_t esr;
        uint32_t ifsr;
        uint64_t afsr0;
        uint64_t afsr1;
    } arch;
};

struct domain {
    int dummy;
};

#define READ_SYSREG(reg) (0)
#define READ_SYSREG32(reg) (0)
#define READ_SYSREG64(reg) (0)
#define READ_CP32(reg) (0)
#define is_32bit_domain(d) (0)
#define cpu_has_thumbee (0)
#define CONFIG_ARM_32
#define CONFIG_ARM_64
#define isb() do {} while (0)

static void p2m_save_state(struct vcpu *p) {}
static void virt_timer_save(struct vcpu *p) {}
static void vfp_save_state(struct vcpu *p) {}
static void gic_save_state(struct vcpu *p) {}
static void context_saved(struct vcpu *p) {}