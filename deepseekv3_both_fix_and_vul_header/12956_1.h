#include <stddef.h>
#include <errno.h>

struct files_struct {
    void *file_lock;
    struct fdtable *fdt;
};

struct fdtable {
    unsigned int max_fds;
    struct file **fd;
};

struct file;

extern struct task_struct {
    struct files_struct *files;
} *current;

void spin_lock(void *lock);
void spin_unlock(void *lock);
struct fdtable *files_fdtable(struct files_struct *files);
void rcu_assign_pointer(void *ptr, void *val);
void __put_unused_fd(struct files_struct *files, unsigned int fd);
void get_file(struct file *file);
int filp_close(struct file *file, struct files_struct *files);