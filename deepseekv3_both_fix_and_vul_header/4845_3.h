#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define FALSE false
#define TRUE true
#define ENC_BIG_ENDIAN 0

typedef bool gboolean;
typedef int8_t gint8;
typedef int32_t gint32;
typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int gint;

struct value_string {
    unsigned int value;
    const char *strptr;
};

struct value_string_ext {
    struct value_string *value_string;
    const char *true_string;
    const char *false_string;
};

struct expert_field {
    int ei;
    const char *name;
};

typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;

typedef struct asn1_ctx {
    proto_item *created_item;
    packet_info *pinfo;
} asn1_ctx_t;

typedef struct asn_namedbit {
    int bit;
    int gb0;
    int gb1;
    int *p_id;
    const char *tstr;
    const char *fstr;
} asn_namedbit;

extern gboolean decode_unexpected;
extern int hf_ber_error;
extern int hf_ber_bitstring_empty;
extern int hf_ber_bitstring_padding;
extern int ett_ber_unknown;
extern struct expert_field ei_ber_expected_bitstring;
extern struct expert_field ei_ber_illegal_padding;
extern struct expert_field ei_ber_bits_unknown;
extern struct expert_field ei_ber_bits_set_padded;

extern const struct value_string ber_class_codes[];
extern const struct value_string_ext ber_pc_codes_short;

#define BER_CLASS_APP 1
#define BER_CLASS_UNI 2
#define BER_UNI_TAG_BITSTRING 3

/* Function prototypes */
int dissect_ber_identifier(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, gint8 *ber_class, gboolean *pc, gint32 *tag);
int dissect_ber_length(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint32 *len, gboolean *indefinite);
void tvb_ensure_bytes_exist(tvbuff_t *tvb, int offset, int length);
proto_item *proto_tree_add_string_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *value, const char *format, ...);
const char *val_to_str_const(unsigned int value, const struct value_string *vs, const char *default_str);
void expert_add_info(packet_info *pinfo, proto_item *item, struct expert_field *expert);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
void dissect_unknown_ber(packet_info *pinfo, tvbuff_t *tvb, int offset, proto_tree *tree);
int tvb_length_remaining(tvbuff_t *tvb, int offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void expert_add_info_format(packet_info *pinfo, proto_item *item, struct expert_field *expert, const char *format, ...);
tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);
tvbuff_t *tvb_new_subset_remaining(tvbuff_t *tvb, int offset);
void *tvb_memdup(void *scope, tvbuff_t *tvb, int offset, int length);
void *wmem_packet_scope(void);
proto_item *proto_tree_add_boolean(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
void proto_item_append_text(proto_item *item, const char *format, ...);
char *bytes_to_ep_str(const guint8 *bytes, int len);
void ber_check_length(int actual_len, gint32 min_len, gint32 max_len, asn1_ctx_t *actx, proto_item *item, gboolean report);