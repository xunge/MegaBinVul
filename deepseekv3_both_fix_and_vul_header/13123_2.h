#include <stddef.h>
#include <stdbool.h>

#define HEX_CHARS 16
#define MAX_MEMHEX_BYTES 8

struct seq_buf {
    char *buffer;
    size_t size;
    size_t len;
};

#define BUILD_BUG_ON(condition) ((void)0)

#define WARN_ON(condition) (condition)
#define WARN_ON_ONCE(condition) (condition)

static inline char hex_asc(unsigned char c) { return c < 10 ? c + '0' : c - 10 + 'a'; }
static inline char hex_asc_hi(unsigned char c) { return hex_asc(c >> 4); }
static inline char hex_asc_lo(unsigned char c) { return hex_asc(c & 0xf); }

static inline void seq_buf_putmem(struct seq_buf *s, const void *mem, unsigned int len) {}
static inline bool seq_buf_has_overflowed(struct seq_buf *s) { return false; }

#define min(a, b) ((a) < (b) ? (a) : (b))