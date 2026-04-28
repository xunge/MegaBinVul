#include <stddef.h>
#include <limits.h>

#define PAGE_SIZE 4096
#define PID_MAX_LIMIT 32768

#define BITS_PER_PAGE (PAGE_SIZE * 8)
#define BITS_PER_PAGE_MASK (BITS_PER_PAGE - 1)
#define PIDMAP_ENTRIES ((PID_MAX_LIMIT + BITS_PER_PAGE - 1)/BITS_PER_PAGE)

#define unlikely(x) __builtin_expect(!!(x), 0)

struct pidmap {
    unsigned long *page;
};

struct pid_namespace {
    struct pidmap pidmap[PIDMAP_ENTRIES];
};

static inline int find_next_bit(const unsigned long *addr, int size, int offset)
{
    while (offset < size) {
        if (addr[offset / (sizeof(*addr) * 8)] & (1UL << (offset % (sizeof(*addr) * 8))))
            return offset;
        offset++;
    }
    return size;
}

static inline int mk_pid(struct pid_namespace *ns, struct pidmap *map, int offset)
{
    return (map - ns->pidmap) * BITS_PER_PAGE + offset;
}