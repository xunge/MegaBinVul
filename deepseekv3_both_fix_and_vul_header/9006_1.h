#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

struct cgfs_files {
    uid_t uid;
    gid_t gid;
    mode_t mode;
};

struct fuse_context {
    pid_t pid;
};

extern struct fuse_context *fuse_get_context(void);
extern const char *pick_controller_from_path(struct fuse_context *fc, const char *path);
extern const char *find_cgroup_in_path(const char *path);
extern void get_cgdir_and_path(const char *cgroup, char **cgdir, char **fpath);
extern int is_child_cgroup(const char *controller, const char *path1, const char *path2);
extern int caller_is_in_ancestor(pid_t pid, const char *controller, const char *cgroup, void *unused);
extern int fc_may_access(struct fuse_context *fc, const char *controller, const char *cgroup, const char *file, int mode);
extern struct cgfs_files *cgfs_get_key(const char *controller, const char *path1, const char *path2);
extern void free_key(struct cgfs_files *k);