#include <stdint.h>
#include <assert.h>

typedef struct DnsPacket DnsPacket;
typedef struct DnsResourceKey DnsResourceKey;
typedef struct DnsQuestion DnsQuestion;

struct DnsQuestion {
    DnsResourceKey **keys;
    unsigned n_keys;
};

struct DnsPacket {
    DnsQuestion *question;
    uint16_t flags;
};

#define DNS_PACKET_QR(p) ((p)->flags & 0x8000)

int dns_packet_extract(DnsPacket *p);
int dns_resource_key_equal(const DnsResourceKey *a, const DnsResourceKey *b);