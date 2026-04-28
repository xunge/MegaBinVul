#include <stdint.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
typedef int gboolean;
typedef uint32_t guint;
typedef uint16_t guint16;
typedef uint8_t guint8;

#define IRCOMM_3_WIRE_RAW 0x01
#define IRCOMM_3_WIRE 0x02
#define IRCOMM_9_WIRE 0x04
#define IRCOMM_CENTRONICS 0x08
#define IRCOMM_SERIAL 0x01
#define IRCOMM_PARALLEL 0x02

#define IRCOMM_SERVICE_TYPE 0x01
#define IRCOMM_PORT_TYPE 0x02
#define IRCOMM_PORT_NAME 0x03

#define MAX_PARAMETERS 16
#define ENC_NA 0

#define _U_ __attribute__((unused))

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

extern int hf_ircomm_param;
extern int* ett_param;

extern gboolean check_iap_octet_result(tvbuff_t* tvb, proto_tree* tree, guint offset, const char* label, guint8 attr_type);
extern guint dissect_param_tuple(tvbuff_t* tvb, proto_tree* tree, guint offset);
extern guint16 tvb_get_ntohs(tvbuff_t* tvb, int offset);
extern guint8 tvb_get_guint8(tvbuff_t* tvb, int offset);
extern proto_item* proto_tree_add_item(proto_tree* tree, int hfindex, tvbuff_t* tvb, int start, int length, int encoding);
extern proto_tree* proto_item_add_subtree(proto_item* ti, int ett);
extern void proto_item_append_text(proto_item* ti, const char* format, ...);
extern const char* tvb_format_text(tvbuff_t* tvb, int offset, int length);
extern size_t g_strlcat(char* dst, const char* src, size_t size);