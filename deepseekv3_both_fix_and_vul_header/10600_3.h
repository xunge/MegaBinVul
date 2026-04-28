#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int32_t gint;
typedef unsigned int guint;

struct e_in6_addr {
    uint8_t bytes[16];
};

struct ip6_rthdr {
    uint8_t ip6r_nxt;
    uint8_t ip6r_len;
    uint8_t ip6r_type;
    uint8_t ip6r_segleft;
};

struct rthdr_proto_item {
    void *segs;
};

struct packet_info {
    struct {
        int type;
        void *data;
    } dst, src;
    void *pool;
};

struct expert_info {
    int dummy;
};

struct tvbuff {
    void *data;
};

struct proto_tree {
    void *tree;
};

struct proto_item {
    void *item;
};

struct wmem_array {
    void *array;
};

struct wmem_allocator {
    void *allocator;
};

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct wmem_array wmem_array_t;
typedef struct wmem_allocator wmem_allocator_t;

#define IPv6_ADDR_SIZE 16
#define ENC_BIG_ENDIAN 0
#define ENC_NA 0
#define AT_IPv6 0

static int g_ipv6_rpl_srh_strict_rfc_checking;

static struct expert_info ei_ipv6_dst_addr_not_multicast;
static struct expert_info ei_ipv6_routing_rpl_cmpri_cmpre_pad;
static struct expert_info ei_ipv6_routing_rpl_reserved;
static struct expert_info ei_ipv6_routing_rpl_addr_count_ge0;
static struct expert_info ei_ipv6_routing_invalid_segleft;
static struct expert_info ei_ipv6_src_route_list_src_addr;
static struct expert_info ei_ipv6_src_route_list_dst_addr;
static struct expert_info ei_ipv6_src_route_list_multicast_addr;
static struct expert_info ei_ipv6_src_route_list_mult_inst_same_addr;

static int hf_ipv6_routing_rpl_cmprI;
static int hf_ipv6_routing_rpl_cmprE;
static int hf_ipv6_routing_rpl_pad;
static int hf_ipv6_routing_rpl_reserved;
static int hf_ipv6_routing_rpl_addr_count;
static int hf_ipv6_routing_rpl_addr;
static int hf_ipv6_routing_rpl_fulladdr;