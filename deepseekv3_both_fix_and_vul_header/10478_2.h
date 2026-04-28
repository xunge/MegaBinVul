#include <errno.h>
#include <stddef.h>

struct cred {
    void *process_keyring;
    unsigned int uid;
    unsigned int gid;
};

struct key;

struct key *keyring_alloc(const char *description, unsigned int uid, unsigned int gid,
                         const struct cred *cred, unsigned long perm,
                         unsigned long flags,
                         void *dest, void *authkey);

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))
#define KEY_POS_ALL 0x1f1f0000
#define KEY_USR_VIEW 0x00010000
#define KEY_ALLOC_QUOTA_OVERRUN 0x0001