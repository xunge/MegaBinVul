#include <stdint.h>
#include <stddef.h>

#define EINVAL 22

typedef uint64_t addr_t;
typedef uint32_t __u32;
typedef uint64_t __u64;

struct psw_t {
    __u64 mask;
    __u64 addr;
};

struct per_struct32 {
    __u32 control_regs[3];
    __u32 starting_addr;
    __u32 ending_addr;
    struct {
        struct {
            __u32 address;
        } words;
    } lowcore;
};

struct per_struct {
    __u64 control_regs[3];
    __u64 starting_addr;
    __u64 ending_addr;
    struct {
        __u64 address;
    } lowcore;
};

struct thread_struct {
    __u32 acrs[16];
    struct {
        __u32 fpc;
        __u32 fp_regs[0];
    } fp_regs;
    struct per_struct per_info;
};

struct pt_regs {
    struct psw_t psw;
    __u64 orig_gpr2;
};

struct user32 {
    struct {
        struct psw_t psw;
        __u32 acrs[16];
        __u32 orig_gpr2;
        struct {
            __u32 fpc;
            __u32 fp_regs[0];
        } fp_regs;
        struct per_struct32 per_info;
    } regs;
};

struct task_struct {
    struct thread_struct thread;
};

#define PSW32_MASK_MERGE(a, b) ((a) & (b))
#define PSW_MASK_MERGE(a, b) ((a) & (b))
#define PSW32_ADDR_INSN 0x7FFFFFFFUL
#define FPC_VALID_MASK 0xFFFFFFFF

static __u32 psw32_user_bits;
static __u64 psw_user32_bits;

static inline struct pt_regs *task_pt_regs(struct task_struct *task) {
    return (struct pt_regs *)0;
}

static void FixPerRegisters(struct task_struct *child) {}

typedef struct per_struct32 per_struct32;