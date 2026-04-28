#include <sys/types.h>
#include <sys/uio.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define BLOCKIF_IOV_MAX 16
#define DEV_BSIZE 512
#define VRING_DESC_F_WRITE 2

struct pci_vtblk_softc {
    void *bc;
    struct pci_vtblk_ioreq *vbsc_ios;
    char vbsc_ident[20];
};

struct vqueue_info {
    // dummy definition
};

struct virtio_blk_hdr {
    uint32_t vbh_type;
    uint32_t vbh_sector;
};

struct virtio_blk_discard_write_zeroes {
    uint64_t sector;
    uint32_t num_sectors;
    uint32_t flags;
};

struct blockif_req {
    struct iovec *br_iov;
    int br_iovcnt;
    off_t br_offset;
    size_t br_resid;
};

struct pci_vtblk_ioreq {
    struct blockif_req io_req;
    void *io_status;
};

#define VBH_OP_READ 0
#define VBH_OP_WRITE 1
#define VBH_OP_DISCARD 2
#define VBH_OP_FLUSH 3
#define VBH_OP_FLUSH_OUT 4
#define VBH_OP_IDENT 5
#define VBH_FLAG_BARRIER (1 << 31)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define DPRINTF(x)

static int vq_getchain(struct vqueue_info *vq, uint16_t *idx, struct iovec *iov, int max, uint16_t *flags);
static const char *print_vbh_op(int type);
static int blockif_read(void *bc, struct blockif_req *req);
static int blockif_write(void *bc, struct blockif_req *req);
static int blockif_delete(void *bc, struct blockif_req *req);
static int blockif_flush(void *bc, struct blockif_req *req);
static void pci_vtblk_done_locked(struct blockif_req *req, int err);