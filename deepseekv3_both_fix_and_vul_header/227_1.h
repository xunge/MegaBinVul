#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define GFP_KERNEL 0

struct property {
    char *name;
    void *value;
    size_t length;
};

struct cc_workarea {
    uint32_t name_offset;
    uint32_t prop_offset;
    uint32_t prop_length;
};

static inline uint32_t be32_to_cpu(uint32_t x) {
    return ((x & 0xFF000000) >> 24) | 
           ((x & 0x00FF0000) >> 8) |
           ((x & 0x0000FF00) << 8) |
           ((x & 0x000000FF) << 24);
}

static void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static char *kstrdup(const char *s, int flags) {
    return strdup(s);
}

static void *kmemdup(const void *src, size_t len, int flags) {
    void *dst = malloc(len);
    if (dst)
        memcpy(dst, src, len);
    return dst;
}

static void dlpar_free_cc_property(struct property *prop);