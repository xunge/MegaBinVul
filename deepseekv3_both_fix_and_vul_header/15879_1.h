#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct lys_module;

struct lys_node {
    const char *name;
    int nodetype;
};

#define LYS_NODE int
#define LYS_AUGMENT (1 << 0)
#define LYS_USES (1 << 1)
#define LYS_GROUPING (1 << 2)
#define LYS_CHOICE (1 << 3)
#define LYS_CASE (1 << 4)
#define LYS_INPUT (1 << 5)
#define LYS_OUTPUT (1 << 6)

const struct lys_module *lys_node_module(const struct lys_node *node);
const struct lys_module *lys_main_module(const struct lys_module *mod);
const struct lys_node *lys_getnext(const struct lys_node *node, const struct lys_node *parent, const struct lys_module *mod, int flags);