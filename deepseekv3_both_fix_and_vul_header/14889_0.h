#include <stddef.h>

typedef unsigned long addr_t;

struct user {
    struct {
        struct {
            unsigned long mask;
        } psw;
        unsigned long acrs[16];
        unsigned long orig_gpr2;
        struct {
            unsigned long fpc;
        } fp_regs;
        unsigned long per_info;
    } regs;
};

struct pt_regs {
    unsigned long psw;
    unsigned long orig_gpr2;
};

struct thread_struct {
    unsigned long acrs[16];
    unsigned long fp_regs;
    unsigned long per_info;
};

struct task_struct {
    struct thread_struct thread;
    struct pt_regs *pt_regs;
};

#define PSW_MASK_PER 0x40000000UL
#define FPC_VALID_MASK 0xFFFFFFFFUL
#define BITS_PER_LONG (__CHAR_BIT__ * sizeof(long))
#define CONFIG_64BIT 1

static inline struct pt_regs *task_pt_regs(struct task_struct *task) {
    return task->pt_regs;
}