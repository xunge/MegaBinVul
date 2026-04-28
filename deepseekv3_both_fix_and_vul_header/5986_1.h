#include <stdlib.h>
#include <stdint.h>

struct vmctx;
struct pci_vdev {
    void *arg;
};
struct virtio_hdcp;

#define DPRINTF(x) printf x