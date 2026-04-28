#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct ssh {
    struct Authctxt *authctxt;
    u_int compat;
};

struct sshbuf;
struct sshkey {
    int type;
};

struct Authctxt {
    int valid;
    char *user;
    char *service;
    void *pw;
};

typedef struct ssh SSH;
typedef struct sshbuf SSHBuf;
typedef struct sshkey SSHKey;
typedef struct Authctxt Authctxt;

#define KEY_UNSPEC 0
#define KEY_RSA 1
#define SSH_BUG_RSASIGMD5 0x0001
#define SSH2_MSG_USERAUTH_REQUEST 50

extern u_char *session_id2;
extern size_t session_id2_len;
extern struct {
    char *hostbased_key_types;
} options;

int debug2(const char *fmt, ...);
int debug(const char *fmt, ...);
int logit(const char *fmt, ...);
int error(const char *fmt, ...);
void fatal(const char *fmt, ...);
char *ssh_err(int err);
SSHBuf *sshbuf_new(void);
void sshbuf_free(SSHBuf *buf);
int sshbuf_put_string(SSHBuf *buf, const void *v, size_t len);
int sshbuf_put_u8(SSHBuf *buf, uint8_t val);
int sshbuf_put_cstring(SSHBuf *buf, const char *v);
u_char *sshbuf_ptr(const SSHBuf *buf);
size_t sshbuf_len(const SSHBuf *buf);
void sshbuf_dump(const SSHBuf *buf, FILE *f);
void sshbuf_dump_data(const void *buf, size_t len, FILE *f);
int sshpkt_get_cstring(SSH *ssh, char **valp, size_t *lenp);
int sshpkt_get_string(SSH *ssh, u_char **valp, size_t *lenp);
int sshkey_type_from_name(const char *name);
int sshkey_from_blob(const void *blob, size_t blen, SSHKey **keyp);
void sshkey_free(SSHKey *key);
const char *sshkey_type(const SSHKey *key);
int sshkey_verify(const SSHKey *key, const u_char *sig, size_t siglen,
    const u_char *data, size_t datalen, const char *alg, u_int compat);
int match_pattern_list(const char *str, const char *pattern, int noneg);
int hostbased_key_allowed(void *pw, const char *cuser, const char *chost, SSHKey *key);
void auth2_record_info(Authctxt *authctxt, const char *fmt, ...);
void auth2_record_key(Authctxt *authctxt, int authenticated, SSHKey *key);
int PRIVSEP(int);
int sshkey_type_plain(int type);