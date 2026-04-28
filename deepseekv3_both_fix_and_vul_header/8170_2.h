#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUF_SIZE 24
#define GFP_KERNEL 0
#define ENOMEM 12
#define V4L2_BUF_TYPE_SDR_CAPTURE 10
#define VB2_MMAP 1
#define VB2_USERPTR 2
#define VB2_READ 4
#define V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC 0x0002
#define VFL_TYPE_SDR 13
#define V4L2_CID_RF_TUNER_LNA_GAIN_AUTO 0x0100
#define V4L2_CID_RF_TUNER_LNA_GAIN 0x0101
#define V4L2_CID_RF_TUNER_MIXER_GAIN_AUTO 0x0102
#define V4L2_CID_RF_TUNER_MIXER_GAIN 0x0103
#define V4L2_CID_RF_TUNER_IF_GAIN 0x0104
#define CMD_BOARD_ID_READ 0
#define CMD_VERSION_STRING_READ 1

typedef uint8_t u8;
typedef uint32_t u32;
typedef int32_t s32;

struct mutex {
    int dummy;
};

struct spinlock {
    int dummy;
};

struct list_head {
    struct list_head *next, *prev;
};

struct device {
    int dummy;
};

struct usb_device {
    int dummy;
};

struct usb_interface {
    struct device dev;
};

struct usb_device_id {
    int dummy;
};

struct vb2_queue {
    unsigned int type;
    unsigned int io_modes;
    void *drv_priv;
    size_t buf_struct_size;
    const void *ops;
    const void *mem_ops;
    unsigned int timestamp_flags;
    void *lock;
};

struct video_device {
    struct vb2_queue *queue;
    void *v4l2_dev;
    void *lock;
};

struct v4l2_device {
    void (*release)(void);
    void *ctrl_handler;
};

struct v4l2_ctrl_handler {
    int error;
};

struct v4l2_ctrl {
    int dummy;
};

struct vb2_v4l2_buffer {
    int dummy;
};

struct v4l2_frequency_band {
    unsigned int rangelow;
};

struct airspy_format {
    u32 pixelformat;
    unsigned int buffersize;
};

struct airspy {
    struct usb_device *udev;
    struct device *dev;
    struct mutex v4l2_lock;
    struct mutex vb_queue_lock;
    struct spinlock queued_bufs_lock;
    struct list_head queued_bufs;
    unsigned int f_adc;
    unsigned int f_rf;
    u32 pixelformat;
    unsigned int buffersize;
    struct vb2_queue vb_queue;
    struct video_device vdev;
    struct v4l2_device v4l2_dev;
    struct v4l2_ctrl_handler hdl;
    struct v4l2_ctrl *lna_gain_auto;
    struct v4l2_ctrl *lna_gain;
    struct v4l2_ctrl *mixer_gain_auto;
    struct v4l2_ctrl *mixer_gain;
    struct v4l2_ctrl *if_gain;
};

struct airspy_frame_buf {
    struct vb2_v4l2_buffer vb;
    struct list_head list;
};

static struct v4l2_frequency_band bands[] = {
    { .rangelow = 24000000 }
};

static struct v4l2_frequency_band bands_rf[] = {
    { .rangelow = 24000000 }
};

static struct airspy_format formats[] = {
    { .pixelformat = 0, .buffersize = 0x10000 }
};

static const struct {
    int dummy;
} airspy_vb2_ops;

static const struct {
    int dummy;
} airspy_ctrl_ops;

static struct video_device airspy_template;

static const void *vb2_vmalloc_memops;

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void mutex_init(struct mutex *lock) {}
static inline void spin_lock_init(struct spinlock *lock) {}
static inline void INIT_LIST_HEAD(struct list_head *list) { list->next = list; list->prev = list; }
static inline struct usb_device *interface_to_usbdev(struct usb_interface *intf) { return NULL; }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}
static inline void dev_info(struct device *dev, const char *fmt, ...) {}
static inline void dev_notice(struct device *dev, const char *fmt, ...) {}
static inline int vb2_queue_init(struct vb2_queue *q) { return 0; }
static inline void video_set_drvdata(struct video_device *vdev, void *data) {}
static inline int v4l2_device_register(struct device *dev, struct v4l2_device *v4l2_dev) { return 0; }
static inline void v4l2_ctrl_handler_init(struct v4l2_ctrl_handler *hdl, int nr_of_controls_hint) {}
static inline struct v4l2_ctrl *v4l2_ctrl_new_std(struct v4l2_ctrl_handler *hdl, const void *ops, u32 id, s32 min, s32 max, s32 step, s32 def) { return NULL; }
static inline void v4l2_ctrl_auto_cluster(int ncontrols, struct v4l2_ctrl **controls, u8 manual_val, bool set_volatile) {}
static inline void v4l2_ctrl_handler_setup(struct v4l2_ctrl_handler *hdl) {}
static inline int video_register_device(struct video_device *vdev, int type, int nr) { return 0; }
static inline const char *video_device_node_name(struct video_device *vdev) { return ""; }
static inline void v4l2_ctrl_handler_free(struct v4l2_ctrl_handler *hdl) {}
static inline void v4l2_device_unregister(struct v4l2_device *v4l2_dev) {}
static inline int airspy_ctrl_msg(struct airspy *s, int cmd, int value, int index, void *buf, int len) { return 0; }
static inline void airspy_video_release(void) {}