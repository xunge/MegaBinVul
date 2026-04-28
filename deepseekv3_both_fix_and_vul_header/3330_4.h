#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

struct kiocb;
struct msghdr;
struct iovec;

struct sock {
    int sk_family;
};

struct sk_buff {
    unsigned int len;
    void *data;
    int iif;
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

struct ipv6hdr {
    struct in6_addr saddr;
};

struct ip6cb {
    int iif;
};

#define IP6CB(skb) ((struct ip6cb *)skb)

#define pr_debug(fmt, ...)
#define CONFIG_IPV6 1
#define IS_ENABLED(x) (x)

struct pingv6_ops {
    int (*ipv6_recv_error)(struct sock *sk, struct msghdr *msg, size_t len);
    void (*ip6_datagram_recv_ctl)(struct sock *sk, struct msghdr *msg, struct sk_buff *skb);
};

extern struct pingv6_ops pingv6_ops;
extern int ip_recv_error(struct sock *sk, struct msghdr *msg, size_t len);
extern struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err);
extern int skb_copy_datagram_iovec(struct sk_buff *skb, int offset, struct iovec *to, int size);
extern void sock_recv_timestamp(struct msghdr *msg, struct sock *sk, struct sk_buff *skb);
extern void ip_cmsg_recv(struct msghdr *msg, struct sk_buff *skb);
extern void skb_free_datagram(struct sock *sk, struct sk_buff *skb);
extern struct inet_sock *inet_sk(const struct sock *sk);
extern struct ipv6_pinfo *inet6_sk(const struct sock *sk);
extern struct iphdr *ip_hdr(const struct sk_buff *skb);
extern struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb);
extern uint32_t ip6_flowinfo(const struct ipv6hdr *hdr);
extern uint32_t ipv6_iface_scope_id(const struct in6_addr *addr, int iface);
extern void BUG(void);