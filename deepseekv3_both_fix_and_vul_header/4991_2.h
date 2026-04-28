#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define X86EMUL_OKAY 0
#define X86EMUL_EXCEPTION 1
#define TRAP_gp_fault 13
#define MSR_EFER 0xC0000080
#define MSR_IA32_TSC 0x10
#define MSR_IA32_TSC_ADJUST 0x3B
#define MSR_TSC_AUX 0xC0000103
#define MSR_IA32_APICBASE 0x1B
#define MSR_IA32_APICBASE_MSR 0x800
#define MSR_IA32_TSC_DEADLINE 0x6E0
#define MSR_IA32_CR_PAT 0x277
#define MSR_MTRRcap 0xFE
#define MSR_MTRRdefType 0x2FF
#define MSR_MTRRfix64K_00000 0x250
#define MSR_MTRRfix16K_80000 0x258
#define MSR_MTRRfix16K_A0000 0x259
#define MSR_MTRRfix4K_C0000 0x268
#define MSR_MTRRfix4K_F8000 0x26F
#define MSR_K8_ENABLE_C1E 0xC0010055
#define MSR_AMD64_NB_CFG 0xC001001F
#define MTRR_VCNT 8
#define X86_FEATURE_MTRR (6*32+12)
#define MSR_READ 0

#define MSR_IA32_MTRR_PHYSBASE(n) (0x200 + 2 * (n))
#define MSR_IA32_MTRR_PHYSMASK(n) (0x200 + 2 * (n) + 1)

typedef bool bool_t;

struct vcpu {
    struct {
        struct {
            struct {
                uint64_t var_ranges[16];
                uint64_t fixed_ranges[11];
                uint64_t mtrr_cap;
                uint64_t def_type;
                bool enabled;
            } mtrr;
            uint64_t guest_efer;
        } hvm_vcpu;
    } arch;
};

struct vlapic {
    struct {
        uint64_t apic_base_msr;
    } hw;
};

struct hvm_funcs {
    int (*msr_read_intercept)(unsigned int msr, uint64_t *msr_content);
};

extern struct vcpu *current;
extern struct hvm_funcs hvm_funcs;

uint64_t hvm_get_guest_tsc(struct vcpu *v);
uint64_t hvm_get_guest_tsc_adjust(struct vcpu *v);
uint64_t hvm_msr_tsc_aux(struct vcpu *v);
struct vlapic *vcpu_vlapic(struct vcpu *v);
uint64_t vlapic_tdt_msr_get(struct vlapic *v);
void hvm_get_guest_pat(struct vcpu *v, uint64_t *msr_content);
void hvm_cpuid(unsigned int op, unsigned int *eax, unsigned int *ebx, unsigned int *ecx, unsigned int *edx);
int vmce_rdmsr(unsigned int msr, uint64_t *msr_content);
void hvm_inject_hw_exception(unsigned int trap, int error_code);
bool hvm_x2apic_msr_read(struct vcpu *v, unsigned int msr, uint64_t *msr_content);
unsigned int cpufeat_mask(unsigned int feature);
void HVMTRACE_3D(unsigned int event, unsigned int a, unsigned int b, unsigned int c);