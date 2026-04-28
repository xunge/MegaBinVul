#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define _U_ 

#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define CONVERSATION_TIPC 0

#define TIPCv1 1
#define TIPCv2 2
#define TIPC_MAX_RECURSION_DEPTH 10
#define TIPCv2_LINK_PROTOCOL 2
#define TIPCv2_DATA_LOW 1
#define TIPCv2_DATA_NORMAL 2
#define TIPCv2_DATA_HIGH 3
#define TIPCv2_DATA_NON_REJECTABLE 4
#define TIPCv2_NEIGHBOUR_DISCOVERY 5
#define TIPC_ROUTING_MANAGER 1
#define TIPC_LINK_PROTOCOL 2
#define TIPC_CHANGEOVER_PROTOCOL 3
#define TIPC_SEGMENTATION_MANAGER 4
#define TIPC_MSG_BUNDLER 5
#define TIPC_NAME_DISTRIBUTOR 6
#define TIPC_CONNECTION_MANAGER 7
#define TIPC_CONNECTED_MSG 1
#define TIPC_NAMED_MSG 2
#define TIPC_DIRECT_MSG 3

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int gboolean;
typedef char gchar;

typedef struct tvbuff {
    int dummy;
} tvbuff_t;

typedef struct proto_item {
    int dummy;
} proto_item;

typedef struct proto_tree {
    int dummy;
} proto_tree;

typedef struct cinfo {
    int dummy;
} cinfo;

typedef struct address {
    int dummy;
} address;

typedef struct packet_info {
    cinfo *cinfo;
    address src;
    address dst;
} packet_info;

typedef struct expert_field {
    int dummy;
} expert_field;

static int proto_tipc = -1;
static int ett_tipc = -1;
static int ett_tipc_data = -1;
static int hf_tipc_ver = -1;
static int hf_tipc_usr = -1;
static int hf_tipc_hdr_size = -1;
static int hf_tipc_nonsequenced = -1;
static int hf_tipc_unused = -1;
static int hf_tipc_destdrop = -1;
static int hf_tipcv2_srcdrop = -1;
static int hf_tipc_msg_size = -1;
static int hf_tipc_ack_link_lev_seq = -1;
static int hf_tipc_link_lev_seq = -1;
static int hf_tipc_prev_proc = -1;
static int hf_tipc_org_port = -1;
static int hf_tipc_dst_port = -1;
static int hf_tipc_data = -1;
static int hf_tipc_nd_msg_type = -1;
static int hf_tipc_cm_msg_type = -1;
static int hf_tipc_data_msg_type = -1;
static int hf_tipc_err_code = -1;
static int hf_tipc_reroute_cnt = -1;
static int hf_tipc_act_id = -1;
static int hf_tipc_org_proc = -1;
static int hf_tipc_dst_proc = -1;
static int hf_tipc_port_name_type = -1;
static int hf_tipc_port_name_instance = -1;
static int hf_tipc_named_msg_hdr = -1;
static expert_field ei_tipc_max_recursion_depth_reached;

static const struct {
    int val;
    const char *str;
} tipc_user_values[] = {
    {0, "Reserved"},
    {1, "Routing Manager"},
    {2, "Link Protocol"},
    {3, "Changeover Protocol"},
    {4, "Segmentation Manager"},
    {5, "Message Bundler"},
    {6, "Name Distributor"},
    {7, "Connection Manager"},
    {0, NULL}
};

static const struct {
    int val;
    const char *str;
} tipcv2_user_short_str_vals[] = {
    {0, "Reserved"},
    {1, "Data Low"},
    {2, "Data Normal"},
    {3, "Data High"},
    {4, "Data Non-rejectable"},
    {5, "Neighbour Discovery"},
    {6, "Link Protocol"},
    {0, NULL}
};

static gboolean dissect_tipc_data = TRUE;
static proto_tree *top_tree = NULL;
static int tipc_address_type = -1;

static void col_set_str(cinfo *cinfo, int col, const char *str) {}
static void col_clear(cinfo *cinfo, int col) {}
static guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset) { return 0; }
static guint32 tvb_reported_length_remaining(tvbuff_t *tvb, int offset) { return 0; }
static tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length) { return NULL; }
static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static void col_append_fstr(cinfo *cinfo, int col, const char *fmt, ...) {}
static const char *val_to_str_const(int val, const void *vals, const char *default_str) { return NULL; }
static gboolean tipc_v1_set_col_msgtype(packet_info *pinfo, guint8 user, guint8 msg_type) { return FALSE; }
static void set_address_tvb(address *addr, int type, int size, tvbuff_t *tvb, int offset) {}
static void tipc_v2_set_info_col(tvbuff_t *tvb, packet_info *pinfo, guint8 user, guint8 msg_type, guint8 hdr_size) {}
static void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int offset, int length) {}
static int tvb_captured_length(tvbuff_t *tvb) { return 0; }
static void p_set_proto_depth(packet_info *pinfo, int proto, unsigned depth) {}
static unsigned p_get_proto_depth(packet_info *pinfo, int proto) { return 0; }
static proto_item *proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding) { return NULL; }
static proto_tree *proto_item_add_subtree(proto_item *ti, int ett) { return NULL; }
static void proto_item_append_text(proto_item *item, const char *fmt, ...) {}
static void proto_tree_add_item_ret_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding, guint32 *retval) {}
static void conversation_set_conv_addr_port_endpoints(packet_info *pinfo, address *src, address *dst, int conv_type, guint32 srcport, guint32 destport) {}
static void proto_tree_add_string(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, const char *str) {}
static void dissect_tipc_v2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, int offset, guint8 user, guint32 msg_size, guint8 hdr_size, gboolean datatype_hdr) {}
static void dissect_tipc_int_prot_msg(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint8 user, guint32 msg_size) {}
static void dissect_tipc_name_dist_data(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset) {}
static void call_tipc_v2_data_subdissectors(tvbuff_t *tvb, packet_info *pinfo, guint32 *name_type_p, guint8 user) {}
static char *tipc_addr_to_str(guint32 addr) { return NULL; }
static tvbuff_t *tvb_new_subset_remaining(tvbuff_t *tvb, int offset) { return NULL; }
static proto_tree *proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *fmt, ...) { return NULL; }