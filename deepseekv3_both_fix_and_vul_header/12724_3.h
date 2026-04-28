#include <stdint.h>
#include <stddef.h>

typedef struct IDEDMA {
    /* dummy structure since we only use it for DO_UPCAST */
    int dummy;
} IDEDMA;

typedef struct QEMUSGList {
    /* dummy structure since we only use pointers */
    int dummy;
} QEMUSGList;

typedef struct AHCICmd {
    uint32_t status;
} AHCICmd;

typedef struct IDEState {
    uint8_t *io_buffer;
    int io_buffer_index;
    int io_buffer_size;
    uint32_t io_buffer_offset;
    QEMUSGList sg;
} IDEState;

typedef struct AHCIDevice {
    struct {
        IDEState ifs[1];
        int port_no;
    } port;
    IDEDMA dma;
    AHCICmd *cur_cmd;
} AHCIDevice;

#define DO_UPCAST(type, field, vm) ((type *)((char *)(vm) - offsetof(type, field)))
#define DPRINTF(port_no, fmt, ...)

int ahci_populate_sglist(AHCIDevice *ad, QEMUSGList *sg, uint32_t offset);
void dma_buf_read(uint8_t *p, int l, QEMUSGList *sg);
void dma_buf_write(uint8_t *p, int l, QEMUSGList *sg);
void qemu_sglist_destroy(QEMUSGList *sg);
uint32_t cpu_to_le32(uint32_t v);
uint32_t le32_to_cpu(uint32_t v);