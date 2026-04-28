#include <stdint.h>

#define EFAULT 14

struct file;
typedef uint32_t u32;
typedef int32_t s32;

struct video_tuner { int dummy; };
struct video_buffer { int dummy; };
struct video_window { int dummy; };
struct video_code { int dummy; };
struct video_audio { int dummy; };

struct v4l2_format { int dummy; };
struct v4l2_buffer { int dummy; };
struct v4l2_framebuffer { int dummy; };
struct v4l2_input { int dummy; };
struct v4l2_standard { int dummy; };
struct v4l2_ext_controls { int dummy; };

typedef struct {
    unsigned long seg;
} mm_segment_t;

#define __user
#define KERNEL_DS ((mm_segment_t){0})

/* Define unique values for all IOCTL commands */
#define VIDIOCGTUNER32   0x1000
#define VIDIOCSTUNER32   0x1001
#define VIDIOCGWIN32     0x1002
#define VIDIOCSWIN32     0x1003
#define VIDIOCGFBUF32    0x1004
#define VIDIOCSFBUF32    0x1005
#define VIDIOCGFREQ32    0x1006
#define VIDIOCSFREQ32    0x1007
#define VIDIOCSMICROCODE32 0x1008
#define VIDIOC_G_FMT32   0x1009
#define VIDIOC_S_FMT32   0x1010
#define VIDIOC_QUERYBUF32 0x1011
#define VIDIOC_G_FBUF32  0x1012
#define VIDIOC_S_FBUF32  0x1013
#define VIDIOC_QBUF32    0x1014
#define VIDIOC_DQBUF32   0x1015
#define VIDIOC_ENUMSTD32 0x1016
#define VIDIOC_ENUMINPUT32 0x1017
#define VIDIOC_TRY_FMT32 0x1018
#define VIDIOC_G_EXT_CTRLS32 0x1019
#define VIDIOC_S_EXT_CTRLS32 0x1020
#define VIDIOC_TRY_EXT_CTRLS32 0x1021
#define VIDIOC_OVERLAY32 0x1022
#define VIDIOC_OVERLAY32_OLD 0x1023
#define VIDIOC_STREAMON32 0x1024
#define VIDIOC_STREAMOFF32 0x1025
#define VIDIOC_G_INPUT32 0x1026
#define VIDIOC_S_INPUT32 0x1027
#define VIDIOC_G_OUTPUT32 0x1028
#define VIDIOC_S_OUTPUT32 0x1029

#define VIDIOCGTUNER     0x2000
#define VIDIOCSTUNER     0x2001
#define VIDIOCGWIN       0x2002
#define VIDIOCSWIN       0x2003
#define VIDIOCGFBUF      0x2004
#define VIDIOCSFBUF      0x2005
#define VIDIOCGFREQ      0x2006
#define VIDIOCSFREQ      0x2007
#define VIDIOCSMICROCODE 0x2008
#define VIDIOC_G_FMT     0x2009
#define VIDIOC_S_FMT     0x2010
#define VIDIOC_QUERYBUF  0x2011
#define VIDIOC_G_FBUF    0x2012
#define VIDIOC_S_FBUF    0x2013
#define VIDIOC_QBUF      0x2014
#define VIDIOC_DQBUF     0x2015
#define VIDIOC_ENUMSTD   0x2016
#define VIDIOC_ENUMINPUT 0x2017
#define VIDIOC_TRY_FMT   0x2018
#define VIDIOC_G_EXT_CTRLS 0x2019
#define VIDIOC_S_EXT_CTRLS 0x2020
#define VIDIOC_TRY_EXT_CTRLS 0x2021
#define VIDIOC_OVERLAY   0x2022
#define VIDIOC_STREAMON  0x2023
#define VIDIOC_STREAMOFF 0x2024
#define VIDIOC_G_INPUT   0x2025
#define VIDIOC_S_INPUT   0x2026
#define VIDIOC_G_OUTPUT  0x2027
#define VIDIOC_S_OUTPUT  0x2028

static inline void *compat_ptr(unsigned long uptr) { return (void *)uptr; }
static inline mm_segment_t get_fs(void) { return (mm_segment_t){0}; }
static inline void set_fs(mm_segment_t fs) { }
static inline long native_ioctl(struct file *file, unsigned int cmd, unsigned long arg) { return 0; }

static inline int get_user(int val, int __user *ptr) { return 0; }
static inline int put_user(int val, int __user *ptr) { return 0; }

static inline int get_video_tuner32(struct video_tuner *vt, void __user *up) { return 0; }
static inline int get_video_buffer32(struct video_buffer *vb, void __user *up) { return 0; }
static inline int get_video_window32(struct video_window *vw, void __user *up) { return 0; }
static inline int get_microcode32(struct video_code *vc, void __user *up) { return 0; }
static inline int get_v4l2_format32(struct v4l2_format *v2f, void __user *up) { return 0; }
static inline int get_v4l2_buffer32(struct v4l2_buffer *v2b, void __user *up) { return 0; }
static inline int get_v4l2_framebuffer32(struct v4l2_framebuffer *v2fb, void __user *up) { return 0; }
static inline int get_v4l2_standard32(struct v4l2_standard *v2s, void __user *up) { return 0; }
static inline int get_v4l2_input32(struct v4l2_input *v2i, void __user *up) { return 0; }
static inline int get_v4l2_ext_controls32(struct v4l2_ext_controls *v2ecs, void __user *up) { return 0; }
static inline int put_video_tuner32(struct video_tuner *vt, void __user *up) { return 0; }
static inline int put_video_window32(struct video_window *vw, void __user *up) { return 0; }
static inline int put_video_buffer32(struct video_buffer *vb, void __user *up) { return 0; }
static inline int put_v4l2_framebuffer32(struct v4l2_framebuffer *v2fb, void __user *up) { return 0; }
static inline int put_v4l2_format32(struct v4l2_format *v2f, void __user *up) { return 0; }
static inline int put_v4l2_buffer32(struct v4l2_buffer *v2b, void __user *up) { return 0; }
static inline int put_v4l2_standard32(struct v4l2_standard *v2s, void __user *up) { return 0; }
static inline int put_v4l2_input32(struct v4l2_input *v2i, void __user *up) { return 0; }
static inline int put_v4l2_ext_controls32(struct v4l2_ext_controls *v2ecs, void __user *up) { return 0; }