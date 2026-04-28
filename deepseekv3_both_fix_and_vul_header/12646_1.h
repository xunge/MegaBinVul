#include <stdlib.h>
#include <string.h>

struct ly_ctx {
    struct {
        int flags;
    } models;
};

struct lyxml_elem {
    char *name;
    struct lyxml_elem *child;
    struct lyxml_elem *next;
    struct {
        char *value;
    } *ns;
};

struct lys_module {
    struct ly_ctx *ctx;
    int version;
};

struct lys_node {
    struct lys_module *module;
    int nodetype;
    void *ext;
    size_t ext_size;
};

struct lys_node_inout {
    struct lys_node *prev;
    int nodetype;
    char *name;
    void *tpdf;
    size_t tpdf_size;
    void *must;
    size_t must_size;
    void *ext;
    size_t ext_size;
};

struct unres_schema {
    // dummy structure
};

#define LY_NSYIN "urn:ietf:params:xml:ns:yang:yin:1"
#define LYS_INPUT 0
#define LYS_OUTPUT 1
#define LYS_ANYXML 2
#define LYS_ANYDATA 3
#define LY_LDGYIN 0
#define LYE_INSTMT 0
#define LYE_MISSCHILDSTMT 0
#define LY_VLOG_LYS 0
#define LY_CTX_TRUSTED 0
#define LYS_PARSE_OPT_CFG_IGNORE 0
#define LYS_PARSE_OPT_INGRP 0
#define UNRES_XPATH 0
#define LYEXT_PAR_NODE 0

#define LY_TREE_FOR_SAFE(start, next, elem) \
    for ((elem) = (start); (elem); (elem) = (next), (next) = (elem) ? (elem)->next : NULL)

#define LY_CHECK_ERR_RETURN(cond, action, retval) \
    if (cond) { action; return retval; }

#define LY_CHECK_ERR_GOTO(cond, action, label) \
    if (cond) { action; goto label; }

#define LOGMEM(ctx) 
#define LOGINT(ctx) 
#define LOGDBG(level, ...) 
#define LOGVAL(ctx, type, vlog, node, ...) 
#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, type, name, label) \
    if ((count) >= (size)) { goto label; }

static inline const char *strnodetype(int nodetype) { return ""; }