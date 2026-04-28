#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

struct fuse_file_info {
    unsigned long fh;
};

struct fuse_context {
    pid_t pid;
};

struct file_info {
    char *controller;
    char *cgroup;
    int type;
    void *buf;
    void *file;
    size_t buflen;
};

#define LXC_TYPE_CGDIR 0
#define EIO 5
#define ENOENT 2
#define EACCES 13
#define ENOMEM 12
#define O_RDONLY 00

extern struct fuse_context *fuse_get_context(void);
extern char *pick_controller_from_path(struct fuse_context *fc, const char *path);
extern char *find_cgroup_in_path(const char *path);
extern int caller_may_see_dir(pid_t pid, const char *controller, const char *cgroup);
extern int fc_may_access(struct fuse_context *fc, const char *controller, const char *cgroup, void *null, int flags);
extern char *must_copy_string(const char *str);