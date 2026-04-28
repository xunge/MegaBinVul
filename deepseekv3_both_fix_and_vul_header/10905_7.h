#include <stdint.h>
#include <stddef.h>

typedef int gint;
typedef unsigned int guint;
typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;

typedef struct tvbuff_t {
    // dummy structure
} tvbuff_t;

typedef struct packet_info {
    struct {
        int COL_INFO;
    } *cinfo;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

#define ENC_BIG_ENDIAN 0
#define PROTO_CHECKSUM_VERIFY 0
#define COL_INFO 0

extern int proto_mac_mgmt_msg_dlmap_decoder;
extern int ett_305;
extern int ett_275_phy;
extern int ett_dlmap_ie;
extern int hf_dlmapc_compr;
extern int hf_dlmapc_ulmap;
extern int hf_dlmapc_rsv;
extern int hf_dlmapc_len;
extern int hf_dlmap_phy_fdur_ms;
extern int hf_dlmap_phy_fdur_per_sec;
extern int hf_dlmap_phy_fnum;
extern int hf_dlmap_dcd;
extern int hf_dlmapc_opid;
extern int hf_dlmapc_secid;
extern int hf_dlmap_ofdma_sym;
extern int hf_dlmapc_count;
extern int hf_padding;
extern int hf_mac_header_compress_dlmap_crc;
extern int hf_mac_header_compress_dlmap_crc_status;
extern int ei_mac_header_invalid_length;
extern int ei_mac_header_compress_dlmap_crc;

extern guint tvb_reported_length(const tvbuff_t*);
extern guint8 tvb_get_guint8(const tvbuff_t*, int);
extern guint16 tvb_get_ntohs(const tvbuff_t*, int);
extern const guint8* tvb_get_ptr(const tvbuff_t*, int, int);
extern guint32 wimax_mac_calc_crc32(const guint8*, int);
extern int dissect_dlmap_ie(proto_tree*, packet_info*, guint, guint, const tvbuff_t*);
extern void wimax_decode_ulmapc(proto_tree*, packet_info*, guint, guint, const tvbuff_t*);
extern void col_append_sep_str(void*, int, const char*, const char*);
extern void expert_add_info_format(packet_info*, proto_item*, int*, const char*, ...);
extern proto_item* proto_tree_add_protocol_format(proto_tree*, int, const tvbuff_t*, int, int, const char*, ...);
extern proto_tree* proto_item_add_subtree(proto_item*, int);
extern void proto_tree_add_item(proto_tree*, int, const tvbuff_t*, int, int, int);
extern proto_tree* proto_tree_add_subtree(proto_tree*, const tvbuff_t*, int, int, int, proto_item**, const char*);
extern proto_tree* proto_tree_add_subtree_format(proto_tree*, const tvbuff_t*, int, int, int, proto_item**, const char*, ...);
extern void proto_tree_add_bytes_format(proto_tree*, int, const tvbuff_t*, int, void*, const char*);
extern void proto_item_set_text(proto_item*, const char*, ...);
extern void proto_item_set_end(proto_item*, const tvbuff_t*, int);
extern void proto_tree_add_checksum(proto_tree*, const tvbuff_t*, int, int, int, int*, packet_info*, guint32, int, int);
extern proto_item* proto_tree_add_protocol_format(proto_tree*, int, const tvbuff_t*, int, int, const char*, ...);

extern uint32_t INC_CID;

#define BYTE_TO_NIB(x) ((x)*2)
#define NIB_PADDING(x) ((x) % 2)
#define NIBHI(x,y) ((x)/2)
#define NIB_ADDR(x) ((x)/2)
#define MIN(a,b) ((a) < (b) ? (a) : (b))