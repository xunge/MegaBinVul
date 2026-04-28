#include <string.h>
#include <stdint.h>

#define CONFIG_PPC_FPU_REGS
#define PT_FPR0 0
#define PT_FPSCR 1
#define EIO 5
#define CONFIG_PPC32

#define IS_ENABLED(x) 1

typedef uint32_t u32;

struct fp_state {
    u32 fpr[32];
    unsigned long fpscr;
};

struct thread_struct {
    struct fp_state fp_state;
    #define TS_FPR(i) fp_state.fpr[i]
};

struct task_struct {
    struct thread_struct thread;
};

static inline void flush_fp_to_thread(struct task_struct *task) {}