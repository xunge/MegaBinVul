#include <stddef.h>

struct spinlock {
    int dummy;
};
#define spin_lock(lock) (void)0
#define spin_lock_nested(lock, subclass) (void)0
#define spin_unlock(lock) (void)0
#define SINGLE_DEPTH_NESTING 0

struct cred;
struct pid;

struct sock {
    struct spinlock sk_peer_lock;
    struct pid *sk_peer_pid;
    const struct cred *sk_peer_cred;
};

static struct pid *get_pid(struct pid *pid) { return pid; }
static void put_pid(struct pid *pid) {}
static const struct cred *get_cred(const struct cred *cred) { return cred; }
static void put_cred(const struct cred *cred) {}