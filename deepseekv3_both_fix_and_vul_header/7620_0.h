#include <stdint.h>
#include <stddef.h>

#define CONFIG_SMM_MODULE_STACK_SIZE 1024
#define BIOS_DEBUG 0

struct smm_loader_params {
    size_t per_cpu_stack_size;
    int num_concurrent_stacks;
    size_t per_cpu_save_state_size;
    int num_concurrent_save_states;
};

struct mp_state_ops {
    void (*adjust_smm_params)(struct smm_loader_params *, int);
};

struct mp_state {
    struct mp_state_ops ops;
} mp_state;

void printk(int level, const char *format, ...);
int smm_load_module(void *smbase, size_t smsize, struct smm_loader_params *params);
void adjust_smm_apic_id_map(struct smm_loader_params *params);