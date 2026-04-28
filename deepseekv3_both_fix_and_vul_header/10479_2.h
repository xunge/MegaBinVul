#include <stddef.h>

struct cred {
    unsigned int uid;
    unsigned int gid;
    void *thread_keyring;
};

struct key;

#define KEY_POS_ALL 0
#define KEY_USR_VIEW 0
#define KEY_ALLOC_QUOTA_OVERRUN 0

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

struct key *keyring_alloc(const char *description, unsigned int uid, unsigned int gid,
                         const struct cred *cred, unsigned long perm,
                         unsigned long flags, void *restrict_link,
                         void *destructor);