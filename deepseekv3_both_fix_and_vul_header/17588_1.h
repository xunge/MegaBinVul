#include <stdint.h>

struct mm_struct {
    struct {
        uint64_t asce;
    } context;
};

struct thread_struct {
    int mm_segment;
};

struct task_struct {
    struct mm_struct *active_mm;
    struct thread_struct thread;
};

extern struct task_struct *current;

struct lowcore {
    uint64_t user_asce;
};

extern struct lowcore S390_lowcore;

#define USER_DS 0
#define USER_DS_SACF 1
#define CIF_ASCE_PRIMARY 0
#define CIF_ASCE_SECONDARY 1

static inline void __ctl_load(uint64_t asce, int a, int b) {}
static inline void clear_cpu_flag(int flag) {}
static inline int test_cpu_flag(int flag) { return 0; }
static inline void WARN_ON(int condition) {}
static inline void __tlb_flush_local(void) {}