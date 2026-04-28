#include <stdint.h>

#define ESP_TCLO 0
#define ESP_TCMID 1
#define ESP_TCHI 2
#define ESP_RSTAT 3
#define STAT_TC 0x01
#define ESP_CMDBUF_SZ 32

typedef struct ESPState {
    uint8_t *rregs;
    int dma;
    int dma_enabled;
    void (*dma_cb)(struct ESPState *);
    uint32_t dma_counter;
    int do_cmd;
    int ti_size;
    int dma_left;
    int cmdlen;
    uint8_t *cmdbuf;
} ESPState;

void trace_esp_handle_ti(uint32_t minlen);
void trace_esp_handle_ti_cmd(int cmdlen);
void esp_do_dma(ESPState *s);
void do_cmd(ESPState *s, uint8_t *cmdbuf);