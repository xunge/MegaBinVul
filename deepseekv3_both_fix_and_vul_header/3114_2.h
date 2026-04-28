#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

typedef int kuid_t;
typedef int kgid_t;

struct user_namespace {
    // dummy structure
};

struct pid_namespace {
    struct user_namespace *user_ns;
};

struct cred {
    uid_t uid;
    uid_t euid;
    uid_t suid;
    gid_t gid;
    gid_t egid;
    gid_t sgid;
    struct user_namespace *user_ns;
};

struct nsproxy {
    struct pid_namespace *pid_ns;
};

struct task_struct {
    pid_t pid;
    struct nsproxy *nsproxy;
    struct cred *cred;
};

struct ucred {
    uid_t uid;
    gid_t gid;
    pid_t pid;
};

#define CAP_SYS_ADMIN 0
#define CAP_SETUID 0
#define CAP_SETGID 0
#define EINVAL 22
#define EPERM 1

static struct task_struct *current;
static inline struct cred *current_cred(void) { return current->cred; }
static inline int uid_valid(kuid_t uid) { return 1; }
static inline int gid_valid(kgid_t gid) { return 1; }
static inline kuid_t make_kuid(struct user_namespace *ns, uid_t uid) { return uid; }
static inline kgid_t make_kgid(struct user_namespace *ns, gid_t gid) { return gid; }
static inline int uid_eq(kuid_t a, kuid_t b) { return a == b; }
static inline int gid_eq(kgid_t a, kgid_t b) { return a == b; }
static inline int ns_capable(struct user_namespace *ns, int cap) { return 1; }
static inline int nsown_capable(int cap) { return 1; }
static inline pid_t task_tgid_vnr(struct task_struct *task) { return task->pid; }
static inline struct pid_namespace *task_active_pid_ns(struct task_struct *task) { return task->nsproxy->pid_ns; }