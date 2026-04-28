#include <stdint.h>
#include <stddef.h>

#define O_LBMR_PSER_T_LEN 0
#define O_LBMR_PSER_T_FLAGS 2
#define O_LBMR_PSER_T_DEP_TYPE 4
#define O_LBMR_PSER_T_SOURCE_IP 6
#define O_LBMR_PSER_T_STORE_IP 10
#define O_LBMR_PSER_T_TRANSPORT_IDX 14
#define O_LBMR_PSER_T_TOPIC_IDX 18
#define O_LBMR_PSER_T_SOURCE_PORT 22
#define O_LBMR_PSER_T_STORE_PORT 24
#define O_LBMR_PSER_T_TOPIC 26

#define L_LBMR_PSER_T 26
#define L_LBMR_PSER_T_DEP_TYPE 2
#define L_LBMR_PSER_T_LEN 2
#define L_LBMR_PSER_T_SOURCE_IP 4
#define L_LBMR_PSER_T_STORE_IP 4
#define L_LBMR_PSER_T_TRANSPORT_IDX 4
#define L_LBMR_PSER_T_TOPIC_IDX 4
#define L_LBMR_PSER_T_SOURCE_PORT 2
#define L_LBMR_PSER_T_STORE_PORT 2

#define O_LBMR_PSER_OPTLEN_T_OPTLEN 0
#define O_LBMR_PSER_OPTLEN_T_TYPE 2
#define L_LBMR_PSER_OPTLEN_T 4
#define L_LBMR_PSER_OPTLEN_T_TYPE 2
#define L_LBMR_PSER_OPTLEN_T_OPTLEN 2

#define O_LBMR_PSER_OPT_HDR_T_TYPE 0
#define O_LBMR_PSER_OPT_HDR_T_LEN 1
#define L_LBMR_PSER_OPT_CTXINST_T 4
#define O_LBMR_PSER_OPT_CTXINST_T_LEN 0
#define O_LBMR_PSER_OPT_CTXINST_T_TYPE 1
#define O_LBMR_PSER_OPT_CTXINST_T_CTXINST 2
#define L_LBMR_PSER_OPT_CTXINST_T_LEN 1
#define L_LBMR_PSER_OPT_CTXINST_T_TYPE 1
#define L_LBMR_PSER_OPT_CTXINST_T_CTXINST 2

#define LBMR_PSER_OPT_FLAG 0x0001
#define LBMR_PSER_OPT_SRC_CTXINST_TYPE 1
#define LBMR_PSER_OPT_STORE_CTXINST_TYPE 2

#define ENC_BIG_ENDIAN 0
#define ENC_ASCII 1
#define ENC_NA 2

typedef uint8_t guint8;
typedef uint16_t guint16;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field {
    int ei;
    const char *name;
} expert_field;

static int hf_lbmr_pser_dep_type;
static int hf_lbmr_pser_len;
static int hf_lbmr_pser_flags;
static int hf_lbmr_pser_flags_option;
static int hf_lbmr_pser_source_ip;
static int hf_lbmr_pser_store_ip;
static int hf_lbmr_pser_transport_idx;
static int hf_lbmr_pser_topic_idx;
static int hf_lbmr_pser_source_port;
static int hf_lbmr_pser_store_port;
static int hf_lbmr_pser_topic;
static int hf_lbmr_pser_opts;
static int hf_lbmr_pser_optlen;
static int hf_lbmr_pser_optlen_type;
static int hf_lbmr_pser_optlen_optlen;
static int hf_lbmr_pser_opt_ctxinst;
static int hf_lbmr_pser_opt_ctxinst_len;
static int hf_lbmr_pser_opt_ctxinst_type;
static int hf_lbmr_pser_opt_ctxinst_ctxinst;

static int ett_lbmr_pser_flags;
static int ett_lbmr_pser_opts;
static int ett_lbmr_pser_opt_len;
static int ett_lbmr_pser_opt_ctxinst;

static expert_field ei_lbmr_analysis_invalid_value = {0, "Invalid value"};

static guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
static guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
static proto_tree* proto_item_add_subtree(proto_item *item, int ett);
static void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_hdr, int ett, const int *fields, int encoding);
static void proto_item_set_len(proto_item *item, int length);
static void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *expert, const char *format, ...);