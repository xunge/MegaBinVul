#include <stddef.h>
#include <string.h>

#define MAX_SKB_FRAGS 18
#define PAGE_SIZE 4096
#define XEN_NETTXF_more_data (1 << 0)

#define unlikely(x) (x)

typedef unsigned int RING_IDX;

struct xenvif {
    struct {
        RING_IDX req_cons;
    } tx;
    void *dev;
};

struct xen_netif_tx_request {
    unsigned short flags;
    unsigned short offset;
    unsigned short size;
};

#define RING_GET_REQUEST(_r, _idx) \
    ((struct xen_netif_tx_request *)(_r) + (_idx))

#define netdev_dbg(dev, fmt, ...)