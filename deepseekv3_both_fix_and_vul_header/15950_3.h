#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define S_IFDIR 0040000
#define S_IRUGO (S_IRUSR|S_IRGRP|S_IROTH)
#define S_IXUGO (S_IXUSR|S_IXGRP|S_IXOTH)
#define PIDTYPE_PID 0
#define ENOENT 2

struct vfsmount;
struct dentry {
    struct inode *d_inode;
    struct super_block *d_sb;
};
struct kstat {
    uid_t uid;
    gid_t gid;
};
struct inode {
    unsigned int i_mode;
};
struct task_struct;
struct cred {
    uid_t euid;
    gid_t egid;
};
struct pid_namespace;
struct super_block {
    struct pid_namespace *s_fs_info;
};

int generic_fillattr(struct inode *inode, struct kstat *stat);
void rcu_read_lock(void);
void rcu_read_unlock(void);
struct task_struct *pid_task(void *pid, int type);
void *proc_pid(struct inode *inode);
int has_pid_permissions(struct pid_namespace *pid, struct task_struct *task, int level);
int task_dumpable(struct task_struct *task);
struct cred *__task_cred(struct task_struct *task);