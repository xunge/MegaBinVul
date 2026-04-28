#include <stdint.h>
#include <stdbool.h>
#include <sys/uio.h>

typedef uint64_t hwaddr;

#define NVME_SUCCESS 0
#define NVME_DATA_TRAS_ERROR 1
#define NVME_INVALID_USE_OF_CMB 2
#define NVME_DNR 0x4000
#define NVME_INTERNAL_DEV_ERROR 3
#define IOV_MAX 1024

typedef struct NvmeSg {
    unsigned int flags;
    struct {
        int niov;
    } iov;
    struct {
        int nsg;
    } qsg;
} NvmeSg;

typedef struct NvmeCtrl {
    // Placeholder for NVMe controller structure
} NvmeCtrl;

#define NVME_SG_DMA 0x1

static inline bool nvme_addr_is_iomem(NvmeCtrl *n, hwaddr addr) { return false; }
static inline bool nvme_addr_is_cmb(NvmeCtrl *n, hwaddr addr) { return false; }
static inline bool nvme_addr_is_pmr(NvmeCtrl *n, hwaddr addr) { return false; }
static uint16_t nvme_map_addr_cmb(NvmeCtrl *n, void *iov, hwaddr addr, size_t len) { return 0; }
static uint16_t nvme_map_addr_pmr(NvmeCtrl *n, void *iov, hwaddr addr, size_t len) { return 0; }
static void qemu_sglist_add(void *qsg, hwaddr addr, size_t len) {}
static void trace_pci_nvme_map_addr(hwaddr addr, size_t len) {}

#define NVME_GUEST_ERR(err, msg) 