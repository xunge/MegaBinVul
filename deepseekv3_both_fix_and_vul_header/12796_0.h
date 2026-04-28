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
  uint8_t hdr_ext_len;
};

typedef struct {
  uint8_t u8[16];
} uip_ipaddr_t;

#define RPL_WITH_NON_STORING 1
#define RPL_RH_TYPE_SRH 3
#define RPL_RH_LEN 4
#define RPL_SRH_LEN 4

extern uint8_t *uip_buf;
extern uint16_t uip_len;
#define UIP_PROTO_ROUTING 43

struct uip_ip_hdr {
  uip_ipaddr_t destipaddr;
};
#define UIP_IP_BUF ((struct uip_ip_hdr *)uip_buf)

void *uipbuf_search_header(uint8_t *buf, uint16_t len, uint8_t proto);
void uip_ipaddr_copy(uip_ipaddr_t *dest, const uip_ipaddr_t *src);

#define LOG_DBG(...)
#define LOG_INFO(...)
#define LOG_INFO_6ADDR(addr)
#define LOG_INFO_(...)