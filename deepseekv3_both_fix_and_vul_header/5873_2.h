#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint64_t guint64;
typedef int gint;

typedef struct {
    int flags;
} RlcMacDownlink_t;

typedef struct {
    int bsn1;
    int bsn2;
} egprs_dl_header_info_t;

typedef struct {
    void* cinfo;
} packet_info;

typedef struct {
    int reported_length;
} tvbuff_t;

typedef struct proto_item proto_item;
typedef struct proto_tree proto_tree;

#define GSM_RLC_MAC_EGPRS_BLOCK2 0
#define array_length(x) (sizeof(x)/sizeof((x)[0]))
#define COL_INFO 0
#define ENC_BIG_ENDIAN 0

typedef struct {
    // Define fields as needed
} length_indicator_t;

extern proto_tree* proto_item_add_subtree(proto_item*, int);
extern proto_item* proto_tree_add_protocol_format(proto_tree*, int, tvbuff_t*, int, int, const char*, ...);
extern void proto_tree_add_bits_ret_val(proto_tree*, int, tvbuff_t*, int, int, void*, int);
extern void proto_tree_add_expert(proto_tree*, packet_info*, void*, tvbuff_t*, int, int);
extern void col_append_sep_str(void*, int, const char*, const char*);
extern int construct_egprs_data_segment_li_array(tvbuff_t*, proto_tree*, packet_info*, int, guint8*, length_indicator_t*, guint64*);
extern void dissect_egprs_data_segments(tvbuff_t*, packet_info*, proto_tree*, int, int, guint8, length_indicator_t*);
extern int tvb_reported_length(tvbuff_t*);

int proto_gsm_rlcmac;
int ett_gsm_rlcmac_data;
int hf_fbi;
int hf_e;
void* ei_gsm_rlcmac_unexpected_header_extension;