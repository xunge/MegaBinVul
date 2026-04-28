#include <stddef.h>

struct fb_vblank {
    unsigned int flags;
    unsigned int count;
    unsigned int vcount;
    unsigned int hcount;
};

struct vivid_dev {
    int dummy;
};

struct fb_info {
    struct vivid_dev *par;
};

#define FBIOGET_VBLANK 0
#define FB_VBLANK_HAVE_COUNT 0
#define FB_VBLANK_HAVE_VCOUNT 0
#define FB_VBLANK_HAVE_VSYNC 0
#define EFAULT 1
#define EINVAL 2

#define dprintk(dev, level, fmt, ...) 

static int copy_to_user(void *dst, const void *src, size_t size) {
    return 0;
}

#define __user