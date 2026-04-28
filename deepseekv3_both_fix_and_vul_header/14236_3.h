#include <string.h>
#include <stdint.h>

typedef uint32_t guint;
typedef uint8_t guint8;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct tvbuff tvbuff_t;
typedef struct {
    void *pool;
    void *cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct {
    int dummy;
} expert_field;

typedef struct {
    guint value;
    const char *strptr;
} value_string;

enum {
    ENC_NA,
    ENC_BIG_ENDIAN
};

enum {
    COL_INFO
};

extern int hf_bencoded_dict_entry;
extern int ett_bencoded_dict_entry;
extern int hf_ip;
extern int hf_port;
extern expert_field ei_int_string;
extern const char *dict_str;
extern const char *list_str;
extern const value_string short_key_name_value_string[];
extern const value_string short_val_name_value_string[];

extern int dissect_bencoded_string(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char **str, gboolean tohex, const char *label);
extern int dissect_bencoded_dict(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char *label);
extern int dissect_bt_dht_error(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char **str, const char *label);
extern int dissect_bt_dht_values(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char **str, const char *label);
extern int dissect_bencoded_list(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char *label);
extern int dissect_bencoded_int(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char **str, const char *label);
extern int dissect_bt_dht_nodes(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, guint offset, const char **str, const char *label, int version);
extern int bencoded_string_length(packet_info *pinfo, tvbuff_t *tvb, guint *offset);
extern const char *tvb_ip_to_str(void *pool, tvbuff_t *tvb, guint offset);
extern proto_item* proto_tree_add_item(proto_tree *tree, int hfindex, tvbuff_t *tvb, guint offset, guint length, int encoding);
extern proto_tree* proto_item_add_subtree(proto_item *ti, int ett);
extern guint8 tvb_get_guint8(tvbuff_t *tvb, guint offset);
extern void proto_tree_add_expert_format(proto_tree *tree, packet_info *pinfo, expert_field *ef, tvbuff_t *tvb, guint offset, int len, const char *format, ...);
extern const char* val_to_str_const(guint val, const value_string *vs, const char *default_str);
extern void proto_item_set_text(proto_item *ti, const char *format, ...);
extern void proto_item_set_len(proto_item *ti, guint length);
extern void col_append_fstr(void *cinfo, int column, const char *format, ...);