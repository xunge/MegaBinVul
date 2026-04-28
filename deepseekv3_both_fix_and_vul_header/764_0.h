#include <stdint.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>

struct rx_header {
    uint32_t callNumber;
    uint32_t serviceId;
};

struct rx_cache_entry {
    uint32_t callnum;
    struct in_addr client;
    struct in_addr server;
    uint32_t serviceId;
    int dport;
    int32_t opcode;
};

#define RX_CACHE_SIZE 32
#define EXTRACT_32BITS(p) (*(uint32_t*)(p))
#define UNALIGNED_MEMCPY(dst, src, size) memcpy(dst, src, size)

static struct rx_cache_entry rx_cache[RX_CACHE_SIZE];
static int rx_cache_hint;