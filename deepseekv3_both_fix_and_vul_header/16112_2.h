#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

#define X86EMUL_UNHANDLEABLE 0
#define X86EMUL_EXCEPTION 1
#define X86EMUL_OKAY 2

#define TRAP_gp_fault 13

#define MSR_FS_BASE 0xc0000100
#define MSR_GS_BASE 0xc0000101
#define MSR_SHADOW_GS_BASE 0xc0000102
#define MSR_EFER 0xc0000080
#define MSR_K7_FID_VID_STATUS 0xc0010042
#define MSR_K7_FID_VID_CTL 0xc0010041
#define MSR_K8_PSTATE_LIMIT 0xc0010061
#define MSR_K8_PSTATE_CTRL 0xc0010062
#define MSR_K8_PSTATE_STATUS 0xc0010063
#define MSR_K8_PSTATE0 0xc0010064
#define MSR_K8_PSTATE1 0xc0010065
#define MSR_K8_PSTATE2 0xc0010066
#define MSR_K8_PSTATE3 0xc0010067
#define MSR_K8_PSTATE4 0xc0010068
#define MSR_K8_PSTATE5 0xc0010069
#define MSR_K8_PSTATE6 0xc001006a
#define MSR_K8_PSTATE7 0xc001006b
#define MSR_K8_HWCR 0xc0010015
#define MSR_AMD64_NB_CFG 0xc001001f
#define MSR_FAM10H_MMIO_CONF_BASE 0xc0010058
#define MSR_IA32_MISC_ENABLE 0x000001a0
#define MSR_IA32_MPERF 0x000000e7
#define MSR_IA32_APERF 0x000000e8
#define MSR_IA32_PERF_CTL 0x00000199
#define MSR_IA32_THERM_CONTROL 0x0000019a
#define MSR_IA32_ENERGY_PERF_BIAS 0x000001b0
#define MSR_P6_PERFCTR0 0x000000c1
#define MSR_P6_PERFCTR1 0x000000c2
#define MSR_P6_PERFCTR(n) (MSR_P6_PERFCTR0 + (n))
#define MSR_P6_EVNTSEL0 0x00000186
#define MSR_P6_EVNTSEL(n) (MSR_P6_EVNTSEL0 + (n))
#define MSR_CORE_PERF_FIXED_CTR0 0x00000309
#define MSR_CORE_PERF_FIXED_CTR1 0x0000030a
#define MSR_CORE_PERF_FIXED_CTR2 0x0000030b
#define MSR_CORE_PERF_FIXED_CTR_CTRL 0x0000038d
#define MSR_CORE_PERF_GLOBAL_OVF_CTRL 0x00000390
#define MSR_AMD_FAM15H_EVNTSEL0 0xc0010200
#define MSR_AMD_FAM15H_PERFCTR5 0xc0010205
#define MSR_K7_EVNTSEL0 0xc0010000
#define MSR_K7_PERFCTR3 0xc0010003

#define X86_VENDOR_AMD 1
#define X86_VENDOR_HYGON 2
#define X86_VENDOR_INTEL 3

#define AMD64_NB_CFG_CF8_EXT_ENABLE_BIT 30
#define FAM10H_MMIO_CONF_ENABLE (1ULL << 0)
#define FAM10H_MMIO_CONF_BUSRANGE_MASK 0xff
#define FAM10H_MMIO_CONF_BUSRANGE_SHIFT 2
#define FAM10H_MMIO_CONF_BASE_MASK 0xfffff
#define FAM10H_MMIO_CONF_BASE_SHIFT 20

#define PCI_PROBE_MASK 0xffff0000
#define PCI_PROBE_MMCONF 0x40000000

#define XENPMU_MODE_ALL 0x7
#define XENLOG_WARNING 1

#define likely(x) __builtin_expect(!!(x), 1)

typedef uint64_t u64;

struct x86_emulate_ctxt;
struct vcpu {
    struct domain *domain;
    struct arch {
        struct pv {
            uint64_t gs_base_user;
        } pv;
    } arch;
};
struct domain;

static struct vcpu *current;

static int guest_wrmsr(struct vcpu *vcpu, unsigned int reg, uint64_t val);
static void x86_emul_hw_exception(int trap, int error_code, struct x86_emulate_ctxt *ctxt);
static bool is_pv_32bit_domain(const struct domain *d);
static bool is_canonical_address(uint64_t addr);
static void wrfsbase(uint64_t val);
static void wrgsbase(uint64_t val);
static void wrgsshadow(uint64_t val);
static uint64_t guest_efer(const struct domain *d);
static bool is_cpufreq_controller(const struct domain *d);
static int wrmsr_safe(unsigned int reg, uint64_t val);
static bool is_hwdom_pinned_vcpu(struct vcpu *vcpu);
static int rdmsr_safe(unsigned int reg, uint64_t *val);
static uint64_t guest_misc_enable(uint64_t val);
static bool is_hardware_domain(const struct domain *d);
static bool vpmu_do_wrmsr(unsigned int reg, uint64_t val, int flags);
static void gdprintk(int level, const char *fmt, ...);
static void rdmsrl(unsigned int reg, uint64_t *val);

extern struct {
    int x86_vendor;
    int x86;
} boot_cpu_data;

extern unsigned int pci_probe;
extern unsigned int vpmu_mode;