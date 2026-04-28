#include <stdint.h>
#include <stddef.h>

#define OFPTMPT_EVICTION 0
#define OFPTMPT_VACANCY 1
#define OFPTMPT_EXPERIMENTER 0xFFFF

typedef uint16_t guint16;
typedef uint8_t guint8;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field {
    int dummy;
} expert_field;

#define _U_
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

static int ett_openflow_v6_tablemod_prop = -1;
static int ett_openflow_v6_tablemod_prop_eviction_flags = -1;

static int hf_openflow_v6_tablemod_prop_type = -1;
static int hf_openflow_v6_tablemod_prop_length = -1;
static int hf_openflow_v6_tablemod_prop_eviction_flags = -1;
static int hf_openflow_v6_tablemod_prop_eviction_flags_other = -1;
static int hf_openflow_v6_tablemod_prop_eviction_flags_importance = -1;
static int hf_openflow_v6_tablemod_prop_eviction_flags_lifetime = -1;
static int hf_openflow_v6_tablemod_prop_vacancy_vacancy_down = -1;
static int hf_openflow_v6_tablemod_prop_vacancy_vacancy_up = -1;
static int hf_openflow_v6_tablemod_prop_vacancy_vacancy = -1;
static int hf_openflow_v6_tablemod_prop_vacancy_pad = -1;
static int hf_openflow_v6_tablemod_prop_experimenter_experimenter = -1;
static int hf_openflow_v6_tablemod_prop_experimenter_exp_type = -1;

static expert_field ei_openflow_v6_length_too_short = {0};
static expert_field ei_openflow_v6_tablemod_prop_undecoded = {0};

static guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset) { return 0; }
static proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, void *null, const char *name) { return NULL; }
static proto_item* proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef) {}
static void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int offset, int length, const char *format, ...) {}