#include <stddef.h>

typedef struct Node Node;
typedef struct BagNode BagNode;
typedef struct QuantNode QuantNode;
typedef struct regex_t regex_t;

struct BagNode {
    int type;
    union {
        struct {
            int regnum;
        } m;
        struct {
            Node* Then;
            Node* Else;
        } te;
    };
    Node* body;
    unsigned called : 1;
    unsigned recursion : 1;
    unsigned stop_bt_simple_repeat : 1;
};

struct QuantNode {
    Node* body;
    int lower;
};

struct regex_t {
    unsigned int bt_mem_start;
    unsigned int bt_mem_end;
};

#define NODE_BAG_BODY(node) ((node)->body)
#define NODE_IS_CALLED(node) ((node)->called)
#define NODE_IS_RECURSION(node) ((node)->recursion)
#define NODE_IS_STOP_BT_SIMPLE_REPEAT(node) ((node)->stop_bt_simple_repeat)
#define MEM_STATUS_AT0(bt_mem, regnum) ((bt_mem) & (1 << (regnum)))
#define QUANT_(node) ((QuantNode*)(node))
#define NODE_QUANT_BODY(qn) ((qn)->body)
#define IS_NOT_NULL(ptr) ((ptr) != NULL)

enum {
    BAG_OPTION,
    BAG_MEMORY,
    BAG_STOP_BACKTRACK,
    BAG_IF_ELSE
};

#define SIZE_OP_CALL 1
#define SIZE_OP_JUMP 1
#define SIZE_OP_RETURN 1
#define SIZE_OP_MEMORY_START_PUSH 1
#define SIZE_OP_MEMORY_END_PUSH 1
#define SIZE_OP_MEMORY_END_PUSH_REC 1
#define SIZE_OP_MEMORY_END_REC 1
#define SIZE_OP_MEMORY_START 1
#define SIZE_OP_MEMORY_END 1
#define SIZE_OP_PUSH 1
#define SIZE_OP_POP_OUT 1
#define SIZE_OP_ATOMIC_START 1
#define SIZE_OP_ATOMIC_END 1

#define ONIGERR_TOO_BIG_NUMBER_FOR_REPEAT_RANGE -1

static int compile_length_option_node(BagNode* node, regex_t* reg);
static int compile_length_tree(Node* node, regex_t* reg);
static int onig_positive_int_multiply(int a, int b);