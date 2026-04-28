#include <stddef.h>
#include <time.h>
#include <errno.h>

#define KEY_FLAG_INVALIDATED 0
#define KEY_FLAG_REVOKED 1
#define KEY_FLAG_NEGATIVE 2
#define KEY_NEED_SEARCH 0
#define KEYRING_SEARCH_DO_STATE_CHECK 0
#define KEYRING_SEARCH_SKIP_EXPIRED 0
#define KEYRING_SEARCH_NO_CHECK_PERM 0

struct key;
struct cred;

struct key_type {
    const char *type;
};

struct keyring_search_context {
    struct key_type index_key;
    unsigned int flags;
    int skipped_ret;
    struct timespec now;
    struct {
        int (*cmp)(const struct key *, const void *);
    } match_data;
    void *result;
    unsigned long possessed;
    const struct cred *cred;
};

struct key {
    unsigned long flags;
    short state;
    int serial;
    struct key_type *type;
    time_t expiry;
    int reject_error;
};

static inline void *ERR_PTR(long error) {
    return (void *)error;
}

static inline void kenter(const char *fmt, ...) {}
static inline void kleave(const char *fmt, ...) {}
static inline struct key *keyring_ptr_to_key(const void *object) { return NULL; }
static inline void *make_key_ref(const struct key *key, unsigned long possessed) { return NULL; }
static inline int key_task_permission(void *ref, const struct cred *cred, int perm) { return 0; }
static inline void smp_rmb(void) {}
#define READ_ONCE(x) (x)