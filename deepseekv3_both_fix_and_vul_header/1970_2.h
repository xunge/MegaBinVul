#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define VBLK_SIZE_HEAD 16

struct list_head {
    struct list_head *next, *prev;
};

#define list_for_each(pos, head) \
    for (pos = (head)->next; pos != (head); pos = pos->next)

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr)-(unsigned long)(&((type *)0)->member)))

#define list_add_tail(new, head) \
    do { \
        (new)->next = (head); \
        (new)->prev = (head)->prev; \
        (head)->prev->next = (new); \
        (head)->prev = (new); \
    } while (0)

#define GFP_KERNEL 0

static inline uint32_t get_unaligned_be32(const void *p)
{
    const uint8_t *cp = p;
    return (cp[0] << 24) | (cp[1] << 16) | (cp[2] << 8) | cp[3];
}

static inline uint16_t get_unaligned_be16(const void *p)
{
    const uint8_t *cp = p;
    return (cp[0] << 8) | cp[1];
}

#define BUG_ON(condition) do { if (condition) abort(); } while (0)

typedef uint8_t u8;

struct frag {
    uint32_t group;
    uint16_t num;
    uint16_t rec;
    uint8_t map;
    struct list_head list;
    uint8_t data[];
};

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

void ldm_error(const char *fmt, ...);
void ldm_crit(const char *fmt, ...);