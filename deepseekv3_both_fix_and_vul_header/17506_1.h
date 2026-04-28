#include <sys/socket.h>
#include <linux/if_packet.h>
#include <errno.h>

#define MAX_ADDR_LEN 32
#define ERR_PTR(err) ((void *)(long)(err))
#define ENOTSOCK 88
#define ESOCKTNOSUPPORT 94
#define EPFNOSUPPORT 96

struct socket {
    struct sock *sk;
    struct proto_ops *ops;
};

struct sock {
    unsigned short sk_type;
    unsigned short sk_family;
};

struct proto_ops {
    int (*getname)(struct socket *, struct sockaddr *, int);
};

struct socket *sockfd_lookup(int fd, int *err);
void sockfd_put(struct socket *sock);