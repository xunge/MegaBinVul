#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    struct {
        int num;
    } *fd;
    struct {
        int COL_PROTOCOL;
        int COL_INFO;
    } *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct _header_field_info hf_register_info;
typedef struct _header_field_info header_field_info;
typedef struct expert_field expert_field;

#define _U_ __attribute__((unused))

#define BIT_IS_CLEAR(val, bit) (!((val) & (1 << (bit))))
#define BIT_IS_SET(val, bit) ((val) & (1 << (bit)))

enum {
    ENC_NA,
    ENC_BIG_ENDIAN
};

enum {
    BMT_NO_FLAGS = 0,
    PROTO_CHECKSUM_VERIFY = 1
};

enum {
    COL_PROTOCOL,
    COL_INFO
};

extern int hf_dvb_s2_bb_matype1_gs;
extern int hf_dvb_s2_bb_matype1_mis;
extern int hf_dvb_s2_bb_matype1_acm;
extern int hf_dvb_s2_bb_matype1_issyi;
extern int hf_dvb_s2_bb_matype1_npd;
extern int hf_dvb_s2_bb_matype1_low_ro;
extern int hf_dvb_s2_bb_matype1;
extern int hf_dvb_s2_bb_matype1_high_ro;
extern int hf_dvb_s2_bb_matype2;
extern int hf_dvb_s2_bb_upl;
extern int hf_dvb_s2_bb_dfl;
extern int hf_dvb_s2_bb_sync;
extern int hf_dvb_s2_bb_syncd;
extern int hf_dvb_s2_bb_crc;
extern int hf_dvb_s2_bb_crc_status;
extern int hf_dvb_s2_bb_eip_crc32;
extern int hf_dvb_s2_bb_df;
extern int hf_dvb_s2_bb_packetized;
extern int hf_dvb_s2_bb_transport;
extern int hf_dvb_s2_bb_reserved;

extern expert_field ei_dvb_s2_bb_crc;
extern expert_field ei_dvb_s2_bb_issy_invalid;
extern expert_field ei_dvb_s2_bb_npd_invalid;
extern expert_field ei_dvb_s2_bb_upl_invalid;
extern expert_field ei_dvb_s2_bb_reserved;

extern int proto_dvb_s2_bb;
extern int ett_dvb_s2_bb;
extern int ett_dvb_s2_bb_matype1;

extern int DVB_S2_BB_HEADER_LEN;
extern int DVB_S2_BB_OFFS_MATYPE1;
extern int DVB_S2_BB_OFFS_MATYPE2;
extern int DVB_S2_BB_OFFS_UPL;
extern int DVB_S2_BB_OFFS_DFL;
extern int DVB_S2_BB_OFFS_SYNC;
extern int DVB_S2_BB_OFFS_SYNCD;
extern int DVB_S2_BB_OFFS_CRC;
extern int DVB_S2_BB_EIP_CRC32_LEN;
extern int DVB_S2_GSE_MINSIZE;

extern int DVB_S2_BB_MIS_POS;
extern int DVB_S2_BB_ISSYI_POS;
extern int DVB_S2_BB_NPD_POS;
extern int DVB_S2_BB_TSGS_MASK;
extern int DVB_S2_BB_SYNC_EIP_CRC32;

#define DVB_S2_BB_TSGS_GENERIC_CONTINUOUS 0
#define DVB_S2_BB_TSGS_GENERIC_PACKETIZED 1
#define DVB_S2_BB_TSGS_TRANSPORT_STREAM 2

extern int _use_low_rolloff_value;
extern int dvb_s2_df_dissection;

guint8 compute_crc8(tvbuff_t *tvb, int len, guint8 crc8);
int dissect_dvb_s2_gse(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);

void col_append_str(void *cinfo, int col, const char *str);
proto_item *proto_tree_add_item(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
void proto_tree_add_bitmask_with_flags(proto_tree *tree, tvbuff_t *tvb, int offset, int hf, int ett, int *const *fields, int encoding, int flags);
void proto_tree_add_uint_format_value(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, guint32 value, const char *format, ...);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
void proto_tree_add_uint_format(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, guint32 value, const char *format, ...);
void proto_tree_add_checksum(proto_tree *tree, tvbuff_t *tvb, int offset, int hf_crc, int hf_status, expert_field *ei, packet_info *pinfo, guint32 crc, int encoding, int flags);
void expert_add_info(packet_info *pinfo, proto_item *ti, expert_field *ei);
void expert_add_info_format(packet_info *pinfo, proto_item *ti, expert_field *ei, const char *format, ...);
tvbuff_t *tvb_new_subset_length(tvbuff_t *tvb, int offset, int length);