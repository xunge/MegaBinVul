#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

typedef unsigned int kuid_t;
typedef unsigned int kgid_t;

struct mm_struct;
struct user_namespace;

struct cred {
    kuid_t uid;
    kuid_t euid;
    kuid_t suid;
    kgid_t gid;
    kgid_t egid;
    kgid_t sgid;
    struct user_namespace *user_ns;
};

struct task_struct {
    struct mm_struct *mm;
    // Other task_struct members would go here
};

#define SUID_DUMP_USER 0
#define current ((struct task_struct *)0)
#define smp_rmb() do {} while (0)
#define EPERM 1

const struct cred *current_cred(void);
bool same_thread_group(struct task_struct *p1, struct task_struct *p2);
const struct cred *__task_cred(struct task_struct *task);
bool uid_eq(kuid_t left, kuid_t right);
bool gid_eq(kgid_t left, kgid_t right);
bool ptrace_has_cap(struct user_namespace *ns, unsigned int mode);
int get_dumpable(struct mm_struct *mm);
int security_ptrace_access_check(struct task_struct *child, unsigned int mode);

static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}