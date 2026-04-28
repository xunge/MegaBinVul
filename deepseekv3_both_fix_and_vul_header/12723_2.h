#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct IDEDMA {
    /* dummy structure for IDEDMA */
} IDEDMA;

typedef struct QEMUSGList {
    /* dummy structure for QEMUSGList */
} QEMUSGList;

typedef struct AHCICommand {
    uint32_t opts;
    uint32_t status;
} AHCICommand;

typedef struct IDEState {
    uint8_t *data_ptr;
    uint8_t *data_end;
    QEMUSGList sg;
    void (*end_transfer_func)(struct IDEState *);
    uint8_t status;
} IDEState;

typedef struct AHCIPort {
    IDEState ifs[1];
} AHCIPort;

typedef struct AHCIDevice {
    IDEDMA dma;
    AHCIPort port;
    AHCICommand *cur_cmd;
    bool done_atapi_packet;
    int port_no;
} AHCIDevice;

#define AHCI_CMD_WRITE (1 << 0)
#define AHCI_CMD_ATAPI (1 << 1)
#define DRQ_STAT (1 << 3)

static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }

#define DO_UPCAST(type, field, ptr) ((type *)((char *)(ptr) - offsetof(type, field)))
#define DPRINTF(port, fmt, ...) (void)0

void dma_buf_write(void *ptr, uint32_t size, QEMUSGList *sg);
void dma_buf_read(void *ptr, uint32_t size, QEMUSGList *sg);
bool ahci_populate_sglist(AHCIDevice *ad, QEMUSGList *sg, int flags);
void qemu_sglist_destroy(QEMUSGList *sg);
void ahci_write_fis_pio(AHCIDevice *ad, uint32_t status);