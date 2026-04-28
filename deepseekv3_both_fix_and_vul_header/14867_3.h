#include <stdint.h>

#define VM_MASK 0x00020000
#define LDT_SEGMENT 0x4

typedef uint32_t u32;

struct semaphore {
    int count;
};

struct task_struct {
    struct {
        struct {
            struct semaphore sem;
            u32 *ldt;
            unsigned long size;
        } context;
    } *mm;
};

struct pt_regs {
    unsigned long eip;
    unsigned long xcs;
    unsigned long eflags;
};

static inline void down(struct semaphore *sem) { sem->count--; }
static inline void up(struct semaphore *sem) { sem->count++; }
#define unlikely(x) (x)