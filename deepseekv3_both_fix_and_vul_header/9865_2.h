#include <stddef.h>
#include <limits.h>

#define CONFIG_STACK_GROWSUP
#define PAGE_SIZE 4096
#define ARG_MAX 131072
#define RLIMIT_STACK 3
#define ACCESS_ONCE(x) (*(volatile typeof(x) *)&(x))

struct page;
struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
};
struct mm_struct;
struct signal_struct {
    struct rlimit *rlim;
};
struct rlimit {
    unsigned long rlim_cur;
};
struct task_struct {
    struct signal_struct *signal;
};
struct linux_binprm {
    struct vm_area_struct *vma;
    struct mm_struct *mm;
};

extern struct task_struct *current;
extern int expand_stack_downwards(struct vm_area_struct *vma, unsigned long address);
extern int get_user_pages(struct task_struct *tsk, struct mm_struct *mm, unsigned long start, int nr_pages, int write, int force, struct page **pages, struct vm_area_struct **vmas);
extern void put_page(struct page *page);
extern void acct_arg_size(struct linux_binprm *bprm, unsigned long pages);