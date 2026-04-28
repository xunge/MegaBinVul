#include <stdlib.h>
#include <stdint.h>

struct vmctx;
struct virtio_rpmb;

struct pci_vdev {
    void *arg;
};

#define DPRINTF(fmt)