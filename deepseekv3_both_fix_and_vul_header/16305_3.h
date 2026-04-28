#include <stdbool.h>

struct mm_struct;
struct cred;

struct spinlock {
    int dummy;
};

struct fs_struct {
    struct spinlock lock;
    bool in_exec;
    int users;
};

struct task_struct {
    struct mm_struct *mm;
    struct fs_struct *fs;
};

struct io_op_def {
    bool needs_mm;
    bool needs_fs;
};

struct io_wq_work {
    struct mm_struct *mm;
    const struct cred *creds;
    struct fs_struct *fs;
    unsigned int flags;
};

struct io_kiocb {
    struct io_wq_work work;
};

#define IO_WQ_WORK_CANCEL 0x1

extern struct task_struct *current;

static inline void mmgrab(struct mm_struct *mm) {}
static inline const struct cred *get_current_cred() { return 0; }
static inline void spin_lock(struct spinlock *lock) {}
static inline void spin_unlock(struct spinlock *lock) {}