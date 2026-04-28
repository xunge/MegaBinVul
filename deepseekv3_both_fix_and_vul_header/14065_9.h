#include <stdint.h>
#include <stdlib.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gint;
typedef int gboolean;

typedef struct tvbuff tvbuff_t;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct conversation conversation_t;

typedef struct wmem_list {
    void *data;
    struct wmem_list *next;
} wmem_list_t;

typedef struct wmem_list_frame {
    void *data;
    struct wmem_list_frame *next;
} wmem_list_frame_t;

typedef struct {
    int fnum;
    guint8 function_code;
    guint16 base_address;
    guint16 num_reg;
} modbus_request_info_t;

typedef struct {
    wmem_list_t *modbus_request_frame_data;
    int register_format;
} modbus_conversation;

typedef struct {
    int register_format;
    guint16 reg_base;
    guint16 num_reg;
    gboolean request_found;
    guint32 req_frame_num;
} modbus_pkt_info_t;

typedef struct fd {
    struct {
        gboolean visited;
    } flags;
} fd;

typedef struct packet_info {
    fd *fd;
    int num;
} packet_info;

typedef struct {
    const char *str;
    int value;
} value_string;

extern int proto_modbus;
extern int ett_modbus_hdr;
extern int hf_modbus_functioncode;
extern int hf_modbus_exceptioncode;
extern int global_mbus_register_format;
extern const value_string function_code_vals[];
extern const value_string exception_code_vals[];

#define QUERY_PACKET 0
#define RESPONSE_PACKET 1
#define TRUE 1
#define FALSE 0
#define ENC_BIG_ENDIAN 0

extern conversation_t *find_or_create_conversation(packet_info *pinfo);
extern void *conversation_get_proto_data(conversation_t *conv, int proto);
extern void conversation_add_proto_data(conversation_t *conv, int proto, void *data);
extern void *p_get_proto_data(void *scope, packet_info *pinfo, int proto, int id);
extern void p_add_proto_data(void *scope, packet_info *pinfo, int proto, int id, void *data);
extern void dissect_modbus_request(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 function_code, int offset, int len, modbus_pkt_info_t *pkt_info);
extern void dissect_modbus_response(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint8 function_code, int offset, int len, modbus_pkt_info_t *pkt_info);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
extern guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
extern int tvb_captured_length(tvbuff_t *tvb);
extern proto_item *proto_tree_add_protocol_format(proto_tree *tree, int proto, tvbuff_t *tvb, int offset, int len, const char *format);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern void proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int len, int encoding);
extern void proto_item_set_text(proto_item *item, const char *format, ...);
extern void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int offset, int len, guint32 value);
extern const char *val_to_str(guint32 val, const value_string *vs, const char *fmt);
extern const char *val_to_str_const(guint32 val, const value_string *vs, const char *def_str);

static inline void *wmem_new(void *allocator, size_t size) {
    return malloc(size);
}

static inline void *wmem_new0(void *allocator, size_t size) {
    return calloc(1, size);
}

static inline wmem_list_t *wmem_list_new(void *allocator) {
    wmem_list_t *list = malloc(sizeof(wmem_list_t));
    list->data = NULL;
    list->next = NULL;
    return list;
}

static inline void wmem_list_prepend(wmem_list_t *list, void *data) {
    wmem_list_t *new_node = malloc(sizeof(wmem_list_t));
    new_node->data = data;
    new_node->next = list->next;
    list->next = new_node;
}

static inline wmem_list_frame_t *wmem_list_head(wmem_list_t *list) {
    return (wmem_list_frame_t *)list->next;
}

static inline void *wmem_list_frame_data(wmem_list_frame_t *frame) {
    return frame->data;
}

static inline wmem_list_frame_t *wmem_list_frame_next(wmem_list_frame_t *frame) {
    return frame->next;
}

#define wmem_file_scope() NULL

/* Replace the problematic allocations with direct sizeof calls */
#define wmem_new0_modbus_pkt_info_t(allocator) ((modbus_pkt_info_t *)calloc(1, sizeof(modbus_pkt_info_t)))
#define wmem_new_modbus_conversation(allocator) ((modbus_conversation *)malloc(sizeof(modbus_conversation)))
#define wmem_new_modbus_request_info_t(allocator) ((modbus_request_info_t *)malloc(sizeof(modbus_request_info_t)))

/* Update the function calls to use the new macros */
#define wmem_new0(allocator, type) wmem_new0_##type(allocator)
#define wmem_new(allocator, type) wmem_new_##type(allocator)