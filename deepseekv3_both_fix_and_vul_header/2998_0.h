#include <sys/types.h>
#include <unistd.h>

#define INVALID_UID ((uid_t)-1)
#define INVALID_GID ((gid_t)-1)

struct cred {
    uid_t uid;
    gid_t gid;
    uid_t euid;
    gid_t egid;
};

struct scm_creds {
    pid_t pid;
    uid_t uid;
    gid_t gid;
};

struct scm_cookie {
    struct pid *pid;
    const struct cred *cred;
    struct scm_creds creds;
};

struct pid;

extern struct pid *get_pid(struct pid *pid);
extern void put_pid(struct pid *pid);
extern const struct cred *get_cred(const struct cred *cred);
extern void put_cred(const struct cred *cred);
extern pid_t pid_vnr(struct pid *pid);