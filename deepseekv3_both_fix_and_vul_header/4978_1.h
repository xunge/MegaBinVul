#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define ASSOC_ARRAY_KEY_CHUNK_SIZE 4
#define ASSOC_ARRAY_KEY_CHUNK_SHIFT 2
#define ASSOC_ARRAY_FAN_OUT 16

struct assoc_array;
struct assoc_array_ops;
struct assoc_array_shortcut;
struct assoc_array_node;
struct assoc_array_edit;
struct assoc_array_ptr;

enum {
    ASSOC_ARRAY_PTR_META_TYPE = 3,
};

#define assoc_array_ptr_is_meta(p) ((unsigned long)(p) & ASSOC_ARRAY_PTR_META_TYPE)
#define assoc_array_ptr_is_shortcut(p) (assoc_array_ptr_is_meta(p) && (unsigned long)(p) & 1)
#define assoc_array_ptr_is_node(p) (assoc_array_ptr_is_meta(p) && !((unsigned long)(p) & 1))
#define assoc_array_ptr_is_leaf(p) (!assoc_array_ptr_is_meta(p))

#define assoc_array_ptr_to_shortcut(p) ((struct assoc_array_shortcut *)((unsigned long)(p) & ~1UL))
#define assoc_array_ptr_to_node(p) ((struct assoc_array_node *)((unsigned long)(p) & ~3UL))
#define assoc_array_ptr_to_leaf(p) ((void *)((unsigned long)(p) & ~3UL))

#define assoc_array_shortcut_to_ptr(p) ((struct assoc_array_ptr *)((unsigned long)(p) | 1UL))
#define assoc_array_node_to_ptr(p) ((struct assoc_array_ptr *)((unsigned long)(p) | 2UL))

struct assoc_array_ptr {
    unsigned long value;
};

struct assoc_array {
    struct assoc_array_ptr *root;
    unsigned long nr_leaves_on_tree;
};

struct assoc_array_ops {
    // operation function pointers would be defined here
};

struct assoc_array_shortcut {
    struct assoc_array_ptr *back_pointer;
    unsigned long parent_slot;
    struct assoc_array_ptr *next_node;
    unsigned long skip_to_level;
    unsigned long index_key[];
};

struct assoc_array_node {
    struct assoc_array_ptr *back_pointer;
    unsigned long parent_slot;
    struct assoc_array_ptr *slots[ASSOC_ARRAY_FAN_OUT];
    unsigned long nr_leaves_on_branch;
};

struct assoc_array_edit {
    struct assoc_array *array;
    const struct assoc_array_ops *ops;
    const struct assoc_array_ops *ops_for_excised_subtree;
    struct {
        struct assoc_array_ptr **ptr;
        struct assoc_array_ptr *to;
    } set[1];
    struct assoc_array_ptr *excised_subtree;
};

#define GFP_KERNEL 0
#define ENOMEM 12

static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }

#define pr_devel(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline unsigned long round_up(unsigned long x, unsigned long y)
{
    return ((x + y - 1) / y) * y;
}

void assoc_array_apply_edit(struct assoc_array_edit *edit);
void assoc_array_destroy_subtree(struct assoc_array_ptr *root, const struct assoc_array_ops *ops);