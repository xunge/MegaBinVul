#include <stdint.h>
#include <string.h>

typedef struct NICState NICState;

typedef struct XgmacState {
    NICState *nic;
    uint32_t regs[256];
} XgmacState;

struct desc {
    uint32_t ctl_stat;
    uint32_t buffer1_addr;
    uint32_t buffer1_size;
    uint32_t buffer2_addr;
    uint32_t buffer2_size;
};

#define DMA_STATUS 0
#define DMA_STATUS_TI (1 << 0)
#define DMA_STATUS_NIS (1 << 15)

#define DEBUGF_BRK(fmt, ...)

void xgmac_read_desc(XgmacState *s, struct desc *bd, int idx);
void xgmac_write_desc(XgmacState *s, struct desc *bd, int idx);
void cpu_physical_memory_read(uint32_t addr, uint8_t *buf, int len);
void qemu_send_packet(void *queue, uint8_t *buf, int len);
void *qemu_get_queue(NICState *nic);