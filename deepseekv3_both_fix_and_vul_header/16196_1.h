#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <err.h>

#define DLT_RAW 12
#define DLT_JUNIPER_ETHER 308
#define DLT_EN10MB 1
#define DLT_PPP_SERIAL 50
#define DLT_C_HDLC 104
#define DLT_LINUX_SLL 113

#define JUNIPER_PCAP_MAGIC "\x4d\x47\x43"
#define JUNIPER_FLAG_NO_L2 0x01
#define JUNIPER_FLAG_EXT   0x02
#define CISCO_HDLC_LEN 4
#define SLL_HDR_LEN 16
#define ETHERTYPE_VLAN 0x8100

typedef struct eth_hdr {
    uint8_t  ether_dhost[6];
    uint8_t  ether_shost[6];
    uint16_t ether_type;
} eth_hdr_t;

typedef struct vlan_hdr {
    uint16_t vlan_tpid;
    uint16_t vlan_tci;
} vlan_hdr_t;