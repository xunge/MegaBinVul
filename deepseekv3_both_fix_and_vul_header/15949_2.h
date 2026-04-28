#include <stdbool.h>
#include <errno.h>

struct inode {
    struct super_block *i_sb;
};

struct super_block {
    struct pid_namespace *s_fs_info;
};

struct pid_namespace {
    int hide_pid;
};

struct task_struct;

extern struct task_struct *get_proc_task(struct inode *);
extern bool has_pid_permissions(struct pid_namespace *, struct task_struct *, int);
extern void put_task_struct(struct task_struct *);
extern int generic_permission(struct inode *, int);