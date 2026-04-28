#define __init
#define AF_INET6 10
#define KERN_INFO ""
#define EAGAIN 11

struct xfrm_tunnel;
struct pernet_operations;

extern struct xfrm_tunnel sit_handler;
extern struct pernet_operations sit_net_ops;

int printk(const char *fmt, ...);
int xfrm4_tunnel_register(struct xfrm_tunnel *handler, int family);
int xfrm4_tunnel_deregister(struct xfrm_tunnel *handler, int family);
int register_pernet_device(struct pernet_operations *ops);