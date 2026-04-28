#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint32_t uid_t;
typedef uint32_t key_perm_t;
typedef int32_t gid_t;

#define KEY_POS_ALL 0x1f
#define KEY_POS_SETATTR 0x10
#define KEY_USR_ALL 0x3f
#define KEY_ALLOC_UID_KEYRING 0x01
#define KEY_ALLOC_IN_QUOTA 0x02
#define INVALID_GID (-1)

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)-4096)
#define PTR_ERR(x) ((long)(x))
#define ERR_PTR(x) ((void *)(long)(x))

struct key;
struct user_namespace;

struct cred {
    struct user_struct *user;
    struct user_namespace *user_ns;
};

struct user_struct {
    uid_t uid;
    struct key *uid_keyring;
    struct key *session_keyring;
};

struct mutex {
    int dummy;
};

extern struct mutex key_user_keyring_mutex;
extern const struct cred *current_cred(void);
extern void kenter(const char *fmt, ...);
extern void kleave(const char *fmt, ...);
extern struct key *find_keyring_by_name(const char *name, bool update);
extern struct key *keyring_alloc(const char *desc, uid_t uid, gid_t gid,
                                const struct cred *cred, key_perm_t perm,
                                unsigned long flags,
                                struct key *dest, struct key *instkey);
extern int key_link(struct key *keyring, struct key *key);
extern void key_put(struct key *key);
extern uid_t from_kuid(struct user_namespace *ns, uid_t uid);
extern void mutex_lock(struct mutex *lock);
extern void mutex_unlock(struct mutex *lock);