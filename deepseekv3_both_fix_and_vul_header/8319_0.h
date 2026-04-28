#include <stdint.h>
#include <stdbool.h>

#define ESP_CMDBUF_SZ 32
#define TI_BUFSZ 32

typedef struct ESPState {
    uint8_t wregs[256];
    uint8_t rregs[256];
    uint8_t cmdbuf[ESP_CMDBUF_SZ];
    uint8_t ti_buf[TI_BUFSZ];
    uint32_t cmdlen;
    uint32_t ti_size;
    uint32_t ti_wptr;
    bool do_cmd;
    bool dma;
    bool tchi_written;
} ESPState;

enum {
    ESP_TCHI,
    ESP_TCLO,
    ESP_TCMID,
    ESP_FIFO,
    ESP_CMD,
    ESP_WBUSID,
    ESP_WSYNO,
    ESP_CFG1,
    ESP_CFG2,
    ESP_CFG3,
    ESP_RES3,
    ESP_RES4,
    ESP_WCCF,
    ESP_WTEST,
    ESP_RSTAT,
    ESP_RINTR,
    ESP_RSEQ,
    ESP_RFLAGS
};

enum {
    STAT_TC,
    STAT_MI
};

enum {
    INTR_FC,
    INTR_RST,
    INTR_DC
};

enum {
    CMD_DMA,
    CMD_CMD,
    CMD_NOP,
    CMD_FLUSH,
    CMD_RESET,
    CMD_BUSRESET,
    CMD_TI,
    CMD_ICCS,
    CMD_MSGACC,
    CMD_PAD,
    CMD_SATN,
    CMD_RSTATN,
    CMD_SEL,
    CMD_SELATN,
    CMD_SELATNS,
    CMD_ENSEL,
    CMD_DISSEL
};

enum {
    CFG1_RESREPT
};

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