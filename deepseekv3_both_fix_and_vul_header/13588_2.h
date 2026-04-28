#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    uint8_t u8[16];
} uip_ipaddr_t;

typedef struct rpl_instance_t {
    uint8_t default_lifetime;
    struct rpl_dag_t *current_dag;
} rpl_instance_t;

typedef struct rpl_dag_t {
    uint8_t rank;
    uip_ipaddr_t dag_id;
    struct rpl_parent_t *preferred_parent;
} rpl_dag_t;

typedef struct rpl_parent_t {
    uint8_t rank;
    uint8_t flags;
} rpl_parent_t;

typedef struct uip_ds6_route_t {
    uint8_t length;
    struct {
        uint8_t lifetime;
        uint8_t dao_seqno_in;
        uint8_t dao_seqno_out;
    } state;
} uip_ds6_route_t;

typedef struct uip_mcast6_route_t {
    rpl_dag_t *dag;
    uint8_t lifetime;
} uip_mcast6_route_t;

typedef struct {
} uip_ds6_nbr_t;

typedef struct {
    uip_ipaddr_t srcipaddr;
} uip_buf_t;

typedef struct {
} packetbuf_t;

#define RPL_WITH_STORING 1
#define RPL_WITH_MULTICAST 1
#define RPL_DAO_D_FLAG 0x80
#define RPL_OPTION_PAD1 0
#define RPL_OPTION_TARGET 5
#define RPL_OPTION_TRANSIT 6
#define RPL_ROUTE_FROM_MULTICAST_DAO 0
#define RPL_ROUTE_FROM_UNICAST_DAO 1
#define RPL_INFINITE_RANK 0xFF
#define RPL_PARENT_FLAG_UPDATED 0x01
#define RPL_ZERO_LIFETIME 0
#define RPL_DAO_K_FLAG 0x40
#define RPL_DAO_ACK_UNCONDITIONAL_ACCEPT 0
#define RPL_DAO_ACK_UNABLE_TO_ADD_ROUTE_AT_ROOT 1
#define RPL_DAO_ACK_UNABLE_TO_ACCEPT 2
#define RPL_LIFETIME(x, y) (y)
#define RPL_NOPATH_REMOVAL_DELAY 60
#define RPL_ROUTE_IS_NOPATH_RECEIVED(x) (0)
#define RPL_ROUTE_SET_NOPATH_RECEIVED(x)
#define RPL_ROUTE_IS_DAO_PENDING(x) (0)
#define RPL_ROUTE_CLEAR_NOPATH_RECEIVED(x)
#define ROOT_RANK(x) (1)
#define DAG_RANK(x, y) (x)
#define CHAR_BIT 8
#define NBR_TABLE_REASON_RPL_DAO 0
#define ICMP6_RPL 155
#define RPL_CODE_DAO 1

#define LOG_INFO(...)
#define LOG_DBG(...)
#define LOG_DBG_6ADDR(...)
#define LOG_DBG_(...)
#define LOG_WARN(...)
#define LOG_ERR(...)
#define LOG_ERR_6ADDR(...)
#define LOG_ERR_LLADDR(...)
#define LOG_ERR_(...)
#define LOG_INFO_6ADDR(...)
#define LOG_INFO_(...)
#define RPL_STAT(...)

extern uip_buf_t *UIP_IP_BUF;
extern unsigned char *UIP_ICMP_PAYLOAD;
extern uint16_t uip_len;
extern uint8_t uip_l3_icmp_hdr_len;

extern rpl_instance_t *rpl_get_instance(uint8_t instance_id);
extern void uip_ipaddr_copy(uip_ipaddr_t *dest, const uip_ipaddr_t *src);
extern int uip_is_addr_mcast(const uip_ipaddr_t *addr);
extern int uip_is_addr_mcast_global(const uip_ipaddr_t *addr);
extern int uip_ipaddr_cmp(const uip_ipaddr_t *addr1, const uip_ipaddr_t *addr2);
extern rpl_parent_t *rpl_find_parent(rpl_dag_t *dag, const uip_ipaddr_t *addr);
extern uip_ds6_nbr_t *rpl_icmp6_update_nbr_table(const uip_ipaddr_t *addr, int reason, rpl_instance_t *instance);
extern uip_ds6_route_t *rpl_add_route(rpl_dag_t *dag, const uip_ipaddr_t *prefix, uint8_t prefixlen, const uip_ipaddr_t *next_hop);
extern uip_ds6_route_t *uip_ds6_route_lookup(const uip_ipaddr_t *prefix);
extern void uip_icmp6_send(const uip_ipaddr_t *dest, uint8_t type, uint8_t code, uint16_t len);
extern void uipbuf_clear(void);
extern void dao_ack_output(rpl_instance_t *instance, const uip_ipaddr_t *dest, uint16_t sequence, uint8_t code);
extern uint8_t prepare_for_dao_fwd(uint16_t sequence, uip_ds6_route_t *rep);
extern void *packetbuf_addr(int type);
extern void *uip_ds6_route_nexthop(uip_ds6_route_t *route);
extern uip_ipaddr_t *rpl_parent_get_ipaddr(rpl_parent_t *parent);
extern uip_mcast6_route_t *uip_mcast6_route_add(const uip_ipaddr_t *addr);

uip_mcast6_route_t *mcast_group;