#include <stdbool.h>
#include <unistd.h>

#define PAGE_SIZE 4096
#define SEC_FTR_BCCTRL_SERIALISED 0
#define SEC_FTR_COUNT_CACHE_DISABLED 0
#define COUNT_CACHE_FLUSH_NONE 0
#define COUNT_CACHE_FLUSH_HW 1

struct device;
struct device_attribute;
struct seq_buf {
    char *buffer;
    size_t size;
    size_t len;
};

static inline void seq_buf_init(struct seq_buf *s, char *buf, size_t size) {
    s->buffer = buf;
    s->size = size;
    s->len = 0;
}

static inline void seq_buf_printf(struct seq_buf *s, const char *fmt, ...) {
    // Simplified implementation
    (void)s;
    (void)fmt;
}

extern bool security_ftr_enabled(unsigned long feature);
extern bool link_stack_flush_enabled;
extern bool btb_flush_enabled;
extern int count_cache_flush_type;