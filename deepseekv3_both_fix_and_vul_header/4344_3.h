#include <stdint.h>
#include <stddef.h>

typedef struct {
    int value;
    const char *strptr;
} value_string;

typedef struct hf_register_info {
    int *hf_field;
    struct {
        const char *name;
        const char *abbrev;
        int type;
        int display;
        const value_string *strings;
        uint32_t bitmask;
        const char *blurb;
        int hfinfo;
    } info;
} hf_register_info;

typedef int gint;

static int hf_pktc_kmmid;
static int hf_pktc_doi;
static int hf_pktc_version_major;
static int hf_pktc_version_minor;
static int hf_pktc_server_nonce;
static int hf_pktc_server_principal;
static int hf_pktc_timestamp;
static int hf_pktc_app_spec_data;
static int hf_pktc_list_of_ciphersuites;
static int hf_pktc_list_of_ciphersuites_len;
static int hf_pktc_snmpAuthenticationAlgorithm;
static int hf_pktc_snmpEncryptionTransformID;
static int hf_pktc_ipsecAuthenticationAlgorithm;
static int hf_pktc_ipsecEncryptionTransformID;
static int hf_pktc_snmpEngineID_len;
static int hf_pktc_snmpEngineID;
static int hf_pktc_snmpEngineBoots;
static int hf_pktc_snmpEngineTime;
static int hf_pktc_usmUserName_len;
static int hf_pktc_usmUserName;
static int hf_pktc_ipsec_spi;
static int hf_pktc_reestablish_flag;
static int hf_pktc_ack_required_flag;
static int hf_pktc_sec_param_lifetime;
static int hf_pktc_sha1_hmac;
static int hf_pktc_grace_period;

static gint ett_pktc;
static gint ett_pktc_app_spec_data;
static gint ett_pktc_list_of_ciphersuites;
static gint ett_pktc_engineid;
static gint ett_pktc_version;

static const value_string kmmid_types[] = { {0, NULL}, {0, NULL} };
static const value_string doi_types[] = { {0, NULL}, {0, NULL} };
static const value_string snmp_authentication_algorithm_vals[] = { {0, NULL}, {0, NULL} };
static const value_string snmp_transform_id_vals[] = { {0, NULL}, {0, NULL} };
static const value_string ipsec_authentication_algorithm_vals[] = { {0, NULL}, {0, NULL} };
static const value_string ipsec_transform_id_vals[] = { {0, NULL}, {0, NULL} };

#define FT_UINT8 0
#define FT_UINT32 0
#define FT_STRING 0
#define FT_NONE 0
#define FT_BYTES 0
#define FT_BOOLEAN 0
#define BASE_HEX 0
#define BASE_DEC 0
#define BASE_NONE 0
#define STR_UNICODE 0
#define VALS(x) x
#define HFILL 0
#define array_length(x) (sizeof(x)/sizeof(x[0]))

int proto_pktc;
int proto_register_protocol(const char *name, const char *short_name, const char *filter_name);
void proto_register_field_array(int proto, hf_register_info *hf, int size);
void proto_register_subtree_array(gint **ett, int size);