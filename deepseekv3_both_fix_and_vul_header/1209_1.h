#include <stdint.h>
#include <string.h>

typedef struct {
    uint16_t u16[8];
} uip_ipaddr_t;

typedef struct {
    uint8_t u8[6];
} uip_lladdr_t;

typedef struct uip_ds6_addr {
    uip_ipaddr_t ipaddr;
    uint8_t state;
} uip_ds6_addr;

typedef struct uip_ds6_nbr {
    uip_ipaddr_t ipaddr;
    uip_lladdr_t lladdr;
    uint8_t state;
} uip_ds6_nbr;

#define UIP_STAT(x) (x)

extern uip_ds6_nbr *uip_ds6_nbr_lookup(const uip_ipaddr_t *ipaddr);
extern const uip_lladdr_t *uip_ds6_nbr_get_ll(uip_ds6_nbr *nbr);
extern int uip_ds6_nbr_update_ll(uip_ds6_nbr **nbr, const uip_lladdr_t *lladdr);
extern uip_ds6_nbr *uip_ds6_nbr_add(const uip_ipaddr_t *ipaddr, const uip_lladdr_t *lladdr, uint8_t isrouter, uint8_t state, uint8_t reason, void *data);
extern uip_ds6_addr *uip_ds6_addr_lookup(const uip_ipaddr_t *ipaddr);
extern int uip_ds6_is_my_addr(const uip_ipaddr_t *ipaddr);
extern void uip_ds6_dad_failed(uip_ds6_addr *addr);
extern void uip_create_linklocal_allnodes_mcast(uip_ipaddr_t *ipaddr);
extern void uip_ds6_select_src(uip_ipaddr_t *src, const uip_ipaddr_t *dst);
extern void uip_ipaddr_copy(uip_ipaddr_t *dest, const uip_ipaddr_t *src);
extern int uip_is_addr_mcast(const uip_ipaddr_t *addr);
extern int uip_is_addr_unspecified(const uip_ipaddr_t *addr);
extern int uip_is_addr_solicited_node(const uip_ipaddr_t *addr);
extern uint16_t uip_icmp6chksum(void);
extern void extract_lladdr_from_llao_aligned(uip_lladdr_t *lladdr);
extern void create_llao(uint8_t *buf, uint8_t type);
extern void uipbuf_clear(void);
extern void uipbuf_set_len(uint16_t len);
extern void uipbuf_set_len_field(void *ip, uint16_t len);

#define UIP_ND6_NS_LEN 24
#define UIP_ND6_NA_LEN 24
#define UIP_ND6_OPT_HDR_LEN 2
#define UIP_ND6_OPT_DATA_OFFSET 2
#define UIP_ND6_OPT_LLAO_LEN 8
#define UIP_ND6_OPT_SLLAO 1
#define UIP_ND6_OPT_TLLAO 2
#define UIP_LLADDR_LEN 6
#define UIP_ND6_HOP_LIMIT 255
#define UIP_ND6_NA_FLAG_SOLICITED 0x40
#define UIP_ND6_NA_FLAG_OVERRIDE 0x20
#define UIP_ND6_NA_FLAG_ROUTER 0x80
#define UIP_PROTO_ICMP6 58
#define ICMP6_NA 136
#define UIP_IPH_LEN 40
#define UIP_ICMPH_LEN 8
#define NBR_STALE 2
#define NBR_INCOMPLETE 1
#define NBR_TABLE_REASON_IPV6_ND 1
#define ADDR_TENTATIVE 1

#define LOG_INFO(...)
#define LOG_INFO_6ADDR(...)
#define LOG_INFO_(...)
#define LOG_ERR(...)
#define LOG_WARN(...)

#define UIP_CONF_IPV6_CHECKS 1
#define UIP_CONF_ROUTER 0
#define UIP_ND6_DEF_MAXDADNS 3

struct uip_stat {
    struct {
        unsigned long recv;
        unsigned long sent;
    } nd6;
} uip_stat;

extern uint8_t *uip_buf;
extern uint16_t uip_len;
extern uint16_t uip_l3_icmp_hdr_len;
extern uint8_t *nd6_opt_llao;
extern uint16_t nd6_opt_offset;
extern uip_ds6_nbr *nbr;
extern uip_ds6_addr *addr;

struct uip_ip_hdr {
    uint8_t vtc;
    uint8_t tcflow;
    uint16_t flow;
    uint8_t ttl;
    uint8_t proto;
    uip_ipaddr_t srcipaddr;
    uip_ipaddr_t destipaddr;
};

struct uip_icmp_hdr {
    uint8_t type;
    uint8_t icode;
    uint16_t icmpchksum;
};

struct uip_nd6_ns_hdr {
    uint8_t flagsreserved[4];
    uip_ipaddr_t tgtipaddr;
};

struct uip_nd6_na_hdr {
    uint8_t flagsreserved;
    uip_ipaddr_t tgtipaddr;
};

struct uip_nd6_opt_hdr {
    uint8_t type;
    uint8_t len;
};

#define UIP_IP_BUF ((struct uip_ip_hdr *)uip_buf)
#define UIP_ICMP_BUF ((struct uip_icmp_hdr *)&uip_buf[UIP_IPH_LEN])
#define UIP_ND6_NS_BUF ((struct uip_nd6_ns_hdr *)&uip_buf[UIP_IPH_LEN + UIP_ICMPH_LEN])
#define UIP_ND6_NA_BUF ((struct uip_nd6_na_hdr *)&uip_buf[UIP_IPH_LEN + UIP_ICMPH_LEN])
#define ND6_OPT_HDR_BUF(offset) ((struct uip_nd6_opt_hdr *)&uip_buf[UIP_IPH_LEN + UIP_ICMPH_LEN + offset])