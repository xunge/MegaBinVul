#include <stddef.h>
#include <sys/types.h>

#define VERIFY_READ 0
#define EOPNOTSUPP 95
#define EIO 5

struct task_struct;
struct user_regset {
    int (*set)(struct task_struct *, const struct user_regset *,
               unsigned int, unsigned int, void *, const void *);
};
struct user_regset_view {
    const struct user_regset *regsets;
};

static inline int access_ok(int type, const void *addr, unsigned long size) {
    return 1;
}

#define __user