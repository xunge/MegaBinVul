#include <stdint.h>
#include <stdio.h>
#include <pthread.h>
#include <assert.h>

#define UNUSED __attribute__((unused))

struct pci_devinst {
    void *pi_arg;
};

struct virtio_softc {
    unsigned int vs_flags;
    pthread_mutex_t *vs_mtx;
    struct virtio_consts *vs_vc;
    uint32_t vs_negotiated_caps;
    int vs_curq;
    uint8_t vs_status;
    uint16_t vs_msix_cfg_idx;
    struct vqueue_info *vs_queues;
};

struct vqueue_info {
    void (*vq_notify)(void *, struct vqueue_info *);
    uint16_t vq_msix_idx;
};

struct virtio_consts {
    const char *vc_name;
    uint32_t vc_hv_caps;
    void (*vc_apply_features)(void *, uint32_t);
    size_t vc_cfgsize;
    int (*vc_cfgwrite)(void *, int, int, uint32_t);
    int vc_nvq;
    void (*vc_qnotify)(void *, struct vqueue_info *);
    void (*vc_reset)(void *);
};

struct config_reg {
    const char *cr_name;
    int cr_size;
    int cr_ro;
};

#define VIRTIO_USE_MSIX (1 << 0)
#define VTCFG_R_CFG0 40
#define VTCFG_R_CFG1 44
#define VTCFG_R_GUESTCAP 8
#define VTCFG_R_PFN 12
#define VTCFG_R_QSEL 14
#define VTCFG_R_QNOTIFY 16
#define VTCFG_R_STATUS 18
#define VTCFG_R_CFGVEC 20
#define VTCFG_R_QVEC 22

#define DEV_SOFTC(vs) ((void *)(vs))

static inline int pci_msix_table_bar(struct pci_devinst *pi) { return 0; }
static inline int pci_msix_pba_bar(struct pci_devinst *pi) { return 0; }
static inline void pci_emul_msix_twrite(struct pci_devinst *pi, uint64_t offset, int size, uint64_t value) {}
static inline int pci_msix_enabled(struct pci_devinst *pi) { return 0; }
static inline struct config_reg *vi_find_cr(int offset) { return NULL; }
static inline void vi_vq_init(struct virtio_softc *vs, uint32_t value) {}