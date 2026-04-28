#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define ARCMSR_MESSAGE_FAIL 0x0001
#define ARCMSR_API_DATA_BUFLEN 1032
#define ARCMSR_MAX_QBUFFER 4096
#define ARCMSR_MESSAGE_READ_RQBUFFER 0x0001
#define ARCMSR_MESSAGE_WRITE_WQBUFFER 0x0002
#define ARCMSR_MESSAGE_CLEAR_RQBUFFER 0x0003
#define ARCMSR_MESSAGE_CLEAR_WQBUFFER 0x0004
#define ARCMSR_MESSAGE_CLEAR_ALLQBUFFER 0x0005
#define ARCMSR_MESSAGE_RETURN_CODE_3F 0x003F
#define ARCMSR_MESSAGE_SAY_HELLO 0x0020
#define ARCMSR_MESSAGE_SAY_GOODBYE 0x0021
#define ARCMSR_MESSAGE_FLUSH_ADAPTER_CACHE 0x0022
#define ARCMSR_MESSAGE_RETURNCODE_OK 0x0000
#define ARCMSR_MESSAGE_RETURNCODE_BUS_HANG_ON 0x0001
#define ARCMSR_MESSAGE_RETURNCODE_3F 0x003F
#define FW_DEADLOCK 0xFFFFFFFF
#define ACB_F_IOPDATA_OVERFLOW 0x00000040
#define ACB_F_MESSAGE_RQBUFFER_CLEARED 0x00000001
#define ACB_F_MESSAGE_WQBUFFER_CLEARED 0x00000002
#define ACB_F_MESSAGE_WQBUFFER_READED 0x00000004
#define SCSI_SENSE_CURRENT_ERRORS 0x70
#define ILLEGAL_REQUEST 0x05
#define GFP_ATOMIC 0

struct AdapterControlBlock {
    unsigned long rqbuffer_lock;
    unsigned long wqbuffer_lock;
    unsigned int rqbuf_getIndex;
    unsigned int rqbuf_putIndex;
    unsigned int wqbuf_getIndex;
    unsigned int wqbuf_putIndex;
    uint8_t *rqbuffer;
    uint8_t *wqbuffer;
    uint32_t acb_flags;
    uint32_t fw_flag;
};

struct CMD_MESSAGE_FIELD {
    struct {
        uint32_t Length;
        uint32_t ReturnCode;
    } cmdmessage;
    uint8_t messagedatabuffer[ARCMSR_API_DATA_BUFLEN];
};

struct QBUFFER {
    uint8_t data[ARCMSR_MAX_QBUFFER];
};

struct SENSE_DATA {
    uint8_t ErrorCode;
    uint8_t Valid;
    uint8_t SenseKey;
    uint8_t AdditionalSenseLength;
    uint8_t AdditionalSenseCode;
};

struct scsi_cmnd {
    uint8_t cmnd[16];
    void *sense_buffer;
};

struct scatterlist {
    unsigned long offset;
    unsigned int length;
    void *page_link;
};

#define CIRC_CNT(head,tail,size) (((head) - (tail)) & ((size)-1))
#define CIRC_CNT_TO_END(head,tail,size) \
    (CIRC_CNT((head),(tail),(size)) + 1)

static inline void *kmap_atomic(void *page) { return page; }
static inline void kunmap_atomic(void *addr) {}
static inline void *sg_page(struct scatterlist *sg) { return sg->page_link; }
static inline unsigned int scsi_sg_count(struct scsi_cmnd *cmd) { return 0; }
static inline struct scatterlist *scsi_sglist(struct scsi_cmnd *cmd) { return NULL; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void spin_lock_irqsave(unsigned long *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(unsigned long *lock, unsigned long flags) {}
static inline int pr_info(const char *fmt, ...) { return 0; }
static inline struct QBUFFER *arcmsr_get_iop_rqbuffer(struct AdapterControlBlock *acb) { return NULL; }
static inline int arcmsr_Read_iop_rqbuffer_data(struct AdapterControlBlock *acb, struct QBUFFER *prbuffer) { return 0; }
static inline void arcmsr_write_ioctldata2iop(struct AdapterControlBlock *acb) {}
static inline void arcmsr_clear_iop2drv_rqueue_buffer(struct AdapterControlBlock *acb) {}
static inline void arcmsr_iop_parking(struct AdapterControlBlock *acb) {}
static inline void arcmsr_flush_adapter_cache(struct AdapterControlBlock *acb) {}

#define __iomem