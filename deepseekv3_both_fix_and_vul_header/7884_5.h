#include <stdint.h>
#include <stddef.h>

#define OFPBPT_EXPERIMENTER 0xFFFF
#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0

typedef uint16_t guint16;

extern int ett_openflow_v6_bundle_prop;
extern struct expert_field ei_openflow_v6_length_too_short;
extern struct expert_field ei_openflow_v6_bundle_prop_undecoded;
extern int hf_openflow_v6_bundle_prop_type;
extern int hf_openflow_v6_bundle_prop_length;
extern int hf_openflow_v6_bundle_prop_experimenter_experimenter;
extern int hf_openflow_v6_bundle_prop_experimenter_exp_type;

typedef struct tvbuff {
    uint16_t (*get_ntohs)(struct tvbuff*, int);
} tvbuff_t;

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

static inline uint16_t tvb_get_ntohs(tvbuff_t *tvb, int offset) {
    return tvb->get_ntohs(tvb, offset);
}

static inline proto_tree* proto_tree_add_subtree(proto_tree *parent, tvbuff_t *tvb, int offset, int length, 
                                               int ett, proto_item* item, const char* text) {
    return NULL;
}

static inline proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, 
                                     int start, int length, int encoding) {
    return NULL;
}

static inline void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, 
                                              expert_field *ef, tvbuff_t *tvb, 
                                              int start, int length, const char *format, ...) {}

static inline void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef) {}