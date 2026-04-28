#include <stddef.h>

struct video_code {
    char loadwhat[32];
    int datasize;
    void *data;
};

struct video_code32 {
    char loadwhat[32];
    int datasize;
    void *data;
};

#define VERIFY_READ 0
#define __user
#define EFAULT 14

static inline int access_ok(int type, const void *addr, unsigned long size) { return 1; }
static inline int copy_from_user(void *to, const void *from, unsigned long n) { return 0; }
static inline int get_user(int *val, const int *addr) { *val = *addr; return 0; }