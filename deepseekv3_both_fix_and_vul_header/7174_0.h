#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <sys/uio.h>

struct vqueue_info;
struct pci_vtrnd_softc {
    int vrsc_fd;
};

#define DPRINTF(x) 
int vq_has_descs(struct vqueue_info *vq);
int vq_getchain(struct vqueue_info *vq, uint16_t *idx, struct iovec *iov, int n, void **ptr);
void vq_relchain(struct vqueue_info *vq, uint16_t idx, uint32_t len);
void vq_endchains(struct vqueue_info *vq, int used_all);