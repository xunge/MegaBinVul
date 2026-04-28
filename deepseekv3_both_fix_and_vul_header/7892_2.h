#include <stdint.h>
#include <stddef.h>

#define S7COMM_ITEM_RETVAL_RESERVED 0
#define S7COMM_ITEM_RETVAL_DATA_OK 0xFF
#define S7COMM_ITEM_RETVAL_DATA_ERR 0x05
#define S7COMM_DATA_TRANSPORT_SIZE_BBIT 3
#define S7COMM_DATA_TRANSPORT_SIZE_BBYTE 4
#define S7COMM_DATA_TRANSPORT_SIZE_BINT 5
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

typedef uint32_t guint32;
typedef uint16_t guint16;
typedef uint8_t guint8;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

struct value_string {
    guint32 value;
    const char *strptr;
};

extern int hf_s7comm_data_item;
extern int hf_s7comm_data_returncode;
extern int hf_s7comm_data_transport_size;
extern int hf_s7comm_data_length;
extern int hf_s7comm_readresponse_data;
extern int hf_s7comm_data_fillbyte;
extern int ett_s7comm_data_item;

extern const struct value_string s7comm_item_return_valuenames[];

guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *item, int ett);
void proto_item_append_text(proto_item *item, const char *format, ...);
const char* val_to_str(guint32 val, const struct value_string *vs, const char *fmt);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);