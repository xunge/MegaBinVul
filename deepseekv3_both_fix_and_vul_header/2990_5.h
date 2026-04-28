#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>

typedef unsigned long compat_uptr_t;

struct video_spu_palette {
    void *palette;
    int length;
};

struct compat_video_spu_palette {
    compat_uptr_t palette;
    int length;
};

#define __user
#define EFAULT 14

static inline void *compat_alloc_user_space(size_t len) {
    return malloc(len);
}

static inline void *compat_ptr(compat_uptr_t uptr) {
    return (void *)(unsigned long)uptr;
}

static inline int get_user(compat_uptr_t *val, compat_uptr_t *addr) {
    *val = *addr;
    return 0;
}

static inline int put_user(void *ptr, void **addr) {
    *addr = ptr;
    return 0;
}

static inline int sys_ioctl(unsigned int fd, unsigned int cmd, unsigned long arg) {
    return ioctl(fd, cmd, arg);
}