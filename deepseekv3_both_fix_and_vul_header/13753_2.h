#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>

#define GFP_KERNEL 0
#define ENOMEM (-12)
#define EINVAL (-22)
#define PCAN_UFD_CMD_BUFFER_SIZE 64
#define PCAN_UFD_LED_DEF 0
#define CAN_CTRLMODE_FD_NON_ISO 0x100
#define PCAN_USBPRO_REQ_INFO 0
#define PCAN_USBPRO_INFO_FW 1

struct device {
    struct device *parent;
};

struct net_device {
    struct device dev;
};

struct peak_usb_device {
    struct net_device *netdev;
    struct peak_usb_device *prev_siblings;
    struct {
        char *name;
        int ctrl_count;
        struct {
            int freq;
        } clock;
    } *adapter;
    struct {
        unsigned int ctrlmode;
        unsigned int ctrlmode_supported;
    } can;
    int ctrl_idx;
    unsigned int device_number;
};

struct pcan_usb_pro_fw_info {
    uint32_t hw_version;
    uint8_t fw_version[3];
    uint32_t dev_id[2];
};

struct pcan_usb_if {
    struct pcan_usb_pro_fw_info fw_info;
    uint8_t cm_ignore_count;
    struct peak_usb_device *dev[2];
};

struct pcan_usb_fd_device {
    struct peak_usb_device dev;
    struct pcan_usb_if *usb_if;
    void *cmd_buffer_addr;
};

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline uint32_t le32_to_cpu(uint32_t val) { return val; }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void dev_warn(struct device *dev, const char *fmt, ...) {}

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

static int pcan_usb_pro_send_req(struct peak_usb_device *dev, int req_type, int req_id, void *data, int data_len) { return 0; }
static int pcan_usb_fd_drv_loaded(struct peak_usb_device *dev, int loaded) { return 0; }
static void pcan_usb_fd_set_clock_domain(struct peak_usb_device *dev, int idx) {}
static void pcan_usb_fd_set_can_led(struct peak_usb_device *dev, int led_state) {}

static const int pcan_usb_fd_clk_freq[] = {8000000, 24000000, 40000000, 80000000};