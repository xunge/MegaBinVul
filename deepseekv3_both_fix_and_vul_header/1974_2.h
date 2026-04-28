#include <stddef.h>
#include <limits.h>

#define PAGE_SHIFT 12
#define VM_DONTEXPAND 0x00020000
#define VM_PFNMAP 0x00000400
#define VM_LOCKED 0x00002000
#define VM_ACCOUNT 0x00004000
#define CAP_IPC_LOCK 0
#define RLIMIT_MEMLOCK 8
#define EFAULT 14
#define EINVAL 22
#define ENOMEM 12
#define EAGAIN 11

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    unsigned long vm_flags;
    unsigned long vm_pgoff;
};

struct mm_struct {
    struct vm_area_struct *mmap;
    unsigned long locked_vm;
    struct mm_struct *mm;
};

struct task_struct {
    struct mm_struct *mm;
};

extern struct task_struct *current;
extern struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr);
extern int is_vm_hugetlb_page(struct vm_area_struct *vma);
extern int may_expand_vm(struct mm_struct *mm, unsigned long npages);
extern int security_vm_enough_memory(unsigned long pages);
extern unsigned long rlimit(int resource);
extern int capable(int cap);

static inline void *ERR_PTR(long error) {
    return (void *)error;
}