#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>

#define TGID_OFFSET 0
#define FIRST_PROCESS_ENTRY 0
#define PID_MAX_LIMIT (1 << 22)

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
    struct super_block *d_sb;
};

struct file {
    long f_pos;
    struct path f_path;
    struct dentry *f_dentry;
};

struct inode;
struct super_block {
    void *s_fs_info;
};

struct task_struct;
struct pid_namespace;

struct tgid_iter {
    struct task_struct *task;
    unsigned int tgid;
};

typedef int (*filldir_t)(void *, const char *, int, off_t, unsigned long, unsigned);

struct pid_entry {
    int dummy;  // minimal definition to allow sizeof
};

extern const struct pid_entry proc_base_stuff[1];  // array declaration
extern size_t proc_base_stuff_size;  // size variable

#define ARRAY_SIZE(arr) proc_base_stuff_size

extern struct task_struct *get_proc_task(struct inode *);
extern int proc_base_fill_cache(struct file *, void *, filldir_t, struct task_struct *, const struct pid_entry *);
extern struct tgid_iter next_tgid(struct pid_namespace *, struct tgid_iter);
extern int has_pid_permissions(struct pid_namespace *, struct task_struct *, int);
extern int proc_pid_fill_cache(struct file *, void *, filldir_t, struct tgid_iter);
extern int fake_filldir(void *, const char *, int, off_t, unsigned long, unsigned);
extern void put_task_struct(struct task_struct *);