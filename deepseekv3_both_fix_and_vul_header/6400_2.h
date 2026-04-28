#include <stdbool.h>
#include <stddef.h>

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
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
};

struct timerqueue_head {
    struct rb_root_cached rb_root;
    struct timerqueue_node *next;
    struct rb_root head;
};

#define RB_EMPTY_NODE(node) ((node)->__rb_parent_color == (unsigned long)(node))
#define RB_CLEAR_NODE(node) ((node)->__rb_parent_color = (unsigned long)(node))
#define RB_EMPTY_ROOT(root) ((root)->rb_node == NULL)
#define WARN_ON_ONCE(condition) ((void)0)

static inline void rb_erase(struct rb_node *node, struct rb_root *root) {}
static inline void rb_erase_cached(struct rb_node *node, struct rb_root_cached *root) {}
static inline struct rb_node *rb_next(const struct rb_node *node) { return NULL; }
#define rb_entry_safe(ptr, type, member) (NULL)