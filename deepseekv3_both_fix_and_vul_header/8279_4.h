#include <stdint.h>
#include <stddef.h>
#include <sys/time.h>
#include <stdlib.h>

#define U3V_CONTROL_PREFIX 0x43563355
#define U3V_EVENT_PREFIX 0x45563355
#define U3V_STREAM_LEADER_PREFIX 0x4C533355
#define U3V_STREAM_TRAILER_PREFIX 0x54533355

#define IF_CLASS_UNKNOWN 0
#define IF_CLASS_MISCELLANEOUS 0xEF
#define IF_SUBCLASS_UNKNOWN 0
#define IF_SUBCLASS_MISC_U3V 0x03

#define USB_CONV_U3V 1

#define U3V_READMEM_CMD 0x0800
#define U3V_WRITEMEM_CMD 0x0802
#define U3V_EVENT_CMD 0x0C00
#define U3V_READMEM_ACK 0x0801
#define U3V_WRITEMEM_ACK 0x0803
#define U3V_PENDING_ACK 0x0805
#define U3V_STATUS_GENCP_SUCCESS 0x0000

#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_LITTLE_ENDIAN 1
#define PINFO_FD_VISITED(pinfo) (0)

typedef int gint;
typedef unsigned int guint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gboolean;
#define TRUE 1
#define FALSE 0

typedef struct {
    guint8 endpoint;
    guint8 interfaceClass;
    guint8 interfaceSubclass;
    void *class_data;
    guint class_data_type;
} usb_conv_info_t;

typedef struct {
    guint ep_stream;
    void *trans_info;
} u3v_conv_info_t;

typedef struct {
    guint32 cmd_frame;
    guint32 ack_frame;
    struct timeval cmd_time;
} gencp_transaction_t;

typedef struct {
    guint32 value;
    const char *strptr;
} value_string;

typedef struct tvbuff tvbuff_t;
typedef struct packet_info packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct fd_info fd_info;

struct packet_info {
    fd_info *fd;
    void *cinfo;
};

struct fd_info {
    guint32 num;
    struct timeval abs_ts;
};

static void* wmem_file_scope(void) { return NULL; }
static void* wmem_packet_scope(void) { return NULL; }
static void* wmem_new0(void *scope, size_t size) { return calloc(1, size); }
static void* wmem_new(void *scope, size_t size) { return malloc(size); }
static void p_add_proto_data(void *scope, packet_info *pinfo, int proto, guint32 key, void *proto_data) {}
static void* p_get_proto_data(void *scope, packet_info *pinfo, int proto, guint32 key) { return NULL; }
static guint32 tvb_get_letohl(const tvbuff_t *tvb, gint offset) { return 0; }
static guint16 tvb_get_letohs(const tvbuff_t *tvb, gint offset) { return 0; }
static gint tvb_reported_length(const tvbuff_t *tvb) { return 0; }
static gint tvb_captured_length(const tvbuff_t *tvb) { return 0; }
static void proto_item_append_text(proto_item *item, const char *format, ...) {}
static proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, gint start, gint length, int encoding) { return NULL; }
static proto_tree* proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static void col_set_str(packet_info *pinfo, int column, const char *str) {}
static void col_clear(packet_info *pinfo, int column) {}
static void col_append_fstr(packet_info *pinfo, int column, const char *format, ...) {}
static const char* val_to_str(guint32 val, const value_string *vs, const char *default_str) { return default_str; }

extern int proto_u3v;
extern int ett_u3v;
extern int ett_u3v_cmd;
extern int ett_u3v_ack;
extern int ett_u3v_flags;
extern int hf_u3v_ccd_cmd;
extern int hf_u3v_ccd_ack;
extern int hf_u3v_gencp_prefix;
extern int hf_u3v_flag;
extern int hf_u3v_acknowledge_required_flag;
extern int hf_u3v_status;
extern int hf_u3v_command_id;
extern int hf_u3v_length;
extern int hf_u3v_request_id;
extern int hf_u3v_payloaddata;
extern const value_string command_names[];
extern const value_string status_names_short[];

static void dissect_u3v_read_mem_cmd(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t *gencp_trans) {}
static void dissect_u3v_write_mem_cmd(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t *gencp_trans) {}
static void dissect_u3v_event_cmd(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint length) {}
static void dissect_u3v_read_mem_ack(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t *gencp_trans) {}
static void dissect_u3v_write_mem_ack(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t *gencp_trans) {}
static void dissect_u3v_pending_ack(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, gint offset, gint length, u3v_conv_info_t *u3v_conv_info, gencp_transaction_t *gencp_trans) {}
static void dissect_u3v_stream_leader(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, usb_conv_info_t *usb_conv_info) {}
static void dissect_u3v_stream_trailer(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, usb_conv_info_t *usb_conv_info) {}
static void dissect_u3v_stream_payload(proto_tree *tree, tvbuff_t *tvb, packet_info *pinfo, usb_conv_info_t *usb_conv_info) {}

#define wmem_new0(scope, type) ((type*)wmem_new0(scope, sizeof(type)))
#define wmem_new(scope, type) ((type*)wmem_new(scope, sizeof(type)))