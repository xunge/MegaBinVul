#include <stdint.h>
#include <stddef.h>

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

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
    void **pages;
};

struct iso_context {
    struct fw_iso_context base;
    void *context;
};

struct db_descriptor {
    uint16_t control;
    uint16_t first_size;
    uint16_t first_req_count;
    uint16_t first_res_count;
    uint32_t first_buffer;
    uint16_t second_req_count;
    uint16_t second_res_count;
    uint32_t second_buffer;
};

struct descriptor {
    uint8_t data[16];
};

#define PAGE_SHIFT 12
#define PAGE_SIZE (1UL << PAGE_SHIFT)
#define PAGE_MASK (~(PAGE_SIZE-1))

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define max(x, y) ((x) > (y) ? (x) : (y))

#define DESCRIPTOR_STATUS 0x8000
#define DESCRIPTOR_BRANCH_ALWAYS 0x4000
#define DESCRIPTOR_WAIT 0x2000
#define DESCRIPTOR_IRQ_ALWAYS 0x1000

#define EINVAL 22
#define ENOMEM 12

typedef uint32_t dma_addr_t;
typedef uint32_t u32;
typedef uint16_t u16;

static inline u16 cpu_to_le16(u16 val) { return val; }
static inline u32 cpu_to_le32(u32 val) { return val; }

static inline dma_addr_t page_private(void *page) { return 0; }

static void *context_get_descriptors(void *ctx, int count, dma_addr_t *bus) { return NULL; }
static void context_append(void *ctx, void *desc, int z, int header_z) {}