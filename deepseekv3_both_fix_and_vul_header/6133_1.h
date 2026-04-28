#include <stdbool.h>

struct ring_buffer_per_cpu {
    struct buffer_page *reader_page;
    struct buffer_page *commit_page;
};

struct buffer_page {
    unsigned long read;
};

static struct buffer_page *rb_set_head_page(struct ring_buffer_per_cpu *cpu_buffer) {
    return 0;
}

static unsigned long rb_page_commit(struct buffer_page *page) {
    return 0;
}

#define unlikely(x) (x)