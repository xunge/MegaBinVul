#include <linux/version.h>
#include <linux/videodev2.h>
#include <linux/string.h>
#include <linux/types.h>
#include <stdbool.h>
#include <stdio.h>

struct file;

struct video_device {
    void *device_caps;
};

struct v4l2_loopback_device {
    char card_label[32];
    struct video_device *vdev;
    bool announce_all_caps;
    bool ready_for_capture;
    bool ready_for_output;
};

struct v4l2loopback_private {
    int device_nr;
};

#define V4L2LOOPBACK_VERSION_CODE 0

static inline struct v4l2_loopback_device *v4l2loopback_getdevice(struct file *file) { return NULL; }
static inline void *video_get_drvdata(struct video_device *vdev) { return NULL; }