#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>

struct fuse_file_info {
    int flags;
    unsigned long fh;
};

struct fuse_context {
    pid_t pid;
};

struct cgfs_files;
struct file_info {
    char *controller;
    char *cgroup;
    char *file;
    int type;
    char *buf;
    size_t buflen;
};

#define EIO 5
#define EINVAL 22
#define ENOENT 2
#define EACCES 13
#define ENOMEM 12
#define LXC_TYPE_CGFILE 0

extern struct fuse_context *fuse_get_context(void);
extern char *must_copy_string(const char *str);
extern char *pick_controller_from_path(struct fuse_context *fc, const char *path);
extern const char *find_cgroup_in_path(const char *path);
extern void get_cgdir_and_path(const char *cgroup, char **cgdir, char **fpath);
extern struct cgfs_files *cgfs_get_key(const char *controller, const char *path1, const char *path2);
extern void free_key(struct cgfs_files *k);
extern int caller_may_see_dir(pid_t pid, const char *controller, const char *path1);
extern int fc_may_access(struct fuse_context *fc, const char *controller, const char *path1, const char *path2, int flags);