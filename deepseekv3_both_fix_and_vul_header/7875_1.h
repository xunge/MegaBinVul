#include <stdint.h>

#define PARAMETER_END_OF_OPTIONAL_PARAMETERS 0x00
#define PARAMETER_TYPE_LENGTH 1
#define END_OF_OPTIONAL_PARAMETERS_LENGTH 1

typedef uint8_t guint8;
typedef uint16_t guint16;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct sccp_decode_context_t sccp_decode_context_t;

extern guint8 tvb_get_guint8(tvbuff_t *tvb, guint16 offset);
extern int dissect_sccp_variable_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *sccp_tree, proto_tree *tree, guint8 parameter_type, guint16 offset, sccp_decode_context_t* sccp_info);
extern void dissect_sccp_parameter(tvbuff_t *tvb, packet_info *pinfo, proto_tree *sccp_tree, proto_tree *tree, guint8 parameter_type, guint16 offset, guint8 length, sccp_decode_context_t* sccp_info);