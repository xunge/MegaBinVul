#include <stddef.h>
#include <string.h>

typedef unsigned int RING_IDX;

struct xen_netif_extra_info {
    unsigned char type;
    unsigned char flags;
};

struct xenvif {
    void *dev;
    struct {
        RING_IDX req_cons;
    } tx;
};

#define unlikely(x) (x)
#define netdev_dbg(dev, fmt, ...) 
#define EBADR 1
#define EINVAL 2
#define XEN_NETIF_EXTRA_TYPE_MAX 3
#define XEN_NETIF_EXTRA_FLAG_MORE (1 << 0)

#define RING_GET_REQUEST(ring, idx) ((void*)((char*)(ring) + (idx)))