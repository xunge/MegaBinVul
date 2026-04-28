#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define X86EMUL_OKAY 0
#define X86EMUL_EXCEPTION 1
#define TRAP_gp_fault 13
#define MSR_WRITE 0
#define MSR_EFER 0xC0000080
#define MSR_IA32_TSC 0x10
#define MSR_IA32_TSC_ADJUST 0x3B
#define MSR_TSC_AUX 0xC0000103
#define MSR_IA32_APICBASE 0x1B
#define MSR_IA32_TSC_DEADLINE 0x6E0
#define MSR_IA32_APICBASE_MSR 0x800
#define MSR_IA32_CR_PAT 0x277
#define MSR_MTRRcap 0xFE
#define MSR_MTRRdefType 0x2FF
#define MSR_MTRRfix64K_00000 0x250
#define MSR_MTRRfix16K_80000 0x258
#define MSR_MTRRfix16K_A0000 0x259
#define MSR_MTRRfix4K_C0000 0x268
#define MSR_MTRRfix4K_F8000 0x26F
#define MSR_AMD64_NB_CFG 0xC001001F
#define MTRR_VCNT 8
#define X86_FEATURE_MTRR (6*32+12)
#define TSC_MODE_PVRDTSCP 2

#define MSR_IA32_MTRR_PHYSBASE(n) (0x200 + 2 * (n))
#define MSR_IA32_MTRR_PHYSMASK(n) (0x200 + 2 * (n) + 1)

struct domain {
    struct {
        int tsc_mode;
    } arch;
};

struct vcpu {
    struct domain* domain;
    struct {
        struct {
            unsigned int msr_tsc_aux;
            int mtrr;
        } hvm_vcpu;
    } arch;
};

typedef bool bool_t;

extern struct vcpu* current;
extern unsigned int cpufeat_mask(unsigned int);
extern void HVMTRACE_3D(int, unsigned int, uint32_t, uint32_t);
extern void hvm_cpuid(unsigned int, unsigned int*, unsigned int*, unsigned int*, unsigned int*);
extern void hvm_memory_event_msr(unsigned int, uint64_t);
extern int hvm_set_efer(uint64_t);
extern void hvm_set_guest_tsc(struct vcpu*, uint64_t);
extern void hvm_set_guest_tsc_adjust(struct vcpu*, uint64_t);
extern int cpu_has_rdtscp;
extern void wrmsrl(unsigned int, uint32_t);
extern void* vcpu_vlapic(struct vcpu*);
extern int vlapic_msr_set(void*, uint64_t);
extern void vlapic_tdt_msr_set(void*, uint64_t);
extern int hvm_x2apic_msr_write(struct vcpu*, unsigned int, uint64_t);
extern int hvm_set_guest_pat(struct vcpu*, uint64_t);
extern int mtrr_def_type_msr_set(struct domain*, int*, uint64_t);
extern int mtrr_fix_range_msr_set(struct domain*, int*, unsigned int, uint64_t);
extern int mtrr_var_range_msr_set(struct domain*, int*, unsigned int, uint64_t);
extern int vmce_wrmsr(unsigned int, uint64_t);
extern struct {
    int (*msr_write_intercept)(unsigned int, uint64_t);
} hvm_funcs;
extern void hvm_inject_hw_exception(int, int);