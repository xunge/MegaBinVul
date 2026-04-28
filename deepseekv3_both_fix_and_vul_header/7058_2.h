#include <stdint.h>

typedef int32_t gint;
typedef uint32_t guint32;
typedef uint8_t guint8;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void *pool;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define signed_external 0
#define unsecured 1
#define signed_pl 2
#define encrypted 3
#define signed_and_encrypted 4

#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

static int hf_sgeonw_payload_field_type;
static int hf_sgeonw_payload_field;
static int hf_sgeonw_opaque;
static int ett_sgeonw_field;
static int proto_geonw;
#define SEC_TVB_KEY 0

static int dissect_sec_var_len(tvbuff_t *tvb, gint *offset, packet_info *pinfo, proto_tree *tree);
void *wmem_file_scope(void);
void p_add_proto_data(void *pool, packet_info *pinfo, int proto, int key, tvbuff_t *tvb);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset);
tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);