#include <stdint.h>

#define UIP_TCP 1
#define UIP_IPTCPH_LEN 40
#define UIP_PROTO_TCP 6

extern uint16_t uip_len;
extern uint16_t uip_ext_len;

typedef struct {
    uint8_t proto;
} uip_ip_buf_t;

typedef struct {
    uint8_t flags;
} uip_tcp_buf_t;

extern uip_ip_buf_t *UIP_IP_BUF;
extern uip_tcp_buf_t *UIP_TCP_BUF;

void start_periodic_tcp_timer(void);