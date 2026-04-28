#include <stdlib.h>

#define HUF_TREE_MAX_NODES(leaves) (2*(leaves) - 1)

typedef struct x3f_huffnode_s {
    int branch[2];
} x3f_huffnode_t;

typedef struct x3f_hufftree_s {
    int free_node_index;
    int total_node_index;
    x3f_huffnode_t *nodes;
} x3f_hufftree_t;