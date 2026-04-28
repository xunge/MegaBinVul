#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct Authctxt {
    int valid;
    char *user;
    int server_caused_failure;
    void *methoddata;
    int postponed;
} Authctxt;

typedef struct Gssctxt {
    // Opaque GSS context structure
} Gssctxt;

typedef struct ssh {
    Authctxt *authctxt;
} ssh;

#define SSH_GSS_OIDTYPE 0x06
#define SSH2_MSG_USERAUTH_GSSAPI_RESPONSE 60
#define SSH2_MSG_USERAUTH_GSSAPI_TOKEN 61
#define SSH2_MSG_USERAUTH_GSSAPI_ERRTOK 62

#define GSS_ERROR(status) ((status) & 0x80000000)
#define PRIVSEP(x) (x)

typedef uint32_t u_int;
typedef unsigned char u_char;
typedef uint32_t OM_uint32;

typedef struct gss_OID_desc {
    OM_uint32 length;
    void *elements;
} gss_OID_desc;

int sshpkt_get_u32(struct ssh *ssh, u_int *valp);
int sshpkt_get_string(struct ssh *ssh, u_char **valp, size_t *lenp);
int sshpkt_start(struct ssh *ssh, u_char type);
int sshpkt_put_string(struct ssh *ssh, const void *v, size_t len);
int sshpkt_send(struct ssh *ssh);
void ssh_dispatch_set(struct ssh *ssh, int type, int (*handler)(int, u_int32_t, struct ssh *));
char *ssh_err(int);

void ssh_gssapi_test_oid_supported(OM_uint32 *, gss_OID_desc *, int *);
int ssh_gssapi_server_ctx(Gssctxt **, gss_OID_desc *);
void ssh_gssapi_delete_ctx(Gssctxt **);

void fatal(const char *, ...);
void debug(const char *, ...);
void debug2(const char *, ...);
void logit(const char *, ...);

int input_gssapi_token(int, u_int32_t, struct ssh *);
int input_gssapi_errtok(int, u_int32_t, struct ssh *);