#include <stdint.h>
#include <stdio.h>

#define CONFIG_MAX_CPUS 0
#define CONFIG(X) 0
#define CONFIG_MSEG_SIZE 0
#define CONFIG_X86_SMM_LOADER_VERSION2 0
#define CONFIG_STM 0

#define BIOS_CRIT 0
#define BIOS_ERR 0
#define BIOS_INFO 0
#define BIOS_DEBUG 0

#define asmlinkage
#define __func__ ""

struct smm_runtime {
    uintptr_t smbase;
    size_t save_state_size;
    size_t start32_offset;
};

struct smm_module_params {
    const struct smm_runtime *runtime;
    int cpu;
};

struct smm_relocation_ops {
    void (*relocation_handler)(int cpu, uintptr_t curr_smbase, uintptr_t perm_smbase);
};

struct smm_mp_state {
    uintptr_t perm_smbase;
    size_t perm_smsize;
    struct smm_relocation_ops ops;
};

extern struct smm_mp_state mp_state;

void printk(int level, const char *fmt, ...);
uintptr_t smm_get_cpu_smbase(int cpu);
void stm_setup(uintptr_t mseg, int cpu, uintptr_t perm_smbase, uintptr_t base, size_t offset);