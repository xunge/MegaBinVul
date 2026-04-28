#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct expert_field {} expert_field;

typedef enum {
    ENC_NA,
    ENC_BIG_ENDIAN,
    ENC_ASCII
} encoding_type;

typedef enum {
    COL_INFO
} column_type;

typedef enum {
    ASN1_ENC_BER
} asn1_encoding;

typedef struct {
    column_type cinfo;
} packet_info;

typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct tvbuff tvbuff_t;

typedef struct asn1_ctx_t {
    asn1_encoding encoding;
    bool fast;
    packet_info *pinfo;
} asn1_ctx_t;

typedef struct value_string {
    int value;
    const char *strptr;
} value_string;

#define TRUE true
#define FALSE false

extern int proto_rpkirtr;
extern int ett_rpkirtr;
extern int ett_flags;
extern int ett_flags_nd;
extern int hf_rpkirtr_version;
extern int hf_rpkirtr_pdu_type;
extern int hf_rpkirtr_session_id;
extern int hf_rpkirtr_length;
extern int hf_rpkirtr_serial_number;
extern int hf_rpkirtr_reserved;
extern int hf_rpkirtr_flags;
extern int hf_rpkirtr_flags_aw;
extern int hf_rpkirtr_flags_rk;
extern int hf_rpkirtr_prefix_length;
extern int hf_rpkirtr_max_length;
extern int hf_rpkirtr_ipv4_prefix;
extern int hf_rpkirtr_ipv6_prefix;
extern int hf_rpkirtr_as_number;
extern int hf_rpkirtr_refresh_interval;
extern int hf_rpkirtr_retry_interval;
extern int hf_rpkirtr_expire_interval;
extern int hf_rpkirtr_subject_key_identifier;
extern int hf_rpkirtr_subject_public_key_info;
extern int hf_rpkirtr_error_code;
extern int hf_rpkirtr_length_pdu;
extern int hf_rpkirtr_error_pdu;
extern int hf_rpkirtr_length_text;
extern int hf_rpkirtr_error_text;
extern expert_field ei_rpkirtr_wrong_version_router_key;
extern expert_field ei_rpkirtr_bad_length;

typedef uint8_t guint8;
typedef unsigned int guint;
typedef uint32_t guint32;

static const value_string rtr_pdu_type_vals[] = {
    {0, "Serial Notify"},
    {1, "Serial Query"},
    {2, "Reset Query"},
    {3, "Cache Response"},
    {4, "IPv4 Prefix"},
    {6, "IPv6 Prefix"},
    {7, "End Of Data"},
    {8, "Cache Reset"},
    {9, "Router Key"},
    {10, "Error Report"},
    {0, NULL}
};

#define RPKI_RTR_SERIAL_NOTIFY_PDU 0
#define RPKI_RTR_SERIAL_QUERY_PDU 1
#define RPKI_RTR_RESET_QUERY_PDU 2
#define RPKI_RTR_CACHE_RESPONSE_PDU 3
#define RPKI_RTR_IPV4_PREFIX_PDU 4
#define RPKI_RTR_IPV6_PREFIX_PDU 6
#define RPKI_RTR_END_OF_DATA_PDU 7
#define RPKI_RTR_CACHE_RESET_PDU 8
#define RPKI_RTR_ROUTER_KEY 9
#define RPKI_RTR_ERROR_REPORT_PDU 10

#define _U_ __attribute__((unused))

/* Function prototypes */
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
int tvb_reported_length(tvbuff_t *tvb);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, 
                               int start, int length, encoding_type encoding);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void col_append_sep_str(column_type cinfo, column_type col, const char *sep, 
                       const char *str);
const char* val_to_str(int val, const value_string *vs, const char *fmt);
void proto_item_append_text(proto_item *item, const char *format, ...);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef);
void asn1_ctx_init(asn1_ctx_t *ctx, asn1_encoding enc, bool fast, packet_info *pinfo);
int dissect_x509af_SubjectPublicKeyInfo(bool implicit_tag, tvbuff_t *tvb, int offset, 
                                      asn1_ctx_t *actx, proto_tree *tree, int hf_index);