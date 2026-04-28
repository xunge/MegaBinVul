#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

struct inode {
    // dummy definition
};

struct file {
    struct {
        struct dentry *dentry;
    } f_path;
    unsigned int f_mode;
    void *private_data;
};

struct dentry {
    struct inode *d_inode;
};

struct task_struct {
    long self_exec_id;
    // other members
};

struct mm_struct {
    // dummy definition
};

#define ESRCH 3
#define PTRACE_MODE_ATTACH 0
#define FMODE_UNSIGNED_OFFSET (1 << 0)
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define PTR_ERR(x) ((long)(x))

extern struct task_struct *get_proc_task(struct inode *);
extern struct mm_struct *mm_access(struct task_struct *, int);
extern void put_task_struct(struct task_struct *);
extern struct task_struct *current;