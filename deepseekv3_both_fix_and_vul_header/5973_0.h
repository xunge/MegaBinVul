#include <stdlib.h>

#define SEPOL_OK 0
#define SEPOL_ERR -1

struct cil_db;
struct cil_tree_node;

struct cil_args_build {
    struct cil_tree_node *ast;
    struct cil_db *db;
    void *tunif;
    void *in;
    void *macro;
    void *optional;
    void *boolif;
};

int cil_tree_walk(struct cil_tree_node *node, 
                 int (*node_helper)(struct cil_tree_node *, void *),
                 int (*first_child_helper)(struct cil_tree_node *, void *),
                 int (*last_child_helper)(struct cil_tree_node *, void *),
                 void *extra_args);

int __cil_build_ast_node_helper(struct cil_tree_node *node, void *extra_args);
int __cil_build_ast_first_child_helper(struct cil_tree_node *node, void *extra_args);
int __cil_build_ast_last_child_helper(struct cil_tree_node *node, void *extra_args);