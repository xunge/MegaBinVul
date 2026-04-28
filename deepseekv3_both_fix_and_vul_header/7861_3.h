#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    struct {
        int COL_PROTOCOL;
        int COL_INFO;
    } *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct _value_string {
    guint32 value;
    const char *strptr;
};
typedef struct _value_string value_string;

#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_UTF_8 1
#define ENC_ASCII 2
#define ENC_BIG_ENDIAN 3

extern int proto_thrift;
extern int ett_thrift;
extern int hf_thrift_version;
extern int hf_thrift_mtype;
extern int hf_thrift_str_len;
extern int hf_thrift_method;
extern int hf_thrift_seq_id;
extern int hf_thrift_type;
extern int hf_thrift_fid;
extern const value_string thrift_mtype_vals[];

const char* val_to_str(guint32 val, const value_string *vs, const char *fmt);
int tvb_reported_length(tvbuff_t *tvb);
void col_set_str(void *cinfo, int col, const char *str);
void col_clear(void *cinfo, int col);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint32 tvb_get_ntohl(tvbuff_t *tvb, int offset);
char* tvb_get_string_enc(void *scope, tvbuff_t *tvb, int offset, int length, int encoding);
void* wmem_packet_scope(void);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree* proto_tree_add_subtree_format(proto_tree *tree, tvbuff_t *tvb, int start, int length, int ett, proto_item *item, const char *format, ...);
void col_add_fstr(void *cinfo, int col, const char *format, ...);