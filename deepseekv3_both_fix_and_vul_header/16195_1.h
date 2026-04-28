#include <stdint.h>
#include <string.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <err.h>

#define DLT_RAW 12
#define DLT_JUNIPER_ETHER 141
#define DLT_EN10MB 1
#define DLT_PPP_SERIAL 50
#define DLT_C_HDLC 104
#define DLT_LINUX_SLL 113

#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IP6 0x86DD
#define ETHERTYPE_VLAN 0x8100

#define JUNIPER_PCAP_MAGIC "\x4d\x47\x43"
#define JUNIPER_FLAG_EXT   0x01
#define JUNIPER_FLAG_NO_L2 0x02

typedef struct eth_hdr {
    uint8_t  ether_dhost[ETHER_ADDR_LEN];
    uint8_t  ether_shost[ETHER_ADDR_LEN];
    uint16_t ether_type;
} eth_hdr_t;

typedef struct vlan_hdr {
    uint16_t vlan_tpid;
    uint16_t vlan_tci;
} vlan_hdr_t;

typedef struct tcpr_pppserial_hdr {
    uint16_t protocol;
} tcpr_pppserial_hdr;

typedef struct hdlc_hdr {
    uint16_t protocol;
} hdlc_hdr_t;

typedef struct sll_hdr {
    uint16_t sll_protocol;
} sll_hdr_t;

const char *pcap_datalink_val_to_description(int datalink);