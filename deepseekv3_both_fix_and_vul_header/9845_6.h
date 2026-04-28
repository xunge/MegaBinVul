#include <sys/socket.h>
#include <linux/if_packet.h>
#include <string.h>
#include <stddef.h>

#define DECLARE_SOCKADDR(type, name, addr) type name = (type)(addr)
#define EOPNOTSUPP 95

struct socket {
    struct sock *sk;
};

struct sock;

struct packet_sock {
    int ifindex;
    unsigned short num;
};

struct net_device {
    unsigned short type;
    unsigned char addr_len;
    unsigned char dev_addr[32];
};

static inline struct packet_sock *pkt_sk(struct sock *sk) { return (struct packet_sock *)sk; }
static inline void rcu_read_lock(void) {}
static inline void rcu_read_unlock(void) {}
static inline struct net_device *dev_get_by_index_rcu(void *net, int ifindex) { return 0; }
static inline void *sock_net(struct sock *sk) { return 0; }