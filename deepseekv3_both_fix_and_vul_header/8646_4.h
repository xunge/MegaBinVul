#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

#define PACKET_HOST 0
#define XFRM_POLICY_IN 0
#define unlikely(x) (x)

struct sk_buff {
    unsigned char *data;
    void *dev;
    int pkt_type;
};

struct tcphdr {
    uint16_t source;
    uint16_t dest;
    uint8_t doff;
    uint16_t th_dest;
};

struct ipv6hdr {
    uint8_t hop_limit;
    struct in6_addr saddr;
    struct in6_addr daddr;
};

struct inet6_sock {
    int min_hopcount;
};

struct sock {
    int sk_state;
    struct inet6_sock *pinet6;
};

struct net {};
struct request_sock {
    struct sock *rsk_listener;
};
struct inet_timewait_sock {};

struct tcp_hashinfo {};

static struct tcp_hashinfo tcp_hashinfo;

static struct net *dev_net(void *dev) { return NULL; }
static bool pskb_may_pull(struct sk_buff *skb, unsigned int len) { return false; }
static int skb_checksum_init(struct sk_buff *skb, int proto, int (*compute)(void)) { return 0; }
static int ip6_compute_pseudo(void) { return 0; }
static struct ipv6hdr *ipv6_hdr(struct sk_buff *skb) { return NULL; }
static int inet6_iif(struct sk_buff *skb) { return 0; }
static void tcp_v6_fill_cb(struct sk_buff *skb, const struct ipv6hdr *hdr, const struct tcphdr *th) {}
static int tcp_v6_inbound_md5_hash(struct sock *sk, struct sk_buff *skb) { return 0; }
static void sk_drops_add(struct sock *sk, struct sk_buff *skb) {}
static void reqsk_put(struct request_sock *req) {}
static void inet_csk_reqsk_queue_drop_and_put(struct sock *sk, struct request_sock *req) {}
static void sock_hold(struct sock *sk) {}
static struct sock *tcp_check_req(struct sock *sk, struct sk_buff *skb, struct request_sock *req, bool sync) { return NULL; }
static void tcp_v6_restore_cb(struct sk_buff *skb) {}
static int tcp_child_process(struct sock *parent, struct sock *child, struct sk_buff *skb) { return 0; }
static void tcp_v6_send_reset(struct sock *sk, struct sk_buff *skb) {}
static void sock_put(struct sock *sk) {}
static int xfrm6_policy_check(struct sock *sk, int dir, struct sk_buff *skb) { return 0; }
static int sk_filter(struct sock *sk, struct sk_buff *skb) { return 0; }
static int tcp_v6_do_rcv(struct sock *sk, struct sk_buff *skb) { return 0; }
static void sk_incoming_cpu_update(struct sock *sk) {}
static void bh_lock_sock_nested(struct sock *sk) {}
static void tcp_segs_in(struct sock *sk, struct sk_buff *skb) {}
static int sock_owned_by_user(struct sock *sk) { return 0; }
static int tcp_prequeue(struct sock *sk, struct sk_buff *skb) { return 0; }
static int tcp_add_backlog(struct sock *sk, struct sk_buff *skb) { return 0; }
static void bh_unlock_sock(struct sock *sk) {}
static void kfree_skb(struct sk_buff *skb) {}
static void inet_twsk_put(struct inet_timewait_sock *tw) {}
static int tcp_checksum_complete(struct sk_buff *skb) { return 0; }
static int tcp_timewait_state_process(struct inet_timewait_sock *tw, struct sk_buff *skb, const struct tcphdr *th) { return 0; }
static struct sock *inet6_lookup_listener(struct net *net, struct tcp_hashinfo *hashinfo, struct sk_buff *skb, int hdrlen, const struct in6_addr *saddr, uint16_t sport, const struct in6_addr *daddr, uint16_t dport, int dif) { return NULL; }
static void inet_twsk_deschedule_put(struct inet_timewait_sock *tw) {}
static void tcp_v6_timewait_ack(struct sock *sk, struct sk_buff *skb) {}
static struct inet_timewait_sock *inet_twsk(struct sock *sk) { return NULL; }

#define __TCP_INC_STATS(net, field)
#define __NET_INC_STATS(net, field)
#define TCP_MIB_INSEGS 0
#define TCP_MIB_CSUMERRORS 0
#define TCP_MIB_INERRS 0
#define LINUX_MIB_TCPMINTTLDROP 0

enum {
    TCP_TIME_WAIT,
    TCP_NEW_SYN_RECV,
    TCP_LISTEN
};

enum {
    TCP_TW_SYN,
    TCP_TW_ACK,
    TCP_TW_RST,
    TCP_TW_SUCCESS
};

static struct sock *__inet6_lookup_skb(struct tcp_hashinfo *hashinfo, struct sk_buff *skb, int hdrlen, uint16_t sport, uint16_t dport, int iif, bool *refcounted) { return NULL; }
static struct request_sock *inet_reqsk(struct sock *sk) { return NULL; }
static struct inet6_sock *inet6_sk(struct sock *sk) { return sk->pinet6; }
static struct sock *tcp_sk(struct sock *sk) { return sk; }
static int tcp_v6_iif(struct sk_buff *skb) { return 0; }
static int __tcp_hdrlen(const struct tcphdr *th) { return 0; }