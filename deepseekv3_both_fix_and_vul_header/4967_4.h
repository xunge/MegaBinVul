#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

typedef uint8_t u8;

#define DJ_DEVICE_INDEX_MIN 0
#define DJ_DEVICE_INDEX_MAX 6
#define REPORT_ID_DJ_SHORT 0x20
#define REPORT_TYPE_NOTIF_DEVICE_PAIRED 0x01
#define REPORT_TYPE_NOTIF_DEVICE_UNPAIRED 0x02
#define REPORT_TYPE_NOTIF_CONNECTION_STATUS 0x03
#define CONNECTION_STATUS_PARAM_STATUS 0x00
#define STATUS_LINKLOSS 0x01

struct hid_device {
    struct {
        int dummy;
    } dev;
    void* driver_data;
};

struct hid_report;

struct dj_receiver_dev {
    int lock;
};

struct dj_report {
    u8 device_index;
    u8 report_id;
    u8 report_type;
    u8 report_params[32];
};

static inline void* hid_get_drvdata(struct hid_device *hdev) {
    return hdev ? hdev->driver_data : NULL;
}

static inline void dbg_hid(const char *fmt, ...) {}

static inline void dev_err(void *dev, const char *fmt, ...) {}

static inline void spin_lock_irqsave(int *lock, unsigned long flags) {}

static inline void spin_unlock_irqrestore(int *lock, unsigned long flags) {}

static inline void logi_dj_recv_queue_notification(struct dj_receiver_dev *djrcv_dev,
                                                 struct dj_report *dj_report) {}

static inline void logi_dj_recv_forward_null_report(struct dj_receiver_dev *djrcv_dev,
                                                  struct dj_report *dj_report) {}

static inline void logi_dj_recv_forward_report(struct dj_receiver_dev *djrcv_dev,
                                             struct dj_report *dj_report) {}