#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct config_item;

typedef uint32_t __be32;

struct o2nm_node {
    struct rb_node nd_ip_node;
    __be32 nd_ipv4_address;
    unsigned long nd_set_attributes;
};

struct o2nm_cluster {
    struct rb_node *cl_node_ip_tree;
    unsigned long cl_nodes_lock;
};

#define O2NM_NODE_ATTR_ADDRESS 0
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define EINVAL 22
#define ERANGE 34
#define EEXIST 17
#define EBUSY 16

static inline struct o2nm_cluster *to_o2nm_cluster_from_node(struct o2nm_node *node) { return NULL; }
static inline struct o2nm_node *to_o2nm_node(struct config_item *item) { return NULL; }
static inline bool o2nm_node_ip_tree_lookup(struct o2nm_cluster *cluster, __be32 ipv4_addr, struct rb_node ***p, struct rb_node **parent) { return false; }
static inline void rb_link_node(struct rb_node *node, struct rb_node *parent, struct rb_node **rb_link) {}
static inline void rb_insert_color(struct rb_node *node, struct rb_node **root) {}
static inline void write_lock(unsigned long *lock) {}
static inline void write_unlock(unsigned long *lock) {}
static inline int test_and_set_bit(int nr, volatile unsigned long *addr) { return 0; }

static inline void be32_add_cpu(__be32 *a, unsigned int b) { *a = (*a) + b; }