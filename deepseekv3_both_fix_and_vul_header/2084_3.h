#include <stdatomic.h>
#include <stddef.h>

#define CONFIG_KEYS 1
#define CLONE_THREAD 0x00010000
#define CLONE_NEWUSER 0x10000000
#define GFP_KERNEL 0
#define ENOMEM 12

typedef _Atomic int atomic_t;

struct key;
struct user_namespace {
    // dummy definition
};

struct user_struct {
    atomic_t processes;
    struct user_namespace *user_ns;
};

struct thread_group_cred {
    atomic_t usage;
    int lock;
    struct key *process_keyring;
    struct key *session_keyring;
};

struct cred {
    atomic_t usage;
    atomic_t subscribers;
    struct user_struct *user;
    struct user_namespace *user_ns;
    struct thread_group_cred *tgcred;
    struct key *thread_keyring;
};

struct task_struct {
    struct cred *cred;
    struct cred *real_cred;
    struct key *replacement_session_keyring;
};

#define atomic_read(v) atomic_load_explicit(v, memory_order_relaxed)
#define atomic_set(v, i) atomic_store_explicit(v, i, memory_order_relaxed)
#define atomic_inc(v) atomic_fetch_add_explicit(v, 1, memory_order_relaxed)
#define spin_lock_init(lock) (void)0

static inline struct cred *get_cred(struct cred *cred) { return cred; }
static inline void put_cred(struct cred *cred) {}
static inline void alter_cred_subscribers(struct cred *cred, int n) {}
static inline int read_cred_subscribers(struct cred *cred) { return 0; }
static inline void kdebug(const char *fmt, ...) {}
static inline struct cred *prepare_creds(void) { return NULL; }
static inline int create_user_ns(struct cred *new) { return 0; }
static inline void key_put(struct key *key) {}
static inline struct key *key_get(struct key *key) { return key; }
static inline void install_thread_keyring_to_cred(struct cred *new) {}
static inline void release_tgcred(struct cred *new) {}
static inline void validate_creds(struct cred *new) {}
static inline void *kmalloc(size_t size, int flags) { return NULL; }