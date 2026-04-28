#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct key *key_ref_t;
typedef int key_perm_t;
typedef int key_serial_t;

struct key_user {
    struct key *uid_keyring;
    struct key *session_keyring;
};

struct key {
    unsigned long flags;
    struct {
        void *data[1];
    } payload;
    void *description;
    void *type;
    long last_used_at;
    struct key *thread_keyring;
    struct key *process_keyring;
    struct key *session_keyring;
    struct key *request_key_auth;
    struct key_user *user;
    struct {
        void *sem;
    };
};

struct keyring_index_key {
    void *type;
    void *description;
    size_t desc_len;
};

struct key_match_data {
    int (*cmp)(void);
    int lookup_type;
    void *raw_data;
};

struct keyring_search_context {
    struct keyring_index_key index_key;
    struct key_match_data match_data;
    struct key *cred;
    unsigned flags;
};

struct request_key_auth {
    struct key *dest_keyring;
};

struct timespec {
    long tv_sec;
};

#define KEY_SPEC_THREAD_KEYRING (-1)
#define KEY_SPEC_PROCESS_KEYRING (-2)
#define KEY_SPEC_SESSION_KEYRING (-3)
#define KEY_SPEC_USER_KEYRING (-4)
#define KEY_SPEC_USER_SESSION_KEYRING (-5)
#define KEY_SPEC_GROUP_KEYRING (-6)
#define KEY_SPEC_REQKEY_AUTH_KEY (-7)
#define KEY_SPEC_REQUESTOR_KEYRING (-8)

#define KEY_LOOKUP_CREATE 0x01
#define KEY_LOOKUP_PARTIAL 0x02
#define KEY_LOOKUP_FOR_UNLINK 0x04

#define KEYRING_SEARCH_LOOKUP_DIRECT 0x01
#define KEYRING_SEARCH_NO_STATE_CHECK 0x02

#define ENOKEY 126
#define EINVAL 22
#define EKEYREVOKED 128
#define ERESTARTSYS 512
#define EIO 5

#define KEY_FLAG_REVOKED 0x01
#define KEY_FLAG_INSTANTIATED 0x02
#define KEY_IS_UNINSTANTIATED 0

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-1000)
#define ERR_PTR(x) ((void *)(intptr_t)(x))
#define ERR_CAST(x) ((void *)(x))
#define PTR_ERR(x) ((intptr_t)(x))

static inline int lookup_user_key_possessed(void) { return 0; }
static inline void __key_get(struct key *key) {}
static inline void key_put(struct key *key) {}
static inline key_ref_t make_key_ref(struct key *key, int flag) { return key; }
static inline void key_ref_put(key_ref_t key_ref) {}
static inline int key_validate(struct key *key) { return 0; }
static inline int key_task_permission(key_ref_t key_ref, struct key *cred, key_perm_t perm) { return 0; }
static inline int key_read_state(struct key *key) { return 0; }
static inline int wait_for_key_construction(struct key *key, bool wait) { return 0; }
static inline struct key *get_current_cred(void) { return NULL; }
static inline void put_cred(struct key *cred) {}
static inline int install_thread_keyring(void) { return 0; }
static inline int install_process_keyring(void) { return 0; }
static inline int install_user_keyrings(void) { return 0; }
static inline int join_session_keyring(void *arg) { return 0; }
static inline int install_session_keyring(struct key *keyring) { return 0; }
static inline struct key *key_lookup(key_serial_t id) { return NULL; }
static inline key_ref_t search_process_keyrings(void *ctx) { return NULL; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct key *rcu_dereference(struct key *key) { return key; }
static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}
static inline int test_bit(int nr, unsigned long *addr) { return 0; }
static inline void kdebug(const char *fmt, ...) {}
static inline struct timespec current_kernel_time(void) { return (struct timespec){0}; }