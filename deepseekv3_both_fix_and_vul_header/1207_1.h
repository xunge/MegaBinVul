#include <stdint.h>
#include <string.h>

typedef uint8_t uip_ipaddr_t[16];

typedef struct {
    uip_ipaddr_t srcipaddr;
} uip_ip_buf_t;

typedef struct {
    uint8_t payload[1];
} uip_icmp_payload_t;

typedef struct {
    uip_ipaddr_t dag_id;
    uint8_t default_lifetime;
    struct rpl_dag_t *current_dag;
} rpl_dag_t;

typedef struct {
    uint8_t instance_id;
    rpl_dag_t *current_dag;
    uint8_t default_lifetime;
} rpl_instance_t;

#define RPL_WITH_NON_STORING 1
#define RPL_DAO_D_FLAG 0x80
#define RPL_DAO_K_FLAG 0x40
#define RPL_OPTION_PAD1 0
#define RPL_OPTION_TARGET 1
#define RPL_OPTION_TRANSIT 2
#define RPL_ZERO_LIFETIME 0
#define RPL_DAO_ACK_UNCONDITIONAL_ACCEPT 0
#define CHAR_BIT 8

extern uip_ip_buf_t *UIP_IP_BUF;
extern uip_icmp_payload_t *UIP_ICMP_PAYLOAD;
extern uint16_t uip_len;
extern uint16_t uip_l3_icmp_hdr_len;

extern void LOG_INFO(const char *fmt, ...);
extern void LOG_INFO_6ADDR(const uip_ipaddr_t *addr);
extern void LOG_INFO_(const char *fmt, ...);
extern void LOG_DBG(const char *fmt, ...);
extern void LOG_WARN(const char *fmt, ...);
extern void LOG_WARN_6ADDR(const uip_ipaddr_t *addr);
extern void LOG_WARN_(const char *fmt, ...);

extern void uip_ipaddr_copy(uip_ipaddr_t *dest, const uip_ipaddr_t *src);
extern rpl_instance_t *rpl_get_instance(uint8_t instance_id);
extern void uip_sr_expire_parent(rpl_dag_t *dag, const uip_ipaddr_t *prefix, const uip_ipaddr_t *parent_addr);
extern void *uip_sr_update_node(rpl_dag_t *dag, const uip_ipaddr_t *prefix, const uip_ipaddr_t *parent_addr, uint8_t lifetime);
extern void uipbuf_clear(void);
extern void dao_ack_output(rpl_instance_t *instance, const uip_ipaddr_t *sender_addr, uint16_t sequence, uint8_t ack_type);

#define RPL_LIFETIME(instance, lifetime) (lifetime)