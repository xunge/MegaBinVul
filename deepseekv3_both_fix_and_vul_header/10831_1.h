#include <linux/types.h>
#include <stddef.h>

struct config_item {
    struct config_item *ci_parent;
};

struct o2nm_node {
    struct config_item nd_item;
};

struct o2nm_cluster;

static struct o2nm_cluster *to_o2nm_cluster(struct config_item *item);