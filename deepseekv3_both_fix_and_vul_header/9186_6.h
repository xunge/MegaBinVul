#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gboolean;

#define FALSE 0
#define TRUE 1

struct address {
    int type;
    int len;
    void* data;
};

typedef struct tvbuff {
    unsigned char data[1024];
} tvbuff_t;

typedef struct packet_info {
    struct {
        struct address src;
        struct address dst;
        void* cinfo;
    };
} packet_info;

typedef struct proto_tree {
    int dummy;
} proto_tree;

typedef struct conversation {
    guint32 index;
} conversation_t;

typedef struct rsvp_conversation_info {
    struct address source;
    struct address destination;
    guint8 session_type;
    guint8 protocol;
    guint16 udp_dest_port;
    guint32 ext_tunnel_id;
    guint8 dscp;
    guint16 udp_source_port;
} rsvp_conversation_info;

struct rsvp_request_key {
    guint32 conversation;
    guint8 session_type;
    union {
        struct {
            struct address destination;
            guint8 protocol;
            guint16 udp_dest_port;
        } session_ipv4;
        struct {
            struct address destination;
            guint16 udp_dest_port;
            guint32 ext_tunnel_id;
        } session_ipv4_lsp;
        struct {
            struct address destination;
            guint8 dscp;
        } session_agg_ipv4;
        struct {
            struct address destination;
            guint16 udp_dest_port;
            guint32 ext_tunnel_id;
        } session_ipv4_uni;
        struct {
            struct address destination;
            guint16 udp_dest_port;
            guint32 ext_tunnel_id;
        } session_ipv4_enni;
    } u;
    struct {
        struct address source;
        guint16 udp_source_port;
    } source_info;
};

struct rsvp_request_val {
    guint32 value;
};

struct value_string_ext {
    int dummy;
};

struct expert_field {
    int dummy;
};

#define COL_INFO 0
#define TREE(x) NULL
#define TT_RSVP 0

#define RSVP_MSG_BUNDLE 1
#define RSVP_MSG_ACK 2
#define RSVP_MSG_SREFRESH 3
#define RSVP_MSG_HELLO 4

#define RSVP_SESSION_TYPE_IPV4 1
#define RSVP_SESSION_TYPE_IPV6 2
#define RSVP_SESSION_TYPE_IPV4_LSP 3
#define RSVP_SESSION_TYPE_AGGREGATE_IPV4 4
#define RSVP_SESSION_TYPE_IPV4_UNI 5
#define RSVP_SESSION_TYPE_IPV4_E_NNI 6

static void* rsvp_request_hash = NULL;
static struct value_string_ext message_type_vals_ext;
static struct expert_field ei_rsvp_session_type;
static void* rsvp_tap = NULL;
static gboolean rsvp_bundle_dissect = FALSE;

static guint8 tvb_get_guint8(tvbuff_t* tvb, int offset) { return tvb->data[offset]; }
static void col_clear(void* cinfo, int col) {}
static void col_add_str(void* cinfo, int col, const char* str) {}
static void col_set_str(void* cinfo, int col, const char* str) {}
static void col_append_str(void* cinfo, int col, const char* str) {}
static void set_address(struct address* addr, int type, int len, void* data) {
    addr->type = type;
    addr->len = len;
    addr->data = data;
}
static void copy_address_wmem(void* scope, struct address* dst, struct address* src) {
    *dst = *src;
}
static conversation_t* find_or_create_conversation(packet_info* pinfo) {
    static conversation_t conv = {0};
    return &conv;
}
static void find_rsvp_session_tempfilt(tvbuff_t* tvb, int offset, int* session_off, int* tempfilt_off) {
    *session_off = 0;
    *tempfilt_off = 0;
}
static char* summary_session(tvbuff_t* tvb, int offset) { return ""; }
static char* summary_template(tvbuff_t* tvb, int offset) { return ""; }
static void dissect_rsvp_msg_tree(tvbuff_t* tvb, packet_info* pinfo, proto_tree* tree, void* tt_rsvp, void* rsvph, gboolean e2ei) {}
static void tap_queue_packet(void* tap, packet_info* pinfo, void* data) {}
static const char* val_to_str_ext(guint8 val, struct value_string_ext* vs, const char* fmt) { return ""; }
static void* g_hash_table_lookup(void* hash, void* key) { return NULL; }
static void g_hash_table_insert(void* hash, void* key, void* value) {}
static void proto_tree_add_expert(proto_tree* tree, packet_info* pinfo, struct expert_field* ef, tvbuff_t* tvb, int offset1, int offset2) {}

#define wmem_packet_scope() NULL
#define wmem_file_scope() NULL
#define wmem_new0(scope, type) ((type*)calloc(1, sizeof(type)))
#define wmem_new(scope, type) ((type*)malloc(sizeof(type)))
#define wmem_memdup(scope, ptr, size) memcpy(malloc(size), ptr, size)