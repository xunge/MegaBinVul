#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int32_t __s32;
typedef uint8_t __u8;

struct hid_device;
struct hid_usage {
    uint32_t hid;
};

struct hid_field {
    unsigned report_count;
    unsigned report_offset;
    unsigned report_size;
    __s32 logical_minimum;
    __s32 logical_maximum;
    unsigned flags;
    unsigned maxusage;
    struct hid_usage *usage;
    __s32 *value;
};

#define HID_MAIN_ITEM_VARIABLE 0x0001
#define HID_UP_KEYBOARD 0x00010000
#define GFP_ATOMIC 0

#define kmalloc(size, flags) malloc(size)
#define kfree(ptr) free(ptr)

static __s32 hid_field_extract(struct hid_device *hid, __u8 *data, unsigned offset, unsigned size);
static void hid_process_event(struct hid_device *hid, struct hid_field *field, struct hid_usage *usage, __s32 value, int interrupt);
static int search(__s32 *array, __s32 value, unsigned count);
static __s32 snto32(uint32_t value, unsigned n);