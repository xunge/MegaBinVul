#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <pthread.h>

typedef int32_t key_perm_t;
typedef uint32_t uid_t;

#define KEY_POS_ALL    0x1f000000
#define KEY_POS_SETATTR 0x01000000
#define KEY_USR_ALL    0x003f
#define KEY_ALLOC_IN_QUOTA 0x0001
#define INVALID_GID (-1)
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

struct key {
    int dummy;
};

struct cred {
    struct user_struct *user;
    void *user_ns;
};

struct user_struct {
    uid_t uid;
    struct key *uid_keyring;
    struct key *session_keyring;
};

extern pthread_mutex_t key_user_keyring_mutex;
#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock

struct key *find_keyring_by_name(const char *name, bool create);
struct key *keyring_alloc(const char *name, uid_t uid, int gid,
                         const struct cred *cred, key_perm_t perm,
                         unsigned long flags, void *data);
int key_link(struct key *keyring, struct key *key);
void key_put(struct key *key);
const struct cred *current_cred(void);
uid_t from_kuid(void *user_ns, uid_t uid);
void kenter(const char *fmt, ...);
void kleave(const char *fmt, ...);