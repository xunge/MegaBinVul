#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stddef.h>

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct seq_file;

struct key_type {
    const char *name;
    void (*describe)(struct key *, struct seq_file *);
};

struct key {
    struct key_type *type;
    const char *description;
    unsigned int serial;
    unsigned long flags;
    int perm;
    unsigned long expiry;
    int uid;
    int gid;
    int usage;
    struct rb_node serial_node;
};

struct seq_file {
    void *private;
    struct file *file;
};

struct file {
    struct cred *f_cred;
};

struct cred {
    int uid;
    int gid;
};

#define KEY_POS_VIEW 0x00000001
#define KEY_NEED_VIEW 0x00000001
#define KEYRING_SEARCH_LOOKUP_DIRECT 0x0001
#define KEYRING_SEARCH_NO_STATE_CHECK 0x0002
#define KEY_FLAG_REVOKED 0
#define KEY_FLAG_DEAD 1
#define KEY_FLAG_IN_QUOTA 2
#define KEY_FLAG_USER_CONSTRUCT 3
#define KEY_FLAG_INVALIDATED 4
#define KEY_IS_UNINSTANTIATED 0

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define test_bit(n, addr) (1)

typedef struct key *key_ref_t;

struct keyring_search_context {
    struct {
        struct key_type *type;
        const char *description;
    } index_key;
    struct cred *cred;
    struct {
        int (*cmp)(void);
        void *raw_data;
        int lookup_type;
    } match_data;
    int flags;
};

#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static inline key_ref_t make_key_ref(struct key *key, int flag) { return key; }
static inline void key_ref_put(key_ref_t key_ref) {}
static inline key_ref_t search_my_process_keyrings(struct keyring_search_context *ctx) { return NULL; }
static inline int key_task_permission(key_ref_t key_ref, struct cred *cred, int perm) { return 0; }
static inline struct timespec current_kernel_time(void) { struct timespec ts = {0}; return ts; }
static inline short key_read_state(struct key *key) { return 0; }
static inline int refcount_read(int *count) { return *count; }
static inline int from_kuid_munged(void *ns, int uid) { return uid; }
static inline int from_kgid_munged(void *ns, int gid) { return gid; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline int seq_printf(struct seq_file *m, const char *fmt, ...) { return 0; }
static inline void seq_putc(struct seq_file *m, char c) {}
static inline void *seq_user_ns(struct seq_file *m) { return NULL; }
static inline int lookup_user_key_possessed(void) { return 0; }