#include <stdint.h>

typedef struct ESPState ESPState;
typedef struct SCSIRequest SCSIRequest;

struct ESPState {
    uint32_t dma_left;
    int do_cmd;
    uint32_t cmdlen;
    uint8_t *cmdbuf;
    uint32_t async_len;
    uint8_t *async_buf;
    int32_t ti_size;
    void (*dma_memory_read)(void *opaque, uint8_t *buf, uint32_t len);
    void (*dma_memory_write)(void *opaque, uint8_t *buf, uint32_t len);
    void *dma_opaque;
    SCSIRequest *current_req;
};

void scsi_req_continue(SCSIRequest *req);
void esp_dma_done(ESPState *s);
void trace_esp_do_dma(uint32_t cmdlen, uint32_t len);