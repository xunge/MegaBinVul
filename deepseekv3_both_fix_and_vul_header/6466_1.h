#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

#define ASSOC_ARRAY_FAN_OUT 16
#define ASSOC_ARRAY_KEY_CHUNK_SIZE 8
#define ASSOC_ARRAY_KEY_CHUNK_MASK 7
#define ASSOC_ARRAY_KEY_CHUNK_SHIFT 3
#define ASSOC_ARRAY_LEVEL_STEP 8
#define ASSOC_ARRAY_LEVEL_STEP_MASK 7
#define ASSOC_ARRAY_FAN_MASK (ASSOC_ARRAY_FAN_OUT - 1)
#define GFP_KERNEL 0

struct assoc_array_ptr;
struct assoc_array_node {
    struct assoc_array_ptr *back_pointer;
    unsigned long nr_leaves_on_branch;
    struct assoc_array_ptr *slots[ASSOC_ARRAY_FAN_OUT];
    unsigned long parent_slot;
};

struct assoc_array_shortcut {
    struct assoc_array_ptr *back_pointer;
    int parent_slot;
    struct assoc_array_ptr *next_node;
    int skip_to_level;
    unsigned long index_key[];
};

struct assoc_array_edit {
    struct assoc_array_ptr *new_meta[3];
    struct assoc_array_ptr *excised_meta[1];
    struct assoc_array_ptr **leaf_p;
    struct assoc_array_ptr *dead_leaf;
    struct assoc_array_node *adjust_count_on;
    struct assoc_array_ptr *set_backpointers_to;
    struct assoc_array_ptr **set_backpointers[ASSOC_ARRAY_FAN_OUT];
    struct {
        struct assoc_array_ptr **ptr;
        struct assoc_array_ptr *to;
    } set[1];
    unsigned char segment_cache[ASSOC_ARRAY_FAN_OUT + 1];
    struct {
        struct assoc_array_ptr *root;
    } *array;
};

struct assoc_array_ops {
    bool (*compare_object)(const void *leaf, const void *index_key);
    unsigned long (*get_object_key_chunk)(const void *leaf, int level);
    int (*diff_objects)(const void *a, const void *b);
    unsigned long (*get_key_chunk)(const void *index_key, int level);
};

struct assoc_array_walk_result {
    struct {
        struct assoc_array_node *node;
        int level;
        int slot;
    } terminal_node;
};

static inline void *kzalloc(size_t size, int flags) {
    return calloc(1, size);
}

static inline void pr_devel(const char *fmt, ...) {}
static inline void BUG_ON(int condition) { if (condition) abort(); }

#define assoc_array_ptr_to_leaf(ptr) ((void *)(ptr))
#define assoc_array_leaf_to_ptr(leaf) ((struct assoc_array_ptr *)(leaf))
#define assoc_array_ptr_is_leaf(ptr) ((unsigned long)(ptr) & 1)
#define assoc_array_ptr_to_node(ptr) ((struct assoc_array_node *)((unsigned long)(ptr) & ~1UL))
#define assoc_array_node_to_ptr(node) ((struct assoc_array_ptr *)((unsigned long)(node) | 0x1UL))
#define assoc_array_ptr_is_node(ptr) (!assoc_array_ptr_is_leaf(ptr) && (ptr))
#define assoc_array_ptr_to_shortcut(ptr) ((struct assoc_array_shortcut *)((unsigned long)(ptr) & ~1UL))
#define assoc_array_shortcut_to_ptr(sc) ((struct assoc_array_ptr *)((unsigned long)(sc) | 0x1UL))
#define assoc_array_ptr_is_shortcut(ptr) (!assoc_array_ptr_is_leaf(ptr) && !assoc_array_ptr_is_node(ptr))
#define assoc_array_ptr_is_meta(ptr) (!assoc_array_ptr_is_leaf(ptr))

static inline unsigned long round_up(unsigned long x, unsigned long y) {
    return ((x + y - 1) / y) * y;
}