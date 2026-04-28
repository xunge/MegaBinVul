#include <stdint.h>
#include <stdbool.h>

#define S7COMM_UD_SUBF_CYCLIC_MEM 0
#define S7COMM_UD_TYPE_REQ 0
#define S7COMM_UD_TYPE_RES 1
#define S7COMM_UD_TYPE_PUSH 2

#define FALSE false
#define TRUE true
#define ENC_BIG_ENDIAN 0
#define ENC_NA 1

typedef uint32_t guint32;
typedef uint16_t guint16; 
typedef uint8_t guint8;
typedef bool gboolean;

typedef struct tvbuff_t tvbuff_t;
typedef struct proto_tree proto_tree;

extern guint32 s7comm_decode_param_item(tvbuff_t *tvb, guint32 offset, proto_tree *data_tree, guint8 i);
extern guint32 s7comm_decode_response_read_data(tvbuff_t *tvb, proto_tree *data_tree, guint8 item_count, guint32 offset);

extern int hf_s7comm_param_itemcount;
extern int hf_s7comm_cycl_interval_timebase;
extern int hf_s7comm_cycl_interval_time;
extern int hf_s7comm_userdata_data;

guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset);
void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, guint32 value);
void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, int encoding);