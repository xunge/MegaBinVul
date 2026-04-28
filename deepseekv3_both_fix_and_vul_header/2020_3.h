#include <stddef.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <errno.h>

#define __init
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)

struct vfsmount;
struct file_system_type;
struct pid_namespace {
    struct vfsmount *proc_mnt;
};

extern struct file_system_type proc_fs_type;
extern struct pid_namespace init_pid_ns;
extern void proc_init_inodecache(void);
extern void proc_net_init(void);
extern void proc_tty_init(void);
extern void proc_device_tree_init(void);
extern void proc_sys_init(void);
extern int register_filesystem(struct file_system_type *);
extern int unregister_filesystem(struct file_system_type *);
extern struct vfsmount *kern_mount_data(struct file_system_type *, void *);
extern int proc_mkdir(const char *, struct pid_namespace *);
extern int proc_symlink(const char *, struct pid_namespace *, const char *);