#include <stdint.h>
#include <stddef.h>

typedef unsigned char guint8;
typedef unsigned short guint16;
typedef unsigned int guint32;
typedef int gint;
typedef int gboolean;

#define FALSE 0
#define TRUE 1
#define ENC_NA 0

#define BEGINNING_SPDU 0x01
#define END_SPDU 0x02

#define SESSION_NO_ABORT 0
#define SES_DATA_TRANSFER 1
#define SES_EXPEDITED 2
#define SES_TYPED_DATA 3
#define SES_MAJOR_SYNC_POINT 4

typedef enum {
    COL_INFO
} column_type;

typedef struct {
    column_type cinfo;
} packet_info_fields;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    packet_info_fields *cinfo;
    struct {
        int num;
    } *fd;
    struct {
        void *src;
        void *dst;
        int srcport;
        int destport;
    };
    int ptype;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct fragment_head fragment_head;

struct conversation {
    guint32 index;
};
typedef struct conversation conversation_t;

struct SESSION_DATA_STRUCTURE {
    guint8 spdu_type;
    guint8 abort_type;
    guint8 ros_op;
    gboolean rtse_reassemble;
    guint32 pres_ctx_id;
};

extern guint32 ses_pres_ctx_id;
extern gboolean ses_rtse_reassemble;
extern gboolean ses_desegment;
extern int proto_clses;
extern int proto_ses;
extern int ett_ses;
extern int hf_ses_type;
extern int hf_ses_type_0;
extern int hf_ses_length;
extern int hf_ses_segment_data;
extern void *wmem_file_scope();
extern void *p_get_proto_data(void *scope, packet_info *pinfo, int proto, int id);
extern void p_add_proto_data(void *scope, packet_info *pinfo, int proto, int id, void *data);
extern void *wmem_alloc(void *scope, size_t size);
extern const char *val_to_str(guint8 val, const void *vals, const char *fmt);
extern void col_add_str(packet_info_fields *cinfo, column_type col, const char *str);
extern proto_item *proto_tree_add_item(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int length, int encoding);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern void proto_tree_add_uint(proto_tree *tree, int hf, tvbuff_t *tvb, int offset, int length, guint32 value);
extern void proto_item_set_end(proto_item *item, tvbuff_t *tvb, int offset);
extern void proto_item_append_text(proto_item *item, const char *format, ...);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern guint16 get_item_len(tvbuff_t *tvb, int offset, int *len_len);
extern gboolean dissect_parameters(tvbuff_t *tvb, int offset, guint16 len, proto_tree *tree, proto_tree *ses_tree, packet_info *pinfo, guint8 *flags, struct SESSION_DATA_STRUCTURE *session);
extern int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
extern tvbuff_t *tvb_new_subset_remaining(tvbuff_t *tvb, int offset);
extern conversation_t *find_conversation(int num, void *src, void *dst, int ptype, int srcport, int destport, int flags);
extern fragment_head *fragment_add_seq_next(void *table, tvbuff_t *tvb, int offset, packet_info *pinfo, guint32 id, void *data, int frag_len, gboolean more_frags);
extern tvbuff_t *process_reassembled_data(tvbuff_t *tvb, int offset, packet_info *pinfo, const char *name, fragment_head *fd_head, void *frag_items, void *tree_arg, proto_tree *tree);
extern void call_dissector(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);
extern void call_dissector_with_data(void *handle, tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data);
extern int tvb_length(tvbuff_t *tvb);
extern const char *plurality(int value, const char *singular, const char *plural);

extern void *ses_reassembly_table;
extern void *ses_frag_items;
extern void *pres_handle;
extern void *data_handle;
extern const void *ses_vals;
extern const void *ses_category0_vals;

#define wmem_new(scope, type) ((type *)wmem_alloc(scope, sizeof(type)))