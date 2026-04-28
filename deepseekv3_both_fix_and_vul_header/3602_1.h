#include <stdint.h>
#include <stddef.h>
#include <errno.h>
#include <arpa/inet.h>

#define ZIMAGE32_MAGIC_OFFSET 0x24
#define ZIMAGE32_MAGIC 0x016f2818
#define ZIMAGE32_END_OFFSET 0x28
#define DTB_MAGIC 0xd00dfeed
#define XC_INTERNAL_ERROR 1

struct minimal_dtb_header {
    uint32_t magic;
    uint32_t total_size;
};

struct xc_dom_image {
    void *xch;
    void *kernel_blob;
    size_t kernel_size;
};

extern void xc_dom_panic(void *xch, int error, const char *fmt, ...);
extern void xc_dom_printf(void *xch, const char *fmt, ...);