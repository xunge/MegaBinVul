#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t u32;
typedef uint64_t u64;

#define MSR_K8_HWCR 0xC0010015
#define MSR_K8_EXT_FEATURE_MASK 0xC001001F
#define MSR_AMD64_LS_CFG 0xC0011020
#define MSR_AMD64_DE_CFG 0xC0011029
#define MSR_AMD64_IC_CFG 0xC0011021
#define MSR_F10_BU_CFG2 0xC001102A
#define MSR_K7_PERFCTR0 0xC0010000
#define MSR_K7_PERFCTR1 0xC0010001
#define MSR_K7_PERFCTR2 0xC0010002
#define MSR_K7_PERFCTR3 0xC0010003

#define NCAPINTS 32
#define NMI_LOCAL_APIC 1

struct cpuinfo_x86 {
    unsigned int x86;
    unsigned int x86_model;
    unsigned int extended_cpuid_level;
    unsigned int x86_max_cores;
    unsigned long x86_capability[NCAPINTS];
};

extern struct cpuinfo_x86 boot_cpu_data;
extern bool amd_acpi_c1e_quirk;
extern int opt_allow_unsafe;
extern int opt_cpu_info;
extern int opt_arat;
extern int nmi_watchdog;
extern u32 acpi_smi_cmd;
extern u32 acpi_enable_value;
extern u32 acpi_disable_value;

enum {
    X86_FEATURE_PBE,
    X86_FEATURE_LAHF_LM,
    X86_FEATURE_RSTR_FP_ERR_PTRS,
    X86_FEATURE_LFENCE_DISPATCH,
    X86_FEATURE_MFENCE_RDTSC,
    X86_FEATURE_CLFLUSHOPT,
    X86_FEATURE_RDRAND,
    X86_FEATURE_BTC_NO,
    X86_FEATURE_ITSC,
    X86_FEATURE_CONSTANT_TSC,
    X86_FEATURE_NONSTOP_TSC,
    X86_FEATURE_TSC_RELIABLE,
    X86_FEATURE_TOPOEXT,
    X86_FEATURE_MONITOR,
    X86_FEATURE_SEP,
    X86_FEATURE_ARAT,
    X86_FEATURE_EFRO
};

enum {
    X86_BUG_FPU_PTRS,
    X86_BUG_NULL_SEG,
    X86_BUG_CLFLUSH_MFENCE
};

#define AMD_ERRATUM_121 0

#define cf_check

static inline bool cpu_has(const struct cpuinfo_x86 *c, int feature) { return false; }
static inline bool cpu_has_hypervisor(void) { return false; }
static inline bool cpu_has_nscb(void) { return false; }
static inline bool cpu_has_lfence_dispatch(void) { return false; }
static inline bool cpu_has_clflushopt(void) { return false; }
static inline bool is_forced_cpu_cap(int feature) { return false; }
static inline bool cpu_has_amd_erratum(const struct cpuinfo_x86 *c, int erratum) { return false; }

static inline void __clear_bit(int nr, volatile unsigned long *addr) {}
static inline void __set_bit(int nr, volatile unsigned long *addr) {}
static inline void setup_force_cpu_cap(int feature) {}
static inline void setup_clear_cpu_cap(int feature) {}
static inline void warning_add(const char *text) {}
static inline void panic(const char *fmt) {}

static inline void rdmsrl(unsigned int msr, u64 *val) {}
static inline void wrmsrl(unsigned int msr, u64 val) {}
static inline void rdmsr(unsigned int msr, u32 *lo, u32 *hi) {}
static inline void wrmsr(unsigned int msr, u32 lo, u32 hi) {}

static inline bool rdmsr_safe(unsigned int msr, u64 *val) { return false; }
static inline bool wrmsr_safe(unsigned int msr, u64 val) { return false; }
static inline bool rdmsr_amd_safe(unsigned int msr, u32 *lo, u32 *hi) { return false; }
static inline bool wrmsr_amd_safe(unsigned int msr, u32 lo, u32 hi) { return false; }

static inline unsigned int cpuid_ecx(unsigned int op) { return 0; }
static inline unsigned int smp_processor_id(void) { return 0; }

static inline void disable_c1e(void *arg) {}
static inline void amd_init_lfence(struct cpuinfo_x86 *c) {}
static inline void amd_init_ssbd(struct cpuinfo_x86 *c) {}
static inline void amd_init_spectral_chicken(void) {}
static inline void detect_zen2_null_seg_behaviour(void) {}
static inline void display_cacheinfo(struct cpuinfo_x86 *c) {}
static inline void amd_get_topology(struct cpuinfo_x86 *c) {}
static inline void check_enable_amd_mmconf_dmi(void) {}
static inline void fam10h_check_enable_mmcfg(void) {}
static inline void disable_c1_ramping(void) {}
static inline void check_syscfg_dram_mod_en(void) {}
static inline void amd_log_freq(struct cpuinfo_x86 *c) {}

#define printk(fmt, ...) 
#define printk_once(fmt, ...) 
#define KERN_INFO ""
#define KERN_WARNING ""
#define XENLOG_WARNING ""

#define PCI_SBDF(seg, bus, dev, func) 0
static inline u32 pci_conf_read32(unsigned int sbdf, unsigned int reg) { return 0; }
static inline void pci_conf_write32(unsigned int sbdf, unsigned int reg, u32 val) {}

#define __initconst