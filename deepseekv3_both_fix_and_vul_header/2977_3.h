#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

typedef uid_t kuid_t;
typedef gid_t kgid_t;

struct ucred {
    pid_t pid;
    uid_t uid;
    gid_t gid;
};

struct cred {
    uid_t uid;
    uid_t euid;
    uid_t suid;
    gid_t gid;
    gid_t egid;
    gid_t sgid;
    void *user_ns;
};

struct pid_namespace {
    void *user_ns;
};

struct nsproxy {
    struct pid_namespace *pid_ns;
};

struct task_struct {
    struct nsproxy *nsproxy;
    struct cred *cred;
};

extern struct task_struct *current;
extern const struct cred *current_cred(void);
extern int ns_capable(void *ns, int cap);
extern int nsown_capable(int cap);
extern int task_tgid_vnr(struct task_struct *task);
extern int uid_valid(uid_t uid);
extern int gid_valid(gid_t gid);
extern int uid_eq(uid_t uid1, uid_t uid2);
extern int gid_eq(gid_t gid1, gid_t gid2);
extern uid_t make_kuid(void *ns, uid_t uid);
extern gid_t make_kgid(void *ns, gid_t gid);

#define CAP_SYS_ADMIN 0
#define CAP_SETUID 0
#define CAP_SETGID 0
#define EINVAL 22
#define EPERM 1