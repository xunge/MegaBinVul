#include <stdint.h>
#include <errno.h>
#include <stddef.h>
#include <pthread.h>

typedef struct gnrc_pktsnip {
    struct gnrc_pktsnip *next;
    void *data;
    size_t size;
    uint16_t type;
} gnrc_pktsnip_t;

typedef struct {
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t checksum;
    uint16_t off_ctl;
} tcp_hdr_t;

typedef struct gnrc_tcp_tcb {
    struct gnrc_tcp_tcb *next;
    uint16_t local_port;
    uint16_t peer_port;
    uint8_t address_family;
    void *local_addr;
    void *peer_addr;
    uint8_t state;
} gnrc_tcp_tcb_t;

typedef struct {
    uint8_t dst[16];
    uint8_t src[16];
} ipv6_hdr_t;

typedef uint8_t ipv6_addr_t[16];

#define MODULE_GNRC_IPV6
#define GNRC_NETTYPE_IPV6 1
#define GNRC_NETTYPE_TCP 2
#define GNRC_NETTYPE_UNDEF 0
#define MSK_SYN_ACK 0x12
#define MSK_SYN 0x02
#define MSK_RST 0x04
#define GET_OFFSET(ctl) ((ctl) >> 12)
#define TCP_HDR_OFFSET_MIN 5
#define FSM_STATE_LISTEN 1
#define FSM_EVENT_RCVD_PKT 1
#define AF_INET6 2

static pthread_mutex_t _list_tcb_lock = PTHREAD_MUTEX_INITIALIZER;
static gnrc_tcp_tcb_t *_list_tcb_head = NULL;
static int gnrc_tcp_pid = 0;

#define DEBUG(fmt, ...) 
#define LL_SEARCH_SCALAR(list, out, field, value) \
    for ((out) = (list); (out) != NULL; (out) = (out)->next) \
        if ((out)->field == (value)) break

static uint16_t byteorder_ntohs(uint16_t val) { return (val >> 8) | (val << 8); }
static gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt) { return pkt; }
static void gnrc_pktbuf_release(gnrc_pktsnip_t *pkt) {}
static gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, uint16_t type) { return pkt; }
static uint16_t _pkt_calc_csum(gnrc_pktsnip_t *tcp, gnrc_pktsnip_t *ip, gnrc_pktsnip_t *pkt) { return 0; }
static void _fsm(gnrc_tcp_tcb_t *tcb, int event, gnrc_pktsnip_t *pkt, void *arg, int flags) {}
static void _pkt_build_reset_from_pkt(gnrc_pktsnip_t **reset, gnrc_pktsnip_t *pkt) {}
static void gnrc_netapi_send(int pid, gnrc_pktsnip_t *pkt) {}

static int ipv6_addr_equal(ipv6_addr_t *a, ipv6_addr_t *b) { 
    return memcmp(a, b, sizeof(ipv6_addr_t)) == 0; 
}
static int ipv6_addr_is_unspecified(ipv6_addr_t *a) {
    static const ipv6_addr_t zero = {0};
    return memcmp(a, &zero, sizeof(ipv6_addr_t)) == 0;
}