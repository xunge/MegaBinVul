#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <stdlib.h>

#define ASSOC_ARRAY_FAN_OUT 16
#define ASSOC_ARRAY_KEY_CHUNK_SIZE 4
#define ASSOC_ARRAY_KEY_CHUNK_MASK 3
#define ASSOC_ARRAY_LEVEL_STEP 4
#define ASSOC_ARRAY_LEVEL_STEP_MASK 3
#define ASSOC_ARRAY_KEY_CHUNK_SHIFT 2
#define ASSOC_ARRAY_FAN_MASK 15
#define GFP_KERNEL 0

struct assoc_array_ptr;
struct assoc_array_ops;
struct assoc_array_edit;
struct assoc_array_walk_result;
struct assoc_array_shortcut;
struct assoc_array_node;
struct assoc_array;

struct assoc_array_ops {
    bool (*compare_object)(const void *object, const void *index_key);
    unsigned long (*get_object_key_chunk)(const void *object, int level);
    unsigned long (*get_key_chunk)(const void *index_key, int level);
    int (*diff_objects)(const void *a, const void *b);
};

struct assoc_array_edit {
    struct assoc_array_ptr **leaf_p;
    struct assoc_array_ptr *dead_leaf;
    struct assoc_array_ptr *new_meta[3];
    struct assoc_array_ptr *excised_meta[1];
    struct {
        struct assoc_array_ptr **ptr;
        struct assoc_array_ptr *to;
    } set[1];
    struct assoc_array_ptr **set_backpointers[ASSOC_ARRAY_FAN_OUT];
    struct assoc_array_node *adjust_count_on;
    struct assoc_array_ptr *set_backpointers_to;
    unsigned char segment_cache[ASSOC_ARRAY_FAN_OUT + 1];
    struct assoc_array *array;
};

struct assoc_array_walk_result {
    struct {
        struct assoc_array_node *node;
        int level;
        int slot;
    } terminal_node;
};

struct assoc_array_shortcut {
    struct assoc_array_ptr *back_pointer;
    int parent_slot;
    struct assoc_array_ptr *next_node;
    int skip_to_level;
    unsigned long index_key[];
};

struct assoc_array_node {
    struct assoc_array_ptr *back_pointer;
    int parent_slot;
    struct assoc_array_ptr *slots[ASSOC_ARRAY_FAN_OUT];
    unsigned long nr_leaves_on_branch;
};

struct assoc_array {
    struct assoc_array_ptr *root;
};

static inline bool assoc_array_ptr_is_meta(const struct assoc_array_ptr *ptr) { return false; }
static inline bool assoc_array_ptr_is_node(const struct assoc_array_ptr *ptr) { return false; }
static inline bool assoc_array_ptr_is_leaf(const struct assoc_array_ptr *ptr) { return false; }
static inline void *assoc_array_ptr_to_leaf(const struct assoc_array_ptr *ptr) { return NULL; }
static inline struct assoc_array_node *assoc_array_ptr_to_node(const struct assoc_array_ptr *ptr) { return NULL; }
static inline struct assoc_array_shortcut *assoc_array_ptr_to_shortcut(const struct assoc_array_ptr *ptr) { return NULL; }
static inline struct assoc_array_ptr *assoc_array_node_to_ptr(const struct assoc_array_node *node) { return NULL; }
static inline struct assoc_array_ptr *assoc_array_shortcut_to_ptr(const struct assoc_array_shortcut *shortcut) { return NULL; }

#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define pr_devel(fmt, ...) 

static inline unsigned long round_up(unsigned long x, unsigned long y) {
    return ((x + y - 1) / y) * y;
}

static void *kzalloc(size_t size, int flags) { 
    return calloc(1, size); 
}