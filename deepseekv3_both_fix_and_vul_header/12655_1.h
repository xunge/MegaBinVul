#include <stdlib.h>
#include <string.h>

struct ly_ctx {
    // context fields
};

struct lyxml_elem {
    const char *name;
    struct lyxml_elem *child;
    struct lyxml_elem *next;
    struct lyxml_ns *ns;
    // other XML element fields
};

struct lyxml_ns {
    const char *value;
    // other namespace fields
};

struct lys_module {
    struct ly_ctx *ctx;
    int version;
    // other module fields
};

struct lys_node {
    const char *name;
    struct lys_node *prev;
    void *ext;
    int ext_size;
    int iffeature_size;
    // other node fields
};

struct lys_node_rpc_action {
    int nodetype;
    struct lys_node *prev;
    void *tpdf;
    int tpdf_size;
    void *iffeature;
    int iffeature_size;
    // other RPC/action fields
};

struct unres_schema {
    // unresolved schema fields
};

#define LY_NSYIN "urn:ietf:params:xml:ns:yang:yin:1"
#define LYS_RPC 1
#define LYS_ACTION 2
#define LYEXT_PAR_NODE 0
#define OPT_IDENT 0
#define OPT_MODULE 0
#define LY_VLOG_LYS 0
#define LYE_INSTMT 0
#define LYE_TOOMANY 0
#define LY_LDGYIN 0

#define LY_CHECK_ERR_RETURN(cond, action, retval) if (cond) { action; return retval; }
#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }
#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, desc, node, label) \
    if ((count) >= (size)) { goto label; }

#define LY_TREE_FOR_SAFE(first, next, elem) \
    for ((elem) = (first); (elem) && ((next) = (elem)->next, 1); (elem) = (next))