#include <stdint.h>
#include <stddef.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

struct xdr_buf {
    unsigned int page_len;
    unsigned int page_base;
    void **pages;
};

struct xdr_stream {
    struct xdr_buf *buf;
    void **page_ptr;
    uint32_t *p;
    uint32_t *end;
    void *iov;
};

typedef uint32_t __be32;

extern void *page_address(void *page);
extern void xdr_stream_page_set_pos(struct xdr_stream *xdr, unsigned int pos);