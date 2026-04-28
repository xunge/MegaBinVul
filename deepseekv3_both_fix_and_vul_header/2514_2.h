#include <stdint.h>
#include <string.h>

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

typedef unsigned char u_char;
typedef unsigned int u_int;

struct eigrp_common_header {
    uint8_t version;
    uint8_t opcode;
    uint16_t checksum;
    uint32_t flags;
    uint32_t seq;
    uint32_t ack;
    uint32_t asn;
};

struct eigrp_tlv_header {
    uint16_t type;
    uint16_t length;
};

struct eigrp_tlv_general_parm_t {
    uint16_t holdtime;
    uint8_t k1, k2, k3, k4, k5;
};

struct eigrp_tlv_sw_version_t {
    uint8_t ios_major, ios_minor;
    uint8_t eigrp_major, eigrp_minor;
};

struct eigrp_tlv_ip_int_t {
    uint8_t plen;
    uint32_t destination;
    uint32_t nexthop;
    uint32_t delay;
    uint32_t bandwidth;
    uint8_t mtu[3];
    uint8_t hopcount;
    uint8_t reliability;
    uint8_t load;
};

struct eigrp_tlv_ip_ext_t {
    uint8_t plen;
    uint32_t destination;
    uint32_t nexthop;
    uint32_t origin_router;
    uint32_t origin_as;
    uint8_t proto_id;
    uint8_t flags;
    uint32_t tag;
    uint32_t metric;
    uint32_t delay;
    uint32_t bandwidth;
    uint8_t mtu[3];
    uint8_t hopcount;
    uint8_t reliability;
    uint8_t load;
};

struct eigrp_tlv_at_cable_setup_t {
    uint16_t cable_start;
    uint16_t cable_end;
    uint32_t router_id;
};

struct eigrp_tlv_at_int_t {
    uint16_t cable_start;
    uint16_t cable_end;
    uint32_t nexthop;
    uint32_t delay;
    uint32_t bandwidth;
    uint8_t mtu[3];
    uint8_t hopcount;
    uint8_t reliability;
    uint8_t load;
};

struct eigrp_tlv_at_ext_t {
    uint16_t cable_start;
    uint16_t cable_end;
    uint32_t nexthop;
    uint32_t origin_router;
    uint32_t origin_as;
    uint8_t proto_id;
    uint8_t flags;
    uint32_t tag;
    uint16_t metric;
    uint32_t delay;
    uint32_t bandwidth;
    uint8_t mtu[3];
    uint8_t hopcount;
    uint8_t reliability;
    uint8_t load;
};

#define ND_TCHECK(a)
#define ND_TCHECK2(a, b)
#define ND_PRINT(a)
#define EXTRACT_16BITS(a) 0
#define EXTRACT_24BITS(a) 0
#define EXTRACT_32BITS(a) 0
#define tok2str(a, b, c) ""
#define ipaddr_string(a, b) ""
#define print_unknown_data(a, b, c, d)

#define EIGRP_VERSION 2
#define EIGRP_TLV_GENERAL_PARM 0x0001
#define EIGRP_TLV_SW_VERSION 0x0002
#define EIGRP_TLV_IP_INT 0x0102
#define EIGRP_TLV_IP_EXT 0x0103
#define EIGRP_TLV_AT_CABLE_SETUP 0x0201
#define EIGRP_TLV_AT_INT 0x0202
#define EIGRP_TLV_AT_EXT 0x0203
#define EIGRP_TLV_AUTH 0x0003
#define EIGRP_TLV_SEQ 0x0004
#define EIGRP_TLV_MCAST_SEQ 0x0005
#define EIGRP_TLV_IPX_INT 0x0302
#define EIGRP_TLV_IPX_EXT 0x0303

static const char *eigrp_opcode_values[] = { NULL };
static const char *eigrp_common_header_flag_values[] = { NULL };
static const char *eigrp_tlv_values[] = { NULL };
static const char *eigrp_ext_proto_id_values[] = { NULL };