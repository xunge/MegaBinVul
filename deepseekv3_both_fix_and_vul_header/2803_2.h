#include <stdint.h>

#define PKT_CCC_PRI_DHCP 1
#define PKT_CCC_SEC_DHCP 2
#define ENC_BIG_ENDIAN 0

typedef uint16_t guint16;

extern int hf_packetcable_ccc_suboption;
extern int hf_packetcable_ccc_pri_dhcp;
extern int hf_packetcable_ccc_sec_dhcp;
extern int ett_dhcpv6_pkt_option;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct packet_info packet_info;
typedef struct tvbuff_t tvbuff_t;
typedef struct expert_field expert_field;

extern expert_field ei_dhcpv6_no_suboption_len;
extern expert_field ei_dhcpv6_bogus_length;

extern proto_item* proto_tree_add_item(proto_tree*, int, tvbuff_t*, int, int, int);
extern proto_tree* proto_item_add_subtree(proto_item*, int);
extern void expert_add_info_format(packet_info*, proto_item*, expert_field*, const char*, ...);
extern guint16 tvb_get_ntohs(tvbuff_t*, int);