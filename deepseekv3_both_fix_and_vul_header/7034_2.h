#include <stdint.h>
#include <string.h>

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int32_t gint32;
typedef char gchar;
typedef int gboolean;

#define TRUE 1
#define FALSE 0

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t {
    int dummy;
} tvbuff_t;
typedef struct packet_info {
    void *pool;
} packet_info;
typedef struct expert_field {
    int dummy;
} expert_field;

#define ENC_BIG_ENDIAN 0
#define ENC_NA 0
#define ENC_ASCII 0

#define BLOCK_CONTROL_LAST_BLOCK 0x01
#define BLOCK_CONTROL_EID_REFERENCE 0x02
#define BLOCK_CONTROL_REPLICATE 0x04
#define BLOCK_CIPHERSUITE_PARAMS 0x01
#define ECOS_FLAGS_FLOWLABEL 0x04

#define BUNDLE_BLOCK_TYPE_AUTHENTICATION 0x01
#define BUNDLE_BLOCK_TYPE_METADATA_EXTENSION 0x02
#define BUNDLE_BLOCK_TYPE_EXTENSION_SECURITY 0x03
#define BUNDLE_BLOCK_TYPE_BUNDLE_AGE 0x04
#define BUNDLE_BLOCK_TYPE_PREVIOUS_HOP_INSERT 0x05
#define BUNDLE_BLOCK_TYPE_INTEGRITY 0x06
#define BUNDLE_BLOCK_TYPE_CONFIDENTIALITY 0x07
#define BUNDLE_BLOCK_TYPE_CUSTODY_TRANSFER 0x08
#define BUNDLE_BLOCK_TYPE_EXTENDED_COS 0x09

static int ett_metadata_hdr;
static int ett_block_flags;
static int ett_sec_block_param_data;

static int hf_bundle_block_type_code;
static int hf_block_control_flags_sdnv;
static int hf_block_control_replicate;
static int hf_block_control_transmit_status;
static int hf_block_control_delete_bundle;
static int hf_block_control_last_block;
static int hf_block_control_discard_block;
static int hf_block_control_not_processed;
static int hf_block_control_eid_reference;
static int hf_block_control_block_length;
static int hf_bundle_unprocessed_block_data;
static int hf_bundle_age_extension_block_code;
static int hf_bundle_block_previous_hop_scheme;
static int hf_bundle_block_previous_hop_eid;
static int hf_bundle_target_block_type;
static int hf_bundle_target_block_occurrence;
static int hf_bundle_ciphersuite_type;
static int hf_bundle_ciphersuite_flags;
static int hf_block_ciphersuite_params;
static int hf_block_ciphersuite_params_length;
static int hf_block_ciphersuite_param_type;
static int hf_block_ciphersuite_params_item_length;
static int hf_block_ciphersuite_param_data;
static int hf_block_ciphersuite_range_offset;
static int hf_block_ciphersuite_range_length;
static int hf_block_ciphersuite_result_length;
static int hf_block_ciphersuite_result_type;
static int hf_block_ciphersuite_result_item_length;
static int hf_block_ciphersuite_result_data;
static int hf_block_control_block_cteb_custody_id;
static int hf_block_control_block_cteb_creator_custodian_eid;
static int hf_ecos_flags;
static int hf_ecos_flags_critical;
static int hf_ecos_flags_streaming;
static int hf_ecos_flags_flowlabel;
static int hf_ecos_flags_reliable;
static int hf_ecos_ordinal;
static int hf_ecos_flow_label;

static expert_field ei_bundle_offset_error;
static expert_field ei_bundle_block_control_flags;
static expert_field ei_block_control_block_cteb_invalid;
static expert_field ei_block_control_block_cteb_valid;
static expert_field ei_bundle_sdnv_length;

static int evaluate_sdnv(tvbuff_t *tvb, int offset, int *length) { return 0; }
static int evaluate_sdnv_ei(tvbuff_t *tvb, int offset, int *length, expert_field **ei) { return 0; }
static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding) { return NULL; }
static proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value) { return NULL; }
static proto_item* proto_tree_add_boolean(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value) { return NULL; }
static proto_item* proto_tree_add_int(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, gint32 value) { return NULL; }
static proto_item* proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *label) { return NULL; }
static proto_item* proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hfindex, int ett, int *fields, int encoding) { return NULL; }
static proto_item* proto_tree_add_item_ret_length(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, int *ret_length) { return NULL; }
static proto_item* proto_tree_add_item_ret_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, void *pool, const guint8 **ret_string) { return NULL; }
static proto_item* proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ei, tvbuff_t *tvb, int start, int length) { return NULL; }
static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ei) {}
static void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ei, const char *format, ...) {}
static proto_item* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item **item, const char *text) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static void proto_item_set_len(proto_item *item, int length) {}
static int tvb_reported_length_remaining(tvbuff_t *tvb, int offset) { return 0; }