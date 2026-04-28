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

static int ett_openflow_v6_queue_stats_prop;
static int hf_openflow_v6_queue_stats_prop_type;
static int hf_openflow_v6_queue_stats_prop_length;
static int hf_openflow_v6_queue_stats_prop_experimenter_experimenter;
static int hf_openflow_v6_queue_stats_prop_experimenter_exp_type;
static expert_field ei_openflow_v6_length_too_short;
static expert_field ei_openflow_v6_queue_stats_prop_undecoded;

#define OFPMP_EXPERIMENTER 0xFFFF
#define ENC_BIG_ENDIAN 0
#define _U_

static guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset) { return 0; }
static proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, void *null, const char *name) { return NULL; }
static int proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding) { return 0; }
static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef) {}
static void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int offset, int length, const char *format, ...) {}