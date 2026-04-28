#include <stdint.h>

struct domain {
    struct {
        uint32_t vpidr;
    } arch;
};

struct vcpu {
    struct domain *domain;
    struct {
        uint64_t vmpidr;
        uint64_t far;
        uint64_t esr;
        uint64_t ifsr;
        uint64_t afsr0;
        uint64_t afsr1;
        uint64_t vbar;
        uint64_t ttbcr;
        uint64_t ttbr0;
        uint64_t ttbr1;
        uint64_t dacr;
        uint64_t par;
        uint64_t mair;
        uint64_t amair;
        uint64_t cpacr;
        uint64_t contextidr;
        uint64_t tpidr_el0;
        uint64_t tpidrro_el0;
        uint64_t tpidr_el1;
        uint32_t teecr;
        uint32_t teehbr;
        uint32_t dfar;
        uint32_t ifar;
        uint32_t dfsr;
        uint32_t mair0;
        uint32_t mair1;
        uint32_t amair0;
        uint32_t amair1;
        uint32_t joscr;
        uint32_t jmcr;
        uint64_t csselr;
    } arch;
};

#define CONFIG_ARM_32
#define CONFIG_ARM_64

#define VPIDR_EL2 0
#define VMPIDR_EL2 0
#define FAR_EL1 0
#define ESR_EL1 0
#define IFSR32_EL2 0
#define AFSR0_EL1 0
#define AFSR1_EL1 0
#define VBAR_EL1 0
#define TCR_EL1 0
#define TTBR0_EL1 0
#define TTBR1_EL1 0
#define DACR32_EL2 0
#define PAR_EL1 0
#define MAIR_EL1 0
#define AMAIR_EL1 0
#define CPACR_EL1 0
#define CONTEXTIDR_EL1 0
#define TPIDR_EL0 0
#define TPIDRRO_EL0 0
#define TPIDR_EL1 0
#define TEECR32_EL1 0
#define TEEHBR32_EL1 0
#define CSSELR_EL1 0
#define DFAR 0
#define IFAR 0
#define DFSR 0
#define MAIR0 0
#define MAIR1 0
#define AMAIR0 0
#define AMAIR1 0
#define JOSCR 0
#define JMCR 0

#define WRITE_SYSREG32(v, r) (void)0
#define WRITE_SYSREG(v, r) (void)0
#define WRITE_SYSREG64(v, r) (void)0
#define WRITE_CP32(v, r) (void)0
#define isb() (void)0

static void p2m_restore_state(struct vcpu *n) {}
static void gic_restore_state(struct vcpu *n) {}
static void vfp_restore_state(struct vcpu *n) {}
static void virt_timer_restore(struct vcpu *n) {}
static int is_32bit_domain(struct domain *d) { return 0; }
static int cpu_has_thumbee = 0;