#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct olsr_common {
    uint16_t packet_len;
    uint16_t packet_seq;
};

struct olsr_msg4 {
    uint8_t msg_type;
    uint16_t msg_len;
    uint8_t originator[4];
    uint8_t ttl;
    uint8_t hopcount;
    uint8_t vtime;
    uint16_t msg_seq;
};

struct olsr_msg6 {
    uint8_t msg_type;
    uint16_t msg_len;
    uint8_t originator[16];
    uint8_t ttl;
    uint8_t hopcount;
    uint8_t vtime;
    uint16_t msg_seq;
};

struct olsr_hello {
    uint8_t htime;
    uint8_t will;
};

struct olsr_hello_link {
    uint16_t len;
    uint8_t link_code;
};

struct olsr_tc {
    uint16_t ans_seq;
};

struct olsr_hna4 {
    uint8_t network[4];
    uint8_t mask[4];
};

struct olsr_hna6 {
    uint8_t network[16];
    uint8_t mask[16];
};

#define ND_TCHECK2(a, b)
#define ND_PRINT(a)
#define ND_TCHECK(a)
#define EXTRACT_16BITS(a) ntohs(*(uint16_t *)(a))
#define EXTRACT_32BITS(a) ntohl(*(uint32_t *)(a))
#define ME_TO_DOUBLE(a) (a)
#define OLSR_EXTRACT_LINK_TYPE(a) ((a) >> 4)
#define OLSR_EXTRACT_NEIGHBOR_TYPE(a) ((a) & 0x0F)
#define mask62plen(a) 0
#define mask2plen(a) 0
#define deserialize_gw_speed(a) (a)
#define tok2str(a, b, c) (b)
#define ipaddr_string(a, b) ""
#define ip6addr_string(a, b) ""
#define fn_printn(a, b, c, d) ""
#define print_unknown_data(a, b, c, d) ""

#define OLSR_HELLO_MSG 1
#define OLSR_HELLO_LQ_MSG 2
#define OLSR_TC_MSG 3
#define OLSR_TC_LQ_MSG 4
#define OLSR_MID_MSG 5
#define OLSR_HNA_MSG 6
#define OLSR_NAMESERVICE_MSG 7
#define OLSR_POWERINFO_MSG 8

#define GW_HNA_PAD 0
#define GW_HNA_FLAGS 1
#define GW_HNA_UPLINK 2
#define GW_HNA_DOWNLINK 3
#define GW_HNA_FLAG_LINKSPEED 0x01
#define GW_HNA_FLAG_IPV4 0x02
#define GW_HNA_FLAG_IPV4_NAT 0x04
#define GW_HNA_FLAG_IPV6 0x08
#define GW_HNA_FLAG_IPV6PREFIX 0x10

static const char *olsr_msg_values[] = {"Hello", "Hello-LQ", "TC", "TC-LQ", "MID", "HNA", "Nameservice", "Powerinfo", NULL};
static const char *olsr_link_type_values[] = {"Unspecified", "Asymmetric", "Symmetric", "Lost", NULL};
static const char *olsr_neighbor_type_values[] = {"Not-Neighbor", "Symmetric", "MPR", NULL};

static int olsr_print_neighbor(netdissect_options *ndo, const u_char *msg_data, u_int len) { return 0; }
static int olsr_print_lq_neighbor4(netdissect_options *ndo, const u_char *msg_data, u_int len) { return 0; }
static int olsr_print_lq_neighbor6(netdissect_options *ndo, const u_char *msg_data, u_int len) { return 0; }

#define min(a, b) ((a) < (b) ? (a) : (b))