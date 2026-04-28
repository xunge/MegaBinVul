#include <stdint.h>

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    int ike_encr_alg;
    int ike_encr_keylen;
    int ike_hash_alg;
} decrypt_data_t;

typedef struct {
    uint32_t value;
    const char *strptr;
} value_string;

#define ENC_BIG_ENDIAN 0
#define ENC_NA 0

#define TF_IKE2_ENCR 1
#define TF_IKE2_PRF 2
#define TF_IKE2_INTEG 3
#define TF_IKE2_DH 4
#define TF_IKE2_ESN 5

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef int32_t gint32;

extern int hf_isakmp_trans_number;
extern int hf_isakmp_trans_id;
extern int hf_isakmp_reserved;
extern int hf_isakmp_trans_type;
extern int hf_isakmp_trans_encr;
extern int hf_isakmp_trans_prf;
extern int hf_isakmp_trans_integ;
extern int hf_isakmp_trans_dh;
extern int hf_isakmp_trans_esn;
extern int hf_isakmp_trans_id_v2;

extern const value_string vs_v1_trans_isakmp[];
extern const value_string vs_v1_trans_ah[];
extern const value_string vs_v1_trans_esp[];
extern const value_string transform_id_ipcomp[];

guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void proto_item_append_text(proto_item *item, const char *format, ...);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_item* proto_tree_add_uint_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...);
const char* val_to_str_const(guint32 value, const value_string *vs, const char *unknown_str);

int dissect_ike_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, decrypt_data_t *decr);
int dissect_ipsec_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);
int dissect_ike2_transform_attribute(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset);