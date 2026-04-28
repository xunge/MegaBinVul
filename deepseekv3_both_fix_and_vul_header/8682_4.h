#include <stdint.h>
#include <stdlib.h>
#include <sys/uio.h>
#include <stdbool.h>

typedef struct PCIDevice PCIDevice;

struct virtio_net_hdr {
    uint8_t flags;
    uint8_t gso_type;
    uint16_t hdr_len;
    uint16_t gso_size;
    uint16_t csum_start;
    uint16_t csum_offset;
};

struct NetTxPkt {
    PCIDevice *pci_dev;
    struct iovec *vec;
    struct iovec *raw;
    uint32_t max_payload_frags;
    uint32_t max_raw_frags;
    bool has_virt_hdr;
    struct virtio_net_hdr virt_hdr;
    uint8_t l2_hdr[64];
    uint8_t l3_hdr[64];
};

#define NET_TX_PKT_PL_START_FRAG 2
#define NET_TX_PKT_VHDR_FRAG 0
#define NET_TX_PKT_L2HDR_FRAG 1
#define NET_TX_PKT_L3HDR_FRAG 2

void *g_malloc0(size_t size);
void *g_new0(size_t nmemb, size_t size);

#define g_new(type, n) ((type *)g_new0((n), sizeof(type)))