#include <stdlib.h>

#define LY_TREE_FOR_SAFE(first, next, elem) \
    for ((elem) = (first); (elem) && ((next) = (elem)->next, 1); (elem) = (next))

struct lys_module;
struct lys_node;
struct lys_submodule {
    struct lys_module *belongsto;
    void *ctx;
    struct lys_node *data;
};
struct lys_module {
    struct lys_node *data;
};
struct lys_node {
    struct lys_module *module;
    struct lys_node *next;
};