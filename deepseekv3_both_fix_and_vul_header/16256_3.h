#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint32_t guint32;
typedef int32_t gint32;
typedef uint8_t guint8;
typedef unsigned int guint;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    int dummy;
} expert_field;

typedef struct {
    guint32 value;
    const char *strptr;
} value_string;

typedef struct {
    value_string *vals;
} value_string_ext;

#define ENC_NA 0
#define ENC_ASCII 1
#define ENC_LITTLE_ENDIAN 2
#define ENC_TIME_SECS_NSECS 4

static int hf_gquic_tags = -1;
static int hf_gquic_tag_type = -1;
static int hf_gquic_tag_offset_end = -1;
static int hf_gquic_tag_length = -1;
static int hf_gquic_tag_value = -1;
static int hf_gquic_tag_pad = -1;
static int hf_gquic_tag_sni = -1;
static int hf_gquic_tag_ver = -1;
static int hf_gquic_tag_ccs = -1;
static int hf_gquic_tag_pdmd = -1;
static int hf_gquic_tag_uaid = -1;
static int hf_gquic_tag_stk = -1;
static int hf_gquic_tag_sno = -1;
static int hf_gquic_tag_prof = -1;
static int hf_gquic_tag_scfg = -1;
static int hf_gquic_tag_scfg_number = -1;
static int hf_gquic_tag_rrej = -1;
static int hf_gquic_tag_crt = -1;
static int hf_gquic_tag_aead = -1;
static int hf_gquic_tag_scid = -1;
static int hf_gquic_tag_pubs = -1;
static int hf_gquic_tag_kexs = -1;
static int hf_gquic_tag_obit = -1;
static int hf_gquic_tag_expy = -1;
static int hf_gquic_tag_nonc = -1;
static int hf_gquic_tag_mspc = -1;
static int hf_gquic_tag_tcid = -1;
static int hf_gquic_tag_srbf = -1;
static int hf_gquic_tag_icsl = -1;
static int hf_gquic_tag_scls = -1;
static int hf_gquic_tag_copt = -1;
static int hf_gquic_tag_ccrt = -1;
static int hf_gquic_tag_irtt = -1;
static int hf_gquic_tag_cfcw = -1;
static int hf_gquic_tag_sfcw = -1;
static int hf_gquic_tag_cetv = -1;
static int hf_gquic_tag_xlct = -1;
static int hf_gquic_tag_nonp = -1;
static int hf_gquic_tag_csct = -1;
static int hf_gquic_tag_ctim = -1;
static int hf_gquic_tag_rnon = -1;
static int hf_gquic_tag_rseq = -1;
static int hf_gquic_tag_cadr_addr_type = -1;
static int hf_gquic_tag_cadr_addr_ipv4 = -1;
static int hf_gquic_tag_cadr_addr_ipv6 = -1;
static int hf_gquic_tag_cadr_addr = -1;
static int hf_gquic_tag_cadr_port = -1;
static int hf_gquic_tag_mids = -1;
static int hf_gquic_tag_fhol = -1;
static int hf_gquic_tag_sttl = -1;
static int hf_gquic_tag_smhl = -1;
static int hf_gquic_tag_tbkp = -1;
static int hf_gquic_tag_mad0 = -1;
static int hf_gquic_tag_unknown = -1;

static int ett_gquic_tag_value = -1;

static expert_field ei_gquic_tag_length;
static expert_field ei_gquic_tag_undecoded;
static expert_field ei_gquic_tag_unknown;
static expert_field ei_gquic_length_invalid;

