#include <stdint.h>
#include <stddef.h>

#define NWPH_MIN_LEN 4
#define NWPH_VERS 0
#define NWPH_TYPE 1
#define NWPH_HIDC 2
#define NWPH_HLEN 3

#define NWP_TYPE_ANNOUNCEMENT 1
#define NWP_TYPE_NEIGH_LIST 2

#define COL_PROTOCOL 0
#define COL_INFO 1
#define ENC_NA 0
#define ENC_BIG_ENDIAN 1

typedef int32_t gint;
typedef uint8_t guint8;
typedef char gchar;

#define _U_ __attribute__((unused))

typedef struct tvbuff_t {
    size_t reported_length;
    size_t captured_length;
    uint8_t (*get_guint8)(struct tvbuff_t*, int);
} tvbuff_t;

typedef struct cinfo {
    const char* protocol;
    const char* info;
} cinfo;

typedef struct packet_info {
    cinfo* cinfo;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct expert_field expert_field;

typedef struct {
    const char* str;
    int value;
} value_string;

extern int proto_nwp;
extern int ett_nwp_tree;
extern int hf_nwp_version;
extern int hf_nwp_type;
extern int hf_nwp_hid_count;
extern int hf_nwp_haddr_len;
extern expert_field ei_nwp_bad_type;
extern const value_string nwp_type_vals[];

size_t tvb_reported_length(tvbuff_t* tvb);
size_t tvb_captured_length(tvbuff_t* tvb);
guint8 tvb_get_guint8(tvbuff_t* tvb, int offset);
const char* val_to_str(guint8 val, const value_string* vs, const char* fmt);
int try_val_to_str(guint8 val, const value_string* vs);
void col_set_str(cinfo* cinfo, int column, const char* str);
void col_clear(cinfo* cinfo, int column);
proto_item* proto_tree_add_item(proto_tree* tree, int proto, tvbuff_t* tvb, int start, int length, int encoding);
proto_tree* proto_item_add_subtree(proto_item* item, int ett);
void expert_add_info_format(packet_info* pinfo, proto_item* item, expert_field* ef, const char* fmt, const char* str);

void dissect_nwp_ann(tvbuff_t* tvb, proto_tree* tree, guint8 hid_count, guint8 ha_len);
void dissect_nwp_nl(tvbuff_t* tvb, proto_tree* tree, guint8 hid_count, guint8 ha_len);