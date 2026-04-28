#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <sys/uio.h>
#include <stdint.h>

#define EOPNOTSUPP 95
#define IPV6_ADDR_LINKLOCAL 0x0020U

typedef uint32_t __be32;
typedef uint32_t __u32;

struct kiocb;
struct sock;
struct msghdr;
struct sk_buff {
    unsigned int len;
    void *data;
};
struct ipv6_pinfo {
    struct {
        int all;
    } rxopt;
};
struct in6_addr;
struct ipv6hdr {
    struct in6_addr saddr;
};

static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk) { return (struct ipv6_pinfo *)sk; }
static inline struct ipv6hdr *ipv6_hdr(const struct sk_buff *skb) { return (struct ipv6hdr *)skb->data; }
static inline int ipv6_addr_type(const struct in6_addr *addr) { return 0; }
static inline struct {
    int iif;
} *IP6CB(const struct sk_buff *skb) { return (void *)skb->data; }

static int ipv6_recv_error(struct sock *sk, struct msghdr *msg, size_t len) { return 0; }
static struct sk_buff *skb_recv_datagram(struct sock *sk, int flags, int noblock, int *err) { return 0; }
static int skb_copy_datagram_iovec(const struct sk_buff *skb, int offset, struct iovec *to, int size) { return 0; }
static void sock_recv_timestamp(struct msghdr *msg, struct sock *sk, struct sk_buff *skb) {}
static void ip6_datagram_recv_ctl(struct sock *sk, struct msghdr *msg, struct sk_buff *skb) {}
static void skb_free_datagram(struct sock *sk, struct sk_buff *skb) {}

struct sockaddr_l2tpip6 {
    sa_family_t     l2tp_family;
    __be32          l2tp_conn_id;
    struct in6_addr l2tp_addr;
    __u32           l2tp_flowinfo;
    __u32           l2tp_scope_id;
    __u32           l2tp_unused;
};