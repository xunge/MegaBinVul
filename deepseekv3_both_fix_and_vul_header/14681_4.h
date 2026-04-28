#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef bool gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    struct _column_info *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct _column_info column_info;

typedef struct _iax_call_data {
    guint32 forward_circuit_ids[1];
    guint32 dst_codec;
    guint32 src_codec;
    guint32 dst_vformat;
    guint32 src_vformat;
} iax_call_data;

typedef struct _iax_packet_data {
    iax_call_data *call_data;
    gboolean reversed;
    guint32 codec;
    gboolean first_time;
} iax_packet_data;

typedef struct _iax2_info {
    guint8 ftype;
    guint8 csub;
    guint16 scallno;
    guint16 dcallno;
    const char *messageName;
    int callState;
} iax2_info_t;

extern iax2_info_t *iax2_info;
extern int proto_iax2;
extern int hf_iax2_dcallno;
extern int hf_iax2_retransmission;
extern int hf_iax2_callno;
extern int hf_iax2_ts;
extern int hf_iax2_oseqno;
extern int hf_iax2_iseqno;
extern int hf_iax2_type;
extern int hf_iax2_dtmf_csub;
extern int hf_iax2_cmd_csub;
extern int hf_iax2_voice_csub;
extern int hf_iax2_voice_codec;
extern int hf_iax2_video_csub;
extern int hf_iax2_marker;
extern int hf_iax2_video_codec;
extern int hf_iax2_modem_csub;
extern int hf_iax2_text_csub;
extern int hf_iax2_text_text;
extern int hf_iax2_html_csub;
extern int hf_iax2_html_url;
extern int hf_iax2_csub;

#define COL_INFO 0
#define ENC_BIG_ENDIAN 0
#define ENC_ASCII 0
#define ENC_NA 0
#define ENC_UTF_8 0
#define FALSE false
#define TRUE true

extern void *wmem_file_scope();
extern void *p_get_proto_data(void *scope, packet_info *pinfo, int proto, int index);
extern void p_add_proto_data(void *scope, packet_info *pinfo, int proto, int index, void *data);
extern void col_add_fstr(packet_info *pinfo, int column, const char *format, ...);
extern void col_append_fstr(packet_info *pinfo, int column, const char *format, ...);
extern void col_append_str(packet_info *pinfo, int column, const char *str);
extern void PROTO_ITEM_SET_GENERATED(proto_item *item);
extern void PROTO_ITEM_SET_URL(proto_item *item);
extern guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
extern guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
extern const char *val_to_str_ext(guint32 value, const void *vs, const char *fmt);
extern const char *val_to_str(guint32 value, const void *vs, const char *fmt);
extern proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
extern proto_item *proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);

extern int ett_iax2_type;
extern int NUM_TAP_IAX_VOIP_STATES;
extern int NUM_TAP_CMD_VOIP_STATES;
extern int *tap_iax_voip_state;
extern int *tap_cmd_voip_state;
extern const void *iax_frame_types_ext;
extern const void *iax_iax_subclasses_ext;
extern const void *iax_cmd_subclasses_ext;
extern const void *iax_modem_subclasses;

#define AST_FRAME_IAX        0
#define AST_FRAME_DTMF_BEGIN 1
#define AST_FRAME_DTMF_END   2
#define AST_FRAME_CONTROL    3
#define AST_FRAME_VOICE      4
#define AST_FRAME_VIDEO      5
#define AST_FRAME_MODEM      6
#define AST_FRAME_TEXT       7
#define AST_FRAME_HTML      8
#define AST_FRAME_CNG        9
#define IAX_COMMAND_NEW      1