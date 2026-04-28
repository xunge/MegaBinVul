#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <inttypes.h>

typedef uint64_t dma_addr_t;

#define AHCI_CMD_HDR_PRDT_LEN 16
#define DMA_DIRECTION_TO_DEVICE 1
#define DPRINTF(port, fmt, ...) printf(fmt, ##__VA_ARGS__)
#define le32_to_cpu(x) (x)
#define le64_to_cpu(x) (x)

typedef struct {
    uint32_t opts;
    uint64_t tbl_addr;
} AHCICmdHdr;

typedef struct {
    uint64_t addr;
    uint32_t size;
} AHCI_SG;

typedef struct {
    void *as;
} HBAState;

typedef struct BusState {
    void *parent;
} BusState;

typedef struct IDEBus {
    BusState *parent;
} IDEBus;

typedef struct {
    int port_no;
    HBAState *hba;
    IDEBus port;
    AHCICmdHdr *cur_cmd;
} AHCIDevice;

typedef struct {
    int size;
} QEMUSGList;

#define BUS(obj) ((BusState *)(obj))

static inline int prdt_tbl_entry_size(AHCI_SG *tbl) {
    return tbl->size;
}

static inline void *dma_memory_map(void *as, uint64_t addr, dma_addr_t *len, int dir) {
    return NULL;
}

static inline void dma_memory_unmap(void *as, void *buffer, dma_addr_t len, int dir, dma_addr_t access_len) {
}

static inline void qemu_sglist_init(QEMUSGList *sglist, void *parent, int alloc_hint, void *as) {
}

static inline void qemu_sglist_add(QEMUSGList *sglist, uint64_t addr, uint32_t len) {
}

static inline void qemu_sglist_destroy(QEMUSGList *sglist) {
}

static inline void error_report(const char *fmt, ...) {
}