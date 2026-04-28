#include <stdlib.h>
#include <errno.h>

struct cred {
    void *thread_keyring;
};

extern struct cred *prepare_creds(void);
extern int install_thread_keyring_to_cred(struct cred *);
extern void abort_creds(struct cred *);
extern int commit_creds(struct cred *);

#define BUG_ON(condition) do { if (condition) abort(); } while (0)
#define ENOMEM 12