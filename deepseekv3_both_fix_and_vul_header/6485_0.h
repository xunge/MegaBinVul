#include <stddef.h>

#ifdef CONFIG_X86_INTEL_MEMORY_PROTECTION_KEYS
#include <asm/processor.h>
#endif

struct task_struct;
struct mm_struct {
    struct {
        int pkey_allocation_map;
        int execute_only_pkey;
    } context;
};

extern int init_new_context_ldt(struct task_struct *tsk, struct mm_struct *mm);