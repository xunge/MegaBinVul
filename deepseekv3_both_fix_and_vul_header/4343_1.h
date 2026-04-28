#include <stdint.h>

typedef uint8_t guint8;
typedef uint32_t guint32;
typedef unsigned int guint;

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;

extern int hf_pktc_server_nonce;
extern int hf_pktc_server_principal;
extern int hf_pktc_timestamp;
extern int hf_pktc_sec_param_lifetime;
extern int hf_pktc_grace_period;
extern int hf_pktc_reestablish_flag;
extern int hf_pktc_sha1_hmac;

#define ENC_ASCII 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 0

#define KMMID_REKEY 0

guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
guint tvb_strsize(tvbuff_t *tvb, int offset);
const guint8 *tvb_get_ptr(tvbuff_t *tvb, int offset, int length);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
void proto_tree_add_string_format_value(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const guint8 *valueptr, const char *format, ...);

int dissect_pktc_app_specific_data(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint8 doi, int kmmid);
int dissect_pktc_list_of_ciphersuites(packet_info *pinfo, proto_tree *tree, tvbuff_t *tvb, int offset, guint8 doi);