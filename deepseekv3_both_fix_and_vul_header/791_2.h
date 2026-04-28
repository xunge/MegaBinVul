#include <stdint.h>
#include <netinet/in.h>

#define LMP_VERSION 1
#define TRUE 1
#define FALSE 0

#define LMP_EXTRACT_VERSION(version_res) ((version_res) >> 4)

typedef struct netdissect_options {
    int ndo_vflag;
} netdissect_options;

struct lmp_common_header {
    uint8_t version_res[1];
    uint8_t flags;
    uint8_t msg_type;
    uint8_t length[2];
};

struct lmp_object_header {
    uint8_t class_num;
    uint8_t ctype;
    uint8_t length[2];
};

#define LMP_OBJ_CC_ID 1
#define LMP_OBJ_LINK_ID 2
#define LMP_OBJ_INTERFACE_ID 3
#define LMP_OBJ_MESSAGE_ID 4
#define LMP_OBJ_NODE_ID 5
#define LMP_OBJ_CONFIG 6
#define LMP_OBJ_HELLO 7
#define LMP_OBJ_TE_LINK 8
#define LMP_OBJ_DATA_LINK 9
#define LMP_OBJ_VERIFY_BEGIN 10
#define LMP_OBJ_VERIFY_BEGIN_ACK 11
#define LMP_OBJ_VERIFY_ID 12
#define LMP_OBJ_CHANNEL_STATUS 13
#define LMP_OBJ_CHANNEL_STATUS_REQ 14
#define LMP_OBJ_ERROR_CODE 15
#define LMP_OBJ_SERVICE_CONFIG 16

#define LMP_CTYPE_LOC 1
#define LMP_CTYPE_RMT 2
#define LMP_CTYPE_IPV4_LOC 1
#define LMP_CTYPE_IPV4_RMT 2
#define LMP_CTYPE_IPV6_LOC 3
#define LMP_CTYPE_IPV6_RMT 4
#define LMP_CTYPE_UNMD_LOC 5
#define LMP_CTYPE_UNMD_RMT 6
#define LMP_CTYPE_1 1
#define LMP_CTYPE_2 2
#define LMP_CTYPE_IPV4 1
#define LMP_CTYPE_IPV6 2
#define LMP_CTYPE_UNMD 3
#define LMP_CTYPE_HELLO 1
#define LMP_CTYPE_HELLO_CONFIG 1
#define LMP_CTYPE_BEGIN_VERIFY_ERROR 1
#define LMP_CTYPE_LINK_SUMMARY_ERROR 2
#define LMP_CTYPE_SERVICE_CONFIG_SP 1
#define LMP_CTYPE_SERVICE_CONFIG_CPSA 2
#define LMP_CTYPE_SERVICE_CONFIG_TRANSPARENCY_TCM 3
#define LMP_CTYPE_SERVICE_CONFIG_NETWORK_DIVERSITY 4

#define LMP_SD_SERVICE_CONFIG_CPSA_LINK_TYPE_SDH 1
#define LMP_SD_SERVICE_CONFIG_CPSA_LINK_TYPE_SONET 2

#define ND_TCHECK(p) 
#define ND_TCHECK2(p, l) 
#define ND_PRINT(ndo, ...) 
#define EXTRACT_8BITS(p) (*(p))
#define EXTRACT_16BITS(p) ntohs(*(uint16_t *)(p))
#define EXTRACT_32BITS(p) ntohl(*(uint32_t *)(p))

const char *tok2str(const char *strings, const char *fmt, int val);
const char *bittok2str(const char *strings, const char *fmt, int val);
const char *ipaddr_string(netdissect_options *ndo, const u_char *p);
const char *ip6addr_string(netdissect_options *ndo, const u_char *p);
void print_unknown_data(netdissect_options *ndo, const u_char *cp, const char *prefix, int len);

extern const char *lmp_msg_type_values[];
extern const char *lmp_header_flag_values[];
extern const char *lmp_obj_values[];
extern const char *lmp_ctype_values[];
extern const char *lmp_obj_te_link_flag_values[];
extern const char *lmp_obj_data_link_flag_values[];
extern const char *lmp_obj_channel_status_values[];
extern const char *lmp_obj_begin_verify_flag_values[];
extern const char *gmpls_encoding_values[];
extern const char *lmp_obj_begin_verify_error_values[];
extern const char *lmp_obj_link_summary_error_values[];
extern const char *lmp_obj_service_config_sp_flag_values[];
extern const char *lmp_sd_service_config_cpsa_link_type_values[];
extern const char *lmp_sd_service_config_cpsa_signal_type_sdh_values[];
extern const char *lmp_sd_service_config_cpsa_signal_type_sonet_values[];
extern const char *lmp_obj_service_config_cpsa_tp_flag_values[];
extern const char *lmp_obj_service_config_cpsa_cct_flag_values[];
extern const char *lmp_obj_service_config_nsa_transparency_flag_values[];
extern const char *lmp_obj_service_config_nsa_tcm_flag_values[];
extern const char *lmp_obj_service_config_nsa_network_diversity_flag_values[];

int lmp_print_data_link_subobjs(netdissect_options *ndo, const u_char *obj_tptr, u_int obj_tlen, u_int offset);