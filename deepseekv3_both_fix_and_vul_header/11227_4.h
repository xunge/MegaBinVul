#include <stdint.h>
#include <stddef.h>

#define EDP_DEVICE_TYPE_SFS17 1
#define EDP_DEVICE_TYPE_SFS18 2
#define EDP_DEVICE_TYPE_ROUTER 3
#define EDP_DEVICE_TYPE_BRIDGE 4
#define EDP_DEVICE_TYPE_NTSERVER 5
#define EDP_DEVICE_TYPE_NTCLIENT 6
#define EDP_DEVICE_TYPE_WIN95 7
#define EDP_DEVICE_TYPE_WIN98 8
#define EDP_DEVICE_TYPE_UNIXSERVER 9
#define EDP_DEVICE_TYPE_UNIXCLIENT 10
#define EDP_DEVICE_TYPE_VLANMAN 11
#define EDP_DEVICE_TYPE_ACCESSPOINT 12

#define EDP_TUPLE_HOLD 1
#define EDP_TUPLE_INT_NAME 2
#define EDP_TUPLE_SYS_DESCRIPT 3
#define EDP_TUPLE_IPX_ADDR 4
#define EDP_TUPLE_UNKNOWN 0

#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define ENC_ASCII 2

typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gint;
typedef unsigned int guint;
typedef uint8_t guint8;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    void *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

extern int hf_ismp_edp;
extern int hf_ismp_edp_version;
extern int hf_ismp_edp_module_ip;
extern int hf_ismp_edp_module_mac;
extern int hf_ismp_edp_module_port;
extern int hf_ismp_edp_chassis_mac;
extern int hf_ismp_edp_chassis_ip;
extern int hf_ismp_edp_device_type;
extern int hf_ismp_edp_module_rev;
extern int hf_ismp_edp_options;
extern int hf_ismp_edp_num_neighbors;
extern int hf_ismp_edp_neighbors;
extern int hf_ismp_neighborhood_mac_address;
extern int hf_ismp_assigned_neighbor_state;
extern int hf_ismp_edp_num_tuples;
extern int hf_ismp_edp_tuples;
extern int hf_ismp_tuple_type;
extern int hf_ismp_tuple_length;
extern int hf_ismp_hold_time;
extern int hf_ismp_interface_name;
extern int hf_ismp_system_description;
extern int hf_ismp_interface_ipx_address;
extern int hf_ismp_unknown_tuple_data;
extern int hf_ismp_edp_sfs_option_uplink_flood;
extern int hf_ismp_edp_sfs_option_uplink_port;
extern int hf_ismp_edp_sfs_option_uplink_core;
extern int hf_ismp_edp_sfs_option_uplink_switch;
extern int hf_ismp_edp_sfs_option_isolated;
extern int hf_ismp_edp_sfs_option_redun;
extern int hf_ismp_edp_sfs_option_conmsg;
extern int hf_ismp_edp_sfs_option_calltap;
extern int hf_ismp_edp_sfs_option_tagflood;
extern int hf_ismp_edp_sfs_option_unused2;
extern int hf_ismp_edp_sfs_option_resolve;
extern int hf_ismp_edp_sfs_option_flood;
extern int hf_ismp_edp_sfs_option_lsp;
extern int hf_ismp_edp_sfs_option_sfssup;
extern int hf_ismp_edp_sfs_option_unused1;
extern int hf_ismp_edp_rtr_option_level1;
extern int hf_ismp_edp_rtr_option_trans;
extern int hf_ismp_edp_rtr_option_route;
extern int hf_ismp_edp_rtr_option_igmp_snoop;
extern int hf_ismp_edp_rtr_option_gmrp;
extern int hf_ismp_edp_rtr_option_gvrp;
extern int hf_ismp_edp_rtr_option_8021q;
extern int hf_ismp_edp_rtr_option_dvmrp;
extern int hf_ismp_edp_rtr_option_ospf;
extern int hf_ismp_edp_rtr_option_bgp;
extern int hf_ismp_edp_rtr_option_rip;
extern int hf_ismp_edp_rtr_option_igmp;
extern int hf_ismp_edp_rtr_option_ssr;
extern int hf_ismp_edp_switch_option_level1;
extern int hf_ismp_edp_switch_option_trans;
extern int hf_ismp_edp_switch_option_route;
extern int hf_ismp_edp_switch_option_igmp;
extern int hf_ismp_edp_switch_option_gmrp;
extern int hf_ismp_edp_switch_option_gvrp;
extern int hf_ismp_edp_switch_option_8021q;
extern int hf_ismp_edp_end_station_option_ad;
extern int hf_ismp_edp_end_station_option_dns;
extern int hf_ismp_edp_end_station_option_dhcp;
extern int ett_ismp_edp;
extern int ett_ismp_edp_options;
extern int ett_ismp_edp_neighbors;
extern int ett_ismp_edp_neighbors_leaf;
extern int ett_ismp_edp_tuples;
extern int ett_ismp_edp_tuples_leaf;
extern expert_field ei_ismp_malformed;

void col_set_str(void *cinfo, int column, const char *str);
void col_clear(void *cinfo, int column);
void col_add_fstr(void *cinfo, int column, const char *format, ...);
void col_append_fstr(void *cinfo, int column, const char *format, ...);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
proto_tree *proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **tree_item, const char *format, ...);
const char *tvb_ip_to_str(tvbuff_t *tvb, int offset);
const char *tvb_ether_to_str(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
const guint8 *tvb_get_ptr(tvbuff_t *tvb, int offset, int length);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
const char *tvb_format_text(tvbuff_t *tvb, int offset, int length);
const char *ipx_addr_to_str(guint32 network, const guint8 *node);
void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int offset, int length);
proto_item *proto_tree_add_bytes_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const void *data_ptr, const char *format, ...);
void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hfindex, int ett, const gint *const *fields, int encoding);
void proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *value);
void proto_item_set_len(proto_item *item, int length);
void proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...);
void proto_tree_add_item_ret_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, guint32 *retval);