#include <stdlib.h>
#include <string.h>

struct lys_node;
struct lys_module {
    struct ly_ctx *ctx;
};
struct lyxml_elem {
    char *name;
    struct lyxml_ns *ns;
    struct lyxml_elem *child;
    struct lyxml_elem *next;
};
struct lyxml_ns {
    char *value;
};
struct unres_schema;
struct ly_ctx {
    struct {
        unsigned int flags;
    } models;
};
struct lys_node_anydata {
    int nodetype;
    struct lys_node *prev;
    unsigned int flags;
    struct lys_when *when;
    struct lys_must *must;
    unsigned int must_size;
    void *iffeature;
    unsigned int iffeature_size;
};
struct lys_when;
struct lys_must {
    unsigned int dummy;  // placeholder for must structure
};
struct lys_ext_instance {
    unsigned int flags;
};

#define LY_NSYIN "urn:ietf:params:xml:ns:yang:yin:1"
#define LYEXT_PAR_NODE 0
#define LYEXT_SUBSTMT_MANDATORY 0
#define LYS_PARSE_OPT_CFG_IGNORE (1 << 0)
#define LYS_PARSE_OPT_CFG_NOINHERIT (1 << 1)
#define LYS_PARSE_OPT_INGRP (1 << 2)
#define LYS_NODE int
#define LYS_MAND_TRUE (1 << 0)
#define LYS_MAND_FALSE (1 << 1)
#define LYS_VALID_EXT (1 << 2)
#define LYEXT_OPT_VALID (1 << 0)
#define LY_CTX_TRUSTED (1 << 0)
#define LY_LDGYIN 0
#define LYE_TOOMANY 0
#define LYE_INARG 0
#define LYE_INSTMT 0
#define LY_VLOG_LYS 0
#define UNRES_XPATH 0

#define OPT_IDENT (1 << 0)
#define OPT_MODULE (1 << 1)
#define OPT_CFG_IGNORE (1 << 2)
#define OPT_CFG_PARSE (1 << 3)
#define OPT_CFG_INHERIT (1 << 4)

#define LY_CHECK_ERR_RETURN(cond, action, retval) if (cond) { action; return retval; }
#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }
#define LOGMEM(ctx) 
#define LOGVAL(ctx, type, flags, node, ...) 
#define LOGDBG(level, ...) 
#define GETVAL(ctx, var, elem, attr) 

struct lys_node {
    char *name;
    struct lys_ext_instance **ext;
    unsigned int ext_size;
    unsigned int iffeature_size;
    unsigned int flags;
    struct lys_when *when;
    struct lys_module *module;
};

#define LY_TREE_FOR_SAFE(start, next, elem) \
    for ((elem) = (start); (elem); (elem) = (next), (next) = (elem) ? (elem)->next : NULL)

#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, type, node, label) \
    if ((count) >= (size)) { \
        LOGVAL(ctx, LYE_TOOMANY, LY_VLOG_LYS, node, type, "anydata"); \
        goto label; \
    }

static int read_yin_common(struct lys_module *, struct lys_node *, struct lys_node *, int, struct lyxml_elem *, int, struct unres_schema *);
static struct lys_module *lys_main_module(struct lys_module *);
static int lys_node_addchild(struct lys_node *, struct lys_module *, struct lys_node *, int);
static int lyp_yin_parse_subnode_ext(struct lys_module *, struct lys_node *, int, struct lyxml_elem *, int, int, struct unres_schema *);
static struct lys_when *read_yin_when(struct lys_module *, struct lyxml_elem *, struct unres_schema *);
static int lyp_yin_fill_ext(struct lys_node *, int, int, int, struct lys_module *, struct lyxml_elem *, struct lys_ext_instance ***, unsigned int *, struct unres_schema *);
static int fill_yin_must(struct lys_module *, struct lyxml_elem *, struct lys_must *, struct unres_schema *);
static int fill_yin_iffeature(struct lys_node *, int, struct lyxml_elem *, void *, struct unres_schema *);
static void lyp_reduce_ext_list(struct lys_ext_instance ***, unsigned int, unsigned int);
static int lyxp_node_check_syntax(struct lys_node *);
static int unres_schema_add_node(struct lys_module *, struct unres_schema *, struct lys_node *, int, void *);
static void lys_node_free(struct ly_ctx *, struct lys_node *, void *, int);
static void lyxml_free(struct ly_ctx *, struct lyxml_elem *);