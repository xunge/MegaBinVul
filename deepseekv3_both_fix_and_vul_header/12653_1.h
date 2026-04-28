#include <stdlib.h>
#include <string.h>

struct ly_ctx {
    struct {
        int flags;
    } models;
};

struct lyxml_elem {
    char *name;
    struct {
        char *value;
    } *ns;
    struct lyxml_elem *child;
};

struct lys_module {
    struct ly_ctx *ctx;
};

struct lys_node {
    int nodetype;
    char *name;
    void *ext;
    int ext_size;
    int iffeature_size;
    struct lys_node *prev;
};

struct lys_node_case {
    int nodetype;
    struct lys_node *prev;
    void *when;
    void **iffeature;
    int iffeature_size;
};

struct unres_schema {};

#define LYEXT_PAR_NODE 0
#define LYS_CASE 0
#define LYS_PARSE_OPT_CFG_MASK 0
#define LY_NSYIN ""
#define LYE_INSTMT 0
#define LYE_TOOMANY 0
#define LY_VLOG_LYS 0
#define LY_LDGYIN 0
#define LYS_ANYXML 0
#define LYS_ANYDATA 0
#define LY_CTX_TRUSTED 0
#define LYS_PARSE_OPT_INGRP 0
#define UNRES_XPATH 0
#define OPT_IDENT 0
#define OPT_MODULE 0
#define OPT_CFG_INHERIT 0

#define LY_CHECK_ERR_RETURN(cond, action, retval) if (cond) { action; return retval; }
#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }
#define LOGMEM(ctx)
#define LOGDBG(level, fmt, ...)
#define LOGVAL(ctx, code, level, node, ...)
#define LY_TREE_FOR_SAFE(start, next, elem) for ((elem) = (start); (elem); (elem) = (next))
#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, type, stmt, label)