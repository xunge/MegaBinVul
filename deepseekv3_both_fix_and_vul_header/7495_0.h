#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <arpa/inet.h>

#define MPLS_LS_S_MASK 0x00000100
#define MPLS_LS_LABEL_SHIFT 12
#define MPLS_LABEL_GACH 13
#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IP6 0x86DD

struct tcpr_mpls_label {
    uint32_t entry;
};

typedef struct eth_hdr {
    uint8_t ether_dhost[6];
    uint8_t ether_shost[6];
    uint16_t ether_type;
} eth_hdr_t;