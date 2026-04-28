#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

struct cred;
struct pid;

struct sock {
    pthread_spinlock_t sk_peer_lock;
    struct pid *sk_peer_pid;
    const struct cred *sk_peer_cred;
};

struct task_struct {
    pid_t tgid;
};

extern struct task_struct *current;

struct pid *get_pid(pid_t pid);
void put_pid(struct pid *pid);
const struct cred *get_current_cred();
void put_cred(const struct cred *cred);