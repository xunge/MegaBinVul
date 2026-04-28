#include <stdbool.h>
#include <string.h>

struct request {
    // dummy definition
};

struct blk_align_bitmap {
    unsigned long word;
    unsigned int depth;
};

struct blk_mq_bitmap_tags {
    unsigned int map_nr;
    unsigned int bits_per_word;
    struct blk_align_bitmap *map;
};

struct blk_mq_tags {
    struct request **rqs;
};

typedef void busy_tag_iter_fn(struct request *, void *, bool);

extern struct request *blk_mq_tag_to_rq(struct blk_mq_tags *tags, unsigned int tag);

static inline int find_first_bit(const unsigned long *addr, unsigned int size) {
    for (unsigned int i = 0; i < size; i++) {
        if (addr[i / (sizeof(*addr) * 8)] & (1UL << (i % (sizeof(*addr) * 8)))) {
            return i;
        }
    }
    return size;
}

static inline int find_next_bit(const unsigned long *addr, unsigned int size, unsigned int offset) {
    for (unsigned int i = offset; i < size; i++) {
        if (addr[i / (sizeof(*addr) * 8)] & (1UL << (i % (sizeof(*addr) * 8)))) {
            return i;
        }
    }
    return size;
}