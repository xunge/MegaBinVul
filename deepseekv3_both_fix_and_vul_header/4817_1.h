#include <stdint.h>
#include <stdbool.h>

typedef struct ESPState {
    uint32_t rregs[256];
    uint32_t ti_size;
    uint32_t ti_rptr;
    uint32_t ti_wptr;
    uint8_t *ti_buf;
    uint32_t chip_id;
    bool tchi_written;
} ESPState;

#define ESP_FIFO 0
#define ESP_RSTAT 1
#define ESP_RINTR 2
#define ESP_RSEQ 3
#define ESP_TCHI 4

#define STAT_PIO_MASK 0x1
#define STAT_TC 0x2
#define SEQ_CD 0x0

#define LOG_UNIMP 0

void trace_esp_mem_readb(uint32_t addr, uint32_t val);
void esp_raise_irq(ESPState *s);
void esp_lower_irq(ESPState *s);
void qemu_log_mask(int mask, const char *fmt, ...);