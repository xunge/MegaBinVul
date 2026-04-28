#include <stdint.h>
#include <string.h>
#include <stdarg.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef uint32_t guint;
typedef int gboolean;
typedef char gchar;

#define TRUE 1
#define FALSE 0
#define GPOINTER_TO_UINT(p) ((guint32)(uintptr_t)(p))
#define GUINT_TO_POINTER(u) ((void*)(uintptr_t)(u))

#define I_DATA_CHUNK_HEADER_LENGTH 16
#define DATA_CHUNK_HEADER_LENGTH 16
#define I_DATA_CHUNK_PAYLOAD_PROTOCOL_ID_OFFSET 12
#define DATA_CHUNK_PAYLOAD_PROTOCOL_ID_OFFSET 8
#define CHUNK_FLAGS_OFFSET 1
#define DATA_CHUNK_TSN_OFFSET 4
#define I_DATA_CHUNK_RESERVED_OFFSET 8
#define I_DATA_CHUNK_RESERVED_LENGTH 4
#define I_DATA_CHUNK_MID_OFFSET 8
#define I_DATA_CHUNK_MID_LENGTH 4
#define I_DATA_CHUNK_FSN_OFFSET 12
#define I_DATA_CHUNK_FSN_LENGTH 4
#define DATA_CHUNK_STREAM_ID_OFFSET 0
#define DATA_CHUNK_STREAM_ID_LENGTH 2
#define DATA_CHUNK_STREAM_SEQ_NUMBER_OFFSET 2
#define DATA_CHUNK_STREAM_SEQ_NUMBER_LENGTH 2
#define I_DATA_CHUNK_PAYLOAD_OFFSET 16
#define DATA_CHUNK_PAYLOAD_OFFSET 16
#define CHUNK_FLAGS_LENGTH 1
#define DATA_CHUNK_TSN_LENGTH 4
#define I_DATA_CHUNK_PAYLOAD_PROTOCOL_ID_LENGTH 4
#define DATA_CHUNK_PAYLOAD_PROTOCOL_ID_LENGTH 4

#define SCTP_DATA_CHUNK_E_BIT 0x01
#define SCTP_DATA_CHUNK_B_BIT 0x02
#define SCTP_DATA_CHUNK_U_BIT 0x04

#define MAX_NUMBER_OF_PPIDS 8
#define LAST_PPID 0xFFFFFFFF
#define ENC_BIG_ENDIAN 0
#define COL_INFO 0
#define exported_pdu_tap 0
#define EXCEPT_CODE 0
#define GET_MESSAGE ""

typedef struct {
    void *pool;
    void *cinfo;
    void *layers;
    int fragmented;
} packet_info;

typedef struct {
    int dummy;
} proto_tree;

typedef struct {
    int dummy;
} proto_item;

typedef struct {
    int dummy;
} sctp_half_assoc_t;

typedef struct {
    int dummy;
} tvbuff_t;

typedef struct {
    int dummy;
} wmem_list_frame_t;

typedef struct {
    int dummy;
} wmem_list_t;

extern gboolean use_reassembly;
extern int ett_sctp_data_chunk_flags;
extern int hf_data_chunk_e_bit;
extern int hf_data_chunk_b_bit;
extern int hf_data_chunk_u_bit;
extern int hf_data_chunk_i_bit;
extern int hf_data_chunk_tsn;
extern int hf_data_chunk_stream_id;
extern int hf_idata_chunk_reserved;
extern int hf_idata_chunk_mid;
extern int hf_idata_chunk_fsn;
extern int hf_data_chunk_stream_seq_number;
extern int hf_data_chunk_payload_proto_id;
extern int proto_sctp;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define TRY do {
#define CATCH_NONFATAL_ERRORS } while(0); if(0) {
#define ENDTRY }

static inline guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset) { return 0; }
static inline guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset) { return 0; }
static inline guint8 tvb_get_guint8(tvbuff_t *tvb, int offset) { return 0; }
static inline tvbuff_t* tvb_new_subset(tvbuff_t *tvb, int offset, int len, int reported_len) { return NULL; }
static inline int tvb_captured_length_remaining(tvbuff_t *tvb, int offset) { return 0; }
static inline int tvb_reported_length_remaining(tvbuff_t *tvb, int offset) { return 0; }
static inline void proto_item_append_text(proto_item *item, const char *fmt, ...) {}
static inline void proto_item_set_len(proto_item *item, int len) {}
static inline proto_tree* proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static inline proto_item* proto_tree_add_item(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int len, int encoding) { return NULL; }
static inline void* p_get_proto_data(void *pool, packet_info *pinfo, int proto, int idx) { return NULL; }
static inline void p_add_proto_data(void *pool, packet_info *pinfo, int proto, int idx, void *data) {}
static inline gboolean sctp_tsn(packet_info *pinfo, tvbuff_t *tvb, proto_item *item, sctp_half_assoc_t *ha, guint32 tsn) { return FALSE; }
static inline const char* proto_get_protocol_filter_name(int proto_id) { return NULL; }
static inline void col_append_str(void *cinfo, int col, const char *str) {}
static inline void DISSECTOR_ASSERT(gboolean condition) {}
static inline gboolean dissect_fragmented_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, proto_tree *chunk_tree, guint32 tsn, guint32 ppid, guint16 stream_id, guint32 stream_seq_num, guint8 b_bit, guint8 e_bit, guint8 u_bit, gboolean is_idata) { return FALSE; }
static inline gboolean dissect_payload(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint32 ppid) { return FALSE; }
static inline const char* plurality(int count, const char *singular, const char *plural) { return count == 1 ? singular : plural; }
static inline void show_exception(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, int code, const char *message) {}
static inline gboolean have_tap_listener(int tap) { return FALSE; }
static inline void export_sctp_data_chunk(packet_info *pinfo, tvbuff_t *tvb, const char *proto_name) {}
static inline wmem_list_frame_t* wmem_list_tail(void *list) { return NULL; }
static inline wmem_list_frame_t* wmem_list_frame_next(wmem_list_frame_t *frame) { return NULL; }
static inline void* wmem_list_frame_data(wmem_list_frame_t *frame) { return NULL; }