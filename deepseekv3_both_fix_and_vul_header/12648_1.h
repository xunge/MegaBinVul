#include <stdlib.h>
#include <string.h>

struct lyxml_ns {
    char *value;
};

struct lyxml_elem {
    char *name;
    struct lyxml_ns *ns;
    struct lyxml_elem *child;
};

struct ly_ctx {
    struct {
        unsigned int flags;
    } models;
};

struct lys_module {
    struct ly_ctx *ctx;
    int version;
};

struct lys_node {
    char *name;
    void *ext;
    unsigned int ext_size;
    unsigned int iffeature_size;
    void *when;
    unsigned int flags;
    struct lys_node *prev;
    unsigned int nodetype;
};

struct lys_node_choice {
    unsigned int nodetype;
    struct lys_node *prev;
    unsigned int flags;
    void *iffeature;
    unsigned int iffeature_size;
    void *when;
};

struct unres_schema;

#define LY_NSYIN "urn:ietf:params:xml:ns:yang:yin:1"
#define LYEXT_PAR_NODE 0
#define LYS_CHOICE 1
#define LYS_PARSE_OPT_CFG_IGNORE (1 << 0)
#define LYS_PARSE_OPT_CFG_NOINHERIT (1 << 1)
#define LYS_ANYXML 2
#define LYS_ANYDATA 3
#define LYS_MAND_TRUE (1 << 0)
#define LYS_MAND_FALSE (1 << 1)
#define LYEXT_SUBSTMT_DEFAULT 0
#define LYEXT_SUBSTMT_MANDATORY 1
#define LYS_PARSE_OPT_INGRP (1 << 2)
#define UNRES_CHOICE_DFLT 0
#define UNRES_XPATH 1
#define LY_CTX_TRUSTED (1 << 0)

#define OPT_IDENT (1 << 0)
#define OPT_MODULE (1 << 1)
#define OPT_CFG_IGNORE (1 << 2)
#define OPT_CFG_PARSE (1 << 3)
#define OPT_CFG_INHERIT (1 << 4)

#define LY_CHECK_ERR_RETURN(cond, action, retval) if (cond) { action; return retval; }
#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }
#define LOGMEM(ctx)
#define LOGDBG(level, fmt, ...)
#define LOGVAL(ctx, code, vlog, node, ...)
#define LY_TREE_FOR_SAFE(start, next, elem) for ((elem) = (start); (elem); (elem) = (next))
#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, type, name, label)
#define GETVAL(ctx, var, elem, attr) (var = #attr)

enum LY_LOG_LEVEL {
    LY_LDGYIN
};

enum LY_VLOG_FLAG {
    LY_VLOG_LYS,
    LY_VLOG_PREV
};

enum LY_ERR {
    LYE_INARG,
    LYE_INSTMT,
    LYE_INCHILDSTMT,
    LYE_SPEC,
    LYE_TOOMANY
};