#include <stddef.h>
#include <errno.h>

typedef unsigned long addr_t;

struct psw {
    unsigned long mask;
    unsigned long addr;
};

struct fp_regs {
    unsigned long fpc;
    unsigned long fprs[16];
};

struct per_struct {
    unsigned long control_regs[16];
};

struct user_regs_struct {
    struct psw psw;
    unsigned long acrs[16];
    unsigned long orig_gpr2;
    struct fp_regs fp_regs;
    struct per_struct per_info;
};

struct thread_struct {
    unsigned long acrs[16];
    struct fp_regs fp_regs;
    struct per_struct per_info;
};

struct pt_regs {
    unsigned long orig_gpr2;
    struct psw psw;
};

struct task_struct {
    struct thread_struct thread;
    struct pt_regs *pt_regs;
};

struct user {
    struct user_regs_struct regs;
};

#define CONFIG_COMPAT
#define CONFIG_64BIT
#define BITS_PER_LONG (__CHAR_BIT__ * __SIZEOF_LONG__)
#define PSW_MASK_MERGE(a, b) ((a) | (b))
#define PSW_ADDR_AMODE (1UL << 31)
#define FPC_VALID_MASK 0xFFFFFFFF
#define psw_user_bits 0
#define psw_user32_bits 0
#define EINVAL 22

static inline struct pt_regs *task_pt_regs(struct task_struct *task) {
    return task->pt_regs;
}

static void FixPerRegisters(struct task_struct *child) {}