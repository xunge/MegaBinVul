#include <stdint.h>
#include <string.h>

#define TAG_GLOB_MAX 16

#define PREF_SIZE(x) ((x) & 0x03)
#define PREF_TAG(x) (((x) >> 2) & 0x0F)
#define PREF_TYPE(x) (((x) >> 4) & 0x03)

#define TYPE_MAIN 0
#define TYPE_GLOBAL 1
#define TYPE_LOCAL 2

#define TAG_MAIN_INPUT 8
#define TAG_MAIN_OUTPUT 9
#define TAG_MAIN_FEATURE 11
#define TAG_MAIN_COL_START 10
#define TAG_MAIN_COL_END 12

#define TAG_GLOB_USAGE 0
#define TAG_GLOB_LOG_MIN 1
#define TAG_GLOB_LOG_MAX 2
#define TAG_GLOB_PHYS_MIN 3
#define TAG_GLOB_PHYS_MAX 4
#define TAG_GLOB_UNIT_EXP 5
#define TAG_GLOB_UNIT 6
#define TAG_GLOB_REPORT_SZ 7
#define TAG_GLOB_REPORT_ID 8
#define TAG_GLOB_REPORT_CNT 9
#define TAG_GLOB_PUSH 10
#define TAG_GLOB_POP 11

#define DIGITIZER_USAGE_TILT_X 0x3D
#define DIGITIZER_USAGE_TILT_Y 0x3E
#define DIGITIZER_USAGE_TIP_PRESSURE 0x30

typedef uint8_t __u8;
typedef uint16_t __u16;
typedef uint32_t __u32;

struct device {
    // Minimal device structure definition
    int dummy;
};

struct usb_interface {
    struct device dev;
};

struct gtco {
    struct usb_interface *intf;
    __u32 usage;
    __u32 max_X;
    __u32 min_X;
    __u32 max_Y;
    __u32 min_Y;
    __u32 maxtilt_X;
    __u32 mintilt_X;
    __u32 maxtilt_Y;
    __u32 mintilt_Y;
    __u32 maxpressure;
    __u32 minpressure;
};

static inline __u16 get_unaligned_le16(const void *p)
{
    const __u8 *ptr = p;
    return ptr[0] | (ptr[1] << 8);
}

static inline __u32 get_unaligned_le32(const void *p)
{
    const __u8 *ptr = p;
    return ptr[0] | (ptr[1] << 8) | (ptr[2] << 16) | (ptr[3] << 24);
}

#define dev_dbg(dev, fmt, ...) ((void)0)