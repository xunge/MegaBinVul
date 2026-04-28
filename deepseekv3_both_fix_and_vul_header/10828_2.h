#include <stdlib.h>
#include <stdbool.h>

struct SMB2_sess_data {
    struct cifs_ses *ses;
};

struct auth_key {
    void *response;
};

struct cifs_server {
    bool sign;
    bool session_estab;
    unsigned int sequence_number;
    struct {
        int dummy;
    } srv_mutex;
    struct {
        int (*generate_signingkey)(struct cifs_ses *);
    } *ops;
};

struct cifs_ses {
    struct cifs_server *server;
    struct auth_key auth_key;
    int status;
    bool need_reconnect;
};

struct spinlock {
    int dummy;
} GlobalMid_Lock;

#define CifsGood 0
#define FYI 0

void cifs_dbg(int level, const char *format, ...);
void kfree(void *ptr);
void mutex_lock(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void spin_lock(struct spinlock *lock);
void spin_unlock(struct spinlock *lock);

struct mutex {
    int dummy;
};