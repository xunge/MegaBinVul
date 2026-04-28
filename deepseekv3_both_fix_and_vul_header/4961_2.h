#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct {
    int value;
    const char *str;
} value_string;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;

#define PARAM_ESP_INFO 1
#define PARAM_R1_COUNTER 2
#define PARAM_LOCATOR 3
#define PARAM_PUZZLE 4
#define PARAM_SOLUTION 5
#define PARAM_SEQ 6
#define PARAM_ACK 7
#define PARAM_DIFFIE_HELLMAN 8
#define PARAM_ESP_TRANSFORM 9
#define PARAM_HIP_TRANSFORM 10
#define PARAM_NAT_TRAVERSAL_MODE 11
#define PARAM_TRANSACTION_PACING 12
#define PARAM_ENCRYPTED 13
#define PARAM_HIP_CIPHER 14
#define PARAM_HIT_SUITE_LIST 15
#define PARAM_HOST_ID 16
#define PARAM_CERT 17
#define PARAM_NOTIFICATION 18
#define PARAM_ECHO_REQUEST_SIGNED 19
#define PARAM_ECHO_RESPONSE_SIGNED 20
#define PARAM_ECHO_REQUEST_UNSIGNED 21
#define PARAM_ECHO_RESPONSE_UNSIGNED 22
#define PARAM_REG_INFO 23
#define PARAM_REG_REQUEST 24
#define PARAM_REG_RESPONSE 25
#define PARAM_REG_FAILED 26
#define PARAM_HMAC 27
#define PARAM_HMAC_2 28
#define PARAM_RVS_HMAC 29
#define PARAM_RELAY_HMAC 30
#define PARAM_HIP_SIGNATURE 31
#define PARAM_HIP_SIGNATURE_2 32
#define PARAM_FROM 33
#define PARAM_VIA_RVS 34
#define PARAM_RELAY_FROM 35
#define PARAM_RELAY_TO 36
#define PARAM_REG_FROM 37

#define HI_ALG_DSA 1
#define HI_ALG_RSA 2

#define ENC_BIG_ENDIAN 0
#define ENC_NA 1
#define ENC_ASCII 2

static const value_string dh_group_id_vals[] = {
    {0, NULL}
};

static const value_string transform_id_vals[] = {
    {0, NULL}
};

static const value_string mode_id_vals[] = {
    {0, NULL}
};

static const value_string reg_type_vals[] = {
    {0, NULL}
};

static const value_string sig_alg_vals[] = {
    {0, NULL}
};

static expert_field ei_hip_tlv_host_id_len;
static expert_field ei_hip_tlv_host_id_hdr_alg;

static int ett_hip_tlv_data;
static int ett_hip_locator_data;
static int ett_hip_tlv_host_id_hdr;

static int hf_hip_tlv_ei_res;
static int hf_hip_tlv_ei_keyidx;
static int hf_hip_tlv_ei_oldspi;
static int hf_hip_tlv_ei_newspi;
static int hf_hip_tlv_r1_res;
static int hf_hip_tlv_r1count;
static int hf_hip_tlv_locator_address;
static int hf_hip_tlv_locator_traffic_type;
static int hf_hip_tlv_locator_type;
static int hf_hip_tlv_locator_len;
static int hf_hip_tlv_locator_reserved;
static int hf_hip_tlv_locator_lifetime;
static int hf_hip_tlv_locator_spi;
static int hf_hip_tlv_locator_port;
static int hf_hip_tlv_locator_transport_protocol;
static int hf_hip_tlv_locator_kind;
static int hf_hip_tlv_locator_priority;
static int hf_hip_tlv_puzzle_k;
static int hf_hip_tlv_puzzle_life;
static int hf_hip_tlv_puzzle_o;
static int hf_hip_tlv_puzzle_i;
static int hf_hip_tlv_solution_k;
static int hf_hip_tlv_solution_reserved;
static int hf_hip_tlv_solution_o;
static int hf_hip_tlv_solution_i;
static int hf_hip_tlv_solution_j;
static int hf_hip_tlv_seq_updid;
static int hf_hip_tlv_ack_updid;
static int hf_hip_tlv_dh_group_id;
static int hf_hip_tlv_dh_pv_length;
static int hf_hip_tlv_dh_pub;
static int hf_hip_tlv_esp_reserved;
static int hf_hip_tlv_trans_id;
static int hf_hip_tlv_nat_traversal_mode_id;
static int hf_hip_tlv_transaction_minta;
static int hf_hip_tlv_enc_reserved;
static int hf_hip_encrypted_parameter_data;
static int hf_hip_tlv_cipher_id;
static int hf_hip_tlv_hit_suite_id;
static int hf_hip_tlv_host_id_len;
static int hf_hip_tlv_host_di_type;
static int hf_hip_tlv_host_di_len;
static int hf_hip_tlv_host_id_hdr;
static int hf_hip_tlv_host_id_hdr_flags;
static int hf_hip_tlv_host_id_hdr_proto;
static int hf_hip_tlv_host_id_hdr_alg;
static int hf_hip_tlv_host_id_t;
static int hf_hip_tlv_host_id_q;
static int hf_hip_tlv_host_id_p;
static int hf_hip_tlv_host_id_g;
static int hf_hip_tlv_host_id_y;
static int hf_hip_tlv_host_id_e_len;
static int hf_hip_tlv_host_id_e;
static int hf_hip_tlv_host_id_n;
static int hf_hip_fqdn;
static int hf_hip_nai;
static int hf_hip_tlv_cert_group;
static int hf_hip_tlv_cert_count;
static int hf_hip_tlv_cert_id;
static int hf_hip_tlv_cert_type;
static int hf_hip_tlv_certificate;
static int hf_hip_tlv_notification_res;
static int hf_hip_tlv_notification_type;
static int hf_hip_tlv_notification_data;
static int hf_hip_tlv_opaque_data;
static int hf_hip_tlv_reg_ltmin;
static int hf_hip_tlv_reg_ltmax;
static int hf_hip_tlv_reg_failtype;
static int hf_hip_tlv_reg_lt;
static int hf_hip_tlv_reg_type;
static int hf_hip_tlv_hmac;
static int hf_hip_tlv_sig_alg;
static int hf_hip_tlv_sig;
static int hf_hip_tlv_from_address;
static int hf_hip_tlv_rvs_address;
static int hf_hip_tlv_relay_from_port;
static int hf_hip_tlv_relay_from_protocol;
static int hf_hip_tlv_relay_from_reserved;
static int hf_hip_tlv_relay_from_address;
static int hf_hip_tlv_relay_to_port;
static int hf_hip_tlv_relay_to_protocol;
static int hf_hip_tlv_relay_to_reserved;
static int hf_hip_tlv_relay_to_address;
static int hf_hip_tlv_reg_from_port;
static int hf_hip_tlv_reg_from_protocol;
static int hf_hip_tlv_reg_from_reserved;
static int hf_hip_tlv_reg_from_address;