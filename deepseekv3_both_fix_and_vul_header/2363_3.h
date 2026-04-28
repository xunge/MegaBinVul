#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>
#include <errno.h>

typedef struct DnsPacket {
    size_t rindex;
    // 其他必要的成员变量...
} DnsPacket;

typedef struct Bitmap Bitmap;

typedef struct {
    size_t saved_rindex;
} DnsPacketRewinder;

#define INIT_REWINDER(rewinder, p) ((rewinder).saved_rindex = (p)->rindex)
#define CANCEL_REWINDER(rewinder) ((void)0)
#define _cleanup_(x) __attribute__((cleanup(x)))

static inline int bitmap_ensure_allocated(Bitmap **types) { return 0; }
static inline int bitmap_set(Bitmap *types, uint16_t n) { return 0; }
static inline bool dns_type_is_pseudo(uint16_t n) { return false; }
static inline int dns_packet_read_uint8(DnsPacket *p, uint8_t *value, void *unused) { return 0; }
static inline int dns_packet_read(DnsPacket *p, size_t length, const void **data, void *unused) { return 0; }
static inline void rewind_dns_packet(DnsPacketRewinder *rewinder) {}