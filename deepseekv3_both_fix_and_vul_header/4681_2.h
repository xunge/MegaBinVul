#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint64_t target_ulong;

typedef struct CPUX86State {
    // Placeholder for CPUX86State members
} CPUX86State;

typedef struct CPUState {
    // Placeholder for CPUState members
} CPUState;

typedef struct X86CPU {
    CPUX86State env;
    // Placeholder for other X86CPU members
} X86CPU;

typedef struct VAPICHandlers {
    void *set_tpr;
    void *get_tpr[8];
    void *set_tpr_eax;
    void *get_tpr_stack;
} VAPICHandlers;

typedef struct VAPICROMState {
    struct {
        VAPICHandlers up;
        VAPICHandlers mp;
    } rom_state;
} VAPICROMState;

extern int smp_cpus;
extern bool kvm_enabled();

void pause_all_vcpus(void);
void resume_all_vcpus(void);
void cpu_get_tb_cpu_state(CPUX86State *env, target_ulong *pc, target_ulong *cs_base, uint32_t *flags);
void cpu_memory_rw_debug(CPUState *cpu, target_ulong addr, void *buf, int len, int is_write);
void tb_gen_code(CPUState *cpu, target_ulong pc, target_ulong cs_base, uint32_t flags, int max_insns);
void cpu_resume_from_signal(CPUState *cpu, void *puc);
void patch_byte(X86CPU *cpu, target_ulong ip, uint8_t val);
void patch_call(VAPICROMState *s, X86CPU *cpu, target_ulong ip, void *handler);
void abort(void);

#define CPU(cpu) ((CPUState *)(cpu))
#define modrm_reg(x) (((x) >> 3) & 7)