#include <stddef.h>
#include <stdint.h>

enum mc_disposition {
    mc_continue,
    mc_preempt
};

struct multicall_entry {
    unsigned int op;
    long result;
    unsigned long args[5];
};

struct mc_state {
    struct multicall_entry call;
};

typedef long (*arm_hypercall_fn_t)(unsigned long, unsigned long, unsigned long, unsigned long, unsigned long);

struct arm_hypercall {
    arm_hypercall_fn_t fn;
};

struct domain {
    unsigned long domain;
};

extern struct arm_hypercall arm_hypercall_table[10];
extern struct domain *current;

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define likely(x) (x)
#define ENOSYS 38

int is_32bit_domain(struct domain *d);
int check_multicall_32bit_clean(struct multicall_entry *multi);
int psr_mode_is_user(void *regs);
void *guest_cpu_user_regs(void);