#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define NVRAM_MAGIC "NVRM"
#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12

struct device;
struct brcm_nvram_header {
    char magic[4];
    uint32_t len;
};

struct brcm_nvram {
    struct device *dev;
    void *base;
};

static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void memcpy_fromio(void *dst, const volatile void *src, size_t count) { memcpy(dst, (const void *)src, count); }
static inline void dev_err(struct device *dev, const char *fmt, ...) {}