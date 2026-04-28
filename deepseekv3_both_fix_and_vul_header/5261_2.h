#include <stdint.h>
#include <stddef.h>

typedef int gint;

typedef struct {
    unsigned int value;
    const char *strptr;
} value_string;

typedef struct hf_register_info {
    int *hf_field;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const void *strings;
        uint32_t bitmask;
        const char *blurb;
        int hfiller;
    } info;
} hf_register_info;

typedef struct ei_register_info {
    int *ei_field;
    struct {
        const char *pfx;
        int severity;
        int summary;
        const char *text;
        int expfiller;
    } info;
} ei_register_info;

typedef struct {
    int *ett_field;
} ett_register_info;

typedef struct {
    const char *name;
    const char *short_name;
    const char *filter_name;
} protocol_info;

typedef struct {
    protocol_info *proto;
} expert_module_t;

static int hf_gsup_msg_type;
static int hf_gsup_iei;
static int hf_gsup_ie_len;
static int hf_gsup_ie_payload;
static int hf_gsup_rand;
static int hf_gsup_sres;
static int hf_gsup_kc;
static int hf_gsup_ik;
static int hf_gsup_ck;
static int hf_gsup_autn;
static int hf_gsup_auts;
static int hf_gsup_res;
static int hf_gsup_cn_domain;
static int hf_gsup_cancel_type;
static int hf_gsup_pdp_info_compl;
static int hf_gsup_freeze_ptmsi;
static int hf_gsup_apn;
static int hf_gsup_pdp_context_id;
static int hf_gsup_charg_char;
static int hf_gsup_cause;
static int hf_gsup_session_id;
static int hf_gsup_session_state;
static int hf_gsup_sm_rp_mr;
static int hf_gsup_sm_rp_da_id_type;
static int hf_gsup_sm_rp_oa_id_type;
static int hf_gsup_sm_rp_cause;
static int hf_gsup_sm_rp_mms;
static int hf_gsup_sm_alert_rsn;
static int hf_gsup_imei_result;

static int ett_gsup;
static int ett_gsup_ie;

static int ei_sm_rp_da_invalid;
static int ei_sm_rp_oa_invalid;
static int ei_gsup_ie_len_invalid;

static protocol_info *proto_gsup;

static const value_string gsup_msg_types[] = { {0, NULL}, {0, NULL} };
static const value_string gsup_iei_types[] = { {0, NULL}, {0, NULL} };
static const value_string gsup_cndomain_types[] = { {0, NULL}, {0, NULL} };
static const value_string gsup_cancel_types[] = { {0, NULL}, {0, NULL} };
static const value_string gsup_session_states[] = { {0, NULL}, {0, NULL} };
static const value_string osmo_gsup_sms_sm_rp_oda_types[] = { {0, NULL}, {0, NULL} };
static const value_string osmo_gsup_sms_sm_alert_rsn_types[] = { {0, NULL}, {0, NULL} };
static const value_string gsup_imei_result_types[] = { {0, NULL}, {0, NULL} };

#define FT_UINT8 0
#define FT_BYTES 1
#define FT_BOOLEAN 2
#define FT_STRING 3
#define FT_UINT32 4
#define BASE_DEC 0
#define BASE_HEX 1
#define BASE_NONE 2
#define VALS(x) x
#define HFILL 0
#define EXPFILL 0
#define PI_PROTOCOL 0
#define PI_ERROR 1
#define PI_MALFORMED 2
#define PI_WARN 3
#define array_length(x) (sizeof(x)/sizeof(x[0]))

void proto_register_field_array(protocol_info *proto, hf_register_info *hf, int count);
void proto_register_subtree_array(int **ett, int count);
protocol_info *proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
expert_module_t *expert_register_protocol(protocol_info *proto);
void expert_register_field_array(expert_module_t *expert, ei_register_info *ei, int count);