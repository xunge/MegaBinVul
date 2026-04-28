#include <stddef.h>
#include <stdint.h>

#define ENODEV 19
#define EPERM 1
#define EFAULT 14
#define ENOMEM 12
#define FBINFO_STATE_RUNNING 0
#define GFP_KERNEL 0
#define PAGE_SIZE 4096

typedef int64_t loff_t;
typedef size_t ssize_t;
typedef uint32_t u32;
typedef uint8_t u8;
#define __user
#define __iomem

struct fb_fix_screeninfo {
    unsigned long smem_len;
};

struct fb_ops {
    void (*fb_sync)(void *info);
};

struct fb_info {
    void *screen_base;
    unsigned long screen_size;
    struct fb_fix_screeninfo fix;
    struct fb_ops *fbops;
    int state;
};

static inline u32 fb_readl(const volatile void *addr) { return 0; }
static inline u8 fb_readb(const volatile void *addr) { return 0; }
static inline u32 big_swap(u32 val) { return val; }
static inline void *kmalloc(size_t size, int flags) { return NULL; }
static inline void kfree(void *ptr) {}
static inline int copy_to_user(void *to, const void *from, unsigned long n) { return 0; }