#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <err.h>

struct tcpr_mpls_label {
    uint32_t entry;
};

typedef struct eth_hdr {
    uint8_t ether_dhost[ETHER_ADDR_LEN];
    uint8_t ether_shost[ETHER_ADDR_LEN];
    uint16_t ether_type;
} eth_hdr_t;

#define MPLS_LS_S_MASK 0x00000100
#define MPLS_LS_LABEL_SHIFT 12
#define MPLS_LABEL_GACH 13
#define ETHERTYPE_IP6 ETHERTYPE_IPV6