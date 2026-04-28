#include <stdint.h>
#include <stddef.h>

#define OFPACPT_PACKET_IN_SLAVE 0
#define OFPACPT_PACKET_IN_MASTER 1
#define OFPACPT_PORT_STATUS_SLAVE 2
#define OFPACPT_PORT_STATUS_MASTER 3
#define OFPACPT_FLOW_REMOVED_SLAVE 4
#define OFPACPT_FLOW_REMOVED_MASTER 5
#define OFPACPT_ROLE_STATUS_SLAVE 6
#define OFPACPT_ROLE_STATUS_MASTER 7
#define OFPACPT_TABLE_STATUS_SLAVE 8
#define OFPACPT_TABLE_STATUS_MASTER 9
#define OFPACPT_REQUESTFORWARD_SLAVE 10
#define OFPACPT_REQUESTFORWARD_MASTER 11
#define OFPACPT_EXPERIMENTER_SLAVE 12
#define OFPACPT_EXPERIMENTER_MASTER 13

#define ENC_BIG_ENDIAN 0
#define _U_ __attribute__((unused))

typedef uint16_t guint16;
typedef struct tvbuff {
    guint16 (*get_ntohs)(struct tvbuff*, int);
} tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;

static guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset) {
    return tvb->get_ntohs(tvb, offset);
}

static proto_tree* proto_tree_add_subtree(proto_tree *parent, tvbuff_t *tvb, int offset, int length, 
                                        int ett, proto_item** item, const char *text) {
    return NULL;
}

static proto_item* proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, 
                                     int start, int length, int encoding) {
    return NULL;
}

static proto_tree* proto_item_add_subtree(proto_item *item, int ett) {
    return NULL;
}

static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef) {
}

static void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, 
                                       expert_field *ef, tvbuff_t *tvb, 
                                       int offset, int length, const char *text) {
}

static int ett_openflow_v6_async_config_prop;
static int ett_openflow_v6_async_config_prop_reason_packet_in_mask;
static int ett_openflow_v6_async_config_prop_reason_port_status_mask;
static int ett_openflow_v6_async_config_prop_reason_flow_removed_mask;
static int ett_openflow_v6_async_config_prop_reason_role_status_mask;
static int ett_openflow_v6_async_config_prop_reason_table_status_mask;
static int ett_openflow_v6_async_config_prop_reason_requestforward_mask;

static int hf_openflow_v6_async_config_prop_type;
static int hf_openflow_v6_async_config_prop_length;
static int hf_openflow_v6_async_config_prop_reason_packet_in_mask;
static int hf_openflow_v6_async_config_prop_reason_packet_in_mask_table_miss;
static int hf_openflow_v6_async_config_prop_reason_packet_in_mask_apply_action;
static int hf_openflow_v6_async_config_prop_reason_packet_in_mask_invalid_ttl;
static int hf_openflow_v6_async_config_prop_reason_packet_in_mask_action_set;
static int hf_openflow_v6_async_config_prop_reason_packet_in_mask_group;
static int hf_openflow_v6_async_config_prop_reason_packet_in_mask_packet_out;
static int hf_openflow_v6_async_config_prop_reason_port_status_mask;
static int hf_openflow_v6_async_config_prop_reason_port_status_mask_add;
static int hf_openflow_v6_async_config_prop_reason_port_status_mask_delete;
static int hf_openflow_v6_async_config_prop_reason_port_status_mask_modify;
static int hf_openflow_v6_async_config_prop_reason_flow_removed_mask;
static int hf_openflow_v6_async_config_prop_reason_flow_removed_mask_idle_timeout;
static int hf_openflow_v6_async_config_prop_reason_flow_removed_mask_hard_timeout;
static int hf_openflow_v6_async_config_prop_reason_flow_removed_mask_delete;
static int hf_openflow_v6_async_config_prop_reason_flow_removed_mask_group_delete;
static int hf_openflow_v6_async_config_prop_reason_flow_removed_mask_meter_delete;
static int hf_openflow_v6_async_config_prop_reason_flow_removed_mask_eviction;
static int hf_openflow_v6_async_config_prop_reason_role_status_mask;
static int hf_openflow_v6_async_config_prop_reason_role_status_mask_master_request;
static int hf_openflow_v6_async_config_prop_reason_role_status_mask_config;
static int hf_openflow_v6_async_config_prop_reason_role_status_mask_experimenter;
static int hf_openflow_v6_async_config_prop_reason_table_status_mask;
static int hf_openflow_v6_async_config_prop_reason_table_status_mask_vacancy_down;
static int hf_openflow_v6_async_config_prop_reason_table_status_mask_vacancy_up;
static int hf_openflow_v6_async_config_prop_reason_requestforward_mask;
static int hf_openflow_v6_async_config_prop_reason_requestforward_mask_group_mod;
static int hf_openflow_v6_async_config_prop_reason_requestforward_mask_meter_mod;
static int hf_openflow_v6_async_config_prop_experimenter_experimenter;
static int hf_openflow_v6_async_config_prop_experimenter_exp_type;

static expert_field ei_openflow_v6_length_too_short = {0};
static expert_field ei_openflow_v6_async_config_prop_undecoded = {0};