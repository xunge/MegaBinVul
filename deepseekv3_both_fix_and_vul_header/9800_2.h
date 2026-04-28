#include <unistd.h>
#include <sys/resource.h>
#include <stddef.h>

#define VM_STACK_FLAGS 0
#define VM_EXEC 0x00000004
#define VM_STACK_INCOMPLETE_SETUP 0x00000080
#define EXSTACK_DEFAULT_X 0
#define EXSTACK_DISABLE_X 1
#define EXSTACK_ENABLE_X 2
#define CONFIG_STACK_GROWSUP 0
#define PAGE_SIZE 4096
#define PAGE_MASK (~(PAGE_SIZE-1))
#define ENOMEM 12
#define EFAULT 14

struct linux_binprm {
    unsigned long p;
    unsigned long exec;
    unsigned long loader;
    struct vm_area_struct *vma;
};

struct mm_struct {
    unsigned long arg_start;
    unsigned long def_flags;
    unsigned long start_stack;
    void *mmap_sem;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    struct vm_area_struct *vm_next;
};

#define PAGE_ALIGN(addr) (((addr) + PAGE_SIZE - 1) & PAGE_MASK)
#define BUG_ON(cond) (void)(cond)
#define unlikely(x) (x)

static inline unsigned long rlimit_max(int resource) { 
    struct rlimit rlim;
    getrlimit(resource, &rlim);
    return rlim.rlim_max;
}

static inline unsigned long rlimit(int resource) {
    struct rlimit rlim;
    getrlimit(resource, &rlim);
    return rlim.rlim_cur;
}

static inline unsigned long arch_align_stack(unsigned long addr) { return addr; }
static inline void down_write(void *sem) {}
static inline void up_write(void *sem) {}

static inline int mprotect_fixup(struct vm_area_struct *vma, 
                                struct vm_area_struct **prev,
                                unsigned long start,
                                unsigned long end,
                                unsigned long flags) { return 0; }

static inline int shift_arg_pages(struct vm_area_struct *vma, 
                                unsigned long shift) { return 0; }

static inline int expand_stack(struct vm_area_struct *vma, 
                             unsigned long addr) { return 0; }

extern struct task_struct {
    struct mm_struct *mm;
} *current;