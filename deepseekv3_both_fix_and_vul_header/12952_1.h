#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define CONFIG_PPC_FPU_REGS 1
#define PT_FPR0 0
#define PT_FPSCR 32
#define EIO 5
#define CONFIG_PPC32 1
#define IS_ENABLED(x) (x)

static inline void flush_fp_to_thread(struct task_struct *child) {}

struct fp_state {
    uint64_t fpr[32];
    uint64_t fpscr;
};

struct thread_struct {
    struct fp_state fp_state;
    #define TS_FPR(i) fp_state.fpr[i]
};

struct task_struct {
    struct thread_struct thread;
};

typedef uint32_t u32;