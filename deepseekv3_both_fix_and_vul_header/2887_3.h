#include <sys/socket.h>
#include <netinet/in.h>
#include <linux/in6.h>
#include <linux/l2tp.h>
#include <errno.h>
#include <stdbool.h>

struct sock {
    int sk_bound_dev_if;
};

struct socket {
    struct sock *sk;
};

struct ipv6_pinfo {
    struct in6_addr daddr;
    struct in6_addr saddr;
    struct in6_addr rcv_saddr;
    __be32 flow_label;
    bool sndflow;
};

struct l2tp_ip6_sock {
    __u32 conn_id;
    __u32 peer_conn_id;
};

#define IPV6_ADDR_LINKLOCAL 0x0020U
#define ENOTCONN 107

static inline struct ipv6_pinfo *inet6_sk(const struct sock *sk) {
    return (struct ipv6_pinfo *)sk;
}

static inline struct l2tp_ip6_sock *l2tp_ip6_sk(const struct sock *sk) {
    return (struct l2tp_ip6_sock *)sk;
}

static inline int ipv6_addr_any(const struct in6_addr *addr) {
    return IN6_IS_ADDR_UNSPECIFIED(addr);
}

static inline unsigned ipv6_addr_type(const struct in6_addr *addr) {
    return IN6_IS_ADDR_LINKLOCAL(addr) ? IPV6_ADDR_LINKLOCAL : 0;
}