#include <stddef.h>

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct rb_root {
    struct rb_node *rb_node;
};

#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define rb_link_node(node, parent, rb_link) do { \
    *(rb_link) = (node); \
    (node)->rb_left = NULL; \
    (node)->rb_right = NULL; \
} while (0)
#define rb_insert_color(node, root) do {} while (0)
#define BUG() (*(volatile int *)0 = 0)

struct nvkm_vmm {
    struct rb_root root;
};

struct nvkm_vma {
    unsigned long long addr;
    struct rb_node tree;
};