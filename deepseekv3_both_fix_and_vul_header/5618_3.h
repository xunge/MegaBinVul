#include <stdint.h>
#include <limits.h>
#include <stddef.h>

typedef struct IDEDMA {
    /* empty structure - forward declaration */
} IDEDMA;

typedef struct PCIDevice {
    /* empty structure - forward declaration */
} PCIDevice;

typedef struct BMDMAState {
    IDEDMA dma;
    PCIDevice *pci_dev;
    uint32_t cur_addr;
    uint32_t cur_prd_len;
    uint32_t cur_prd_addr;
    int cur_prd_last;
    uint32_t addr;
} BMDMAState;

typedef struct IDEState {
    int nsector;
    int io_buffer_size;
    struct {
        int size;
    } sg;
} IDEState;

#define BMDMA_PAGE_SIZE 4096
#define DO_UPCAST(type, field, obj) ((type *)((char *)(obj) - offsetof(type, field)))
#define PCI_DEVICE(obj) ((PCIDevice *)(obj))

static IDEState *bmdma_active_if(BMDMAState *bm);
static void pci_dma_sglist_init(void *sg, PCIDevice *pci_dev, int entries);
static void pci_dma_read(PCIDevice *pci_dev, uint32_t addr, void *buf, int len);
static void qemu_sglist_add(void *sg, uint32_t addr, int len);
static void qemu_sglist_destroy(void *sg);
static uint32_t le32_to_cpu(uint32_t val);
static void error_report(const char *fmt, ...);