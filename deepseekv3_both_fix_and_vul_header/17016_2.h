#include <stdint.h>
#include <string.h>

#define PACKETBUF_ADDR_SENDER 0

typedef struct {
    uint16_t credits;
} l2cap_channel_peer_t;

typedef struct {
    l2cap_channel_peer_t channel_peer;
} l2cap_channel_t;

typedef struct {
    uint8_t addr[6];
} linkaddr_t;

typedef struct {
    linkaddr_t sender;
} packetbuf_t;

extern linkaddr_t packetbuf_addr(uint8_t addr_type);
extern l2cap_channel_t *get_channel_for_addr(linkaddr_t addr);
extern void LOG_WARN(const char *fmt, ...);