#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <string.h>

struct sock {
    void *sk_backlog_rcv;
    int sk_bound_dev_if;
    struct inet_sock *inet;
    int sk_gso_type;
};

struct sk_buff {
    unsigned short protocol;
    struct {
        struct ipv6hdr *ipv6h;
        void *raw;
    } nh;
    void *pktopts;
};

struct request_sock;
struct dst_entry;
struct inet6_request_sock {
    struct in6_addr rmt_addr;
    struct in6_addr loc_addr;
    struct sk_buff *pktopts;
    int iif;
};

struct ipv6_pinfo {
    struct in6_addr daddr;
    struct in6_addr saddr;
    struct in6_addr rcv_saddr;
    void *pktoptions;
    struct ipv6_txoptions *opt;
    int mcast_oif;
    int mcast_hops;
    struct {
        unsigned int all;
        struct {
            int osrcrt;
        } bits;
    } rxopt;
    void *ipv6_fl_list;
};

struct tcp6_sock {
    struct ipv6_pinfo inet6;
};

struct inet_sock {
    void *pinet6;
    unsigned int daddr;
    unsigned int saddr;
    unsigned int rcv_saddr;
    void *opt;
    unsigned short sport;
};

struct tcp_sock {
    void *af_specific;
    int advmss;
};

struct ipv6_txoptions {
    int tot_len;
    int opt_nflen;
    int opt_flen;
    void *srcrt;
};

struct tcp_md5sig_key {
    char *key;
    int keylen;
};

struct inet6_skb_parm {
    int srcrt;
};

struct ipv6_rt_hdr;
struct rt0_hdr {
    struct in6_addr *addr;
};

struct flowi {
    unsigned char proto;
    struct in6_addr fl6_dst;
    struct in6_addr fl6_src;
    int oif;
    unsigned short fl_ip_dport;
    unsigned short fl_ip_sport;
};

struct tcp_hashinfo {
    int dummy;
};

struct in6_addr;
struct ipv6hdr {
    int hop_limit;
};

struct inet_connection_sock {
    void *icsk_af_ops;
    int icsk_pmtu_cookie;
    int icsk_ext_hdr_len;
};

struct inet_rsk {
    unsigned short rmt_port;
};

#define ETH_P_IP 0x0800
#define CONFIG_TCP_MD5SIG 1
#define GFP_ATOMIC 0
#define LINUX_MIB_LISTENOVERFLOWS 0
#define LINUX_MIB_LISTENDROPS 0
#define LOOPBACK4_IPV6 0
#define RTAX_ADVMSS 0
#define SKB_GSO_TCPV6 0

static inline struct inet6_request_sock *inet6_rsk(struct request_sock *req) { return (struct inet6_request_sock *)req; }
static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk) { return (struct ipv6_pinfo *)sk; }
static inline struct tcp_sock *tcp_sk(const struct sock *sk) { return (struct tcp_sock *)sk; }
static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline int inet6_iif(const struct sk_buff *skb) { return 0; }
static inline int sk_acceptq_is_full(const struct sock *sk) { return 0; }
static inline int ip6_dst_lookup(struct sock *sk, struct dst_entry **dst, struct flowi *fl) { return 0; }
static inline int xfrm_lookup(struct dst_entry **dst, struct flowi *fl, struct sock *sk, int flags) { return 0; }
static inline struct sock *tcp_create_openreq_child(struct sock *sk, struct request_sock *req, struct sk_buff *skb) { return NULL; }
static inline void __ip6_dst_store(struct sock *sk, struct dst_entry *dst, void *src, void *dst_cookie) {}
static inline struct ipv6_txoptions *ipv6_dup_options(struct sock *sk, struct ipv6_txoptions *opt) { return NULL; }
static inline void sock_kfree_s(struct sock *sk, void *opt, int len) {}
static inline void tcp_mtup_init(struct sock *sk) {}
static inline void tcp_sync_mss(struct sock *sk, int pmtu) {}
static inline int dst_mtu(const struct dst_entry *dst) { return 0; }
static inline int dst_metric(const struct dst_entry *dst, int metric) { return 0; }
static inline void tcp_initialize_rcv_mss(struct sock *sk) {}
static inline struct tcp_md5sig_key *tcp_v6_md5_do_lookup(struct sock *sk, struct in6_addr *addr) { return NULL; }
static inline void tcp_v6_md5_do_add(struct sock *sk, struct in6_addr *addr, void *key, int keylen) {}
static inline void __inet6_hash(struct tcp_hashinfo *hashinfo, struct sock *sk) {}
static inline void inet_inherit_port(struct tcp_hashinfo *hashinfo, struct sock *sk, struct sock *newsk) {}
static inline void dst_release(struct dst_entry *dst) {}
static inline void NET_INC_STATS_BH(int stat) {}
static inline void security_req_classify_flow(struct request_sock *req, struct flowi *fl) {}
static inline struct ipv6_txoptions *ipv6_invert_rthdr(struct sock *sk, struct ipv6_rt_hdr *hdr) { return NULL; }
static inline struct sock *tcp_v4_syn_recv_sock(struct sock *sk, struct sk_buff *skb, struct request_sock *req, struct dst_entry *dst) { return NULL; }
static inline void *kmemdup(const void *src, size_t len, int gfp) { return NULL; }
static inline void kfree_skb(struct sk_buff *skb) {}
static inline struct sk_buff *skb_clone(struct sk_buff *skb, int gfp) { return NULL; }
static inline void skb_set_owner_r(struct sk_buff *skb, struct sock *sk) {}
static inline void ipv6_addr_set(struct in6_addr *addr, int a, int b, int c, int d) {}
static inline void ipv6_addr_copy(struct in6_addr *dst, const struct in6_addr *src) {}
static inline struct inet6_skb_parm *IP6CB(struct sk_buff *skb) { return NULL; }
static inline struct inet_connection_sock *inet_csk(struct sock *sk) { return (struct inet_connection_sock *)sk; }
static inline void tcp_v4_do_rcv(struct sock *sk) {}
static inline struct inet_rsk *inet_rsk(const struct request_sock *req) { return (struct inet_rsk *)req; }

static const void *ipv6_mapped;
static const void *tcp_sock_ipv6_mapped_specific;
static struct tcp_hashinfo tcp_hashinfo;