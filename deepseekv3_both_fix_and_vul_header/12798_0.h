#include <stdint.h>
#include <string.h>

struct uip_routing_hdr {
  uint8_t next;
  uint8_t len;
  uint8_t routing_type;
  uint8_t seg_left;
};

struct uip_rpl_srh_hdr {
  uint8_t cmpr;
  uint8_t pad;
  uint8_t reserved;
};

struct uip_ip_hdr {
  uint8_t vtc;
  uint8_t tcflow;
  uint16_t flow;
  uint8_t len[2];
  uint8_t proto;
  uint8_t ttl;
  uint8_t srcipaddr[16];
  uint8_t destipaddr[16];
};

#define UIP_PROTO_ROUTING 43
#define RPL_RH_TYPE_SRH 3
#define RPL_RH_LEN 4
#define RPL_SRH_LEN 3

extern struct uip_ip_hdr *UIP_IP_BUF;
extern uint8_t *uip_buf;
extern uint16_t uip_len;

void *uipbuf_search_header(uint8_t *buf, uint16_t len, uint8_t proto);
void uip_ipaddr_copy(void *dest, const void *src);

#define LOG_DBG(...)
#define LOG_ERR(...) 
#define LOG_INFO(...)
#define LOG_INFO_6ADDR(addr)
#define LOG_INFO_(...)