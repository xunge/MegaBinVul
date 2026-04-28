#include <stdbool.h>
#include <string.h>

#define PATH_MAX 4096
#define GFP_ATOMIC 0

struct dentry;
struct vfsmount;
struct files_struct;

struct path {
    struct dentry *dentry;
    struct vfsmount *mnt;
};

struct file {
    struct path f_path;
};

struct fdtable {
    struct file **fd;
};

struct task_struct {
    struct task_struct *real_parent;
    struct files_struct *files;
};

struct kuid {
    unsigned int val;
};

typedef unsigned int uid_t;

extern bool is_manager_apk(char *path);
extern void ksu_set_manager_uid(uid_t uid);
extern struct task_struct *current;
extern int d_is_reg(struct dentry *dentry);
extern char *d_path(const struct path *path, char *buf, int buflen);
extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern struct fdtable *files_fdtable(struct files_struct *files);
extern struct kuid task_uid(struct task_struct *task);
extern struct kuid current_uid(void);
extern int startswith(const char *str, const char *prefix);
extern int endswith(const char *str, const char *suffix);
extern void pr_info(const char *fmt, ...);
extern void pr_err(const char *fmt, ...);