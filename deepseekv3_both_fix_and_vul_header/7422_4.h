#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Authctxt {
    int is_trivial_auth;
    const char *host;
    int attempt_passwd;
    const char *server_user;
    const char *service;
    struct {
        const char *name;
    } *method;
};

struct ssh {
    struct Authctxt *authctxt;
};

struct options {
    const char *host_key_alias;
    int number_of_password_prompts;
};
extern struct options options;

#define SSH2_MSG_USERAUTH_REQUEST 50
#define SSH2_MSG_USERAUTH_PASSWD_CHANGEREQ 60

char *read_passphrase(const char *, int);
int xasprintf(char **, const char *, ...);
int sshpkt_start(struct ssh *, int);
int sshpkt_put_cstring(struct ssh *, const char *);
int sshpkt_put_u8(struct ssh *, int);
int sshpkt_add_padding(struct ssh *, int);
int sshpkt_send(struct ssh *);
void fatal_fr(int, const char *);
void freezero(void *, size_t);
void error(const char *);
void ssh_dispatch_set(struct ssh *, int, int (*)(int, int, struct ssh *));
int input_userauth_passwd_changereq(int, int, struct ssh *);

typedef struct Authctxt Authctxt;