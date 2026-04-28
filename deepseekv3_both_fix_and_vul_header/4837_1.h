#include <stddef.h>
#include <stdint.h>

typedef unsigned long addr_t;
typedef uint32_t __u32;
typedef uint64_t __u64;

#define EINVAL 22

#define PSW32_MASK_USER 0x0000FFFF
#define PSW32_MASK_RI 0x00010000
#define PSW32_USER_BITS 0x000A0000
#define PSW32_MASK_ASC 0x00030000
#define PSW32_ASC_HOME 0x00010000
#define PSW_MASK_USER 0xFFFFFFFF00000000
#define PSW_MASK_BA 0x0000000100000000
#define PSW32_ADDR_INSN 0x7FFFFFFF
#define PSW32_ADDR_AMODE 0x80000000

struct thread_struct {
    __u32 acrs[16];
    __u32 fp_regs[16];
};

struct psw_struct {
    __u64 mask;
    __u64 addr;
};

struct pt_regs {
    struct psw_struct psw;
    __u32 orig_gpr2;
};

struct task_struct {
    struct thread_struct thread;
    struct pt_regs *pt_regs;
};

struct compat_user {
    struct {
        struct {
            __u32 mask;
            __u32 addr;
        } psw;
        __u32 acrs[16];
        __u32 orig_gpr2;
        struct {
            __u32 fpc;
            __u32 fp_regs[16];
        } fp_regs;
        __u32 per_info;
    } regs;
};

static inline struct pt_regs *task_pt_regs(struct task_struct *task)
{
    return task->pt_regs;
}

static inline int is_ri_task(struct task_struct *task)
{
    return 0;
}

static inline int test_fp_ctl(__u32 val)
{
    return 0;
}

static inline void __poke_user_per_compat(struct task_struct *child, addr_t addr, addr_t data)
{
}