#include <stdint.h>

#define OFPTT_MAX 0xfe
#define _U_ __attribute__((unused))
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef uint8_t guint8;
typedef uint16_t guint16;

extern int hf_openflow_v5_tablemod_table_id;
extern int hf_openflow_v5_tablemod_table_id_reserved;
extern int hf_openflow_v5_tablemod_pad;
extern int hf_openflow_v5_tablemod_config;
extern int hf_openflow_v5_tablemod_config_eviction;
extern int hf_openflow_v5_tablemod_config_vacancy_events;
extern int ett_openflow_v5_tablemod_config;

typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;

static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
static proto_tree* proto_item_add_subtree(proto_item *ti, int ett);
static int dissect_openflow_tablemod_prop_v5(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, guint16 length);