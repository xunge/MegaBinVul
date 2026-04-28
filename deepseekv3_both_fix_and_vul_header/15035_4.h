#include <stdlib.h>
#include <string.h>
#include <errno.h>

typedef unsigned char u8;
typedef unsigned int __u32;

struct sock;
struct dccp_so_feat {
    __u32 dccpsf_feat;
    __u32 dccpsf_len;
    u8 *dccpsf_val;
};

#define GFP_KERNEL 0
#define EFAULT 14
#define EINVAL 22
#define ENOMEM 12

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static int dccp_feat_change(void *msk, int type, __u32 feat, u8 *val, __u32 len, int flags) {
    return 0;
}
static void *dccp_msk(struct sock *sk) {
    return NULL;
}

#define __user