static const value_string tag_vals[] = {
    {0x50414400, "PAD"},
    {0x534E4900, "SNI"},
    {0x56455200, "VER"},
    {0x43435300, "CCS"},
    {0x50444D44, "PDMD"},
    {0x55414944, "UAID"},
    {0x53544B00, "STK"},
    {0x534E4F00, "SNO"},
    {0x50524F46, "PROF"},
    {0x53434647, "SCFG"},
    {0x5252454A, "RREJ"},
    {0x43525400, "CRT"},
    {0x41454144, "AEAD"},
    {0x53434944, "SCID"},
    {0x50554253, "PUBS"},
    {0x4B455853, "KEXS"},
    {0x4F424954, "OBIT"},
    {0x45585059, "EXPY"},
    {0x4E4F4E43, "NONC"},
    {0x4D535043, "MSPC"},
    {0x54434944, "TCID"},
    {0x53524246, "SRBF"},
    {0x4943534C, "ICSL"},
    {0x53434C53, "SCLS"},
    {0x434F5054, "COPT"},
    {0x43435254, "CCRT"},
    {0x49525454, "IRTT"},
    {0x43464357, "CFCW"},
    {0x53464357, "SFCW"},
    {0x43455456, "CETV"},
    {0x584C4354, "XLCT"},
    {0x4E4F4E50, "NONP"},
    {0x43534354, "CSCT"},
    {0x4354494D, "CTIM"},
    {0x524E4F4E, "RNON"},
    {0x52534551, "RSEQ"},
    {0x43414452, "CADR"},
    {0x4D494453, "MIDS"},
    {0x46484F4C, "FHOL"},
    {0x5354544C, "STTL"},
    {0x534D484C, "SMHL"},
    {0x54424B50, "TBKP"},
    {0x4D414430, "MAD0"},
    {0, NULL}
};

static const value_string tag_aead_vals[] = {
    {0x41455347, "AESG"},
    {0, NULL}
};

static const value_string tag_kexs_vals[] = {
    {0x43525558, "CRUX"},
    {0, NULL}
};

static value_string_ext handshake_failure_reason_vals_ext = {NULL};

#define TAG_PAD 0x50414400
#define TAG_SNI 0x534E4900
#define TAG_VER 0x56455200
#define TAG_CCS 0x43435300
#define TAG_PDMD 0x50444D44
#define TAG_UAID 0x55414944
#define TAG_STK 0x53544B00
#define TAG_SNO 0x534E4F00
#define TAG_PROF 0x50524F46
#define TAG_SCFG 0x53434647
#define TAG_RREJ 0x5252454A
#define TAG_CRT 0x43525400
#define TAG_AEAD 0x41454144
#define TAG_SCID 0x53434944
#define TAG_PUBS 0x50554253
#define TAG_KEXS 0x4B455853
#define TAG_OBIT 0x4F424954
#define TAG_EXPY 0x45585059
#define TAG_NONC 0x4E4F4E43
#define TAG_MSPC 0x4D535043
#define TAG_TCID 0x54434944
#define TAG_SRBF 0x53524246
#define TAG_ICSL 0x4943534C
#define TAG_SCLS 0x53434C53
#define TAG_COPT 0x434F5054
#define TAG_CCRT 0x43435254
#define TAG_IRTT 0x49525454
#define TAG_CFCW 0x43464357
#define TAG_SFCW 0x53464357
#define TAG_CETV 0x43455456
#define TAG_XLCT 0x584C4354
#define TAG_NONP 0x4E4F4E50
#define TAG_CSCT 0x43534354
#define TAG_CTIM 0x4354494D
#define TAG_RNON 0x524E4F4E
#define TAG_RSEQ 0x52534551
#define TAG_CADR 0x43414452
#define TAG_MIDS 0x4D494453
#define TAG_FHOL 0x46484F4C
#define TAG_STTL 0x5354544C
#define TAG_SMHL 0x534D484C
#define TAG_TBKP 0x54424B50
#define TAG_MAD0 0x4D414430

static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding) {
    return NULL;
}

static proto_tree* proto_item_add_subtree(proto_item *item, int ett) {
    return NULL;
}

static proto_item* proto_tree_add_item_ret_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding, void* wmem, const guint8** strptr) {
    return NULL;
}

static guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset) {
    return 0;
}

static void proto_item_append_text(proto_item *item, const char *format, ...) {
}

static const char* val_to_str(guint32 value, const value_string *vs, const char *default_str) {
    return default_str;
}

static guint32 tvb_get_guint32(tvbuff_t *tvb, int offset, int encoding) {
    return 0;
}

static proto_item* proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value) {
    return NULL;
}

static void proto_item_set_generated(proto_item *item) {
}

static int tvb_reported_length_remaining(tvbuff_t *tvb, int offset) {
    return 0;
}

static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ef) {
}

static void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ef, const char *format, ...) {
}

static const char* val_to_str_ext(guint32 value, value_string_ext *vse, const char *default_str) {
    return default_str;
}

static void* wmem_packet_scope() {
    return NULL;
}

static void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, int start, int length) {
}