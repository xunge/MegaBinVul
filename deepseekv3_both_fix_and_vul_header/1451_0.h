#include <stddef.h>

#define LIBRAW_EXCEPTION_IO_CORRUPT 1
#define UNDEFINED_LEAF (-1)

typedef struct x3f_huffnode_s {
    struct x3f_huffnode_s *branch[2];
    int leaf;
} x3f_huffnode_t;

typedef struct {
    x3f_huffnode_t *nodes;
    size_t free_node_index;
    size_t total_node_index;
} x3f_hufftree_t;