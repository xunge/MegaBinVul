#include <stdint.h>
#include <stdbool.h>

enum {
    XRA_DS_CHANNEL_ID,
    XRA_DS_FREQUENCY,
    XRA_MODULATION,
    XRA_ANNEX,
    XRA_PROFILE_ID,
    XRA_CODEWORD_INFO,
    XRA_NCP_TRUNC,
    XRA_NCP_SYMBOLID,
    XRA_MER,
    XRA_US_CHANNEL_ID,
    XRA_SID,
    XRA_IUC,
    XRA_BURST_ID,
    XRA_BURST_INFO,
    XRA_MINISLOT_INFO,
    XRA_UCD_CCC_PARITY,
    XRA_GRANT_SIZE,
    XRA_SEGMENT_HEADER_PRESENT,
    XRA_NUMBER_OFDMA_FRAMES,
    XRA_ESTIMATED_TIMING_ADJUST,
    XRA_ESTIMATED_POWER_LEVEL,
    XRA_SUBSLOT_ID,
    XRA_CONTROL_WORD
};

typedef unsigned int guint;
typedef unsigned short guint16;
typedef unsigned char guint8;
typedef uint32_t guint32;
typedef int16_t gint16;

#define _U_ __attribute__((unused))

typedef struct tvbuff tvbuff_t;
typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;
typedef struct packet_info packet_info;

struct packet_info {
    struct {
        char* cinfo;
    }* cinfo;
};

extern int hf_xra_tlv;
extern int ett_xra_tlv;
extern int hf_xra_tlv_ds_channel_id;
extern int hf_xra_tlv_ds_channel_frequency;
extern int hf_xra_tlv_modulation;
extern int hf_xra_tlv_annex;
extern int hf_xra_tlv_profile_id;
extern int hf_xra_tlv_ncp_trunc;
extern int hf_xra_tlv_ncp_symbolid;
extern int hf_xra_tlv_mer;
extern int hf_xra_tlv_us_channel_id;
extern int hf_xra_tlv_sid;
extern int hf_xra_tlv_iuc;
extern int hf_xra_tlv_burstid;
extern int hf_xra_tlv_ucd_ccc_parity;
extern int hf_xra_tlv_grant_size;
extern int hf_xra_tlv_segment_header_present;
extern int hf_xra_tlv_ranging_number_ofdma_frames;
extern int hf_xra_tlv_ranging_timing_adjust;
extern int hf_xra_tlv_power_level;
extern int hf_xra_tlv_subslot_id;
extern int hf_xra_tlv_control_word;
extern int hf_xra_unknown;

#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define COL_INFO 0
#define FALSE 0

int proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, int encoding);
proto_tree* proto_item_add_subtree(proto_item* item, int ett);
guint8 tvb_get_guint8(tvbuff_t* tvb, int offset);
int proto_tree_add_item_ret_uint(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, bool little_endian, guint* retval);
int proto_tree_add_double_format_value(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, double value, const char* format, ...);
tvbuff_t* tvb_new_subset_length(tvbuff_t* tvb, int offset, int length);
void col_append_fstr(char* cinfo, int column, const char* format, ...);
int tvb_captured_length(tvbuff_t* tvb);

void dissect_xra_tlv_cw_info(tvbuff_t* tvb, proto_tree* tree, void* data, guint length);
void dissect_xra_tlv_burst_info(tvbuff_t* tvb, proto_tree* tree, void* data, guint length);
void dissect_xra_tlv_ms_info(tvbuff_t* tvb, proto_tree* tree, void* data, guint length);