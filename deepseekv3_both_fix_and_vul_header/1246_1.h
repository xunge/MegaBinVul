#include <stdint.h>
#include <assert.h>
#include <string.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <netinet/in.h>
#include <err.h>

#define DLT_NULL 0
#define DLT_RAW 12
#define DLT_JUNIPER_ETHER 141
#define DLT_EN10MB 1
#define DLT_PPP_SERIAL 50
#define DLT_C_HDLC 104
#define DLT_LINUX_SLL 113

#define ETHERTYPE_IP 0x0800
#define ETHERTYPE_IP6 0x86DD

#define JUNIPER_PCAP_MAGIC "\x4d\x47\x43"
#define JUNIPER_FLAG_EXT 0x80
#define JUNIPER_FLAG_NO_L2 0x40

#define CISCO_HDLC_LEN 4
#define SLL_HDR_LEN 16

typedef struct eth_hdr {
    uint8_t ether_dhost[6];
    uint8_t ether_shost[6];
    uint16_t ether_type;
} eth_hdr_t;

typedef struct tcpr_pppserial_hdr {
    uint8_t address;
    uint8_t control;
    uint16_t protocol;
} tcpr_pppserial_hdr_t;

typedef struct hdlc_hdr {
    uint8_t address;
    uint8_t control;
    uint16_t protocol;
} hdlc_hdr_t;

typedef struct sll_hdr {
    uint16_t sll_pkttype;
    uint16_t sll_hatype;
    uint16_t sll_halen;
    uint8_t sll_addr[8];
    uint16_t sll_protocol;
} sll_hdr_t;

const char *pcap_datalink_val_to_description(int dlt);
int parse_metadata(const u_char *pktdata, const uint32_t datalen, uint16_t *ether_type, uint32_t *l2_net_off, uint32_t *l2offset, uint32_t *vlan_offset);