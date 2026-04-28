#include <stddef.h>

#define PF_RANDOMIZE 0x00400000

struct mm_struct {
    unsigned long mmap_legacy_base;
    unsigned long mmap_base;
    void (*get_unmapped_area)(void);
};

struct task_struct {
    unsigned long flags;
};

extern struct task_struct *current;
extern unsigned long TASK_UNMAPPED_BASE;
extern unsigned long arch_mmap_rnd(void);
extern int mmap_is_legacy(void);
extern unsigned long mmap_legacy_base(unsigned long);
extern unsigned long mmap_base(unsigned long);
extern void arch_get_unmapped_area(void);
extern void arch_get_unmapped_area_topdown(void);