#include <stdbool.h>
#include <stdint.h>

#define XFRM6_TUNNEL_SPI_BYADDR_HSIZE 256
#define XFRM6_TUNNEL_SPI_BYSPI_HSIZE 256
#define IPSEC_PROTO_ANY 0
#define __net_exit

struct hlist_head {
    struct hlist_node *first;
};

struct hlist_node {
    struct hlist_node *next, **pprev;
};

struct xfrm6_tunnel_net {
    struct hlist_head spi_byaddr[XFRM6_TUNNEL_SPI_BYADDR_HSIZE];
    struct hlist_head spi_byspi[XFRM6_TUNNEL_SPI_BYSPI_HSIZE];
};

struct net;

static inline bool hlist_empty(const struct hlist_head *h);
static inline void WARN_ON_ONCE(bool condition);

static struct xfrm6_tunnel_net *xfrm6_tunnel_pernet(struct net *net);
static void xfrm_flush_gc(void);
static void xfrm_state_flush(struct net *net, uint8_t proto, bool task_valid, bool sync);