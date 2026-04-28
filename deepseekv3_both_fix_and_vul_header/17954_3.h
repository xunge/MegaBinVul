#include <stddef.h>
#include <errno.h>

struct task_struct;

struct user_regset {
    int (*get)(struct task_struct *, const struct user_regset *,
               unsigned int, unsigned int, void *, void *);
};

struct user_regset_view {
    const struct user_regset *regsets;
};

#define VERIFY_WRITE 1
#define __user

static inline int access_ok(int type, const void *addr, unsigned long size) {
    return 1;
}