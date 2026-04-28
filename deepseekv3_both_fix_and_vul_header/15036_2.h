#include <stdint.h>
#include <limits.h>
#include <stdlib.h>

typedef uint32_t __u32;
typedef int gfp_t;

struct sctp_auth_bytes {
    __u32 len;
    int refcnt;
};

#define atomic_set(ptr, val) (*(ptr) = (val))
#define kmalloc(size, flags) malloc(size)
#define SCTP_DBG_OBJCNT_INC(x)