#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint32_t dma_addr_t;
typedef uint16_t u16;
typedef uint32_t u32;
typedef size_t size_t;

struct fw_iso_context {
    size_t header_size;
};

struct fw_iso_packet {
    unsigned int header_length;
    unsigned int payload_length;
    unsigned int skip;
    unsigned int interrupt;
};

struct fw_iso_buffer {
    struct page **pages;
};

struct iso_context {
    struct fw_iso_context base;
    void *context;
};

struct page {
    unsigned long private;
};

struct descriptor {
    u16 control;
    u16 req_count;
    u16 res_count;
    u16 transfer_status;
    u32 data_address;
};

#define DESCRIPTOR_STATUS 0
#define DESCRIPTOR_INPUT_MORE 0
#define DESCRIPTOR_WAIT 0
#define DESCRIPTOR_INPUT_LAST 0
#define DESCRIPTOR_BRANCH_ALWAYS 0
#define DESCRIPTOR_IRQ_ALWAYS 0
#define ENOMEM 12

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define max(a, b) ((a) > (b) ? (a) : (b))
#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))

static inline u16 cpu_to_le16(u16 val) { return val; }
static inline u32 cpu_to_le32(u32 val) { return val; }

static struct descriptor *context_get_descriptors(void *ctx, int count, dma_addr_t *bus) { return NULL; }
static void context_append(void *ctx, struct descriptor *d, int z, int header_z) {}

static inline dma_addr_t page_private(struct page *page) { return page->private; }

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))