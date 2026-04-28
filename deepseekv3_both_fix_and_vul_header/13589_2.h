#include <stdint.h>
#include <stddef.h>

typedef struct rpl_instance rpl_instance_t;

extern rpl_instance_t *rpl_get_instance(uint8_t instance_id);
extern void dao_input_storing(void);
extern void dao_input_nonstoring(void);
extern void uipbuf_clear(void);

#define LOG_INFO(...)
#define LOG_INFO_6ADDR(addr)
#define LOG_INFO_(...)
#define LOG_WARN(...)

#define RPL_IS_STORING(instance) (0)
#define RPL_IS_NON_STORING(instance) (0)

extern uint16_t uip_len;
extern uint16_t uip_l3_icmp_hdr_len;
extern uint8_t UIP_ICMP_PAYLOAD[];

struct uip_ip_buf {
    struct {
        uint8_t srcipaddr[16];
    } ipaddr;
};
extern struct uip_ip_buf *UIP_IP_BUF;