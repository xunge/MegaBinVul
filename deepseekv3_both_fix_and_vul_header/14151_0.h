#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdint.h>

#define REF_TABLE_SIZE 256

struct buf {
    uint8_t *data;
    size_t size;
};

struct link_ref {
    unsigned int id;
    struct buf *label;
    struct buf *link;
    struct buf *title;
    struct link_ref *next;
};

static unsigned int hash_link_ref(const uint8_t *name, size_t name_size);
static void bufrelease(struct buf *buf);