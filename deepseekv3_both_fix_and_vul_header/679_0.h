#include <stdlib.h>

typedef struct myhtml_tree_node_t myhtml_tree_node_t;
typedef struct myhtml_tree_t myhtml_tree_t;

struct myhtml_tree_node_t {
    myhtml_tree_node_t* next;
    myhtml_tree_node_t* prev;
    myhtml_tree_node_t* parent;
    myhtml_tree_node_t* last_child;
    myhtml_tree_node_t* child;
    myhtml_tree_t* tree;
};

struct myhtml_tree_t {
    // 这里只需要声明结构体，不需要具体定义
};

void myhtml_tree_node_callback_remove(myhtml_tree_t* tree, myhtml_tree_node_t* node);