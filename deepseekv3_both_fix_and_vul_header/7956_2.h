#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define __user
#define noinline
#define GFP_KERNEL 0

#define HID_REPORT_TYPE_INPUT 1
#define HID_REPORT_ID_UNKNOWN 0

#define _IOWR(a,b,c) ((a)<<8 | (b))
#define _IOW(a,b,c) ((a)<<8 | (b))

#define HIDIOCGUCODE            _IOWR('H', 0x03, struct hiddev_usage_ref)
#define HIDIOCGUSAGE            _IOWR('H', 0x04, struct hiddev_usage_ref)
#define HIDIOCSUSAGE            _IOW('H', 0x05, struct hiddev_usage_ref)
#define HIDIOCGCOLLECTIONINDEX  _IOWR('H', 0x06, struct hiddev_usage_ref)
#define HIDIOCGUSAGES           _IOWR('H', 0x07, struct hiddev_usage_ref_multi)
#define HIDIOCSUSAGES           _IOW('H', 0x08, struct hiddev_usage_ref_multi)

#define HID_MAX_MULTI_USAGES 1024
#define ENOMEM (-1)
#define EFAULT (-2)
#define EINVAL (-3)

struct hiddev {
    struct hid_device *hid;
};

struct hid_device {
    int dummy;
};

struct hid_report {
    unsigned int maxfield;
    struct hid_field **field;
};

struct hid_field {
    unsigned int maxusage;
    unsigned int report_count;
    struct {
        uint32_t hid;
        int collection_index;
    } *usage;
    int32_t *value;
};

struct hiddev_usage_ref {
    uint32_t report_type;
    uint32_t report_id;
    uint32_t field_index;
    uint32_t usage_index;
    uint32_t usage_code;
    int32_t value;
};

struct hiddev_usage_ref_multi {
    struct hiddev_usage_ref uref;
    uint32_t num_values;
    int32_t values[HID_MAX_MULTI_USAGES];
};

struct hiddev_report_info {
    uint32_t report_type;
    uint32_t report_id;
};

static inline int copy_from_user(void *to, const void __user *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_to_user(void __user *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline struct hid_report *hiddev_lookup_report(struct hid_device *hid, struct hiddev_report_info *rinfo) {
    return NULL;
}

static inline struct hid_field *hiddev_lookup_usage(struct hid_device *hid, struct hiddev_usage_ref *uref) {
    return NULL;
}