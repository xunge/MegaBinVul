#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define LY_DATA_TYPE_COUNT 10
#define LYS_CONTAINER 1
#define LYS_LIST 2
#define LYS_GROUPING 3
#define LYS_RPC 4
#define LYS_ACTION 5
#define LYS_NOTIF 6
#define LYS_INPUT 7
#define LYS_OUTPUT 8
#define LY_TYPE_LEAFREF 9

struct lys_module {
    const char *name;
    int tpdf_size;
    struct lys_tpdf *tpdf;
    int inc_size;
    struct {
        struct lys_module *submodule;
    } *inc;
};

struct lys_node {
    int nodetype;
};

struct lys_node_container {
    struct lys_node node;
    int tpdf_size;
    struct lys_tpdf *tpdf;
};

struct lys_node_list {
    struct lys_node node;
    int tpdf_size;
    struct lys_tpdf *tpdf;
};

struct lys_node_grp {
    struct lys_node node;
    int tpdf_size;
    struct lys_tpdf *tpdf;
};

struct lys_node_rpc_action {
    struct lys_node node;
    int tpdf_size;
    struct lys_tpdf *tpdf;
};

struct lys_node_notif {
    struct lys_node node;
    int tpdf_size;
    struct lys_tpdf *tpdf;
};

struct lys_node_inout {
    struct lys_node node;
    int tpdf_size;
    struct lys_tpdf *tpdf;
};

struct lys_tpdf {
    const char *name;
    struct {
        int base;
        union {
            struct {
                const char *path;
            } lref;
        } info;
        struct lys_tpdf *der;
    } type;
};

extern struct lys_tpdf **ly_types;
extern const struct lys_node *lys_parent(const struct lys_node *node);
extern struct lys_module *lyp_get_module(const struct lys_module *module, const char *revision, int rev_size, const char *name, int name_len, int implemented);