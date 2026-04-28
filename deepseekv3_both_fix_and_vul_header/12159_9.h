#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <limits.h>

#define GFP_ATOMIC 0x00000020

struct fdtable {
    struct file **fd;
};

struct path {
    struct dentry *dentry;
};

struct file {
    struct path f_path;
};

struct dentry {
    // minimal definition
};

struct task_struct {
    struct task_struct *real_parent;
    struct files_struct *files;
};

struct files_struct {
    // minimal definition
};

struct kuid {
    uid_t val;
};

extern struct task_struct *current;
extern struct kuid task_uid(struct task_struct *task);
extern void *kmalloc(size_t size, int flags);
extern void kfree(const void *objp);
extern struct fdtable *files_fdtable(struct files_struct *files);
extern bool d_is_reg(struct dentry *dentry);
extern char *d_path(const struct path *path, char *buf, int buflen);
extern int startswith(const char *str, const char *prefix);
extern int endswith(const char *str, const char *suffix);
extern void pr_info(const char *fmt, ...);
extern void pr_err(const char *fmt, ...);
extern struct kuid current_uid(void);
extern bool is_manager_apk(char *path);
extern void ksu_set_manager_uid(uid_t uid);