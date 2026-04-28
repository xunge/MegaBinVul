#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip6.h>
#include <arpa/inet.h>

#define __init
#define KERN_ERR ""
#define EAGAIN 11
#define AF_INET 2
#define AF_INET6 10

struct xfrm6_tunnel {
    // 结构体成员定义
};

struct pernet_operations {
    // 结构体成员定义
};

extern int xfrm6_tunnel_register(struct xfrm6_tunnel *handler, int family);
extern int xfrm6_tunnel_deregister(struct xfrm6_tunnel *handler, int family);
extern int register_pernet_device(struct pernet_operations *ops);
extern int printk(const char *fmt, ...);

struct xfrm6_tunnel ip4ip6_handler;
struct xfrm6_tunnel ip6ip6_handler;
struct pernet_operations ip6_tnl_net_ops;