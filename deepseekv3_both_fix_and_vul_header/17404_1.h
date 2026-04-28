#include <stddef.h>
#include <stdbool.h>
#include <string.h>

#define VBG_IOCTL_HDR_VERSION 0
#define SZ_16M (16 * 1024 * 1024)
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14
#define E2BIG 7

struct file {
    void *private_data;
};

struct vbg_session;
struct vbg_ioctl_hdr {
    unsigned int version;
    size_t size_in;
    size_t size_out;
};

#define VBG_IOCTL_HDR_TYPE_DEFAULT 0
#define IOCSIZE_MASK 0x3FFF
#define VBG_IOCTL_VMMDEV_REQUEST(x) (0)
#define VBG_IOCTL_VMMDEV_REQUEST_BIG (0)

#define GFP_KERNEL 0

#define max(a, b) ((a) > (b) ? (a) : (b))

void *vbg_req_alloc(size_t size, int type);
void vbg_req_free(void *buf, size_t size);
int vbg_core_ioctl(struct vbg_session *session, unsigned int req, void *buf);
void vbg_debug(const char *fmt, ...);
int copy_from_user(void *to, const void *from, unsigned long n);
int copy_to_user(void *to, const void *from, unsigned long n);
void *kmalloc(size_t size, int flags);
void kfree(void *ptr);

#define _IOC_SIZE(nr) ((nr) >> 16) & IOCSIZE_MASK