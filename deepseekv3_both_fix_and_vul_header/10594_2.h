#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef int32_t gint32;
typedef char gchar;

typedef struct tvbuff_t tvbuff_t;
typedef struct packet_info {
    void* cinfo;
} packet_info;
typedef struct proto_tree proto_tree;
typedef struct proto_item proto_item;
typedef struct value_string value_string;

typedef int (*dissector_t)(tvbuff_t *, packet_info *, proto_tree *, void *);

struct SESSION_DATA_STRUCTURE {
    int ros_op;
};

typedef struct {
    int *proto;
    int *ett_proto;
    const char *name;
    const value_string *opr_code_strings;
    const value_string *err_code_strings;
    dissector_t *opr_code_dissectors;
    dissector_t *err_code_dissectors;
} ros_info_t;

#define ROS_OP_TYPE_MASK 0x0F
#define ROS_OP_PDU_MASK 0xF0
#define ROS_OP_BIND 0x01
#define ROS_OP_ERROR 0x02
#define ROS_OP_ARGUMENT 0x04
#define ROS_OP_RESULT 0x08
#define ROS_OP_OPCODE_MASK 0xFF

#define ENC_NA 0
#define COL_PROTOCOL 0
#define COL_INFO 1
#define TRUE true
#define FALSE false

extern void* g_hash_table_lookup(void* table, const char* key);
extern proto_item* proto_tree_add_item(proto_tree* tree, int proto, tvbuff_t* tvb, int start, int length, int encoding);
extern proto_tree* proto_item_add_subtree(proto_item* item, int ett);
extern void col_set_str(void* cinfo, int column, const char* str);
extern void col_append_str(void* cinfo, int column, const char* str);
extern const char* val_to_str(gint32 val, const value_string* vs, const char* default_str);

extern void* protocol_table;
extern int err_ros_bind;
extern int op_ros_bind;

dissector_t ros_lookup_opr_dissector(gint32 opcode, dissector_t* dissectors, bool argument);
dissector_t ros_lookup_err_dissector(gint32 opcode, dissector_t* dissectors);