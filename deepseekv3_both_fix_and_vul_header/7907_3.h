#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct _tvbuff tvbuff_t;
typedef struct _packet_info packet_info;
typedef struct _proto_tree proto_tree;
typedef struct _proto_item proto_item;
typedef struct _fragment_item fragment_item;

#define DOCSIS_MIN_HEADER_LEN 6
#define FCPARM_QUEUE_DEPTH_REQ_FRM 0
#define FCPARM_RQST_FRM 1
#define FCPARM_FRAG_HDR 2
#define FCPARM_TIMING_HDR 3
#define FCPARM_MAC_MGMT_HDR 4
#define FCPARM_CONCAT_HDR 5
#define EXT_HDR_ON 1
#define FCTYPE_PACKET 0
#define FCTYPE_RESERVED 1
#define FCTYPE_ISOLAT 2
#define FCTYPE_MACSPC 3
#define FRAG_LAST 1
#define PROTO_CHECKSUM_VERIFY 0
#define ENC_NA 0
#define ENC_BIG_ENDIAN 0
#define COL_PROTOCOL 0
#define COL_INFO 1
#define TRUE 1
#define FALSE 0

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int32_t gint;
typedef bool gboolean;

extern int proto_docsis;
extern int ett_docsis;
extern int hf_docsis_fctype;
extern int hf_docsis_fcparm;
extern int hf_docsis_exthdr;
extern int hf_docsis_machdr_fcparm;
extern int hf_docsis_mini_slots;
extern int hf_docsis_sid;
extern int hf_docsis_requested_size;
extern int hf_docsis_concat_cnt;
extern int hf_docsis_len;
extern int hf_docsis_frag_fcs;
extern int hf_docsis_frag_fcs_status;
extern int ei_docsis_frag_fcs_bad;
extern void *docsis_mgmt_handle;
extern void *eth_withoutfcs_handle;
extern void *docsis_handle;
extern struct _docsis_reassembly_table docsis_reassembly_table;
extern struct _docsis_frag_items docsis_frag_items;
extern guint32 frag_sid;
extern guint32 frag_seq;
extern guint32 frag_flags;

struct _packet_info {
    bool fragmented;
    void *cinfo;
};

guint8 tvb_get_guint8(tvbuff_t *tvb, gint offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, gint offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, gint offset);
guint16 tvb_captured_length_remaining(tvbuff_t *tvb, gint offset);
guint16 tvb_captured_length(tvbuff_t *tvb);
tvbuff_t *tvb_new_subset_remaining(tvbuff_t *tvb, gint offset);
tvbuff_t *tvb_new_subset_length_caplen(tvbuff_t *tvb, gint offset, gint length, gint caplen);
void call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
void call_data_dissector(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
void col_set_str(void *cinfo, int column, const char *str);
void col_add_fstr(void *cinfo, int column, const char *format, ...);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *item, int ett);
void proto_item_append_text(proto_item *item, const char *format, ...);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, guint32 value);
void proto_tree_add_checksum(proto_tree *tree, tvbuff_t *tvb, gint offset, int hf_checksum, int hf_status, int *ei_checksum, packet_info *pinfo, guint32 checksum, int encoding, int flags);
void expert_add_info(packet_info *pinfo, proto_item *item, int *ei);
guint32 crc32_802_tvb(tvbuff_t *tvb, gint len);
fragment_item *fragment_add_seq_check(void *table, tvbuff_t *tvb, gint offset, packet_info *pinfo, guint32 id, void *data, guint32 seq, guint32 frag_len, gboolean more_frags);
tvbuff_t *process_reassembled_data(tvbuff_t *tvb, gint offset, packet_info *pinfo, const char *name, fragment_item *frag_msg, void *items, void *tree, proto_tree *parent_tree);
void dissect_exthdr_length_field(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 exthdr, guint8 mac_parm, guint16 len_sid, guint16 *payload_length);
void dissect_hcs_field(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 hdrlen);

#define _U_ __attribute__((unused))