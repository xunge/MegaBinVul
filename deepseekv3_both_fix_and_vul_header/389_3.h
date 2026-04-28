#include <stddef.h>

typedef struct BagNode BagNode;
typedef struct regex_t regex_t;
typedef struct ScanEnv ScanEnv;
typedef struct Node Node;
typedef struct QuantNode QuantNode;
typedef struct IfElseNode IfElseNode;

struct IfElseNode {
    Node* Then;
    Node* Else;
};

struct Node {
    Node* body;
};

struct QuantNode {
    int lower;
    Node* body;
};

struct BagNode {
    int type;
    union {
        IfElseNode te;
        Node* body;
    };
};

#define BAG_MEMORY 0
#define BAG_OPTION 1
#define BAG_STOP_BACKTRACK 2
#define BAG_IF_ELSE 3

#define NODE_IS_STOP_BT_SIMPLE_REPEAT(node) 0
#define QUANT_(node) ((QuantNode*)(node))
#define NODE_BAG_BODY(node) ((node)->body)
#define NODE_QUANT_BODY(qn) ((qn)->body)
#define IS_NOT_NULL(ptr) ((ptr) != NULL)

#define OP_PUSH 0
#define OP_POP_OUT 1
#define OP_JUMP 2
#define OP_ATOMIC_START 3
#define OP_ATOMIC_END 4

#define SIZE_INC_OP 1
#define SIZE_OP_POP_OUT 1
#define SIZE_OP_JUMP 1
#define SIZE_OP_PUSH 1
#define SIZE_OP_ATOMIC_END 1

typedef struct {
    union {
        struct {
            int addr;
        } push;
        struct {
            int addr;
        } jump;
    };
} OpCode;

#define COP(reg) ((OpCode*)(reg))

static int compile_bag_memory_node(BagNode* node, regex_t* reg, ScanEnv* env);
static int compile_option_node(BagNode* node, regex_t* reg, ScanEnv* env);
static int compile_tree_n_times(Node* node, int n, regex_t* reg, ScanEnv* env);
static int compile_length_tree(Node* node, regex_t* reg);
static int add_op(regex_t* reg, int op);
static int compile_tree(Node* node, regex_t* reg, ScanEnv* env);