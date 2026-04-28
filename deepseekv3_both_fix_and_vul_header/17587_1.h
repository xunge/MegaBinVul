#include <stddef.h>

typedef unsigned long mm_segment_t;

#define USER_DS ((mm_segment_t)0)
#define likely(x) __builtin_expect(!!(x), 1)

struct task_struct {
    struct {
        mm_segment_t mm_segment;
    } thread;
};

struct lowcore {
    unsigned long kernel_asce;
    unsigned long user_asce;
};

extern struct task_struct *current;
extern struct lowcore S390_lowcore;

enum {
    CIF_ASCE_PRIMARY,
    CIF_ASCE_SECONDARY
};

static inline void __ctl_store(unsigned long val, int cr1, int cr2) {}
static inline void __ctl_load(unsigned long val, int cr1, int cr2) {}
static inline void set_cpu_flag(unsigned int flag) {}