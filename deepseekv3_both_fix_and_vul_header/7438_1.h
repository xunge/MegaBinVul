#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <assert.h>
#include <stddef.h>

#define VIRTQUEUE_MAX_SIZE 1024
#define PRIx64 "llx"

typedef struct NetClientState NetClientState;
typedef struct VirtIONet VirtIONet;
typedef struct VirtIONetQueue VirtIONetQueue;
typedef struct VirtIODevice VirtIODevice;
typedef struct VirtQueueElement VirtQueueElement;

struct virtio_net_hdr_mrg_rxbuf {
    uint16_t num_buffers;
};

struct VirtIONet {
    struct {
        bool enabled;
        bool enabled_software_rss;
        bool populate_hash;
    } rss_data;
    bool mergeable_rx_bufs;
    size_t guest_hdr_len;
    size_t host_hdr_len;
    NetClientState *nic;
};

struct VirtIONetQueue {
    void *rx_vq;
};

struct VirtIODevice {
    uint64_t guest_features;
};

struct VirtQueueElement {
    int in_num;
    const struct iovec *in_sg;
};