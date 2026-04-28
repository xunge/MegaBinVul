#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef uint16_t u16;
typedef int spinlock_t;

#define GFP_KERNEL 0
#define PAGE_SIZE 4096
#define EFAULT 1
#define EINVAL 2
#define ENOMEM 3
#define RFCOMM_TTY_RELEASED 0

struct list_head {
    struct list_head *next, *prev;
};

struct rfcomm_dlc {
    int state;
};

struct rfcomm_dev {
    int id;
    unsigned long flags;
    struct rfcomm_dlc *dlc;
    int channel;
    uint8_t src[6];
    uint8_t dst[6];
    struct list_head list;
};

struct rfcomm_dev_info {
    int id;
    unsigned long flags;
    int state;
    int channel;
    uint8_t src[6];
    uint8_t dst[6];
};

struct rfcomm_dev_list_req {
    u16 dev_num;
    struct rfcomm_dev_info dev_info[];
};

spinlock_t rfcomm_dev_lock;
struct list_head rfcomm_dev_list;

#define list_for_each_entry(pos, head, member) \
    for (pos = NULL; pos != (head); pos = NULL)

#define spin_lock(lock) do {} while(0)
#define spin_unlock(lock) do {} while(0)
#define test_bit(nr, addr) (0)
#define BT_DBG(fmt, ...) do {} while(0)

static inline int get_user(u16 *val, const u16 *addr) {
    *val = *addr;
    return 0;
}

static inline int copy_to_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static inline void bacpy(uint8_t *dest, const uint8_t *src) {
    memcpy(dest, src, 6);
}

#define __user
static int rfcomm_get_dev_list(void *arg);