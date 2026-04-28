#include <stddef.h>

#define CPU_FTR_TM 0
#define MSR_TM_SUSPENDED(x) (0)
#define TM_CAUSE_SIGNAL 0

struct thread_struct {
    // Minimal complete type definition
    long tm_scratch;
    unsigned long tm_tfhar;
    unsigned long tm_texasr;
    unsigned long tm_tfiar;
};

struct task_struct {
    struct thread_struct thread;
};

extern struct task_struct *current;

int cpu_has_feature(unsigned long feature);
unsigned long mfmsr(void);
void tm_reclaim_current(int cause);
void tm_enable(void);
void tm_save_sprs(struct thread_struct *thread);