#include <stddef.h>

struct vr_state {
    unsigned long vr[32];
    unsigned long vscr;
    unsigned long pad[3];
};

struct thread_struct {
    unsigned long used_vr;
    unsigned long load_vec;
    struct vr_state vr_state;
};

struct task_struct {
    struct thread_struct thread;
};

#define CPU_FTR_ALTIVEC (1UL << 0)

static inline int cpu_has_feature(unsigned long feature)
{
    return 1;
}

static inline int tm_active_with_altivec(struct task_struct *tsk)
{
    return 0;
}

static inline void load_vr_state(struct vr_state *state)
{
}