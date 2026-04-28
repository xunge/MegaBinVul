#include <stdint.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define ENC_BIG_ENDIAN 0

typedef int gboolean;
typedef int8_t gint8;
typedef int32_t gint32;
typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int32_t gint;

typedef struct {
    const char *name;
    int value;
} value_string;

typedef struct {
    const char *true_string;
    const char *false_string;
} ber_pc_codes_short_t;

typedef struct {
    int dummy;
} expert_field;

typedef struct frame_data {
    unsigned int num;
} frame_data;

typedef struct pinfo {
    frame_data *fd;
} pinfo;

typedef struct proto_tree proto_tree;
typedef struct tvbuff_t {
    int dummy;
} tvbuff_t;
typedef struct proto_item proto_item;
typedef struct asn_namedbit {
    int *p_id;
    int bit;
    int gb0;
    int gb1;
    const char *tstr;
    const char *fstr;
} asn_namedbit;

typedef struct asn1_ctx_t {
    pinfo *pinfo;
    proto_item *created_item;
} asn1_ctx_t;

enum {
    BER_CLASS_UNI = 0,
    BER_CLASS_APP = 1,
    BER_UNI_TAG_BITSTRING = 3
};

extern const value_string ber_class_codes[];
extern const ber_pc_codes_short_t ber_pc_codes_short;
extern gboolean decode_unexpected;
extern expert_field ei_ber_expected_bitstring;
extern expert_field ei_ber_constr_bitstr;
extern expert_field ei_ber_illegal_padding;
extern expert_field ei_ber_bits_unknown;
extern expert_field ei_ber_bits_set_padded;
extern int hf_ber_error;
extern int hf_ber_bitstring_empty;
extern int hf_ber_bitstring_padding;
extern int ett_ber_unknown;

int dissect_ber_identifier(pinfo *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gint8 *ber_class, gboolean *pc, gint32 *tag);
int dissect_ber_length(pinfo *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 *len, gboolean *indefinite);
void tvb_ensure_bytes_exist(tvbuff_t *tvb, int offset, int length);
proto_item *proto_tree_add_string_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *format, ...);
const char *val_to_str_const(int value, const value_string *vs, const char *default_str);
void expert_add_info(pinfo *pinfo, proto_item *item, expert_field *ef);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
void dissect_unknown_ber(pinfo *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree);
void proto_tree_add_expert_format(proto_tree *tree, pinfo *pinfo, expert_field *ef, tvbuff_t *tvb, int start, int length, const char *format, ...);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void expert_add_info_format(pinfo *pinfo, proto_item *item, expert_field *ef, const char *format, ...);
tvbuff_t *ber_tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);
void proto_item_append_text(proto_item *item, const char *format, ...);
void proto_tree_add_boolean(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
char *bytes_to_str(void *scope, const guint8 *buf, size_t len);
void ber_check_length(int actual_len, int min_len, int max_len, asn1_ctx_t *actx, proto_item *item, gboolean is_bitstring);
guint32 tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void *wmem_packet_scope(void);
guint8 *tvb_memdup(void *scope, tvbuff_t *tvb, int offset, size_t length);