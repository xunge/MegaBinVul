#define __exit __attribute__((section(".exit.text")))

#include <sys/socket.h>
#include <netinet/in.h>

extern struct xfrm6_tunnel_handler xfrm46_tunnel_handler;
extern struct xfrm6_tunnel_handler xfrm6_tunnel_handler;
extern struct xfrm_type xfrm6_tunnel_type;
extern struct pernet_operations xfrm6_tunnel_net_ops;
extern struct kmem_cache *xfrm6_tunnel_spi_kmem;