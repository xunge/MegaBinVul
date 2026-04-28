#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct r_rb_node_t RRBNode;
typedef struct r_rb_tree_t RRBTree;
typedef int (*RRBComparator)(const void *a, const void *b, void *user);

struct r_rb_node_t {
    bool red;
    RRBNode *link[2];
    RRBNode *parent;
    void *data;
};

struct r_rb_tree_t {
    RRBNode *root;
    size_t size;
};

#define IS_RED(n) ((n) && (n)->red)
#define r_return_val_if_fail(cond, val) do { if (!(cond)) return (val); } while (0)

static RRBNode* _node_new(void *data, RRBNode *parent);
static void _set_link(RRBNode *parent, RRBNode *child, int dir);
static RRBNode* _rot_once(RRBNode *root, int dir);
static RRBNode* _rot_twice(RRBNode *root, int dir);

#define R_API