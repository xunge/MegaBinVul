#include <stdint.h>
#include <string.h>

struct fb_info {
    void *par;
};

struct ivtv {
    int is_50hz;
    int is_60hz;
    int last_vsync_field;
    int vsync_waitq;
};

struct fb_vblank {
    unsigned int flags;
    unsigned int count;
    unsigned int vcount;
    unsigned int hcount;
};

struct ivtvfb_dma_frame {
    void *source;
    int dest_offset;
    int count;
};

#define DEFINE_WAIT(name) int name
#define TASK_INTERRUPTIBLE 1
#define FBIOGET_VBLANK 0x4600
#define FBIO_WAITFORVSYNC 0x4601
#define IVTVFB_IOC_DMA_FRAME 0x4602
#define FB_VBLANK_HAVE_COUNT 0x01
#define FB_VBLANK_HAVE_VCOUNT 0x02
#define FB_VBLANK_HAVE_VSYNC 0x04
#define FB_VBLANK_VSYNCING 0x08
#define IVTV_REG_DEC_LINE_FIELD 0
#define EFAULT 14
#define ETIMEDOUT 110
#define EINVAL 22

typedef uint32_t u32;

static inline unsigned int read_reg(unsigned int reg) { return 0; }
static inline int copy_to_user(void *dst, const void *src, unsigned long size) { return 0; }
static inline int copy_from_user(void *dst, const void *src, unsigned long size) { return 0; }
static inline void prepare_to_wait(int *q, int *wait, int state) {}
static inline void finish_wait(int *q, int *wait) {}
static inline int schedule_timeout(int timeout) { return 0; }
static inline int msecs_to_jiffies(int msecs) { return 0; }
static int ivtvfb_prep_frame(struct ivtv *itv, int cmd, void *source, int dest_offset, int count) { return 0; }
#define IVTVFB_DEBUG_INFO(fmt, ...)

// Remove __user attribute from function calls
#define __user