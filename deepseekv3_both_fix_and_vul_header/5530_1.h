#include <stdatomic.h>

struct file {
    _Atomic long f_count;
};

struct task_struct {
    unsigned int flags;
};

extern struct task_struct *current;
extern void file_sb_list_del(struct file *file);
extern void __fput(struct file *file);

#define PF_KTHREAD 0x00200000
#define BUG_ON(condition) ((void)0)