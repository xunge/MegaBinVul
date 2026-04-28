#include <stdlib.h>
#include <string.h>

#define SSH2_MSG_USERAUTH_REQUEST 50
#define SSH2_MSG_USERAUTH_PASSWD_CHANGEREQ 60

typedef struct Authctxt {
    int is_trivial_auth;
    const char *host;
    int attempt_passwd;
    const char *server_user;
    const char *service;
    struct {
        const char *name;
    } *method;
} Authctxt;

struct ssh {
    Authctxt *authctxt;
};

struct options {
    const char *host_key_alias;
    int number_of_password_prompts;
};
extern struct options options;

char *read_passphrase(const char *, int);
void freezero(void *, size_t);
int xasprintf(char **, const char *, ...);
void error(const char *);
void fatal_fr(int, const char *);
int sshpkt_start(struct ssh *, int);
int sshpkt_put_cstring(struct ssh *, const char *);
int sshpkt_put_u8(struct ssh *, unsigned char);
int sshpkt_add_padding(struct ssh *, int);
int sshpkt_send(struct ssh *);
void ssh_dispatch_set(struct ssh *, int, void (*)(struct ssh *, int, void *));
void input_userauth_passwd_changereq(struct ssh *, int, void *);