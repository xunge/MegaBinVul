#include <stdint.h>

typedef uint16_t guint16;
typedef uint8_t guint8;
typedef uint32_t guint32;

#define PARAMETER_LONG_DATA 0
#define PARAMETER_LENGTH_LENGTH 1
#define PARAMETER_LONG_DATA_LENGTH_LENGTH 2

extern int hf_sccp_param_length;
extern int sccp_show_length;
extern const char* sccp_parameter_values[];

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct sccp_decode_context_t sccp_decode_context_t;

static guint16 dissect_sccp_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *sccp_tree, proto_tree *tree, guint8 parameter_type, guint16 offset, guint16 parameter_length, sccp_decode_context_t* sccp_info);

uint8_t tvb_get_guint8(tvbuff_t *tvb, guint16 offset);
uint16_t tvb_get_letohs(tvbuff_t *tvb, guint16 offset);
proto_item* proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value, const char *format, ...);
const char* val_to_str(guint32 val, const char* const* array, const char* fmt);
void PROTO_ITEM_SET_HIDDEN(proto_item *pi);