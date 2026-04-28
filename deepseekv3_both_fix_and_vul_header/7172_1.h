#include <stdint.h>
#include <pthread.h>
#include <assert.h>
#include <stdio.h>
#include <inttypes.h>

#define UNUSED __attribute__((unused))

struct virtio_queue {
    uint32_t vq_pfn;
    uint16_t vq_qsize;
    uint16_t vq_msix_idx;
};

struct virtio_softc {
    void *pi_arg;
    uint32_t vs_flags;
    pthread_mutex_t *vs_mtx;
    struct virtio_consts *vs_vc;
    uint32_t vs_negotiated_caps;
    uint16_t vs_curq;
    struct virtio_queue *vs_queues;
    uint8_t vs_status;
    uint8_t vs_isr;
    uint16_t vs_msix_cfg_idx;
};

struct virtio_consts {
    const char *vc_name;
    uint32_t vc_hv_caps;
    uint16_t vc_nvq;
    uint64_t vc_cfgsize;
    int (*vc_cfgread)(void *, int, int, uint32_t *);
};

struct config_reg {
    const char *cr_name;
    int cr_size;
};

struct pci_devinst {
    void *pi_arg;
};

#define VIRTIO_USE_MSIX (1 << 0)
#define VIRTIO_MSI_NO_VECTOR 0xFFFF

#define VTCFG_R_HOSTCAP 0
#define VTCFG_R_GUESTCAP 4
#define VTCFG_R_PFN 8
#define VTCFG_R_QNUM 12
#define VTCFG_R_QSEL 16
#define VTCFG_R_QNOTIFY 20
#define VTCFG_R_STATUS 24
#define VTCFG_R_ISR 28
#define VTCFG_R_CFGVEC 32
#define VTCFG_R_QVEC 36
#define VTCFG_R_CFG0 40
#define VTCFG_R_CFG1 48

#define DEV_SOFTC(vs) ((void *)(vs))

static inline int pci_msix_table_bar(struct pci_devinst *pi) { return 0; }
static inline int pci_msix_pba_bar(struct pci_devinst *pi) { return 0; }
static inline uint64_t pci_emul_msix_tread(struct pci_devinst *pi, uint64_t offset, int size) { return 0; }
static inline int pci_msix_enabled(struct pci_devinst *pi) { return 0; }
static inline void pci_lintr_deassert(struct pci_devinst *pi) {}

static struct config_reg *vi_find_cr(int offset) { return NULL; }