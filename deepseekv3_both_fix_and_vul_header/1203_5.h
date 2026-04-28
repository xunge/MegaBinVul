#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define V4L2LOOPBACK_SIZE_MIN_WIDTH 48
#define V4L2LOOPBACK_SIZE_MIN_HEIGHT 32
#define V4L2LOOPBACK_DEFAULT_EXCLUSIVECAPS 0
#define DEFAULT_FROM_CONF(field, condition, default_val) \
    (conf && conf->field condition) ? conf->field : default_val

#define GFP_KERNEL 0
#define ENOMEM 12
#define EEXIST 17
#define EINVAL 22
#define ENOSPC 28
#define EFAULT 14

#define KERN_ERR ""
#define KERN_INFO ""

#define V4L2_COLORSPACE_SRGB 1
#define V4L2_FIELD_NONE 1
#define VFL_TYPE_VIDEO 1

struct list_head {
    struct list_head *next, *prev;
};

struct v4l2_loopback_config {
    int announce_all_caps;
    int capture_nr;
    int output_nr;
    char *card_label;
    int max_width;
    int max_height;
    int max_buffers;
    int max_openers;
};

struct v4l2_buffer {
    struct list_head list_head;
};

struct v4l2_ctrl_handler {
    int error;
};

struct v4l2_loopback_device {
    struct {
        char name[32];
        struct v4l2_ctrl_handler *ctrl_handler;
    } v4l2_dev;
    struct {
        char name[32];
        int num;
        void *v4l2_dev;
    } *vdev;
    struct v4l2_ctrl_handler ctrl_handler;
    char card_label[32];
    int max_width;
    int max_height;
    int max_openers;
    int buffers_number;
    int used_buffers;
    struct v4l2_buffer buffers[32];
    int write_position;
    bool announce_all_caps;
    struct {
        int width;
        int height;
        unsigned int pixelformat;
        int colorspace;
        int field;
        unsigned int sizeimage;
    } pix_format;
    unsigned long buffer_size;
    void *image;
    unsigned long imagesize;
    struct {
        void *function;
    } sustain_timer, timeout_timer;
    int reread_count;
    unsigned long timeout_jiffies;
    void *timeout_image;
    bool timeout_happened;
    int lock;
    struct list_head outbufs_list;
    int bufpos2index[32];
    int open_count;
    bool ready_for_capture;
    bool ready_for_output;
    int keep_format;
    int sustain_framerate;
    struct {
        struct {
            int numerator;
            int denominator;
        } timeperframe;
    } capture_param;
    int read_event;
};

struct v4l2loopback_private {
    int device_nr;
};

struct v4l2loopback_format {
    unsigned int fourcc;
};

static struct v4l2loopback_format formats[] = {
    {0}
};

static void *v4l2loopback_index_idr;

static void sustain_timer_clb(unsigned long data) {}
static void timeout_timer_clb(unsigned long data) {}

static struct {
    int keepformat;
    int sustainframerate;
    int timeout;
    int timeoutimageio;
} v4l2loopback_ctrl_keepformat, v4l2loopback_ctrl_sustainframerate,
  v4l2loopback_ctrl_timeout, v4l2loopback_ctrl_timeoutimageio;

static inline void *idr_find(void *idr, int id) { return NULL; }
static inline int idr_alloc(void *idr, void *ptr, int start, int end, int gfp) { return 0; }
static inline void idr_remove(void *idr, int id) {}
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void printk(const char *fmt, ...) {}
static inline void dprintk(const char *fmt, ...) {}
static inline void MARK(void) {}
static inline int v4l2_device_register(void *a, void *b) { return 0; }
static inline void *video_device_alloc(void) { return NULL; }
static inline void video_set_drvdata(void *a, void *b) {}
static inline void *video_get_drvdata(void *a) { return NULL; }
static inline void init_vdev(void *a, int b) {}
static inline void init_capture_param(void *a) {}
static inline int set_timeperframe(void *a, void *b) { return 0; }
static inline void spin_lock_init(void *a) {}
static inline void INIT_LIST_HEAD(struct list_head *a) { a->next = a->prev = a; }
static inline int list_empty(struct list_head *a) { return a->next == a; }
static inline void list_add_tail(struct list_head *a, struct list_head *b) {}
static inline void atomic_set(void *a, int b) {}
static inline void setup_timer(void *a, void *b, int c) {}
static inline int v4l2_ctrl_handler_init(struct v4l2_ctrl_handler *a, int b) { return 0; }
static inline void v4l2_ctrl_new_custom(struct v4l2_ctrl_handler *a, void *b, void *c) {}
static inline int v4l2_ctrl_handler_setup(struct v4l2_ctrl_handler *a) { return 0; }
static inline unsigned long PAGE_ALIGN(unsigned long a) { return a; }
static inline int allocate_buffers(void *a) { return 0; }
static inline void init_waitqueue_head(void *a) {}
static inline int video_register_device(void *a, int b, int c) { return 0; }
static inline void v4l2loopback_create_sysfs(void *a) {}
static inline void video_device_release(void *a) {}
static inline void v4l2_ctrl_handler_free(struct v4l2_ctrl_handler *a) {}
static inline void v4l2_device_unregister(void *a) {}

/* Default values for configuration parameters */
static const int max_width = 640;
static const int max_height = 480;
static const int max_buffers = 2;
static const int max_openers = 1;