#include <stddef.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

struct kernfs_open_file {
    void *kn;
    struct file *file;
};

struct file {
    struct cred *f_cred;
};

struct cred {
    struct user_namespace *user_ns;
};

struct user_namespace {
    int dummy;
};

struct cgroup_root {
    char release_agent_path[PATH_MAX];
};

struct cgroup {
    struct cgroup_root *root;
};

extern struct user_namespace init_user_ns;

typedef int spinlock_t;
typedef long ssize_t;
typedef off_t loff_t;

#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - 2*!!(condition)]))
#define CAP_SYS_ADMIN 0
#define EPERM 1
#define ENODEV 2
#define PATH_MAX 4096

static spinlock_t release_agent_path_lock;

static inline char *strstrip(char *s) { return s; }
static inline char *strlcpy(char *dest, const char *src, size_t size) {
    strncpy(dest, src, size);
    dest[size-1] = '\0';
    return dest;
}
static inline void spin_lock(spinlock_t *lock) {}
static inline void spin_unlock(spinlock_t *lock) {}
static inline struct cgroup *cgroup_kn_lock_live(void *kn, bool b) { return NULL; }
static inline void cgroup_kn_unlock(void *kn) {}
static inline int capable(int cap) { return 0; }