#include <stdint.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>

struct rx_header {
    uint32_t callNumber;
    uint32_t serviceId;
};

struct rx_cache_entry {
    uint32_t callnum;
    uint32_t client;
    uint32_t server;
    int dport;
    uint32_t serviceId;
    uint32_t opcode;
};

typedef struct netdissect_options {
    const u_char *ndo_snapend;
} netdissect_options;

#define RX_CACHE_SIZE 64
static struct rx_cache_entry rx_cache[RX_CACHE_SIZE];
static int rx_cache_next;

#define EXTRACT_32BITS(p) ((uint32_t)ntohl(*(const uint32_t *)(p)))
#define UNALIGNED_MEMCPY(dst, src, len) memcpy((dst), (src), (len))