#include <stdbool.h>
#include <stdint.h>

typedef struct {
    uint8_t k_d_flags;
    /* other members as needed */
} gnrc_rpl_dao_t;

typedef struct {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
    /* other members */
} icmpv6_hdr_t;

typedef struct {
    uint8_t addr[16];
} ipv6_addr_t;

#define GNRC_RPL_DAO_D_BIT (0x80)
#define DEBUG(fmt, ...)