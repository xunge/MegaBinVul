#include <stddef.h>
#include <stdint.h>

#define asmlinkage 

typedef long compat_long_t;

struct task_struct;
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define PTRACE_TRACEME 0
#define PTRACE_ATTACH 1
#define PTRACE_SEIZE 2
#define PTRACE_KILL 3
#define PTRACE_INTERRUPT 4
#define PTRACE_DETACH 5

long ptrace_traceme(void);
struct task_struct *ptrace_get_task_struct(compat_long_t pid);
long ptrace_attach(struct task_struct *child, compat_long_t request, compat_long_t addr, compat_long_t data);
void arch_ptrace_attach(struct task_struct *child);
long ptrace_check_attach(struct task_struct *child, int condition);
long compat_arch_ptrace(struct task_struct *child, compat_long_t request, compat_long_t addr, compat_long_t data);
void ptrace_unfreeze_traced(struct task_struct *child);
void put_task_struct(struct task_struct *child);