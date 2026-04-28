#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define NUMA_NO_NODE (-1)
#define GFP_KERNEL 0
#define ENOMEM 12
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))

struct device {
    int dummy;
};

struct net_device {
    int dummy;
};

struct napi_struct {
    unsigned int napi_id;
};

struct xdp_rxq_info {
    int dummy;
};

struct bpf_prog {
    int dummy;
};

struct ixgbe_rx_buffer {
    int dummy;
};

union ixgbe_adv_rx_desc {
    int dummy;
};

struct ixgbe_q_vector {
    int numa_node;
    struct napi_struct napi;
};

struct ixgbe_ring {
    struct device *dev;
    unsigned int count;
    struct ixgbe_q_vector *q_vector;
    void *rx_buffer_info;
    unsigned int size;
    void *desc;
    uint64_t dma;
    unsigned int next_to_clean;
    unsigned int next_to_use;
    unsigned int queue_index;
    struct xdp_rxq_info xdp_rxq;
    struct bpf_prog *xdp_prog;
};

struct ixgbe_adapter {
    struct net_device *netdev;
    struct bpf_prog *xdp_prog;
};

static inline void *vmalloc_node(size_t size, int node) { return malloc(size); }
static inline void *vmalloc(size_t size) { return malloc(size); }
static inline void vfree(void *addr) { free(addr); }
static inline void *dma_alloc_coherent(struct device *dev, size_t size, uint64_t *dma, int gfp) { *dma = (uint64_t)malloc(size); return (void*)*dma; }
static inline int xdp_rxq_info_reg(struct xdp_rxq_info *xdp_rxq, struct net_device *dev, unsigned int queue_index, unsigned int napi_id) { return 0; }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline int dev_to_node(struct device *dev) { return 0; }
static inline void set_dev_node(struct device *dev, int node) {}