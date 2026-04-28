#include <stdint.h>
#include <string.h>

struct thread_fp_state {
    double fpregs[32];
    unsigned long fpscr;
};

struct thread_vr_state {
    unsigned long vrregs[32];
    unsigned long vscr;
    unsigned char vrsave;
};

struct pt_regs {
    unsigned long msr;
    unsigned long gpr[32];
    unsigned long nip;
    unsigned long link;
    unsigned long ctr;
    unsigned long xer;
    unsigned long ccr;
    unsigned long trap;
};

struct thread_struct {
    struct thread_fp_state fp_state;
    struct thread_vr_state vr_state;
    struct thread_fp_state transact_fp;
    struct thread_vr_state transact_vr;
    struct pt_regs *regs;
    struct pt_regs ckpt_regs;
};

struct thread_info {
    unsigned long flags;
};

#define TIF_RESTORE_TM 0
#define MSR_FP  (1UL << 0)
#define MSR_VEC (1UL << 1)
#define MSR_VSX (1UL << 2)
#define MSR_FE0 (1UL << 3)
#define MSR_FE1 (1UL << 4)

static inline int test_ti_thread_flag(struct thread_info *ti, int flag) {
    return ti->flags & (1UL << flag);
}

static inline void clear_ti_thread_flag(struct thread_info *ti, int flag) {
    ti->flags &= ~(1UL << flag);
}

void tm_reclaim(struct thread_struct *thr, unsigned long msr, uint8_t cause);