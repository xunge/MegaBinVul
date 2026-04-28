#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define DEBUG_NE2000 0
#define MIN_BUF_SIZE 60
#define NE2000_PMEM_END 0x10000

#define E8390_STOP 0x01
#define ENRSR_RXOK 0x01
#define ENRSR_PHY 0x20
#define ENISR_RX 0x01

typedef struct NetClientState NetClientState;

typedef struct NE2000State {
    uint8_t cmd;
    uint8_t rxcr;
    uint8_t mem[NE2000_PMEM_END];
    uint8_t mult[8];
    uint16_t curpag;
    uint16_t start;
    uint16_t stop;
    uint8_t rsr;
    uint8_t isr;
} NE2000State;

static inline int ne2000_buffer_full(NE2000State *s) {
    return 0;
}

static inline unsigned int compute_mcast_idx(const uint8_t *buf) {
    return 0;
}

static inline void ne2000_update_irq(NE2000State *s) {
}

static inline NE2000State *qemu_get_nic_opaque(NetClientState *nc) {
    return NULL;
}