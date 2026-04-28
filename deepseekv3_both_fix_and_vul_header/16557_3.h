#include <stdint.h>
#include <stdlib.h>

#define USBHID_LOCALITEM_TAG_USAGE 0
#define USBHID_LOCALITEM_TAG_USAGE_MIN 1
#define USBHID_LOCALITEM_TAG_USAGE_MAX 2
#define USBHID_LOCALITEM_TAG_DESIG_INDEX 3
#define USBHID_LOCALITEM_TAG_DESIG_MIN 4
#define USBHID_LOCALITEM_TAG_DESIG_MAX 5
#define USBHID_LOCALITEM_TAG_STRING_INDEX 6
#define USBHID_LOCALITEM_TAG_STRING_MIN 7
#define USBHID_LOCALITEM_TAG_STRING_MAX 8
#define USBHID_LOCALITEM_TAG_DELIMITER 9

#define ENC_LITTLE_ENDIAN 0
#define ENC_NA 1

#define _U_ __attribute__((unused))

typedef uint32_t guint32;
typedef char gchar;

typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct tvbuff_t tvbuff_t;
typedef struct proto_item proto_item;
typedef struct usb_hid_global_state {
    guint32 usage_page;
} usb_hid_global_state;

extern int hf_usb_hid_localitem_usage;
extern int hf_usb_hid_localitem_usage_min;
extern int hf_usb_hid_localitem_desig_index;
extern int hf_usb_hid_localitem_desig_min;
extern int hf_usb_hid_localitem_desig_max;
extern int hf_usb_hid_localitem_string_index;
extern int hf_usb_hid_localitem_string_min;
extern int hf_usb_hid_localitem_string_max;
extern int hf_usb_hid_localitem_delimiter;
extern int hf_usb_hid_item_unk_data;

extern guint32 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern guint32 tvb_get_ntohs(tvbuff_t *tvb, int offset);
extern gchar* get_usage_page_item_string(guint32 usage_page, guint32 id);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, int encoding);
extern void proto_tree_add_item_ret_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, int encoding, guint32 *retval);
extern void proto_tree_add_uint_format(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int length, guint32 value, const char *format, ...);
extern void proto_item_append_text(proto_item *ti, const char *format, ...);
extern proto_item* proto_tree_get_parent(proto_tree *tree);

#define g_free free