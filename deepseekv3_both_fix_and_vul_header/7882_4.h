#include <stdint.h>
#include <stddef.h>

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;

typedef uint16_t guint16;

#define ENC_BIG_ENDIAN 0
#define _U_

static int ett_openflow_v6_port_desc_prop;
static int hf_openflow_v6_port_desc_prop_type;
static int hf_openflow_v6_port_desc_prop_length;
static int hf_openflow_v6_port_desc_prop_experimenter_experimenter;
static int hf_openflow_v6_port_desc_prop_experimenter_exp_type;
static expert_field ei_openflow_v6_length_too_short;
static expert_field ei_openflow_v6_port_desc_prop_undecoded;

#define OFPPDPT_ETHERNET 0
#define OFPPDPT_OPTICAL 1
#define OFPPDPT_EXPERIMENTER 0xFFFF

static uint16_t tvb_get_ntohs(tvbuff_t *tvb, int offset) { return 0; }
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding) { return NULL; }
proto_tree* proto_tree_add_subtree(proto_tree *parent_tree, tvbuff_t *tvb, int start, int length, int idx, proto_item **tree_item, const char *text) { return NULL; }
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert) {}
void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int start, int length, const char *format, ...) {}

static int dissect_openflow_port_desc_prop_ethernet_v6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length) { return 0; }
static int dissect_openflow_port_desc_prop_optical_v6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length) { return 0; }