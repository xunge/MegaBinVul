#include <stdint.h>

typedef struct IDEDMAOps {
    void (*commit_buf)(void *, uint32_t);
} IDEDMAOps;

typedef struct IDEDMA {
    const IDEDMAOps *ops;
} IDEDMA;

typedef struct IDEBus {
    IDEDMA *dma;
} IDEBus;

typedef struct IDEState {
    IDEBus *bus;
    void *sg;
} IDEState;

void qemu_sglist_destroy(void *sg);