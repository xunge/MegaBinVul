#include <stdint.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gint;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

static int hf_xra_tlv_ms_info = -1;
static int hf_xra_tlv_start_minislot_id_abs = -1;
static int hf_xra_tlv_start_minislot_id_rel = -1;
static int hf_xra_tlv_stop_minislot_id_rel = -1;
static int hf_xra_unknown = -1;
static int ett_xra_tlv_ms_info = -1;

#define XRA_TLV_MINISLOT_INFO_START_MINISLOT_ID 0
#define XRA_TLV_MINISLOT_INFO_REL_START_MINISLOT 1
#define XRA_TLV_MINISLOT_INFO_REL_STOP_MINISLOT 2

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define _U_ __attribute__((unused))

guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
guint32 tvb_captured_length(tvbuff_t *tvb);