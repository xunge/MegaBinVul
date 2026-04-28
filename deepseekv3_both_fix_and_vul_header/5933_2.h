#include <string.h>
#include <stdint.h>

#define MAX_RDS_PS_NAME 8
#define MAX_RDS_RADIO_TEXT 64
#define V4L2_CID_RDS_TX_PS_NAME 1
#define V4L2_CID_RDS_TX_RADIO_TEXT 2
#define ERANGE 34
#define EFAULT 14
#define EINVAL 22

typedef int32_t s32;

struct v4l2_subdev {
    // Minimal definition to make it complete
    int dummy;
};

struct si4713_device {
    struct v4l2_subdev sd;
};

struct v4l2_ext_control {
    uint32_t id;
    uint32_t size;
    char *string;
};

struct v4l2_queryctrl {
    uint32_t id;
    uint32_t step;
};

static inline int copy_from_user(void *to, const void *from, unsigned long n) {
    memcpy(to, from, n);
    return 0;
}