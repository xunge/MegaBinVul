#include <stdint.h>
#include <assert.h>
#include <stddef.h>

#define MODE_SELECT 0x15
#define GOOD 0
#define SCSI_DISK_QUIRK_MODE_PAGE_VENDOR_SPECIFIC_APPLE 0
#define BLOCK_ACCT_FLUSH 0
#define INVALID_PARAM 0
#define INVALID_PARAM_LEN 0
#define INVALID_FIELD 0

#define SENSE_CODE(code) (code)
#define DO_UPCAST(type, field, dev) \
    ((type *)((char *)(dev) - offsetof(type, field)))

typedef struct SCSIRequest {
    struct {
        uint8_t buf[256];
        int xfer;
    } cmd;
    void *dev;
    void *aiocb;
} SCSIRequest;

typedef struct BlockAcctCookie {
    int dummy;
} BlockAcctCookie;

typedef struct BlockAIOCB {
    int dummy;
} BlockAIOCB;

typedef struct BlockBackend {
    int dummy;
} BlockBackend;

typedef struct BlockAcctStats {
    int dummy;
} BlockAcctStats;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    BlockAcctCookie acct;
    BlockAIOCB *aiocb;
} SCSIDiskReq;

typedef struct {
    BlockBackend *blk;
} SCSIDiskConf;

typedef struct {
    int blocksize;
    SCSIDiskConf conf;
    void *dev;
} SCSIDiskQdev;

typedef struct SCSIDiskState {
    SCSIDiskQdev qdev;
    int quirks;
} SCSIDiskState;

static inline uint16_t lduw_be_p(const uint8_t *p) {
    return (p[0] << 8) | p[1];
}

static inline int mode_select_pages(SCSIDiskReq *r, uint8_t *p, int len, int pass) { return 0; }
static inline void scsi_check_condition(SCSIDiskReq *r, int sense_code) {}
static inline void scsi_req_complete(SCSIRequest *req, int status) {}
static inline void scsi_req_ref(SCSIRequest *req) {}
static inline void scsi_aio_complete(void *opaque, int ret) {}
static inline void trace_scsi_disk_mode_select_set_blocksize(int blocksize) {}
static inline int blk_enable_write_cache(BlockBackend *blk) { return 0; }
static inline BlockAcctStats *blk_get_stats(BlockBackend *blk) { return NULL; }
static inline void block_acct_start(BlockAcctStats *stats, BlockAcctCookie *cookie,
                                  int64_t bytes, int type) {}
static inline BlockAIOCB *blk_aio_flush(BlockBackend *blk,
                                      void (*cb)(void *opaque, int ret),
                                      void *opaque) { return NULL; }