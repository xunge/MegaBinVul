#include <stdint.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Basic type definitions */
typedef int gint;
typedef uint8_t guint8;
typedef uint16_t guint16;
typedef char gchar;
typedef unsigned int guint;

/* Time structure */
typedef struct {
    time_t secs;
    int32_t nsecs;
} nstime_t;

/* Wireshark core types */
typedef struct tvbuff tvbuff_t;
typedef struct packet_info {
    int num;
    struct {
        nstime_t abs_ts;
    } *fd;
    void *cinfo;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct conversation conversation_t;

/* CoAP specific structures */
typedef struct {
    uint8_t block_number;
    uint8_t block_mflag;
    void *uri_str_strbuf;
    void *uri_query_strbuf;
    const char *ctype_str;
    uint16_t ctype_value;
} coap_info;

typedef struct {
    void *messages;
} coap_conv_info;

typedef struct {
    uint32_t req_frame;
    uint32_t rsp_frame;
    nstime_t req_time;
    void *uri_str_strbuf;
} coap_transaction;

/* Constants */
#define DEFAULT_COAP_CTYPE_VALUE 0xFFFF
#define DEFAULT_COAP_BLOCK_NUMBER 0
#define _U_ __attribute__((unused))
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1
#define COL_PROTOCOL 0
#define COL_INFO 1

/* Dummy function macros */
#define PINFO_FD_VISITED(pinfo) (0)
#define wmem_new0(scope, type) ((type*)malloc(sizeof(type)))
#define wmem_file_scope() (NULL)
#define p_add_proto_data(scope, pinfo, proto, idx, data) 
#define p_get_proto_data(scope, pinfo, proto, idx) (NULL)
#define tvb_reported_length(tvb) (0)
#define col_set_str(cinfo, col, str) 
#define col_clear(cinfo, col) 
#define proto_tree_add_item(tree, hf, tvb, offset, len, enc) (NULL)
#define proto_item_add_subtree(item, ett) (NULL)
#define tvb_get_guint8(tvb, offset) (0)
#define tvb_get_ntohs(tvb, offset) (0)
#define col_add_fstr(cinfo, col, fmt, ...) 
#define val_to_str(val, table, def) ("")
#define val_to_str_ext(val, ext, def) ("")
#define proto_item_append_text(item, fmt, ...) 
#define wmem_strbuf_sized_new(scope, init, size) (NULL)
#define wmem_packet_scope() (NULL)
#define tvb_bytes_to_str_punct(scope, tvb, offset, len, punct) (NULL)
#define dissect_coap_options(tvb, pinfo, tree, offset, len, coinfo) (0)
#define tvb_captured_length(tvb) (0)
#define find_or_create_conversation_noaddrb(pinfo, flag) (NULL)
#define conversation_get_proto_data(conv, proto) (NULL)
#define wmem_new(scope, type) ((type*)malloc(sizeof(type)))
#define wmem_map_new(scope, hash, equal) (NULL)
#define g_str_hash NULL
#define g_str_equal NULL
#define conversation_add_proto_data(conv, proto, data) 
#define wmem_map_lookup(map, key) (NULL)
#define wmem_strbuf_new(scope, str) (NULL)
#define wmem_strbuf_get_str(buf) ("")
#define wmem_map_insert(map, key, val) 
#define proto_tree_add_uint(tree, hf, tvb, offset, len, val) (NULL)
#define PROTO_ITEM_SET_GENERATED(item) 
#define nstime_delta(delta, t1, t2) 
#define proto_tree_add_time(tree, hf, tvb, offset, len, time) (NULL)
#define col_append_fstr(cinfo, col, fmt, ...) 
#define wmem_strbuf_get_len(buf) (0)
#define proto_tree_add_string(tree, hf, tvb, offset, len, str) (NULL)
#define PROTO_ITEM_SET_HIDDEN(item) 
#define col_append_str(cinfo, col, str) 
#define g_snprintf(buf, size, fmt, ...) snprintf(buf, size, fmt, __VA_ARGS__)
#define tvb_new_subset_length(tvb, offset, len) (NULL)
#define dissector_try_string(table, str, tvb, pinfo, tree, data) (0)

/* Dummy variables */
extern int proto_coap;
extern int ett_coap;
extern int ett_coap_payload;
extern int hf_coap_version;
extern int hf_coap_ttype;
extern int hf_coap_token_len;
extern int hf_coap_token;
extern int hf_coap_code;
extern int hf_coap_mid;
extern int hf_coap_payload;
extern int hf_coap_payload_desc;
extern int hf_coap_payload_length;
extern int hf_coap_opt_uri_path_recon;
extern int hf_coap_response_in;
extern int hf_coap_response_to;
extern int hf_coap_response_time;
extern const void *vals_ttype_short;
extern const void *vals_code_ext;
extern const void *vals_ttype;
extern void *media_type_dissector_table;