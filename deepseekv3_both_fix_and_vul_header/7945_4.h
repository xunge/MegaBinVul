#include <errno.h>
#include <stddef.h>

struct file_system_type;
struct dentry;
struct user_namespace;

struct pid_namespace {
    struct user_namespace *user_ns;
};

struct super_block {
    unsigned long s_flags;
    unsigned long s_iflags;
    struct dentry *s_root;
    int s_stack_depth;
};

#define MS_KERNMOUNT 0x400000
#define MS_ACTIVE 0x40000000
#define SB_I_NOEXEC 0x00000010
#define FILESYSTEM_MAX_STACK_DEPTH 2
#define CAP_SYS_ADMIN 21
#define EPERM 1
#define EINVAL 22

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define ERR_PTR(err) ((void *)((long)(err)))
#define ERR_CAST(ptr) ((void *)(ptr))

extern int proc_test_super(struct super_block *sb, void *data);
extern int proc_set_super(struct super_block *sb, void *data);
extern int proc_parse_options(char *options, struct pid_namespace *ns);
extern int proc_fill_super(struct super_block *sb);
extern struct dentry *dget(struct dentry *dentry);
extern struct super_block *sget(struct file_system_type *type,
    int (*test)(struct super_block *, void *),
    int (*set)(struct super_block *, void *),
    int flags, void *data);
extern void deactivate_locked_super(struct super_block *sb);
extern int ns_capable(struct user_namespace *ns, int cap);

struct task_struct;
extern struct task_struct *current;
extern struct pid_namespace *task_active_pid_ns(struct task_struct *task);