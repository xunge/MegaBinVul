#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t d_reserved;
} gnrc_rpl_dao_ack_t;

typedef struct {
    // ICMPv6 header fields would go here
} icmpv6_hdr_t;

typedef struct {
    // IPv6 address fields would go here
} ipv6_addr_t;

#define GNRC_RPL_DAO_ACK_D_BIT (0x80)

#define DEBUG(...)