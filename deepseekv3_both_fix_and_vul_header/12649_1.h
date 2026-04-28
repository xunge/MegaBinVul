#include <stdlib.h>
#include <string.h>

struct ly_ctx;
struct lyxml_elem;
struct lys_module;
struct lys_node;
struct unres_schema;

struct lyxml_elem {
    struct lyxml_elem *next;
    struct lyxml_elem *child;
    struct lyxml_ns *ns;
    char *name;
};

struct lyxml_ns {
    char *value;
};

struct lys_module {
    struct ly_ctx *ctx;
};

struct lys_node {
    char *name;
    void *ext;
    int ext_size;
};

struct lys_node_grp {
    int nodetype;
    struct lys_node *prev;
    void *tpdf;
    int tpdf_size;
};

#define LY_NSYIN "urn:ietf:params:xml:ns:yang:yin:1"
#define LYS_GROUPING 1
#define LYEXT_PAR_NODE 1
#define OPT_IDENT 1
#define OPT_MODULE 1
#define LYS_PARSE_OPT_INGRP 1
#define LYS_ANYXML 1
#define LYS_ANYDATA 1
#define LY_LDGYIN 1
#define LYE_INSTMT 1
#define LY_VLOG_LYS 1

#define LY_CHECK_ERR_RETURN(cond, action, retval) if (cond) { action; return retval; }
#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }
#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, type, parent, label)
#define LOGMEM(ctx)
#define LOGDBG(level, fmt, ...)
#define LOGVAL(ctx, code, level, node, msg)
#define LOGWRN(ctx, fmt, ...)

#define LY_TREE_FOR_SAFE(first, next, elem) \
    for ((elem) = (first); (elem) && ((next) = (elem)->next, 1); (elem) = (next))