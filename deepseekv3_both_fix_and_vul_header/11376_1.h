#include <sys/types.h>
#include <pwd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ssh;
struct sshbuf;
struct sshauthopt;
struct passwd;

typedef struct Authctxt {
    int valid;
    struct passwd *pw;
    char *user;
    char *style;
    char *service;
    int postponed;
} Authctxt;

typedef struct ssh {
    Authctxt *authctxt;
    int compat;
} ssh;

typedef struct {
    char *pubkey_key_types;
} Options;

extern Options options;
extern u_char *session_id2;
extern size_t session_id2_len;

#define SSH_BUG_RSASIGMD5 0x0001
#define SSH_BUG_SIGTYPE 0x0002
#define SSH_OLD_SESSIONID 0x0004

#define SSH2_MSG_USERAUTH_REQUEST 50
#define SSH2_MSG_USERAUTH_PK_OK 60

#define KEY_UNSPEC 0
#define KEY_RSA 1

#define PRIVSEP(x) (x)

struct sshkey {
    int type;
    struct sshkey_cert *cert;
};

struct sshkey_cert {
    struct sshkey *signature_key;
};

int debug2(const char *fmt, ...);
int debug3(const char *fmt, ...);
int debug(const char *fmt, ...);
int verbose(const char *fmt, ...);
int logit(const char *fmt, ...);
int error(const char *fmt, ...);
void fatal(const char *fmt, ...);

int sshpkt_get_u8(struct ssh *, u_char *);
int sshpkt_get_cstring(struct ssh *, char **, size_t *);
int sshpkt_get_string(struct ssh *, u_char **, size_t *);
int sshpkt_get_end(struct ssh *);
int sshpkt_start(struct ssh *, u_char);
int sshpkt_put_cstring(struct ssh *, const char *);
int sshpkt_put_string(struct ssh *, const void *, size_t);
int sshpkt_send(struct ssh *);
int ssh_packet_write_wait(struct ssh *);

struct sshbuf *sshbuf_new(void);
int sshbuf_put(struct sshbuf *, const void *, size_t);
int sshbuf_put_string(struct sshbuf *, const void *, size_t);
int sshbuf_put_u8(struct sshbuf *, u_char);
int sshbuf_put_cstring(struct sshbuf *, const char *);
void sshbuf_free(struct sshbuf *);
void *sshbuf_ptr(const struct sshbuf *);
size_t sshbuf_len(const struct sshbuf *);
#ifdef DEBUG_PK
void sshbuf_dump(struct sshbuf *, FILE *);
#endif

int sshkey_type_from_name(const char *);
int sshkey_from_blob(const u_char *, size_t, struct sshkey **);
int sshkey_type_plain(int);
int sshkey_is_cert(const struct sshkey *);
const char *sshkey_type(const struct sshkey *);
const char *sshkey_ssh_name(const struct sshkey *);
int sshkey_verify(const struct sshkey *, const u_char *, size_t,
    const u_char *, size_t, const char *, int);
void sshkey_free(struct sshkey *);

char *format_key(const struct sshkey *);
char *ssh_err(int);

int auth2_key_already_used(Authctxt *, struct sshkey *);
void auth2_record_key(Authctxt *, int, struct sshkey *);
int auth_activate_options(struct ssh *, struct sshauthopt *);
int user_key_allowed(struct ssh *, struct passwd *, struct sshkey *, int, struct sshauthopt **);
void sshauthopt_free(struct sshauthopt *);

int match_pattern_list(const char *, const char *, int);

char *xasprintf(char **, const char *fmt, ...);