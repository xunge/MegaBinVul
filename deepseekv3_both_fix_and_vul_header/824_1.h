#include <stdint.h>

#define X86_CR4_FSGSBASE (1 << 16)

#define DIRTY_DS         (1 << 0)
#define DIRTY_ES         (1 << 1)
#define DIRTY_FS         (1 << 2)
#define DIRTY_GS         (1 << 3)
#define DIRTY_FS_BASE    (1 << 4)
#define DIRTY_GS_BASE    (1 << 5)

#define TF_kernel_mode   (1 << 0)

enum {
    ds,
    es,
    fs,
    gs
};

struct cpu_user_regs {
    uint16_t ds;
    uint16_t es;
    uint16_t fs;
    uint16_t gs;
};

struct arch_pv {
    uint64_t fs_base;
    uint64_t gs_base_user;
    uint64_t gs_base_kernel;
};

struct arch_vcpu {
    struct cpu_user_regs user_regs;
    struct arch_pv pv;
    uint32_t flags;
};

struct vcpu {
    struct arch_vcpu arch;
};

extern uint64_t __rdfsbase(void);
extern uint64_t __rdgsbase(void);
extern uint64_t read_cr4(void);
extern uint16_t read_sreg(uint16_t seg);
extern int is_pv_32bit_vcpu(struct vcpu *v);
extern int cpu_has_fsgsbase;

#define this_cpu(var) (var)