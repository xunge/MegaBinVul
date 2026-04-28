#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define SICSLOWPAN_CONF_FRAG 0
#define SICSLOWPAN_COMPRESSION 0
#define SICSLOWPAN_COMPRESSION_IPV6 0
#define LOG_WARN(...)
#define LOG_INFO(...)
#define LOG_ERR(...)
#define LOG_DBG(...)
#define LOG_DBG_ENABLED 0
#define LOG_DBG_(...)

#define PACKETBUF_ADDR_SENDER 0
#define PACKETBUF_ATTR_RSSI 0
#define PACKETBUF_ATTR_SECURITY_LEVEL 0
#define PACKETBUF_ATTR_KEY_INDEX 0
#define PACKETBUF_FRAG_PTR ((uint8_t*)0)
#define PACKETBUF_FRAG_DISPATCH_SIZE 0
#define PACKETBUF_FRAG_OFFSET 0
#define PACKETBUF_FRAG_TAG 0
#define PACKETBUF_6LO_PTR ((uint8_t*)0)
#define PACKETBUF_6LO_DISPATCH 0

#define SICSLOWPAN_DISPATCH_FRAG_MASK 0
#define SICSLOWPAN_DISPATCH_FRAG1 0
#define SICSLOWPAN_DISPATCH_FRAGN 0
#define SICSLOWPAN_DISPATCH_IPHC_MASK 0
#define SICSLOWPAN_DISPATCH_IPHC 0
#define SICSLOWPAN_DISPATCH_IPV6 0

#define SICSLOWPAN_FRAG1_HDR_LEN 0
#define SICSLOWPAN_FRAGN_HDR_LEN 0
#define SICSLOWPAN_IPV6_HDR_LEN 0
#define SICSLOWPAN_FIRST_FRAGMENT_SIZE 0

#define UIP_IPH_LEN 0
#define UIP_BUFSIZE 0
#define UIP_IP_BUF ((struct uip_ip_buf *)0)

#define LLSEC802154_USES_AUX_HEADER 0
#define LLSEC802154_USES_EXPLICIT_KEYS 0
#define UIPBUF_ATTR_LLSEC_LEVEL 0
#define UIPBUF_ATTR_LLSEC_KEY_ID 0

typedef struct {
    uint8_t *first_frag;
    uint16_t reassembled_len;
    uint16_t first_frag_len;
} frag_info_t;

static uint8_t *packetbuf_dataptr(void) { return NULL; }
static uint16_t packetbuf_datalen(void) { return 0; }
static uint16_t packetbuf_attr(int attr) { return 0; }
static void *packetbuf_addr(int addr) { return NULL; }
static void link_stats_input_callback(void *sender) {}
static void uipbuf_clear(void) {}
static void set_packet_attrs(void) {}
static void tcpip_input(void) {}
static int8_t add_fragment(uint16_t tag, uint16_t size, uint8_t offset) { return 0; }
static void clear_fragments(int8_t context) {}
static bool copy_frags2uip(int8_t context) { return false; }
static void digest_paging_dispatch(void) {}
static void digest_6lorh_hdr(void) {}
static bool uncompress_hdr_iphc(uint8_t *buffer, uint16_t buffer_size, uint16_t frag_size) { return false; }

static uint16_t GET16(uint8_t *ptr, int offset) { return 0; }
static void uipbuf_set_attr(int attr, int value) {}

static uint8_t uncomp_hdr_len;
static uint16_t packetbuf_hdr_len;
static uint8_t *packetbuf_ptr;
static uint16_t packetbuf_payload_len;
static uint16_t uip_len;
static uint8_t curr_page;
static signed short last_rssi;
static frag_info_t frag_info[1];

struct callback_struct {
    void (*input_callback)(void);
};
static struct callback_struct *callback;

struct uip_ip_buf {
    uint8_t len[2];
};

static uint8_t uip_buf[1];