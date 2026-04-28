#include <stddef.h>

#define CONFIG(X) 0
#define CONFIG_SMM_STUB_STACK_SIZE 0
#define BIOS_ERR 0
#define __func__ ""

struct smm_loader_params {
    size_t per_cpu_stack_size;
    int num_concurrent_stacks;
    size_t per_cpu_save_state_size;
    int num_concurrent_save_states;
    void (*handler)(void);
};

struct mp_state_ops {
    void (*adjust_smm_params)(struct smm_loader_params *, int);
};

struct {
    struct mp_state_ops ops;
} mp_state;

void smm_do_relocation(void);
int smm_setup_relocation_handler(struct smm_loader_params *);
void adjust_smm_apic_id_map(struct smm_loader_params *);
void printk(int level, const char *fmt, ...);