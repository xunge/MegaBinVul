#include <stdint.h>
#include <string.h>
#include <stdarg.h>

typedef uint32_t guint32;
typedef uint8_t guint8;
typedef int32_t gint;
typedef char gchar;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

#define ENC_NA 0
#define ENC_ASCII 1
#define BMT_NO_FALSE 0

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct packet_info packet_info;
typedef struct tvbuff_t tvbuff_t;
typedef struct {
    int dummy;
} expert_field;

struct value_string {
    guint32 value;
    const char *strptr;
};

static int hf_capabilities_section;
static int ett_capabilities;
static int ett_capabilities_entry;
static int ett_capabilities_extended_methods;
static int ett_capabilities_header_code_pages;
static int ett_proto_option_capability;

static int hf_capa_client_sdu_size;
static int hf_capa_server_sdu_size;
static int hf_capa_protocol_options;
static int hf_capa_protocol_option_confirmed_push;
static int hf_capa_protocol_option_push;
static int hf_capa_protocol_option_session_resume;
static int hf_capa_protocol_option_ack_headers;
static int hf_capa_protocol_option_large_data_transfer;
static int hf_capa_method_mor;
static int hf_capa_push_mor;
static int hf_capa_extended_method;
static int hf_capa_header_code_page;
static int hf_capa_aliases;
static int hf_capa_client_message_size;
static int hf_capa_server_message_size;

static expert_field ei_wsp_oversized_uintvar;
static expert_field ei_wsp_capability_invalid;
static expert_field ei_wsp_capability_encoding_invalid;

#define WSP_PDU_CONNECT 0
#define WSP_CAPA_CLIENT_SDU_SIZE 0
#define WSP_CAPA_SERVER_SDU_SIZE 1
#define WSP_CAPA_PROTOCOL_OPTIONS 2
#define WSP_CAPA_METHOD_MOR 3
#define WSP_CAPA_PUSH_MOR 4
#define WSP_CAPA_EXTENDED_METHODS 5
#define WSP_CAPA_HEADER_CODE_PAGES 6
#define WSP_CAPA_ALIASES 7
#define WSP_CAPA_CLIENT_MESSAGE_SIZE 8
#define WSP_CAPA_SERVER_MESSAGE_SIZE 9

static const struct value_string wsp_capability_vals[] = {
    { WSP_CAPA_CLIENT_SDU_SIZE, "Client SDU Size" },
    { WSP_CAPA_SERVER_SDU_SIZE, "Server SDU Size" },
    { WSP_CAPA_PROTOCOL_OPTIONS, "Protocol Options" },
    { WSP_CAPA_METHOD_MOR, "Method MOR" },
    { WSP_CAPA_PUSH_MOR, "Push MOR" },
    { WSP_CAPA_EXTENDED_METHODS, "Extended Methods" },
    { WSP_CAPA_HEADER_CODE_PAGES, "Header Code Pages" },
    { WSP_CAPA_ALIASES, "Aliases" },
    { WSP_CAPA_CLIENT_MESSAGE_SIZE, "Client Message Size" },
    { WSP_CAPA_SERVER_MESSAGE_SIZE, "Server Message Size" },
    { 0, NULL }
};

static gboolean is_token_text(guint8 peek) {
    return (peek >= 0x20 && peek <= 0x7E);
}

static void get_text_string(char *str, tvbuff_t *tvb, guint32 offset, guint32 len, gboolean *ok) {
    *ok = TRUE;
}

static void *wmem_packet_scope(void) { return NULL; }
static guint32 tvb_reported_length(tvbuff_t *tvb) { return 0; }
static guint32 tvb_get_guintvar(tvbuff_t *tvb, guint32 offset, guint32 *len, packet_info *pinfo, expert_field *ei) { return 0; }
static guint8 tvb_get_guint8(tvbuff_t *tvb, guint32 offset) { return 0; }
static gchar *tvb_get_stringz_enc(void *scope, tvbuff_t *tvb, guint32 offset, gint *len, int enc) { return NULL; }
static int g_ascii_strcasecmp(const char *s1, const char *s2) { return 0; }
static void expert_add_info_format(packet_info *pinfo, proto_item *item, expert_field *ei, const char *fmt, ...) {}
static void expert_add_info(packet_info *pinfo, proto_item *item, expert_field *ei) {}
static proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, int encoding) { return NULL; }
static proto_tree *proto_item_add_subtree(proto_item *item, int ett) { return NULL; }
static proto_tree *proto_tree_add_subtree(proto_tree *tree, tvbuff_t *tvb, guint32 start, guint32 length, int ett, proto_item **item, const char *text) { return NULL; }
static void proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint32 start, guint32 length, guint32 value) {}
static void proto_tree_add_bitmask_with_flags(proto_tree *tree, tvbuff_t *tvb, guint32 offset, int hfindex, int ett, const int **fields, int encoding, int flags) {}
static const char *val_to_str_const(guint32 value, const struct value_string *vs, const char *default_str) { return NULL; }
static void proto_item_append_text(proto_item *item, const char *format, ...) {}
static void proto_item_set_len(proto_item *item, guint32 length) {}