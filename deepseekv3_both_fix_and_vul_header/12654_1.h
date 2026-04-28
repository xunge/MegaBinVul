#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct lys_node;
struct lys_module;
struct lyxml_elem;
struct unres_schema;
struct lys_node_container;
struct lys_when;
struct lys_tpdf;
struct lys_restr;
struct lys_iffeature;

struct ly_ctx {
    struct {
        uint32_t flags;
    } models;
};

struct lyxml_ns {
    char *value;
};

struct lyxml_elem {
    char *name;
    char *value;
    struct lyxml_elem *child;
    struct lyxml_elem *next;
    struct lyxml_ns *ns;
};

struct lys_node {
    char *name;
    struct lys_node *prev;
    struct lys_node **ext;
    unsigned int ext_size;
    unsigned int iffeature_size;
    uint16_t flags;
};

struct lys_node_container {
    uint16_t nodetype;
    char *presence;
    struct lys_node *prev;
    struct lys_when *when;
    struct lys_tpdf **tpdf;
    unsigned int tpdf_size;
    struct lys_restr **must;
    unsigned int must_size;
    struct lys_iffeature **iffeature;
    unsigned int iffeature_size;
};

struct lys_module {
    struct ly_ctx *ctx;
};

enum LYEXT_PAR {
    LYEXT_PAR_NODE
};

enum LYEXT_SUBSTMT {
    LYEXT_SUBSTMT_PRESENCE
};

enum LYS_NODE {
    LYS_CONTAINER,
    LYS_ANYXML,
    LYS_ANYDATA
};

enum LYS_PARSE_OPT {
    LYS_PARSE_OPT_CFG_IGNORE,
    LYS_PARSE_OPT_CFG_NOINHERIT,
    LYS_PARSE_OPT_INGRP
};

enum LY_VLOG_FLAG {
    LY_VLOG_LYS
};

enum LY_ERR {
    LYE_INSTMT,
    LYE_TOOMANY
};

enum LY_LOG_LEVEL {
    LY_LDGYIN
};

enum LY_CTX_FLAG {
    LY_CTX_TRUSTED = 1
};

enum UNRES_TYPE {
    UNRES_XPATH
};

#define LY_NSYIN "urn:ietf:params:xml:ns:yang:yin:1"
#define LY_CHECK_ERR_RETURN(cond, action, retval) if (cond) { action; return retval; }
#define LY_CHECK_ERR_GOTO(cond, action, label) if (cond) { action; goto label; }
#define LOGMEM(ctx)
#define LOGVAL(ctx, err, flag, node, ...)
#define LOGDBG(level, ...)
#define GETVAL(ctx, var, elem, attr)
#define YIN_CHECK_ARRAY_OVERFLOW_GOTO(ctx, count, size, desc, parent, label)
#define LY_TREE_FOR_SAFE(start, next, elem) for ((elem) = (start); (elem); (elem) = (next))
#define OPT_IDENT 0
#define OPT_MODULE 0
#define OPT_CFG_IGNORE 0
#define OPT_CFG_PARSE 0
#define OPT_CFG_INHERIT 0
#define LYS_VALID_EXT (1 << 0)
#define LYS_VALID_EXT_SUBTREE (1 << 1)
#define LYEXT_OPT_VALID (1 << 0)
#define LYEXT_OPT_VALID_SUBTREE (1 << 1)

char *lydict_insert(struct ly_ctx *ctx, const char *value, size_t len);