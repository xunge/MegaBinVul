#include <stdbool.h>
#include <stddef.h>

enum key_reqkey_defl {
    KEY_REQKEY_DEFL_DEFAULT,
    KEY_REQKEY_DEFL_THREAD_KEYRING,
    KEY_REQKEY_DEFL_PROCESS_KEYRING,
    KEY_REQKEY_DEFL_SESSION_KEYRING,
    KEY_REQKEY_DEFL_USER_KEYRING,
    KEY_REQKEY_DEFL_USER_SESSION_KEYRING,
    KEY_REQKEY_DEFL_GROUP_KEYRING,
    KEY_REQKEY_DEFL_REQUESTOR_KEYRING
};

struct rw_semaphore {
    int dummy;
};

struct key {
    struct rw_semaphore sem;
    union {
        void *data[1];
    } payload;
    unsigned long flags;
};

struct cred {
    int jit_keyring;
    struct key *request_key_auth;
    struct key *thread_keyring;
    struct key *process_keyring;
    struct key *session_keyring;
    struct {
        struct key *session_keyring;
        struct key *uid_keyring;
    } *user;
};

struct request_key_auth {
    struct key *dest_keyring;
};

#define KEY_NEED_WRITE 0x20
#define KEY_FLAG_REVOKED 0x20

#define kenter(fmt, ...)
#define kleave(fmt, ...)
#define BUG()

static inline const struct cred *current_cred(void) { return NULL; }
static inline void down_read(struct rw_semaphore *sem) {}
static inline void up_read(struct rw_semaphore *sem) {}
static inline struct key *key_get(struct key *key) { return key; }
static inline void key_put(struct key *key) {}
static inline int key_permission(void *key_ref, unsigned perm) { return 0; }
static inline void *make_key_ref(struct key *key, bool possession) { return key; }
static inline int key_serial(struct key *key) { return 0; }
static inline bool test_bit(int nr, const volatile unsigned long *addr) { return false; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct key *rcu_dereference(void *p) { return (struct key *)p; }