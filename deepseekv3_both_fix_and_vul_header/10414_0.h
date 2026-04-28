#include <stdint.h>
#include <string.h>

#define HEX_L "0123456789abcdef"
#define HEX_U "0123456789ABCDEF"

typedef struct {
    uint8_t u8[16];
} ipv6_addr_t;

static inline void ipv6_addr_set_unspecified(ipv6_addr_t *addr)
{
    memset(addr, 0, sizeof(ipv6_addr_t));
}

#ifdef MODULE_IPV4_ADDR
typedef struct {
    uint8_t u8[4];
} ipv4_addr_t;

ipv4_addr_t *ipv4_addr_from_str(ipv4_addr_t *result, const char *addr);
#endif