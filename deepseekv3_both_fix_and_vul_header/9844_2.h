#include <sys/socket.h>
#include <string.h>

#define EOPNOTSUPP 95

struct socket {
    void *sk;
};

struct net_device {
    char name[15];
};

struct sock;
struct pkt_sk {
    int ifindex;
};

void rcu_read_lock(void);
void rcu_read_unlock(void);
struct net_device *dev_get_by_index_rcu(void *net, int ifindex);
void *sock_net(struct sock *sk);
struct pkt_sk *pkt_sk(struct sock *sk);