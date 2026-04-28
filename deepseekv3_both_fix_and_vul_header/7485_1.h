#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define ENODEV 19
#define EFAULT 14
#define EINVAL 22
#define ENOMEM 12
#define GFP_KERNEL 0
#define WATCH_TYPE__NR 16
#define WATCH_INFO_LENGTH 0x00000001
#define BITS_PER_LONG (__CHAR_BIT__ * sizeof(long))

struct pipe_inode_info {
    struct watch_queue *watch_queue;
    void *mutex;
};

struct watch_notification_type_filter {
    uint32_t type;
    uint32_t info_filter;
    uint32_t info_mask;
    uint32_t subtype_filter[1];
};

struct watch_notification_filter {
    uint32_t nr_filters;
    uint32_t __reserved;
    struct watch_notification_type_filter filters[];
};

struct watch_type_filter {
    uint32_t type;
    uint32_t info_filter;
    uint32_t info_mask;
    uint32_t subtype_filter[1];
};

struct watch_filter {
    unsigned long type_filter[1];
    unsigned int nr_filters;
    struct watch_type_filter filters[];
};

struct watch_queue {
    struct watch_filter *filter;
};

#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-4096))
#define PTR_ERR(x) ((long)(x))
#define __user
#define __rcu
#define rcu_replace_pointer(ptr, new, cond) (new)
#define kfree_rcu(ptr, rcu) free(ptr)
#define pipe_lock(pipe) 
#define pipe_unlock(pipe) 
#define lockdep_is_held(mutex) 1

static inline void *memdup_user(const void *src, size_t len) {
    void *dst = malloc(len);
    if (dst) memcpy(dst, src, len);
    return dst;
}

static inline int copy_from_user(void *dst, const void *src, size_t len) {
    memcpy(dst, src, len);
    return 0;
}

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}

#define struct_size(p, member, n) \
    (sizeof(*(p)) + sizeof(*(p)->member) * (n))

static inline void __set_bit(int nr, volatile unsigned long *addr) {
    *addr |= (1UL << nr);
}