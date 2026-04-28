#include <stdint.h>
#include <stddef.h>

#define SEPOL_OK 0
#define SEPOL_ERR -1
#define SEPOL_ENOENT -2

#define CIL_TREE_SKIP_HEAD 1

#define CIL_TRUE 1
#define CIL_FALSE 0

enum cil_pass {
    CIL_PASS_TIF,
    CIL_PASS_MACRO,
    CIL_PASS_BLKABS
};

enum cil_log_level {
    CIL_ERR,
    CIL_INFO
};

enum cil_flavor {
    CIL_CAT,
    CIL_SENS,
    CIL_BLOCK,
    CIL_BLOCKINHERIT,
    CIL_BLOCKABSTRACT,
    CIL_MACRO,
    CIL_TUNABLE,
    CIL_IN,
    CIL_TUNABLEIF,
    CIL_CALL,
    CIL_CONDBLOCK,
    CIL_AVRULE,
    CIL_TYPE_RULE,
    CIL_NAMETYPETRANSITION,
    CIL_BOOLEANIF
};

enum cil_avrule_kind {
    CIL_AVRULE_NEVERALLOW
};

struct cil_tree_node {
    enum cil_flavor flavor;
    void *data;
};

struct cil_args_resolve {
    enum cil_pass pass;
    struct cil_tree_node *block;
    struct cil_tree_node *macro;
    struct cil_tree_node *optional;
    struct cil_tree_node *boolif;
};

struct cil_avrule {
    enum cil_avrule_kind rule_kind;
};

struct cil_block {
    int is_abstract;
};

struct cil_datum {
    char *name;
};

struct cil_optional {
    int enabled;
    struct cil_datum datum;
};

struct cil_booleanif {
    int preserved_tunable;
};

#define NODE(x) ((struct cil_tree_node *)x)

int __cil_resolve_ast_node(struct cil_tree_node *node, void *extra_args);
void cil_tree_log(struct cil_tree_node *node, enum cil_log_level level, const char *fmt, ...);
const char *cil_node_to_string(struct cil_tree_node *node);