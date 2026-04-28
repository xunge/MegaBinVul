#include <stddef.h>

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root_cached {
    struct rb_node *rb_root;
    struct rb_node *rb_leftmost;
};

struct timerqueue_node {
    struct rb_node node;
};

struct timerqueue_head {
    struct rb_root_cached rb_root;
    struct timerqueue_node *next;
};

static inline struct rb_node *rb_first_cached(struct rb_root_cached *root) {
    return root->rb_leftmost;
}

#define rb_entry(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))