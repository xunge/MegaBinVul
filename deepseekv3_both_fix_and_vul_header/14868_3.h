#include <stdint.h>
#include <stddef.h>

#define VM_MASK 0x00020000
#define LDT_SEGMENT 0x4

typedef uint32_t u32;

struct task_struct {
    struct {
        struct {
            u32 *ldt;
            size_t size;
            struct {
                int sem;
            } sem;
        } context;
    } *mm;
};

struct pt_regs {
    unsigned long eip;
    unsigned long xcs;
    unsigned long eflags;
};

typedef int semaphore;
#define down(x) (void)(x)
#define up(x) (void)(x)
#define unlikely(x) (x)