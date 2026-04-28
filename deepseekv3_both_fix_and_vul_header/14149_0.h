#include <stdint.h>
#include <stddef.h>

struct buf {
    size_t size;
    size_t asize;
    uint8_t *data;
};

struct link_ref {
    struct buf *link;
    struct buf *title;
    struct buf *label;
    struct buf id;
    struct link_ref *next;
};

struct buf *bufnew(size_t size);
void bufput(struct buf *buf, const uint8_t *data, size_t len);
struct link_ref *add_link_ref(struct link_ref **refs, const uint8_t *data, size_t size);