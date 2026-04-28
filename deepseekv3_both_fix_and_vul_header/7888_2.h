#include <stdint.h>
#include <stddef.h>

typedef int32_t gint;
typedef uint32_t guint32;
typedef int32_t gint32;
typedef uint8_t guint8;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct {
    guint8 interfaceClass;
    gboolean is_request;
} usb_conv_info_t;

typedef struct {
    gint dummy;
} usb_header_t;

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;

extern int hf_usb_bInterfaceClass;
extern int hf_usb_darwin_iso_frame_number;
extern int hf_usb_iso_len;
extern int hf_usb_darwin_iso_timestamp;
extern int hf_usb_darwin_iso_status;
extern int hf_usb_iso_data;
extern int proto_usb;
extern int ett_usb_isodesc;
extern const void* usb_darwin_status_vals_ext;

#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 0
#define _U_ 

#define PROTO_ITEM_SET_GENERATED(x) (void)0
#define proto_tree_add_uint(a,b,c,d,e,f) ((proto_item*)NULL)
#define tvb_captured_length(x) 0
#define tvb_get_guint32(a,b,c) 0
#define val_to_str_ext(a,b,c) ""
#define proto_tree_add_protocol_format(a,b,c,d,e,f,...) ((proto_item*)NULL)
#define proto_item_add_subtree(a,b) ((proto_tree*)NULL)
#define proto_tree_add_item(a,b,c,d,e,f) (void)0
#define proto_tree_set_appendix(a,b,c,d) (void)0