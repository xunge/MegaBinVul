#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>

struct config_item;

struct o2nm_node {
    unsigned long nd_set_attributes;
    int nd_num;
    int nd_local;
};

struct o2nm_cluster {
    int cl_has_local;
    int cl_local_node;
};

#define O2NM_NODE_ATTR_ADDRESS 0
#define O2NM_NODE_ATTR_NUM 1
#define O2NM_NODE_ATTR_PORT 2
#define O2NM_INVALID_NODE_NUM (-1)
#define EINVAL 22
#define EBUSY 16

static inline struct o2nm_node *to_o2nm_node(struct config_item *item) { return NULL; }
static inline struct o2nm_cluster *to_o2nm_cluster_from_node(struct o2nm_node *node) { return NULL; }
static int o2net_start_listening(struct o2nm_node *node) { return 0; }
static void o2net_stop_listening(struct o2nm_node *node) {}

static int test_bit(int nr, const volatile unsigned long *addr) {
    return (*addr & (1UL << nr)) != 0;
}

static unsigned long simple_strtoul(const char *cp, char **endp, unsigned int base) {
    return strtoul(cp, endp, base);
}