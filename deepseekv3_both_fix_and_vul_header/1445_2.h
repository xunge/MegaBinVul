#include <errno.h>
#include <pthread.h>

struct sock;
struct sk_buff;
struct net;

struct sadb_msg {
    unsigned short sadb_msg_satype;
};

struct pfkey_sock {
    unsigned int registered;
};

#define SADB_SATYPE_MAX 255
#define SADB_SATYPE_UNSPEC 0
#define GFP_KERNEL 0
#define __GFP_ZERO 0
#define BROADCAST_REGISTERED 0

extern pthread_mutex_t pfkey_mutex;
extern struct pfkey_sock *pfkey_sk(struct sock *sk);
extern void xfrm_probe_algs(void);
extern struct sk_buff *compose_sadb_supported(const struct sadb_msg *hdr, int flags);
extern void pfkey_broadcast(struct sk_buff *skb, int flags, int type, struct sock *sk, struct net *net);
extern struct net *sock_net(struct sock *sk);