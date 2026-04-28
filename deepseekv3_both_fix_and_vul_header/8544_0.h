#include <stdint.h>

#define FEC_MAX_FRAME_SIZE 2032
#define FEC_MAX_DESC 1024
#define FEC_BD_R 0x8000
#define FEC_BD_L 0x4000
#define FEC_BD_W 0x2000
#define FEC_INT_BABT 0x00400000
#define FEC_INT_TXF 0x00000080
#define FEC_INT_TXB 0x00000040
#define FEC_INT_TXE 0x00000020

typedef struct mcf_fec_bd {
    uint16_t flags;
    uint16_t length;
    uint32_t data;
} mcf_fec_bd;

typedef struct mcf_fec_state {
    uint32_t tx_descriptor;
    uint32_t etdsr;
    uint32_t eir;
    void *nic;
} mcf_fec_state;

#define DPRINTF(fmt, ...) do {} while (0)

void mcf_fec_read_bd(mcf_fec_bd *bd, uint32_t addr);
void mcf_fec_write_bd(mcf_fec_bd *bd, uint32_t addr);
void cpu_physical_memory_read(uint32_t addr, uint8_t *buf, int len);
void qemu_send_packet(void *nc, const uint8_t *buf, int size);
void *qemu_get_queue(void *nic);