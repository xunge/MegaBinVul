#include <stdint.h>
#include <stddef.h>

typedef int32_t gint32;
typedef const char gchar;

typedef struct tvbuff_t {
    // dummy definition
} tvbuff_t;

typedef struct packet_info {
    void *cinfo;
    // other members
} packet_info;

typedef struct proto_tree {
    // dummy definition
} proto_tree;

typedef struct proto_item {
    // dummy definition
} proto_item;

typedef struct value_string {
    // dummy definition
} value_string;

#define TRUE 1
#define FALSE 0

typedef int (*dissector_t)(tvbuff_t *, packet_info *, proto_tree *, void *);

struct SESSION_DATA_STRUCTURE {
    int ros_op;
};

typedef struct {
    const char *name;
    int *proto;
    int *ett_proto;
    const value_string *opr_code_strings;
    const value_string *err_code_strings;
    dissector_t *opr_code_dissectors;
    dissector_t *err_code_dissectors;
} ros_info_t;

#define ROS_OP_TYPE_MASK 0xF0
#define ROS_OP_PDU_MASK 0x0F
#define ROS_OP_BIND 0x10
#define ROS_OP_ERROR 0x01
#define ROS_OP_ARGUMENT 0x02
#define ROS_OP_RESULT 0x03
#define ROS_OP_OPCODE_MASK 0xFF

#define err_ros_bind 0
#define op_ros_bind 1

#define ENC_NA 0
#define COL_PROTOCOL 0
#define COL_INFO 0

extern void col_set_str(void *cinfo, int col, const char *str);
extern void col_append_str(void *cinfo, int col, const char *str);
extern proto_item *proto_tree_add_item(proto_tree *tree, int proto, tvbuff_t *tvb, int start, int length, int encoding);
extern proto_tree *proto_item_add_subtree(proto_item *item, int ett);
extern const char *val_to_str(int val, const value_string *vs, const char *fmt);
extern void *g_hash_table_lookup(void *table, const void *key);
extern dissector_t ros_lookup_opr_dissector(int opcode, dissector_t *dissectors, int is_argument);
extern dissector_t ros_lookup_err_dissector(int opcode, dissector_t *dissectors);

extern void *protocol_table;