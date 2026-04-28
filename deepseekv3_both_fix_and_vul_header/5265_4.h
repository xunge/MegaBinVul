#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1

typedef int gboolean;
typedef char gchar;
typedef unsigned int guint32;

typedef struct tvbuff {
    // dummy structure
} tvbuff_t;

typedef struct packet_info {
    int destport;
    int match_uint;
    void *cinfo;
} packet_info;

typedef struct proto_tree {
    // dummy structure
} proto_tree;

typedef struct proto_item {
    // dummy structure
} proto_item;

typedef struct expert_field {
    // dummy structure
} ei_register_info;

extern int proto_tsdns;
extern int ett_tsdns;
extern int hf_tsdns_data;
extern int hf_tsdns_request;
extern int hf_tsdns_request_domain;
extern int hf_tsdns_response;
extern int hf_tsdns_response_address;
extern int hf_tsdns_response_ip;
extern int hf_tsdns_response_port;
extern ei_register_info ei_response_port_malformed;

#define ENC_NA 0
#define ENC_ASCII 0
#define COL_PROTOCOL 0
#define COL_INFO 0
#define PROTO_ITEM_SET_HIDDEN(item) (void)0
#define _U_ __attribute__((unused))

void *wmem_packet_scope(void);
char *tvb_get_string_enc(void *scope, tvbuff_t *tvb, int offset, int length, int encoding);
char *tvb_format_text(tvbuff_t *tvb, int offset, int length);
gchar **wmem_strsplit(void *scope, const char *src, const char *delimiter, int max_tokens);
int ws_strtou32(const char *str, char **endptr, guint32 *value);
int tvb_reported_length(tvbuff_t *tvb);
int tvb_captured_length(tvbuff_t *tvb);

void col_set_str(void *cinfo, int column, const char *str);
void col_append_fstr(void *cinfo, int column, const char *format, ...);
proto_item *proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, int encoding);
proto_tree *proto_item_add_subtree(proto_item *ti, int ett);
proto_item *proto_tree_add_boolean(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, gboolean value);
proto_item *proto_tree_add_string(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, const char *value);
proto_item *proto_tree_add_uint(proto_tree *tree, int hfindex, tvbuff_t *tvb, int start, int length, guint32 value);
void expert_add_info(packet_info *pinfo, proto_item *item, ei_register_info *ei);