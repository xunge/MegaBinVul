#include <stdint.h>
#include <stddef.h>

typedef uint16_t pending_ring_idx_t;
typedef uint16_t u16;
typedef uint8_t u8;

#define XEN_NETIF_RSP_OKAY 0

struct xenvif;

struct page {
    unsigned long mapping;
};

struct pending_tx_info {
    struct xenvif *vif;
    void *req;
};

struct xen_netbk {
    struct page **mmap_pages;
    struct pending_tx_info *pending_tx_info;
    pending_ring_idx_t pending_prod;
    u16 *pending_ring;
};

void make_tx_response(struct xenvif *vif, void *req, u8 status);
void xenvif_put(struct xenvif *vif);
pending_ring_idx_t pending_index(pending_ring_idx_t index);
void put_page(struct page *page);