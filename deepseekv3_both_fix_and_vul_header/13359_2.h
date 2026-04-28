#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t type;
    uint8_t len;
} uip_nd6_opt_hdr;

typedef struct {
    uint8_t ttl;
    uint8_t srcipaddr[16];
    uint8_t destipaddr[16];
} uip_ip_hdr;

typedef struct {
    uint8_t icode;
} uip_icmp_hdr;

typedef struct {
    struct {
        uint8_t recv;
    } nd6;
} uip_stat_t;

typedef struct uip_ds6_nbr {
    uint8_t reachable;
    uint8_t sendns;
    uint8_t nscount;
    uint8_t isrouter;
    struct uip_ds6_nbr* next;
} uip_ds6_nbr;

typedef uint8_t uip_lladdr_t;
typedef uip_ds6_nbr uip_ds6_nbr_t;

#define UIP_IP_BUF ((uip_ip_hdr*)0)
#define UIP_ICMP_BUF ((uip_icmp_hdr*)0)
#define UIP_ND6_HOP_LIMIT 255
#define UIP_ND6_RS_LEN 8
#define UIP_ND6_OPT_SLLAO 1
#define UIP_ND6_OPT_DATA_OFFSET 2
#define UIP_LLADDR_LEN 6
#define UIP_CONF_IPV6_CHECKS 1
#define NBR_STALE 0
#define NBR_TABLE_REASON_IPV6_ND 0

#define ND6_OPT_HDR_BUF(offset) ((uip_nd6_opt_hdr*)((uint8_t*)UIP_ICMP_BUF + offset))
#define UIP_STAT(x) (x)
#define LOG_INFO(msg)
#define LOG_INFO_6ADDR(addr)
#define LOG_INFO_(msg)
#define LOG_ERR(msg)
#define LOG_WARN(msg)

static uip_stat_t uip_stat;
static uint16_t nd6_opt_offset;
static uint8_t* nd6_opt_llao;
static uint16_t uip_len;
static uint16_t uip_l3_icmp_hdr_len;
static uip_ds6_nbr* nbr;

static int uip_is_addr_unspecified(const uint8_t (*addr)[16]) { return 0; }
static void extract_lladdr_from_llao_aligned(uip_lladdr_t* lladdr) {}
static uip_ds6_nbr* uip_ds6_nbr_lookup(const uint8_t (*ipaddr)[16]) { return NULL; }
static uip_ds6_nbr* uip_ds6_nbr_add(const uint8_t (*ipaddr)[16], const uip_lladdr_t* lladdr, uint8_t isrouter, uint8_t state, uint8_t reason, void* data) { return NULL; }
static void uip_ds6_nbr_rm(uip_ds6_nbr* nbr) {}
static const uip_lladdr_t* uip_ds6_nbr_get_ll(uip_ds6_nbr* nbr) { return NULL; }
static void uip_ds6_send_ra_sollicited(void) {}
static void uipbuf_clear(void) {}