#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

struct kiocb;
struct msghdr;
struct iovec;

struct sock {
    int sk_family;
};

struct sk_buff {
    unsigned int len;
    struct {
        struct iphdr *iph;
    } nh;
};

struct inet_sock {
    unsigned int inet_num;
    int cmsg_flags;
};

struct ipv6_pinfo {
    int sndflow;
    struct {
        int all;
    } rxopt;
};

struct IP6CB {
    int iif;
};

#define IS_ENABLED(x) 0
#define CONFIG_IPV6 0
#define BUG() do { } while (0)
#define pr_debug(fmt, ...) do { } while (0)

struct pingv6_ops {
    int (*ipv6_recv_error)(struct sock *sk, struct msghdr *msg, int len);
    void (*ip6_datagram_recv_ctl)(struct sock *sk, struct msghdr *msg, struct sk_buff *skb);
};

extern struct pingv6_ops pingv6_ops;

static inline struct inet_sock *inet_sk(const struct sock *sk) { return (struct inet_sock *)sk; }
static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk) { return NULL; }
static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) { return NULL; }
static inline struct iphdr *ip_hdr(const struct sk_buff *skb) { return skb->nh.iph; }
static inline struct IP6CB *IP6CB(const struct sk_buff *skb) { return NULL; }
static inline uint32_t ip6_flowinfo(const struct ipv6hdr *ip6) { return 0; }
static inline int ipv6_iface_scope_id(const struct in6_addr *addr, int iif) { return 0; }

int ip_recv_error(struct sock *sk, struct msghdr *msg, int len);
struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err);
int skb_copy_datagram_iovec(const struct sk_buff *skb, int offset, struct iovec *to, int len);
void skb_free_datagram(struct sock *sk, struct sk_buff *skb);
void sock_recv_timestamp(struct msghdr *msg, struct sock *sk, struct sk_buff *skb);
void ip_cmsg_recv(struct msghdr *msg, struct sk_buff *skb);