#include <sys/types.h>
#include <stddef.h>

#define SSH2_MSG_KEXINIT 20
#define SSH_ERR_INVALID_ARGUMENT -1
#define SSH_ERR_INTERNAL_ERROR -2
#define KEX_COOKIE_LEN 16
#define PROPOSAL_MAX 6
#define KEX_MAX 10
#define KEX_INIT_SENT 0x01

struct ssh {
    struct kex *kex;
};

struct kex {
    struct sshbuf *peer;
    int flags;
    int kex_type;
    int (*kex[KEX_MAX])(struct ssh *);
};

struct sshbuf;

int debug(const char *fmt, ...);
void ssh_dispatch_set(struct ssh *ssh, int type, void *handler);
const u_char *sshpkt_ptr(struct ssh *ssh, size_t *dlen);
int sshbuf_put(struct sshbuf *buf, const void *v, size_t len);
int sshpkt_get_u8(struct ssh *ssh, u_char *valp);
int sshpkt_get_string(struct ssh *ssh, u_char **valp, size_t *lenp);
int sshpkt_get_u32(struct ssh *ssh, u_int32_t *valp);
int sshpkt_get_end(struct ssh *ssh);
int kex_send_kexinit(struct ssh *ssh);
int kex_choose_conf(struct ssh *ssh);