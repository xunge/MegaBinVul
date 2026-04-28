#include <stdlib.h>
#include <assert.h>

struct ly_ctx;

struct lys_module {
    struct ly_ctx *ctx;
};

struct lys_node {
    struct lys_module *module;
    void *priv;
    char *name;
    int nodetype;
    char *dsc;
    char *ref;
    struct lys_node *child;
    struct lys_node *next;
    void *iffeature;
    size_t iffeature_size;
    void *ext;
    size_t ext_size;
};

struct lys_node_container {
    struct lys_node node;
};

struct lys_node_choice {
    struct lys_node node;
    void *when;
};

struct lys_node_leaf {
    struct lys_node node;
};

struct lys_node_leaflist {
    struct lys_node node;
};

struct lys_node_list {
    struct lys_node node;
};

struct lys_node_anydata {
    struct lys_node node;
};

struct lys_node_uses {
    struct lys_node node;
};

struct lys_node_case {
    struct lys_node node;
    void *when;
};

struct lys_node_grp {
    struct lys_node node;
};

struct lys_node_rpc_action {
    struct lys_node node;
};

struct lys_node_notif {
    struct lys_node node;
};

struct lys_node_inout {
    struct lys_node node;
};

enum {
    LYS_INPUT,
    LYS_OUTPUT,
    LYS_LEAF,
    LYS_LEAFLIST,
    LYS_CONTAINER,
    LYS_CHOICE,
    LYS_LIST,
    LYS_ANYXML,
    LYS_ANYDATA,
    LYS_USES,
    LYS_CASE,
    LYS_AUGMENT,
    LYS_GROUPING,
    LYS_RPC,
    LYS_ACTION,
    LYS_NOTIF,
    LYS_EXT,
    LYS_UNKNOWN
};

void lydict_remove(struct ly_ctx *ctx, const char *str);
void lys_iffeature_free(struct ly_ctx *ctx, void *iffeature, size_t iffeature_size, int shallow, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_extension_instances_free(struct ly_ctx *ctx, void *ext, size_t ext_size, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_container_free(struct ly_ctx *ctx, struct lys_node_container *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_when_free(struct ly_ctx *ctx, void *when, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_leaf_free(struct ly_ctx *ctx, struct lys_node_leaf *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_leaflist_free(struct ly_ctx *ctx, struct lys_node_leaflist *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_list_free(struct ly_ctx *ctx, struct lys_node_list *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_anydata_free(struct ly_ctx *ctx, struct lys_node_anydata *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_uses_free(struct ly_ctx *ctx, struct lys_node_uses *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_grp_free(struct ly_ctx *ctx, struct lys_node_grp *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_rpc_action_free(struct ly_ctx *ctx, struct lys_node_rpc_action *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_notif_free(struct ly_ctx *ctx, struct lys_node_notif *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_inout_free(struct ly_ctx *ctx, struct lys_node_inout *node, void (*private_destructor)(const struct lys_node *node, void *priv));
void lys_node_unlink(struct lys_node *node);
void LOGINT(struct ly_ctx *ctx);

#define LY_TREE_FOR_SAFE(first, next, iter) \
    for ((iter) = (first); (iter) && ((next) = (iter)->next, 1); (iter) = (next))