#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct uip_ext_hdr {
  uint8_t next;
  uint8_t len;
};

struct uip_udp_hdr {
  uint16_t srcport;
  uint16_t destport;
  uint16_t udplen;
  uint16_t udpchksum;
};

typedef struct {
  uint8_t prefix[16];
} uip_lladdr_t;

typedef struct {
  uint8_t *prefix;
} addr_context_t;

extern uint8_t *packetbuf_ptr;
extern uint16_t packetbuf_datalen();
extern uint16_t packetbuf_hdr_len;
extern uint8_t PACKETBUF_IPHC_BUF[2];
extern uint8_t *packetbuf_addr(int type);
extern addr_context_t *addr_context_lookup_by_number(uint8_t sci);
extern bool uncompress_addr(void *ipaddr, const uint8_t *prefix, int mode, uip_lladdr_t *lladdr);

#define SICSLOWPAN_IPHC_CID 0x80
#define SICSLOWPAN_IPHC_FL_C 0x10
#define SICSLOWPAN_IPHC_TC_C 0x08
#define SICSLOWPAN_IPHC_NH_C 0x04
#define SICSLOWPAN_IPHC_TTL_I 0x03
#define SICSLOWPAN_IPHC_SAM_11 0xC0
#define SICSLOWPAN_IPHC_SAM_BIT 6
#define SICSLOWPAN_IPHC_SAC 0x40
#define SICSLOWPAN_IPHC_M 0x08
#define SICSLOWPAN_IPHC_DAC 0x04
#define SICSLOWPAN_IPHC_DAM_11 0x30
#define SICSLOWPAN_IPHC_DAM_BIT 4
#define SICSLOWPAN_NHC_MASK 0xE0
#define SICSLOWPAN_NHC_EXT_HDR 0xE0
#define SICSLOWPAN_NHC_ETX_HDR_HBHO 0
#define SICSLOWPAN_NHC_ETX_HDR_ROUTING 1
#define SICSLOWPAN_NHC_ETX_HDR_FRAG 2
#define SICSLOWPAN_NHC_ETX_HDR_DESTO 3
#define SICSLOWPAN_NHC_UDP_MASK 0xF8
#define SICSLOWPAN_NHC_UDP_ID 0xF0
#define SICSLOWPAN_NHC_UDP_CHECKSUMC 0x04
#define SICSLOWPAN_NHC_UDP_CS_P_11 0x03
#define SICSLOWPAN_NHC_UDP_CS_P_00 0x00
#define SICSLOWPAN_NHC_UDP_CS_P_01 0x01
#define SICSLOWPAN_NHC_UDP_CS_P_10 0x02
#define SICSLOWPAN_UDP_8_BIT_PORT_MIN 0xF0B0
#define SICSLOWPAN_UDP_4_BIT_PORT_MIN 0xF0B0
#define PACKETBUF_ADDR_SENDER 0
#define PACKETBUF_ADDR_RECEIVER 1

#define UIP_IPH_LEN 40
#define UIP_EXT_HDR_LEN 2
#define UIP_UDPH_LEN 8
#define UIP_PROTO_HBHO 0
#define UIP_PROTO_ROUTING 43
#define UIP_PROTO_FRAG 44
#define UIP_PROTO_DESTO 60
#define UIP_PROTO_UDP 17
#define UIP_HTONS(n) (n)

#define LOG_WARN(...)
#define LOG_DBG(...)
#define LOG_ERR(...)

static uint8_t *iphc_ptr;
static uint16_t uncomp_hdr_len;
static addr_context_t *context;
static const uint8_t ttl_values[] = {1, 64, 255};
static const uint8_t llprefix[] = {0xfe, 0x80};
static const int unc_ctxconf[] = {0, 8, 16, 64};
static const int unc_llconf[] = {0, 8, 16, 64};
static const int unc_mxconf[] = {128, 48, 32, 8};

#define SICSLOWPAN_IP_BUF(buf) ((struct ip_hdr *)buf)
#define SICSLOWPAN_IPPAYLOAD_BUF(buf) ((uint8_t *)buf + UIP_IPH_LEN)

struct ip_hdr {
  uint8_t vtc;
  uint8_t tcflow;
  uint16_t flow;
  uint8_t proto;
  uint8_t ttl;
  uint8_t srcipaddr[16];
  uint8_t destipaddr[16];
  uint8_t len[2];
};