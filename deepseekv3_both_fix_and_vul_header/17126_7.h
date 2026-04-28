#include <stdint.h>
#include <stddef.h>

#define MIN_BOX_SIZE 8
#define _U_

enum {
    BOX_TYPE_NONE,
    COL_PROTOCOL,
    COL_INFO
};

typedef int32_t gint;
typedef uint32_t guint32;

typedef struct tvbuff_t {
    size_t (*reported_length)(struct tvbuff_t*);
    uint32_t (*get_ntohl)(struct tvbuff_t*, int);
    size_t (*reported_length_remaining)(struct tvbuff_t*, int);
} tvbuff_t;

typedef struct {
    void* cinfo;
} packet_info;

typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;

typedef struct {
    const char* name;
    guint32 value;
} value_string;

extern const value_string box_types[];
extern int proto_mp4;
extern gint ett_mp4;

size_t tvb_reported_length(tvbuff_t* tvb);
uint32_t tvb_get_ntohl(tvbuff_t* tvb, int offset);
size_t tvb_reported_length_remaining(tvbuff_t* tvb, int offset);
const char* try_val_to_str(guint32 value, const value_string* vs);
void col_set_str(void* cinfo, int column, const char* str);
void col_clear(void* cinfo, int column);
proto_item* proto_tree_add_protocol_format(proto_tree* tree, int proto, tvbuff_t* tvb, int start, int length, const char* format);
proto_tree* proto_item_add_subtree(proto_item* item, int ett);

/* Two versions of dissect_mp4_box to match both call patterns */
int dissect_mp4_box_v1(guint32 parent_box_type, gint dummy, tvbuff_t* tvb, gint offset, packet_info* pinfo, proto_tree* tree);
int dissect_mp4_box_v2(guint32 parent_box_type, tvbuff_t* tvb, gint offset, packet_info* pinfo, proto_tree* tree);