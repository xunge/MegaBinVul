#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

struct fuse_context {
    pid_t pid;
    uid_t uid;
    gid_t gid;
};

extern struct fuse_context *fuse_get_context(void);
extern char *pick_controller_from_path(struct fuse_context *fc, const char *path);
extern const char *find_cgroup_in_path(const char *path);
extern void get_cgdir_and_path(const char *cgroup, char **cgdir, char **fpath);
extern int fc_may_access(struct fuse_context *fc, const char *controller, const char *path1, void *null, int flags);
extern int caller_is_in_ancestor(pid_t pid, const char *controller, const char *path1, void *null);
extern int cgfs_create(const char *controller, const char *cgroup, uid_t uid, gid_t gid);