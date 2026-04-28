#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

#define EIO 5
#define EINVAL 22
#define EACCES 13

struct fuse_context {
    pid_t pid;
};

extern struct fuse_context *fuse_get_context(void);
extern char *pick_controller_from_path(struct fuse_context *fc, const char *path);
extern const char *find_cgroup_in_path(const char *path);
extern void get_cgdir_and_path(const char *cgroup, char **cgdir, char **fpath);
extern int fc_may_access(struct fuse_context *fc, const char *controller, const char *cgroup, const char *file, int mode);
extern int caller_is_in_ancestor(pid_t pid, const char *controller, const char *cgroup, const char *file);
extern int cgfs_remove(const char *controller, const char *cgroup);