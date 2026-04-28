#include <stdlib.h>
#include <string.h>

#define LY_NSYIN "urn:ietf:params:xml:ns:yang:yin:1"
#define LYS_NODE int
#define LYEXT_PAR_NODE 0
#define LYS_PARSE_OPT_CFG_IGNORE 0
#define LYS_PARSE_OPT_CFG_NOINHERIT 0
#define LYS_MAND_TRUE 1
#define LYS_MAND_FALSE 2
#define LYS_VALID_EXT 4
#define LYEXT_OPT_VALID 8
#define LY_CTX_TRUSTED 16
#define LYS_PARSE_OPT_INGRP 32
#define UNRES_XPATH 64
#define LYEXT_SUBSTMT_MANDATORY 128
#define LY_LDGYIN 256
#define LYE_TOOMANY 512
#define LYE_INARG 1024
#define LYE_INSTMT 2048
#define LY_VLOG_LYS 4096

#define OPT_IDENT 1
#define OPT_MODULE 2
#define OPT_CFG_IGNORE 4
#define OPT_CFG_PARSE 8
#define OPT_CFG_INHERIT 16

struct lys_node;
struct lys_module;
struct lyxml_elem;
struct unres_schema;
struct ly_ctx;
struct lys_node_anydata;
struct lys_when;
struct lys_ext_instance;

struct lys_node {
    char *name;
    struct lys_ext_instance **ext;
    int ext_size;
    int iffeature_size;
    int flags;
    struct lys_when *when;
};

struct lys_node_anydata {
    int nodetype;
    struct lys_node *prev;
    int flags;
    struct lys_when *when;
    struct lys_restr **must;
    int must_size;
    struct lys_iffeature **iffeature;
    int iffeature_size;
};

struct lys_module {
    struct ly_ctx *ctx;
};

struct ly_ctx {
    struct {
        int flags;
    } models;
};

struct lyxml_elem {
    char *name;
    struct lyxml_elem *child;
    struct lyxml_ns *ns;
};

struct lyxml_ns {
    char *value;
};

struct lys_restr;
struct lys_iffeature;
struct lys_ext_instance {
    int flags;
};

#define LOGMEM(ctx)
#define LOGVAL(ctx, type, vlog, node, ...)
#define LOGDBG(level, ...)
#define LY_CHECK_ERR_RETURN(cond, action, retval) if (cond) { action; return retval; }
#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }
#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, desc, node, label)
#define GETVAL(ctx, var, elem, attr)
#define LY_TREE_FOR_SAFE(start, next, elem) for ((elem) = (start); (elem); (elem) = (next))