#include <stddef.h>
#include <sys/types.h>

typedef unsigned int uid_t;
typedef unsigned int gid_t;
typedef int pid_t;

struct user_struct {
    void *user_ns;
};

struct cred {
    uid_t uid;
    uid_t euid;
    uid_t suid;
    uid_t fsuid;
    gid_t gid;
    gid_t egid;
    gid_t sgid;
    gid_t fsgid;
    struct user_struct *user;
    void *user_ns;
    void *group_info;
    unsigned securebits;
    unsigned cap_inheritable;
    unsigned cap_permitted;
    unsigned cap_effective;
    unsigned cap_bset;
    unsigned jit_keyring;
    void *thread_keyring;
    struct {
        pid_t tgid;
        void *process_keyring;
    } *tgcred;
};

struct task_struct {
    struct cred *replacement_session_keyring;
};

extern struct task_struct *current;
extern void write_lock_irq(void *);
extern void write_unlock_irq(void *);
extern struct cred *current_cred(void);
extern struct user_struct *get_uid(struct user_struct *);
extern void *get_group_info(void *);
extern void *key_get(void *);
extern void security_transfer_creds(struct cred *, const struct cred *);
extern void commit_creds(struct cred *);

typedef struct { int lock; } rwlock_t;
static rwlock_t tasklist_lock;