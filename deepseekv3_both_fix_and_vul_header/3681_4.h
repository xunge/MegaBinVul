#include <string.h>
#include <stdlib.h>
#include <errno.h>

struct snd_kcontrol {
    void *private_data;
};

struct user_element {
    struct {
        int user_ctl_lock;
    } *card;
    void *tlv_data;
    unsigned int tlv_data_size;
};

#define EINVAL 22
#define ENXIO 6
#define ENOSPC 28
#define EFAULT 14
#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

#define __user

static inline void *memdup_user(const void *src, size_t len) {
    void *p = malloc(len);
    if (p) memcpy(p, src, len);
    return p;
}

static inline void mutex_lock(int *lock) { *lock = 1; }
static inline void mutex_unlock(int *lock) { *lock = 0; }
static inline void kfree(void *p) { free(p); }
static inline int copy_to_user(void *dst, const void *src, size_t size) {
    memcpy(dst, src, size);
    return 0;
}