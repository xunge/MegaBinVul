#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>

struct xfrm6_tunnel_spi {
    int dummy;
};

struct kmem_cache {
    const char *name;
    unsigned int size;
    unsigned int align;
    void (*ctor)(void *);
};

struct xfrm_type {
    int dummy;
};

struct pernet_operations {
    int dummy;
};

struct xfrm6_tunnel {
    int dummy;
};

#define SLAB_HWCACHE_ALIGN 0
#define ENOMEM 12
#define __init

struct kmem_cache *xfrm6_tunnel_spi_kmem;
static struct xfrm_type xfrm6_tunnel_type;
static struct pernet_operations xfrm6_tunnel_net_ops;
static struct xfrm6_tunnel xfrm6_tunnel_handler;
static struct xfrm6_tunnel xfrm46_tunnel_handler;

struct kmem_cache *kmem_cache_create(const char *, unsigned int, unsigned int, unsigned long, void (*)(void *));
int register_pernet_subsys(struct pernet_operations *);
int xfrm_register_type(struct xfrm_type *, int);
int xfrm6_tunnel_register(struct xfrm6_tunnel *, int);
void xfrm6_tunnel_deregister(struct xfrm6_tunnel *, int);
void xfrm_unregister_type(struct xfrm_type *, int);
void unregister_pernet_subsys(struct pernet_operations *);
void kmem_cache_destroy(struct kmem_cache *);