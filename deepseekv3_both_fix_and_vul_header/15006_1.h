#include <stddef.h>
#include <errno.h>

struct task_struct {
    int ptrace;
    int exit_code;
    int exit_state;
};

extern int valid_signal(unsigned int);
extern void ptrace_disable(struct task_struct *);
extern void __ptrace_detach(struct task_struct *, unsigned int);
extern void __ptrace_unlink(struct task_struct *);
extern void wake_up_process(struct task_struct *);

typedef struct {
    // Simplified rwlock definition
} rwlock_t;
extern rwlock_t tasklist_lock;

#define write_lock_irq(lock) 
#define write_unlock_irq(lock) 
#define EXIT_ZOMBIE 0
#define EIO 5