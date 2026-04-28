#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define GFP_KERNEL 0
#define EAGAIN 11
#define EINVAL 22
#define ENOMEM 12
#define ENOKEY 126
#define KEY_USR_VIEW 0x00000001

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)(-1000))
#define ERR_PTR(error) ((void *)(long)(error))

struct cred;

struct key_payload {
    char *data;
};

struct key {
    unsigned int perm;
    struct {
        int x[1];
    } type_data;
    struct key_payload payload;
    void *sem;
};

struct key_type {
    // minimal definition needed
    int dummy;
};

struct key_type key_type_dns_resolver;
const struct cred *dns_resolver_cache;

#define cFYI(level, fmt, ...)
#define cERROR(level, fmt, ...)

static inline int is_ip(const char *name) {
    return 0;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void down_read(void *sem) {}
static inline void up_read(void *sem) {}

static inline struct key *request_key(struct key_type *type, const char *description, const char *callout_info) {
    return ERR_PTR(-ENOKEY);
}

static inline void key_put(struct key *key) {}

static inline const struct cred *override_creds(const struct cred *new) {
    return NULL;
}

static inline void revert_creds(const struct cred *old) {}