#include <stdbool.h>
#include <stddef.h>
#include <sys/ioctl.h>

#define _IOC_DIR(nr) (((nr) >> _IOC_DIRSHIFT) & _IOC_DIRMASK)
#define _IOC_SIZE(nr) (((nr) >> _IOC_SIZESHIFT) & _IOC_SIZEMASK)
#define _IOC_NONE 0U

#define GFP_KERNEL 0
#define ENOMEM 12
#define EFAULT 14
#define ENOTTY 25
#define ENOIOCTLCMD 515
#define EINVAL 22

#define VIDIOC_DQBUF 0
#define VIDIOC_QBUF 0

struct file;
struct v4l2_buffer {
    int minor;
};
struct video_device {
    int minor;
};

typedef long (*v4l2_kioctl)(struct file *file, unsigned int cmd, void *arg);

#define __user
#define __force

extern long video_translate_cmd(unsigned int orig_cmd);
extern long video_get_user(void *arg, void *parg, unsigned int cmd, unsigned int orig_cmd, bool *always_copy);
extern long check_array_args(unsigned int cmd, void *parg, size_t *array_size, void **user_ptr, void ***kernel_ptr);
extern bool in_compat_syscall(void);
extern long v4l2_compat_get_array_args(struct file *file, void *mbuf, void *user_ptr, size_t array_size, unsigned int orig_cmd, void *parg);
extern long v4l2_compat_put_array_args(struct file *file, void *user_ptr, void *mbuf, size_t array_size, unsigned int orig_cmd, void *parg);
extern long video_put_user(void *arg, void *parg, unsigned int cmd, unsigned int orig_cmd);
extern struct video_device *video_devdata(struct file *file);
extern void trace_v4l2_dqbuf(unsigned int minor, void *buf);
extern void trace_v4l2_qbuf(unsigned int minor, void *buf);
extern void *kvmalloc(size_t size, int flags);
extern void kvfree(const void *addr);
extern unsigned long copy_from_user(void *to, const void *from, unsigned long n);
extern unsigned long copy_to_user(void *to, const void *from, unsigned long n);