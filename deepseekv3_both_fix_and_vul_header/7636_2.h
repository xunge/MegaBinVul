#include <stdint.h>
#include <stddef.h>

#define SADB_SATYPE_MAX 255
#define SADB_SATYPE_UNSPEC 0
#define GFP_KERNEL 0
#define __GFP_ZERO 0
#define BROADCAST_REGISTERED 0
#define EINVAL 22
#define EEXIST 17
#define ENOBUFS 105

struct sadb_msg {
    uint8_t sadb_msg_satype;
};

struct pfkey_sock {
    unsigned int registered;
};

struct sock;
struct sk_buff;

static inline struct pfkey_sock *pfkey_sk(struct sock *sk) { return NULL; }
static void xfrm_probe_algs(void) {}
static struct sk_buff *compose_sadb_supported(const struct sadb_msg *hdr, int flags) { return NULL; }
static void pfkey_broadcast(struct sk_buff *skb, int flags, int type, struct sock *sk, void *net) {}
static int sock_net(struct sock *sk) { return 0; }