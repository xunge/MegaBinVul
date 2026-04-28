#include <stdint.h>
#include <stdbool.h>

#define TRUE true
#define FALSE false
typedef unsigned int guint;

typedef struct {
    uint16_t ike_encr_alg;
    uint16_t ike_hash_alg;
    bool is_psk;
    uint16_t group;
    uint16_t ike_encr_keylen;
} decrypt_data_t;

enum {
    IKE_ATTR_ENCRYPTION_ALGORITHM,
    IKE_ATTR_HASH_ALGORITHM,
    IKE_ATTR_AUTHENTICATION_METHOD,
    IKE_ATTR_GROUP_DESCRIPTION,
    IKE_ATTR_GROUP_TYPE,
    IKE_ATTR_GROUP_PRIME,
    IKE_ATTR_GROUP_GENERATOR_ONE,
    IKE_ATTR_GROUP_GENERATOR_TWO,
    IKE_ATTR_GROUP_CURVE_A,
    IKE_ATTR_GROUP_CURVE_B,
    IKE_ATTR_LIFE_TYPE,
    IKE_ATTR_LIFE_DURATION,
    IKE_ATTR_PRF,
    IKE_ATTR_KEY_LENGTH,
    IKE_ATTR_FIELD_SIZE,
    IKE_ATTR_GROUP_ORDER
};

typedef struct {} tvbuff_t;
typedef struct {} packet_info;
typedef struct {} proto_tree;
typedef struct {} proto_item;
typedef struct {} expert_field;
typedef struct {} value_string;

#define ENC_BIG_ENDIAN 0
#define ENC_NA 0

extern int hf_isakmp_ike_attr;
extern int hf_isakmp_ike_attr_encryption_algorithm;
extern int hf_isakmp_ike_attr_hash_algorithm;
extern int hf_isakmp_ike_attr_authentication_method;
extern int hf_isakmp_ike_attr_group_description;
extern int hf_isakmp_ike_attr_group_type;
extern int hf_isakmp_ike_attr_group_prime;
extern int hf_isakmp_ike_attr_group_generator_one;
extern int hf_isakmp_ike_attr_group_generator_two;
extern int hf_isakmp_ike_attr_group_curve_a;
extern int hf_isakmp_ike_attr_group_curve_b;
extern int hf_isakmp_ike_attr_life_type;
extern int hf_isakmp_ike_attr_life_duration_uint32;
extern int hf_isakmp_ike_attr_life_duration_uint64;
extern int hf_isakmp_ike_attr_life_duration_bytes;
extern int hf_isakmp_ike_attr_prf;
extern int hf_isakmp_ike_attr_key_length;
extern int hf_isakmp_ike_attr_field_size;
extern int hf_isakmp_ike_attr_group_order;

extern const value_string ike_attr_type[];
extern const value_string ike_attr_enc_algo[];
extern const value_string ike_attr_hash_algo[];
extern const value_string ike_attr_authmeth[];
extern const value_string dh_group[];
extern const value_string ike_attr_grp_type[];
extern const value_string attr_life_type[];

extern expert_field ei_isakmp_attribute_value_empty;

uint16_t tvb_get_ntohs(tvbuff_t *tvb, int offset);
const char *val_to_str(unsigned int val, const value_string *vs, const char *fmt);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_item_append_text(proto_item *item, const char *format, ...);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *expert);
void dissect_attribute_header(tvbuff_t *tvb, proto_tree *tree, int offset, int hf_attr, const value_string *vs, guint *headerlen, guint *value_len, guint *attr_type, proto_item **attr_item, proto_tree **attr_tree);
void dissect_life_duration(tvbuff_t *tvb, proto_tree *tree, proto_item *item, int hf_uint32, int hf_uint64, int hf_bytes, int offset, guint value_len);