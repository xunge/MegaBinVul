#include <unistd.h>
#include <errno.h>

#define KEY_REQKEY_DEFL_NO_CHANGE 0
#define KEY_REQKEY_DEFL_THREAD_KEYRING 1
#define KEY_REQKEY_DEFL_PROCESS_KEYRING 2
#define KEY_REQKEY_DEFL_DEFAULT 3
#define KEY_REQKEY_DEFL_SESSION_KEYRING 4
#define KEY_REQKEY_DEFL_USER_KEYRING 5
#define KEY_REQKEY_DEFL_USER_SESSION_KEYRING 6
#define KEY_REQKEY_DEFL_REQUESTOR_KEYRING 7
#define KEY_REQKEY_DEFL_GROUP_KEYRING 8

#define ENOMEM 12
#define EEXIST 17
#define EINVAL 22

struct cred {
    int jit_keyring;
};

extern struct cred *prepare_creds(void);
extern int install_thread_keyring_to_cred(struct cred *new);
extern int install_process_keyring_to_cred(struct cred *new);
extern void commit_creds(struct cred *new);
extern void abort_creds(struct cred *new);
extern int current_cred_xxx(int);

static int jit_keyring;