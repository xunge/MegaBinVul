#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

typedef uint32_t OM_uint32;
typedef unsigned char u_char;

struct sshbuf;
struct ssh_kex {
    uint8_t *session_id;
};

struct Gssctxt {
    /* GSSAPI context implementation */
};

struct Authctxt {
    struct Gssctxt *methoddata;
    char *server_user;
    char *service;
    int is_trivial_auth;
};

struct ssh {
    struct Authctxt *authctxt;
    struct ssh_kex *kex;
};

typedef struct gss_buffer_desc_struct {
    size_t length;
    void *value;
} gss_buffer_desc, *gss_buffer_t;

#define GSS_C_EMPTY_BUFFER {0, NULL}
#define GSS_S_COMPLETE 0
#define GSS_C_INTEG_FLAG (1<<1)
#define GSS_ERROR(status) ((status) != 0)

#define SSH2_MSG_USERAUTH_GSSAPI_ERRTOK 0
#define SSH2_MSG_USERAUTH_GSSAPI_TOKEN 0
#define SSH2_MSG_USERAUTH_GSSAPI_EXCHANGE_COMPLETE 0
#define SSH2_MSG_USERAUTH_GSSAPI_MIC 0

extern struct {
    int gss_deleg_creds;
} options;

void gss_release_buffer(OM_uint32 *, gss_buffer_t);
OM_uint32 ssh_gssapi_init_ctx(struct Gssctxt *, int, gss_buffer_t, gss_buffer_t, OM_uint32 *);
void ssh_gssapi_buildmic(struct sshbuf *, const char *, const char *, const char *, const uint8_t *);
OM_uint32 ssh_gssapi_sign(struct Gssctxt *, gss_buffer_t, gss_buffer_t);
int sshpkt_start(struct ssh *, u_char);
int sshpkt_put_string(struct ssh *, const void *, size_t);
int sshpkt_send(struct ssh *);
struct sshbuf *sshbuf_new(void);
void *sshbuf_mutable_ptr(struct sshbuf *);
size_t sshbuf_len(struct sshbuf *);
void sshbuf_free(struct sshbuf *);
void fatal_f(const char *, ...);
void fatal_fr(int, const char *, ...);

typedef struct Authctxt Authctxt;
typedef struct Gssctxt Gssctxt;