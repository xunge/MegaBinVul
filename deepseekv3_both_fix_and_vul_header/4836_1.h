#include <stddef.h>
#include <errno.h>

typedef unsigned long addr_t;

#define PSW_MASK_USER 0
#define PSW_MASK_RI 0
#define PSW_USER_BITS 0
#define PSW_MASK_ASC 0
#define PSW_ASC_HOME 0
#define PSW_MASK_EA 0
#define PSW_MASK_BA 0
#define CONFIG_64BIT 0
#define BITS_PER_LONG 32
#define EINVAL 22

struct psw {
    unsigned long mask;
};

struct fp_regs {
    unsigned int fpc;
};

struct thread_struct {
    unsigned long acrs[16];
    struct fp_regs fp_regs;
};

struct pt_regs {
    unsigned long orig_gpr2;
    struct psw psw;
};

struct per_info {
};

struct user_regs_struct {
    struct psw psw;
    unsigned long acrs[16];
    unsigned long orig_gpr2;
    struct fp_regs fp_regs;
    struct per_info per_info;
};

struct user {
    struct user_regs_struct regs;
};

struct task_struct {
    struct thread_struct thread;
    struct pt_regs *pt_regs;
};

static inline int is_ri_task(struct task_struct *task) { return 0; }
static inline struct pt_regs *task_pt_regs(struct task_struct *task) { return task->pt_regs; }
static inline int test_fp_ctl(unsigned long val) { return 0; }
static inline void __poke_user_per(struct task_struct *child, addr_t addr, addr_t data) {}