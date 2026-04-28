#include <stdint.h>

typedef int32_t gint;
typedef uint8_t guint8;
typedef unsigned int guint;
typedef uint8_t guchar;
typedef char gchar;

struct value_string {
    guint8 value;
    const char *str;
};

extern int ett_gsup_ie;
extern void expert_add_info(void *pinfo, void *gsup_ti, void *ei);
extern void *ei_gsup_ie_len_invalid;
extern void *hf_gsup_iei;
extern void *hf_gsup_ie_len;
extern void *hf_gsup_rand;
extern void *hf_gsup_sres;
extern void *hf_gsup_kc;
extern void *hf_gsup_ik;
extern void *hf_gsup_ck;
extern void *hf_gsup_autn;
extern void *hf_gsup_auts;
extern void *hf_gsup_res;
extern void *hf_gsup_cn_domain;
extern void *hf_gsup_cancel_type;
extern void *hf_gsup_ie_payload;
extern void *hf_gsup_apn;
extern void *hf_gsup_pdp_context_id;
extern void *hf_gsup_charg_char;
extern void *hf_gsup_cause;
extern void *hf_gsup_pdp_info_compl;
extern void *hf_gsup_freeze_ptmsi;
extern void *hf_gsup_session_id;
extern void *hf_gsup_session_state;
extern void *hf_gsup_sm_rp_mr;
extern void *hf_gsup_sm_rp_cause;
extern void *hf_gsup_sm_rp_mms;
extern void *hf_gsup_sm_alert_rsn;
extern void *hf_gsup_imei_result;
extern const struct value_string gsup_iei_types[];

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define ENC_BIG_ENDIAN 0
#define ENC_NA 0
#define ENC_ASCII 0
#define FALSE 0
#define E164_ENC_BCD 0

#define OSMO_GSUP_AUTH_TUPLE_IE 0
#define OSMO_GSUP_PDP_INFO_IE 1
#define OSMO_GSUP_RAND_IE 2
#define OSMO_GSUP_SRES_IE 3
#define OSMO_GSUP_KC_IE 4
#define OSMO_GSUP_IK_IE 5
#define OSMO_GSUP_CK_IE 6
#define OSMO_GSUP_AUTN_IE 7
#define OSMO_GSUP_AUTS_IE 8
#define OSMO_GSUP_RES_IE 9
#define OSMO_GSUP_CN_DOMAIN_IE 10
#define OSMO_GSUP_CANCEL_TYPE_IE 11
#define OSMO_GSUP_IMSI_IE 12
#define OSMO_GSUP_MSISDN_IE 13
#define OSMO_GSUP_ACCESS_POINT_NAME_IE 14
#define OSMO_GSUP_PDP_CONTEXT_ID_IE 15
#define OSMO_GSUP_CHARG_CHAR_IE 16
#define OSMO_GSUP_CAUSE_IE 17
#define OSMO_GSUP_PDP_INFO_COMPL_IE 18
#define OSMO_GSUP_FREEZE_PTMSI_IE 19
#define OSMO_GSUP_SESSION_ID_IE 20
#define OSMO_GSUP_SESSION_STATE_IE 21
#define OSMO_GSUP_SS_INFO_IE 22
#define OSMO_GSUP_SM_RP_MR_IE 23
#define OSMO_GSUP_SM_RP_DA_IE 24
#define OSMO_GSUP_SM_RP_OA_IE 25
#define OSMO_GSUP_SM_RP_UI_IE 26
#define OSMO_GSUP_SM_RP_CAUSE_IE 27
#define OSMO_GSUP_SM_RP_MMS_IE 28
#define OSMO_GSUP_SM_ALERT_RSN_IE 29
#define OSMO_GSUP_IMEI_IE 30
#define OSMO_GSUP_IMEI_RESULT_IE 31
#define OSMO_GSUP_HLR_NUMBER_IE 32
#define OSMO_GSUP_PDP_TYPE_IE 33
#define OSMO_GSUP_PDP_QOS_IE 34

guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
proto_tree *proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int offset, int length, int ett, proto_item **ti, const char *format, ...);
void proto_tree_add_item(proto_tree *tree, void *hf, tvbuff_t *tvb, int offset, int length, int encoding);
void proto_tree_add_uint(proto_tree *tree, void *hf, tvbuff_t *tvb, int offset, int length, guint value);
void proto_tree_add_string(proto_tree *tree, void *hf, tvbuff_t *tvb, int offset, int length, const char *value);
void proto_item_append_text(proto_item *ti, const char *format, ...);
const char *val_to_str(guint8 value, const struct value_string *vs, const char *default_str);
const char *dissect_e212_imsi(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int offset, int length, int unknown);
const char *dissect_e164_msisdn(tvbuff_t *tvb, proto_tree *tree, int offset, int length, int encoding);
void get_dns_name(tvbuff_t *tvb, int offset, int length, int unknown, const guchar **apn, guint *apn_len);
void dissect_ss_info_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree);
void dissect_sm_rp_da_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree);
void dissect_sm_rp_oa_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree);
void dissect_sm_rp_ui_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree, guint8 msg_type);
void dissect_imei_ie(tvbuff_t *tvb, packet_info *pinfo, int offset, int length, proto_tree *tree);