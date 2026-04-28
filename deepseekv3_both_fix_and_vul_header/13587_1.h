#include <stdint.h>
#include <string.h>

typedef uint8_t uip_ipaddr_t[16];

typedef struct {
    uint8_t default_lifetime;
    void *current_dag;
} rpl_instance_t;

typedef struct {
    uint8_t dag_id[16];
} rpl_dag_t;

typedef struct {
    uint8_t srcipaddr[16];
} uip_ip_buf_t;

typedef struct {
    uint8_t *payload;
} uip_icmp_payload_t;

#define UIP_IP_BUF ((uip_ip_buf_t *)0)
#define UIP_ICMP_PAYLOAD ((uip_icmp_payload_t *)0)->payload
#define RPL_WITH_NON_STORING 1
#define RPL_DAO_D_FLAG 0x80
#define RPL_OPTION_PAD1 0
#define RPL_OPTION_TARGET 5
#define RPL_OPTION_TRANSIT 6
#define RPL_DAO_K_FLAG 0x40
#define RPL_DAO_ACK_UNCONDITIONAL_ACCEPT 0
#define RPL_ZERO_LIFETIME 0
#define CHAR_BIT 8

extern rpl_instance_t *rpl_get_instance(uint8_t instance_id);
extern void uip_ipaddr_copy(void *dest, const void *src);
extern uint16_t uip_len;
extern uint16_t uip_l3_icmp_hdr_len;
extern void uip_sr_expire_parent(rpl_dag_t *dag, void *prefix, void *parent_addr);
extern void *uip_sr_update_node(rpl_dag_t *dag, void *prefix, void *parent_addr, uint16_t lifetime);
extern void uipbuf_clear(void);
extern void dao_ack_output(rpl_instance_t *instance, void *sender_addr, uint16_t sequence, uint8_t type);

#define LOG_INFO(...)
#define LOG_INFO_6ADDR(...)
#define LOG_INFO_(...)
#define LOG_ERR(...)
#define LOG_DBG(...)
#define LOG_WARN(...)
#define LOG_WARN_6ADDR(...)
#define LOG_WARN_(...)
#define RPL_LIFETIME(instance, lifetime) (lifetime)