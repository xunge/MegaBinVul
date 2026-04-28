#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

#define O2NM_MAX_NODES 255
#define O2NM_NODE_ATTR_ADDRESS 0
#define O2NM_NODE_ATTR_PORT 1
#define O2NM_NODE_ATTR_NUM 2

struct config_item;
struct o2nm_node {
    unsigned long nd_set_attributes;
    unsigned int nd_num;
};

struct o2nm_cluster {
    int cl_nodes_lock;
    struct o2nm_node *cl_nodes[O2NM_MAX_NODES];
    unsigned long cl_nodes_bitmap[(O2NM_MAX_NODES + CHAR_BIT - 1) / CHAR_BIT];
};

static inline struct o2nm_cluster *to_o2nm_cluster_from_node(struct o2nm_node *node)
{
    return NULL;
}

static inline struct o2nm_node *to_o2nm_node(struct config_item *item)
{
    return NULL;
}

static inline unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base)
{
    return strtoul(cp, endp, base);
}

#define test_bit(nr, addr) ((*(addr)) & (1UL << (nr)))
#define set_bit(nr, addr) ((*(addr)) |= (1UL << (nr)))
#define test_and_set_bit(nr, addr) ({ int old = test_bit(nr, addr); set_bit(nr, addr); old; })

#define EINVAL 22
#define ERANGE 34
#define EEXIST 17
#define EBUSY 16

#define write_lock(lock) (void)0
#define write_unlock(lock) (void)0