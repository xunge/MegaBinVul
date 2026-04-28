#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct rb_root_cached {
    struct rb_root rb_root;
    struct rb_node *rb_leftmost;
};

struct timerqueue_node {
    struct rb_node node;
    unsigned long expires;
};

struct timerqueue_head {
    union {
        struct rb_root head;
        struct rb_root_cached rb_root;
    };
    struct timerqueue_node *next;
};

#define RB_EMPTY_NODE(node) ((node)->rb_left == NULL && (node)->rb_right == NULL)
#define WARN_ON_ONCE(cond) do { if (cond) abort(); } while (0)

void rb_link_node(struct rb_node *node, struct rb_node *parent, struct rb_node **rb_link);
void rb_insert_color(struct rb_node *node, struct rb_root *root);
void rb_insert_color_cached(struct rb_node *node, struct rb_root_cached *root, bool leftmost);

#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))