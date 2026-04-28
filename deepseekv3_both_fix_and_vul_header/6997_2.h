#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long ut64;

typedef struct RSpace {
    // Placeholder for RSpace structure
    int dummy;
} RSpace;

typedef struct RIntervalNode {
    ut64 start;
    ut64 end;
    void *data;
    struct RIntervalNode *left;
    struct RIntervalNode *right;
} RIntervalNode;

typedef struct RIntervalTree {
    RIntervalNode *root;
} RIntervalTree;

typedef enum {
    R_META_TYPE_ANY,
    R_META_TYPE_DATA,
    R_META_TYPE_CODE,
    R_META_TYPE_STRING,
    R_META_TYPE_FORMAT,
    R_META_TYPE_MAGIC,
    R_META_TYPE_HIDE,
    R_META_TYPE_COMMENT
} RAnalMetaType;

typedef struct RAnalMetaItem {
    RAnalMetaType type;
    int subtype;
    RSpace *space;
    char *str;
} RAnalMetaItem;

typedef struct RAnal {
    RIntervalTree meta;
    RSpace meta_spaces;
} RAnal;

#define R_NEW0(x) calloc(1, sizeof(x))
#define R_DIRTY(x)

static RSpace *r_spaces_current(RSpace *spaces) { return spaces; }
static RIntervalNode *find_node_at(RAnal *a, RAnalMetaType type, RSpace *space, ut64 from) { return NULL; }
static void r_interval_tree_insert(RIntervalTree *tree, ut64 from, ut64 to, void *data) {}
static void r_interval_tree_resize(RIntervalTree *tree, RIntervalNode *node, ut64 from, ut64 to) {}