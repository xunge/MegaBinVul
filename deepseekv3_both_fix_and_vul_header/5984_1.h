#include <stdlib.h>

struct vmctx;
struct pci_vdev {
    void *arg;
};
struct blockif_ctxt;
struct virtio_blk {
    int dummy_bctxt;
    struct blockif_ctxt *bc;
    void *base;
};

#define DPRINTF(fmt, ...)
#define WPRINTF(fmt, ...)

int blockif_flush_all(struct blockif_ctxt *bctxt);
void blockif_close(struct blockif_ctxt *bctxt);
void virtio_reset_dev(void *base);