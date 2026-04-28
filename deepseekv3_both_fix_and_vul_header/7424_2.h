#include <sys/queue.h>
#include <stdlib.h>

typedef struct Identity Identity;
typedef struct Authctxt Authctxt;
typedef struct ssh ssh;

struct Identity {
    int tried;
    void *key;
    char *filename;
    int isprivate;
    TAILQ_ENTRY(Identity) next;
};

TAILQ_HEAD(identity_head, Identity);

struct Authctxt {
    struct identity_head keys;
    int is_trivial_auth;
    void *authctxt;
};

struct ssh {
    Authctxt *authctxt;
};

int try_identity(struct ssh *ssh, Identity *id);
char *format_identity(Identity *id);
int send_pubkey_test(struct ssh *ssh, Identity *id);
void *load_identity_file(Identity *id);
int sign_and_send_pubkey(struct ssh *ssh, Identity *id);
void sshkey_free(void *key);
void debug(const char *fmt, ...);