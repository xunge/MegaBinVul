#include <stdint.h>
#include <stddef.h>

#define S7COMM_UD_TYPE_REQ 0x01
#define S7COMM_UD_TYPE_RES 0x02
#define S7COMM_ITEM_RETVAL_DATA_OK 0xff
#define TRUE 1
#define FALSE 0
#define COL_INFO 0
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;
typedef int gboolean;
typedef int gint;
typedef const char gchar;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct packet_info {
    struct {
        char* info;
    } *cinfo;
};

extern int hf_s7comm_userdata_szl_id;
extern int hf_s7comm_userdata_szl_index;
extern int hf_s7comm_userdata_szl_tree;
extern int hf_s7comm_userdata_szl_data;
extern int hf_s7comm_userdata_szl_id_partlist_len;
extern int hf_s7comm_userdata_szl_id_partlist_cnt;
extern int hf_s7comm_userdata_szl_partial_list;
extern int ett_s7comm_userdata_szl_id;
extern int ett_s7comm_szl;
extern const void* s7comm_userdata_szl_id_fields;
extern const void* s7comm_item_return_valuenames;

extern const gchar* s7comm_get_szl_id_index_description_text(guint16 id, guint16 idx);
extern guint16 tvb_get_ntohs(tvbuff_t *tvb, guint32 offset);
extern void proto_tree_add_bitmask(proto_tree *tree, tvbuff_t *tvb, guint32 offset, int hf_index, int ett, const void *fields, int encoding);
extern proto_item* proto_tree_add_item(proto_tree *tree, int hf_index, tvbuff_t *tvb, guint32 offset, gint length, int encoding);
extern void proto_item_append_text(proto_item *item, const char *format, ...);
extern void col_append_fstr(void *cinfo, int column, const char *format, ...);
extern proto_tree* proto_item_add_subtree(proto_item *item, int ett);
extern void proto_tree_add_uint(proto_tree *tree, int hf_index, tvbuff_t *tvb, guint32 offset, gint length, guint32 value);
extern const char* val_to_str(guint8 val, const void* valuenames, const char* fmt);

extern guint32 s7comm_decode_szl_id_xy00(tvbuff_t *tvb, proto_tree *tree, guint16 id, guint16 idx, guint32 offset);
extern guint32 s7comm_decode_szl_id_0013_idx_0000(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0111_idx_0001(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0131_idx_0001(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0131_idx_0002(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0131_idx_0003(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0131_idx_0004(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0131_idx_0006(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0131_idx_0010(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0132_idx_0001(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0132_idx_0002(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0132_idx_0004(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0132_idx_0005(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0132_idx_0006(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_xy74_idx_0000(tvbuff_t *tvb, proto_tree *tree, guint32 offset);
extern guint32 s7comm_decode_szl_id_0424_idx_0000(tvbuff_t *tvb, proto_tree *tree, guint32 offset);