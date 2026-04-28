#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define REPORT_TYPE_LEDS 0x01
#define REPORT_ID_DJ_SHORT 0x20
#define DJREPORT_SHORT_LENGTH 32

typedef unsigned char u8;
typedef unsigned short __u8;

struct hid_device {
    void *driver_data;
};

struct dj_device {
    struct dj_receiver_dev *dj_receiver_dev;
    unsigned char device_index;
};

struct dj_receiver_dev {
    struct hid_device *hdev;
};

#define GFP_ATOMIC 0
#define ENOMEM 12
#define EINVAL 22

void *kzalloc(size_t size, int flags);
void kfree(void *ptr);
int hid_hw_raw_request(struct hid_device *hdev, unsigned char reportnum, u8 *buf, size_t count, unsigned char report_type, int reqtype);