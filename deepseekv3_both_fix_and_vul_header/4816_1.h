#include <stdint.h>
#include <stdbool.h>

#define TI_BUFSZ 32

typedef struct ESPState {
    uint8_t wregs[256];
    uint8_t rregs[256];
    uint8_t cmdbuf[TI_BUFSZ];
    uint8_t ti_buf[TI_BUFSZ];
    int cmdlen;
    int ti_size;
    int ti_wptr;
    bool do_cmd;
    bool dma;
    bool tchi_written;
} ESPState;

#define ESP_TCHI 0
#define ESP_TCLO 1
#define ESP_TCMID 2
#define ESP_FIFO 3
#define ESP_CMD 4
#define ESP_WBUSID 5
#define ESP_WSYNO 6
#define ESP_CFG1 7
#define ESP_CFG2 8
#define ESP_CFG3 9
#define ESP_RES3 10
#define ESP_RES4 11
#define ESP_WCCF 12
#define ESP_WTEST 13
#define ESP_RSTAT 14
#define ESP_RINTR 15
#define ESP_RSEQ 16
#define ESP_RFLAGS 17

#define STAT_TC 0x01
#define STAT_MI 0x02
#define INTR_FC 0x01
#define INTR_RST 0x02
#define INTR_DC 0x04
#define CMD_DMA 0x80
#define CMD_CMD 0x7F
#define CMD_NOP 0x00
#define CMD_FLUSH 0x01
#define CMD_RESET 0x02
#define CMD_BUSRESET 0x03
#define CMD_TI 0x10
#define CMD_ICCS 0x11
#define CMD_MSGACC 0x12
#define CMD_PAD 0x18
#define CMD_SATN 0x1A
#define CMD_RSTATN 0x1B
#define CMD_SEL 0x41
#define CMD_SELATN 0x42
#define CMD_SELATNS 0x43
#define CMD_ENSEL 0x44
#define CMD_DISSEL 0x45
#define CFG1_RESREPT 0x40

void trace_esp_mem_writeb(uint32_t saddr, uint8_t old_val, uint64_t new_val);
void trace_esp_mem_writeb_cmd_nop(uint64_t val);
void trace_esp_mem_writeb_cmd_flush(uint64_t val);
void trace_esp_mem_writeb_cmd_reset(uint64_t val);
void trace_esp_mem_writeb_cmd_bus_reset(uint64_t val);
void trace_esp_mem_writeb_cmd_iccs(uint64_t val);
void trace_esp_mem_writeb_cmd_msgacc(uint64_t val);
void trace_esp_mem_writeb_cmd_pad(uint64_t val);
void trace_esp_mem_writeb_cmd_satn(uint64_t val);
void trace_esp_mem_writeb_cmd_rstatn(uint64_t val);
void trace_esp_mem_writeb_cmd_sel(uint64_t val);
void trace_esp_mem_writeb_cmd_selatn(uint64_t val);
void trace_esp_mem_writeb_cmd_selatns(uint64_t val);
void trace_esp_mem_writeb_cmd_ensel(uint64_t val);
void trace_esp_mem_writeb_cmd_dissel(uint64_t val);
void trace_esp_error_fifo_overrun(void);
void trace_esp_error_unhandled_command(uint64_t val);
void trace_esp_error_invalid_write(uint64_t val, uint32_t saddr);
void esp_soft_reset(ESPState *s);
void esp_raise_irq(ESPState *s);
void handle_ti(ESPState *s);
void write_response(ESPState *s);
void handle_s_without_atn(ESPState *s);
void handle_satn(ESPState *s);
void handle_satn_stop(ESPState *s);