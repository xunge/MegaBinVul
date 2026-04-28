#include <sys/types.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SSH2_MSG_USERAUTH_INFO_RESPONSE 60
#define RP_ECHO 0x01

struct Authctxt {
    int info_req_seen;
    int is_trivial_auth;
    char *server_user;
    char *host;
};

struct ssh {
    struct Authctxt *authctxt;
};

struct options {
    char *host_key_alias;
} options;

typedef struct Authctxt Authctxt;
typedef struct ssh ssh;

int debug2_f(const char *fmt, ...);
void fatal_f(const char *fmt, ...);
void logit(const char *fmt, ...);
int sshpkt_get_cstring(ssh *ssh, char **valp, size_t *lenp);
int sshpkt_get_u32(ssh *ssh, u_int32_t *valp);
int sshpkt_get_u8(ssh *ssh, u_char *valp);
int sshpkt_start(ssh *ssh, u_char type);
int sshpkt_put_u32(ssh *ssh, u_int32_t val);
int sshpkt_put_cstring(ssh *ssh, const char *val);
int sshpkt_get_end(ssh *ssh);
int sshpkt_add_padding(ssh *ssh, u_char pad);
int sshpkt_send(ssh *ssh);
char *read_passphrase(const char *prompt, int flags);
int asmprintf(char **ret, size_t max, size_t *len, const char *fmt, ...);
void freezero(void *ptr, size_t sz);