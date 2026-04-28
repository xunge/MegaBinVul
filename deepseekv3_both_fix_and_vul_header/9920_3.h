#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>

#define FIRST_PROCESS_ENTRY 0
#define TGID_OFFSET 0
#define PID_MAX_LIMIT 0
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef int (*filldir_t)(void *, const char *, int, off_t, ino_t, unsigned);

struct path {
    struct dentry *dentry;
};

struct dentry {
    struct inode *d_inode;
    struct super_block *d_sb;
};

struct inode;
struct super_block {
    void *s_fs_info;
};

struct file {
    off_t f_pos;
    struct path f_path;
    struct dentry *f_dentry;
};

struct task_struct;
struct pid_namespace;

struct tgid_iter {
    struct task_struct *task;
    unsigned int tgid;
};

struct pid_entry {
    int dummy;  // 添加至少一个成员使结构体完整
};

extern const struct pid_entry proc_base_stuff[1];  // 声明为数组形式
extern struct task_struct *get_proc_task(struct inode *);
extern int proc_base_fill_cache(struct file *, void *, filldir_t, struct task_struct *, const struct pid_entry *);
extern struct tgid_iter next_tgid(struct pid_namespace *, struct tgid_iter);
extern int proc_pid_fill_cache(struct file *, void *, filldir_t, struct tgid_iter);
extern void put_task_struct(struct task_struct *);