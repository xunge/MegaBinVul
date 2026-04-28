#include <stddef.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/types.h>

#define ENOMEM 12
#define ENOKEY 126

#define PTR_ERR(x) ((long)(x))
#define IS_ERR(x) ((unsigned long)(x) >= (unsigned long)-4095)

struct cred {
    struct key *session_keyring;
    uid_t uid;
    gid_t gid;
};

struct key {
    long serial;
};

struct mutex {
    int dummy;
};

extern struct mutex key_session_mutex;
extern const struct cred *current_cred(void);
extern struct cred *prepare_creds(void);
extern long commit_creds(struct cred *);
extern void abort_creds(struct cred *);
extern int install_session_keyring_to_cred(struct cred *, struct key *);
extern struct key *find_keyring_by_name(const char *, bool);
extern struct key *keyring_alloc(const char *, uid_t, gid_t, const struct cred *,
                                unsigned long, unsigned long, struct key *);
extern void key_put(struct key *);
extern void mutex_lock(struct mutex *);
extern void mutex_unlock(struct mutex *);

#define KEY_POS_ALL 0x1f000000
#define KEY_USR_VIEW 0x00010000
#define KEY_USR_READ 0x00020000
#define KEY_USR_LINK 0x00040000
#define KEY_ALLOC_IN_QUOTA 0x0001