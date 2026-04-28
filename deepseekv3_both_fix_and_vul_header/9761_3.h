#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#define MAX_CONTROL_COUNT 1024
#define GFP_KERNEL 0
#define KERN_ERR ""

struct snd_kcontrol_volatile {
    unsigned int access;
};

struct snd_kcontrol {
    unsigned int count;
    struct snd_kcontrol_volatile *vd;
};

static inline int snd_BUG_ON(int cond) {
    if (cond) {
        fprintf(stderr, "BUG at %s:%d\n", __FILE__, __LINE__);
        abort();
    }
    return 0;
}

static inline void snd_printk(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
}

static inline void *kzalloc(size_t size, int flags) {
    void *ptr = malloc(size);
    if (ptr) memset(ptr, 0, size);
    return ptr;
}