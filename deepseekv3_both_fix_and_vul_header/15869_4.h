#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

struct lys_node {
    struct lys_module *module;
    unsigned int flags;
    const char *name;
    const char *dflt;
};

struct lys_node_list {
    struct lys_node node;
    struct lys_module *module;
    unsigned int keys_size;
    struct lys_node **keys;
    struct lys_node *child;
    unsigned int flags;
    const char *name;
};

struct lys_module {
    struct ly_ctx *ctx;
};

struct ly_ctx;

enum LYS_GETNEXT_NOSTATECHECK {
    LYS_GETNEXT_NOSTATECHECK
};

enum LYS_NODE {
    LYS_LEAF
};

enum LYS_PATH_FIRST_PREFIX {
    LYS_PATH_FIRST_PREFIX
};

enum ILO_OPT {
    ILO_STORE,
    ILO_LOG
};

enum LOG_VAL {
    LYE_INRESOLV,
    LY_VLOG_LYS
};

extern enum ILO_OPT log_opt;

extern int LOGVAL(struct ly_ctx *ctx, enum LOG_VAL code, int type, struct lys_node_list *list, const char *msg1, const char *msg2);
extern int LOGWRN(struct ly_ctx *ctx, const char *fmt, ...);
extern struct lys_module *lys_node_module(struct lys_node *node);
extern int lys_getnext_data(struct lys_module *module, struct lys_node *parent, const char *name, int nam_len, enum LYS_NODE node_type, ...);
extern int check_key(struct lys_node_list *list, int i, const char *keys_str, int len);
extern int lyp_check_status(unsigned int parent_flags, struct lys_module *parent_module, const char *parent_name, unsigned int node_flags, struct lys_module *node_module, const char *node_name, struct lys_node *node);
extern char *lys_path(struct lys_node *node, enum LYS_PATH_FIRST_PREFIX flag);