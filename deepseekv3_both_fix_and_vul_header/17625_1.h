#include <stdint.h>
#include <string.h>

#define DFU_GETSTATUS 0
#define DFU_GETSTATE 1
#define DFU_ABORT 2
#define DFU_CLRSTATUS 3
#define DFU_DNLOAD 4
#define DFU_UPLOAD 5
#define DFU_DETACH 6

#define USB_DFU_MAX_XFER_SIZE 1024
#define DT_FLASH_AREA_IMAGE_1_ID 1

#define EINVAL 22
#define EIO 5

#define LOG_DBG(...)
#define LOG_ERR(...)
#define LOG_WRN(...)

typedef int32_t s32_t;
typedef uint8_t u8_t;
typedef uint32_t u32_t;

enum dfu_state {
    dfuIDLE,
    dfuDNBUSY,
    dfuDNLOAD_IDLE,
    dfuMANIFEST_SYNC,
    dfuUPLOAD_IDLE,
    dfuERROR,
    appIDLE,
    appDETACH
};

enum dfu_status {
    statusOK,
    errWRITE,
    errUNKNOWN,
    errFILE
};

struct usb_setup_packet {
    uint8_t bRequest;
    uint16_t wValue;
    uint16_t wLength;
};

struct flash_area {
    int dummy;
};

struct dfu_data_t {
    enum dfu_state state;
    enum dfu_status status;
    uint16_t bwPollTimeout;
    uint32_t flash_upload_size;
    uint32_t bytes_sent;
    uint32_t block_nr;
    int flash_area_id;
};

struct dfu_worker_t {
    enum dfu_state worker_state;
    uint16_t worker_len;
    uint8_t buf[USB_DFU_MAX_XFER_SIZE];
};

struct dfu_config_t {
    uint8_t *usb_device_description;
};

extern struct dfu_data_t dfu_data;
extern struct dfu_worker_t dfu_data_worker;
extern struct dfu_config_t dfu_config;
extern struct k_poll_signal dfu_signal;
extern struct k_work dfu_work;
extern const uint8_t dfu_mode_desc[];

static inline void sys_put_le16(uint16_t val, uint8_t *dst)
{
    dst[0] = val & 0xFF;
    dst[1] = val >> 8;
}

static int dfu_check_app_state(void) { return 0; }
static void dfu_reset_counters(void) {}
int usb_set_config(uint8_t *desc) { return 0; }
int flash_area_open(int id, const struct flash_area **fa) { return 0; }
int flash_area_read(const struct flash_area *fa, uint32_t off, void *dst, uint32_t len) { return 0; }
void flash_area_close(const struct flash_area *fa) {}
void k_poll_signal_reset(struct k_poll_signal *sig) {}
void k_poll_signal_raise(struct k_poll_signal *sig, int result) {}
void k_work_submit(struct k_work *work) {}