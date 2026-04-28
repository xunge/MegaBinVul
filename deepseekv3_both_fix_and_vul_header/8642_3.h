#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;

typedef uint32_t __be32;
typedef uint16_t __be16;

struct device {
    // Minimal device structure definition
    int dummy;
};

struct net_device {
    struct device dev;
};

struct fw_iso_context {
    struct {
        struct {
            u32 generation;
        } *card;
    };
};

struct fwnet_device {
    void *lock;
    u32 rcv_buffer_size;
    u32 broadcast_rcv_next_ptr;
    __be32 **broadcast_rcv_buffer_ptrs;
    u32 num_broadcast_rcv_ptrs;
    struct fw_iso_context *broadcast_rcv_context;
    void *broadcast_rcv_buffer;
    struct net_device *netdev;
};

struct fw_iso_packet {
    u32 payload_length;
    u32 interrupt;
    u32 skip;
    u32 tag;
    u32 sy;
    u32 header_length;
};

#define IANA_SPECIFIER_ID 0x00005E
#define RFC2734_SW_VERSION 1
#define RFC3146_SW_VERSION 2
#define IEEE1394_GASP_HDR_SIZE 8
#define IS_ENABLED(x) 0

static inline u32 be32_to_cpu(__be32 x) { return x; }
static inline u16 be16_to_cpup(const __be16 *p) { return *p; }
static inline void spin_lock_irqsave(void *lock, unsigned long flags) {}
static inline void spin_unlock_irqrestore(void *lock, unsigned long flags) {}
static inline void fwnet_incoming_packet(struct fwnet_device *dev, __be32 *buf_ptr, u32 length, u16 source_node_id, u32 generation, bool flag) {}
static inline int fw_iso_context_queue(struct fw_iso_context *ctx, struct fw_iso_packet *packet, void **buf, unsigned long offset) { return 0; }
static inline void fw_iso_context_queue_flush(struct fw_iso_context *ctx) {}
static inline void dev_err(struct device *dev, const char *fmt, ...) {}