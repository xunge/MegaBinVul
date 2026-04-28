#include <stddef.h>

#define SEPOL_OK 0

enum cil_flavor {
    CIL_TUNABLEIF,
    CIL_IN,
    CIL_MACRO,
    CIL_OPTIONAL,
    CIL_BOOLEANIF
};

struct cil_tree_node {
    enum cil_flavor flavor;
};

struct cil_args_build {
    struct cil_tree_node *ast;
    struct cil_tree_node *tunif;
    struct cil_tree_node *in;
    struct cil_tree_node *macro;
    struct cil_tree_node *optional;
    struct cil_tree_node *boolif;
};