#include <stdbool.h>
#include <string.h>
#include <stddef.h>

#define R_API

typedef struct r_rbnode_t RRBNode;
typedef struct r_rbtree_t RRBTree;
typedef int (*RRBComparator)(const void *a, const void *b, void *user);

#define r_return_val_if_fail(cond, val) do { if (!(cond)) return (val); } while (0)
#define IS_RED(node) ((node) && (node)->red)

struct r_rbtree_t {
    RRBNode *root;
    size_t size;
};

struct r_rbnode_t {
    RRBNode *link[2];
    RRBNode *parent;
    void *data;
    bool red;
};

static RRBNode *_node_new(void *data, RRBNode *parent) { return NULL; }
static void _set_link(RRBNode *parent, RRBNode *child, int dir) {}
static RRBNode *_rot_once(RRBNode *node, int dir) { return NULL; }
static RRBNode *_rot_twice(RRBNode *node, int dir) { return NULL; }