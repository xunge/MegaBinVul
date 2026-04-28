#include <stdint.h>
#include <stdlib.h>
#include <errno.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct QEMUFile QEMUFile;
typedef struct PXA2xxSSPState PXA2xxSSPState;

struct PXA2xxSSPState {
    uint32_t enable;
    uint32_t sscr[2];
    uint32_t sspsp;
    uint32_t ssto;
    uint32_t ssitr;
    uint32_t sssr;
    uint8_t sstsa;
    uint8_t ssrsa;
    uint8_t ssacd;
    uint8_t rx_fifo[16];
    int rx_level;
    int rx_start;
};

int qemu_get_be32(QEMUFile *f);
void qemu_get_be32s(QEMUFile *f, uint32_t *pv);
void qemu_get_8s(QEMUFile *f, uint8_t *pv);
int qemu_get_byte(QEMUFile *f);