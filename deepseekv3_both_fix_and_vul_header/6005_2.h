#include <stdint.h>
#include <string.h>

#define __user
#define EFAULT 14
#define COMPAT_TO_USER 0

typedef uint32_t compat_uint_t;
typedef uint16_t u_int16_t;

struct xt_target {
    int (*compat)(void*, void**, compat_uint_t*, int);
};

struct ipt_entry_target {
    union {
        struct {
            struct xt_target *target;
        } kernel;
    } u;
};

struct ipt_entry {
    u_int16_t target_offset;
    u_int16_t next_offset;
};

struct compat_ipt_entry {
    u_int16_t target_offset;
    u_int16_t next_offset;
};

#define IPT_MATCH_ITERATE(e, fn, ptr, sz) 0

static inline int copy_to_user(void *dst, const void *src, size_t size) {
    memcpy(dst, src, size);
    return 0;
}

static inline int put_user(u_int16_t val, u_int16_t *addr) {
    *addr = val;
    return 0;
}

static inline struct ipt_entry_target *ipt_get_target(struct ipt_entry *e) {
    return (struct ipt_entry_target *)((char *)e + e->target_offset);
}

static inline int xt_compat_target(struct ipt_entry_target *t, void **dstptr,
                                  compat_uint_t *size, int mode) {
    return 0;
}