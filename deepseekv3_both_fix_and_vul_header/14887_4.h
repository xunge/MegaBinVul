#include <stdint.h>
#include <stddef.h>

typedef uint64_t addr_t;
typedef uint32_t u32;
typedef uint32_t __u32;

struct user32 {
    struct {
        struct {
            uint64_t mask;
            uint64_t addr;
        } psw;
        uint32_t acrs[16];
        uint32_t orig_gpr2;
        uint32_t fp_regs[16];
        uint32_t per_info;
    } regs;
};

struct per_struct32 {
    uint32_t control_regs[3];
    uint32_t starting_addr;
    uint32_t ending_addr;
    struct {
        struct {
            uint32_t address;
        } words;
    } lowcore;
};

struct pt_regs {
    struct {
        uint64_t mask;
        uint64_t addr;
    } psw;
    uint64_t orig_gpr2;
};

struct task_struct {
    struct {
        uint32_t acrs[16];
        uint32_t fp_regs[16];
        uint32_t per_info;
    } thread;
};

extern uint32_t psw32_user_bits;
extern struct pt_regs *task_pt_regs(struct task_struct *);

#define PSW32_MASK_MERGE(a, b) ((a) | (b))
#define PSW32_ADDR_AMODE31 (1u << 31)

// 修改为使用struct关键字声明变量
#define per_struct32 struct per_struct32