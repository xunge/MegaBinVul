#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>

#define DO_UPCAST(type, field, dev) \
    ((type *) ((char *)(dev) - offsetof(type, field)))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define TEST_UNIT_READY 0x00
#define INQUIRY 0x12
#define MODE_SENSE 0x1a
#define MODE_SENSE_10 0x5a
#define READ_TOC 0x43
#define RESERVE 0x16
#define RESERVE_10 0x56
#define RELEASE 0x17
#define RELEASE_10 0x57
#define START_STOP 0x1b
#define ALLOW_MEDIUM_REMOVAL 0x1e
#define READ_CAPACITY_10 0x25
#define GET_CONFIGURATION 0x46
#define SERVICE_ACTION_IN_16 0x9e
#define VERIFY_10 0x2f

#define SAI_READ_CAPACITY_16 0x10

struct iovec {
    void *iov_base;
    size_t iov_len;
};

struct SCSIDevice {
    struct {
        unsigned int discard_granularity;
    } conf;
};

struct BlockDriverState;

typedef struct SCSIRequest {
    struct SCSIDevice *dev;
    struct {
        uint8_t *buf;
        uint32_t xfer;
    } cmd;
    int status;
} SCSIRequest;

typedef struct SCSIDiskReq {
    SCSIRequest req;
    struct iovec iov;
    int buflen;
} SCSIDiskReq;

typedef struct SCSIDiskState {
    struct SCSIDevice qdev;
    struct BlockDriverState *bs;
    uint64_t max_lba;
    unsigned int cluster_size;
    bool tray_open;
    bool tray_locked;
} SCSIDiskState;

static void *qemu_blockalign(struct BlockDriverState *bs, size_t size);
static int scsi_disk_emulate_inquiry(SCSIRequest *req, uint8_t *outbuf);
static int scsi_disk_emulate_mode_sense(SCSIDiskReq *r, uint8_t *outbuf);
static int scsi_disk_emulate_read_toc(SCSIRequest *req, uint8_t *outbuf);
static int scsi_disk_emulate_start_stop(SCSIDiskReq *r);
static void bdrv_get_geometry(struct BlockDriverState *bs, uint64_t *nb_sectors);
static bool bdrv_is_inserted(struct BlockDriverState *bs);
static void bdrv_lock_medium(struct BlockDriverState *bs, bool locked);
static unsigned int get_physical_block_exp(struct SCSIDevice *conf);
static void scsi_check_condition(SCSIDiskReq *r, int sense_code);

#define SENSE_CODE(code) (code)
#define NO_MEDIUM 0x3a
#define LUN_NOT_READY 0x04
#define INVALID_FIELD 0x24
#define INVALID_OPCODE 0x20
#define DPRINTF(fmt, ...)