#include <stdatomic.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/syscall.h>

struct task_struct {
    struct completion *vfork_done;
    int *clear_child_tid;
    int flags;
};

struct mm_struct {
    _Atomic int mm_users;
};

struct completion;

#define PF_SIGNALED 0
#define FUTEX_WAKE 1
#define __user

typedef uint32_t u32;

static inline int atomic_read(const _Atomic int *v) {
    return atomic_load(v);
}

void deactivate_mm(struct task_struct *tsk, struct mm_struct *mm);
void complete(struct completion *done);
long sys_futex(void *uaddr, int op, int val, const void *timeout, void *uaddr2, int val3);
int put_user(int x, void *ptr);