#include <stdint.h>

typedef uint16_t guint16;
typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;

#define _U_ __attribute__((unused))

static int ett_openflow_v5_queue_desc_prop;
static int hf_openflow_v5_queue_desc_prop_property;
static int hf_openflow_v5_queue_desc_prop_len;
static int hf_openflow_v5_queue_desc_prop_pad;
static int hf_openflow_v5_queue_desc_prop_min_rate_rate;
static int hf_openflow_v5_queue_desc_prop_min_rate_rate_reserved;
static int hf_openflow_v5_queue_desc_prop_min_rate_pad;
static int hf_openflow_v5_queue_desc_prop_max_rate_rate;
static int hf_openflow_v5_queue_desc_prop_max_rate_rate_reserved;
static int hf_openflow_v5_queue_desc_prop_max_rate_pad;
static int hf_openflow_v5_queue_desc_prop_experimenter_experimenter;
static int hf_openflow_v5_queue_desc_prop_experimenter_exp_type;
static expert_field ei_openflow_v5_length_too_short;
static expert_field ei_openflow_v5_queue_desc_prop_undecoded;

#define OFPQDPT_MIN_RATE 1
#define OFPQDPT_MAX_RATE 2
#define OFPQDPT_EXPERIMENTER 0xffff
#define OFPQDP_MIN_RATE_MAX 1000
#define OFPQDP_MAX_RATE_MAX 1000

#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *text);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, int encoding);
void proto_item_set_len(proto_item *ti, int length);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
void expert_add_info(packet_info *pinfo, proto_item *ti, expert_field *ef);
proto_item* proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int offset, int length, const char *format, ...);