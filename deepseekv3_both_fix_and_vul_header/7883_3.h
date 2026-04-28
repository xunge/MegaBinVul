#include <stdint.h>
#include <stddef.h>

typedef uint16_t guint16;
typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct { int dummy; } expert_field;

static int ett_openflow_v6_portmod_prop;
static int hf_openflow_v6_portmod_prop_type;
static int hf_openflow_v6_portmod_prop_length;
static int hf_openflow_v6_portmod_prop_experimenter_experimenter;
static int hf_openflow_v6_portmod_prop_experimenter_exp_type;
static expert_field ei_openflow_v6_length_too_short;
static expert_field ei_openflow_v6_portmod_prop_undecoded;

#define OFPPMPT_ETHERNET 0
#define OFPPMPT_OPTICAL 1
#define OFPPMPT_EXPERIMENTER 0xFFFF
#define ENC_BIG_ENDIAN 0
#define _U_ __attribute__((unused))

static guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
static proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item* item, const char *text);
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, int encoding);
static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);
static void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *expert, tvbuff_t *tvb, int offset, int length, const char *format, ...);

static int dissect_openflow_portmod_prop_ethernet_v6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length);
static int dissect_openflow_portmod_prop_optical_v6(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length);