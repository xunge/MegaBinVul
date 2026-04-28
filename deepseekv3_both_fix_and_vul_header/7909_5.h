#include <stdint.h>
#include <stddef.h>

typedef uint8_t guint8;
typedef uint16_t guint16;
typedef uint32_t guint32;
typedef int gboolean;
#define FALSE 0
#define TRUE 1

typedef struct tvbuff_t {
    int dummy;
} tvbuff_t;

typedef struct proto_item {
    int dummy;
} proto_item;

typedef struct proto_tree {
    int dummy;
} proto_tree;

typedef struct column_info {
    int COL_PROTOCOL;
    int COL_INFO;
} column_info;

typedef struct packet_info {
    int can_desegment;
    int saved_can_desegment;
    int desegment_offset;
    int desegment_len;
    column_info *cinfo;
    void* pool;
} packet_info;

typedef struct expert_field {
    int dummy;
} expert_field;

#define _U_ __attribute__((unused))
#define ENC_NA 0
#define DESEGMENT_ONE_MORE_SEGMENT (-1)
#define COL_PROTOCOL 0
#define COL_INFO 1

extern proto_tree *top_tree;
extern int proto_sigcomp;
extern int ett_sigcomp;
extern int hf_sigcomp_starting_to_remove_escape_digits;
extern int hf_sigcomp_escape_digit_found;
extern int hf_sigcomp_illegal_escape_code;
extern int hf_sigcomp_end_of_sigcomp_message_indication_found;
extern int hf_sigcomp_addr_value;
extern int hf_sigcomp_copying_bytes_literally;
extern int hf_sigcomp_data_for_sigcomp_dissector;
extern int udvm_print_detail_level;
extern expert_field ei_sigcomp_tcp_fragment;

guint16 tvb_get_ntohs(tvbuff_t *tvb, int offset);
guint8 tvb_get_guint8(tvbuff_t *tvb, int offset);
int tvb_reported_length_remaining(tvbuff_t *tvb, int offset);
int tvb_captured_length_remaining(tvbuff_t *tvb, int offset);
void col_set_str(column_info *cinfo, int col, const char* str);
void col_clear(column_info *cinfo, int col);
proto_item* proto_tree_add_item(proto_tree *tree, int proto, tvbuff_t *tvb, 
                              int start, int length, int encoding);
proto_tree* proto_item_add_subtree(proto_item *ti, int ett);
void* wmem_alloc(void* pool, size_t size);
void proto_tree_add_none_format(proto_tree *tree, int hf, tvbuff_t *tvb, 
                              int start, int length, const char* format);
void proto_tree_add_uint_format(proto_tree *tree, int hf, tvbuff_t *tvb, 
                              int start, int length, guint32 value, const char* format, ...);
void proto_tree_add_bytes_format(proto_tree *tree, int hf, tvbuff_t *tvb, 
                               int start, int length, const char* format, ...);
tvbuff_t* tvb_new_child_real_data(tvbuff_t *parent, guint8* data, int length, int reported_length);
void add_new_data_source(packet_info *pinfo, tvbuff_t *tvb, const char* description);
void proto_tree_add_expert(proto_tree *tree, packet_info *pinfo, expert_field *ef, 
                         tvbuff_t *tvb, int start, int length);

void dissect_sigcomp_common(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree);