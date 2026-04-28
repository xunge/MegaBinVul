#include <stdint.h>
#include <string.h>

#define BLOCK_CONTROL_LAST_BLOCK 0x01
#define BLOCK_CONTROL_EID_REFERENCE 0x02
#define BLOCK_CONTROL_REPLICATE 0x04
#define ECOS_FLAGS_ORDINAL 0x04

typedef uint8_t guint8;
typedef int gboolean;
typedef char gchar;

struct proto_tree;
struct proto_item;
struct tvbuff_t;
struct packet_info;
struct expert_field {
    int dummy;
};

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct expert_field expert_field;

static int evaluate_sdnv(tvbuff_t *tvb, int offset, int *length) {
    return 0;
}

static int tvb_get_guint8(tvbuff_t *tvb, int offset) {
    return 0;
}

static proto_tree* proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **item, const char *text) {
    return NULL;
}

static void proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int encoding) {
}

static proto_item* proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, unsigned int value) {
    return NULL;
}

static proto_tree* proto_item_add_subtree(proto_item *item, int ett) {
    return NULL;
}

static proto_item* proto_tree_add_boolean(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, unsigned int value) {
    return NULL;
}

static proto_item* proto_tree_add_int(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, int value) {
    return NULL;
}

static void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ef, const char *fmt, ...) {
}

static void proto_item_set_len(proto_item *item, int length) {
}

static char* tvb_get_string_enc(void *scope, tvbuff_t *tvb, int offset, int length, int encoding) {
    return NULL;
}

static void* wmem_packet_scope() {
    return NULL;
}

static proto_item* proto_tree_add_string(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, const char *value) {
    return NULL;
}

static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef) {
}

static void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hf, int ett, const int **fields, int encoding) {
}

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
static int hf_block_control_block_cteb_custody_id;
static int hf_block_control_block_cteb_creator_custodian_eid;
static int hf_ecos_flags;
static int hf_ecos_flags_critical;
static int hf_ecos_flags_streaming;
static int hf_ecos_flags_ordinal;
static int hf_ecos_ordinal;
static int hf_ecos_flow_label;

static expert_field ei_bundle_offset_error;
static expert_field ei_bundle_block_control_flags;
static expert_field ei_block_control_block_cteb_invalid;
static expert_field ei_block_control_block_cteb_valid;
static expert_field ei_bundle_sdnv_length;

static int ett_metadata_hdr;
static int ett_block_flags;

#define BUNDLE_BLOCK_TYPE_AUTHENTICATION 1
#define BUNDLE_BLOCK_TYPE_INTEGRITY 2
#define BUNDLE_BLOCK_TYPE_CONFIDENTIALITY 3
#define BUNDLE_BLOCK_TYPE_PREVIOUS_HOP_INSERT 4
#define BUNDLE_BLOCK_TYPE_METADATA_EXTENSION 5
#define BUNDLE_BLOCK_TYPE_EXTENSION_SECURITY 6
#define BUNDLE_BLOCK_TYPE_CUSTODY_TRANSFER 7
#define BUNDLE_BLOCK_TYPE_EXTENDED_COS 8

#define TRUE 1
#define FALSE 0
#define ENC_BIG_ENDIAN 0
#define ENC_ASCII 0