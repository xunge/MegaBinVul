#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

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
};

struct vm_area_struct {
    struct list_head anon_vma_chain;
    struct anon_vma *anon_vma;
};

struct anon_vma {
    struct rb_root_cached rb_root;
    struct anon_vma *parent;
    int degree;
    int num_active_vmas;
    int num_children;
};

struct anon_vma_chain {
    struct list_head same_vma;
    struct anon_vma *anon_vma;
    struct rb_node rb;
};

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = container_of((head)->next, typeof(*pos), member), \
         n = container_of(pos->member.next, typeof(*pos), member); \
         &pos->member != (head); \
         pos = n, n = container_of(n->member.next, typeof(*n), member))

#define RB_EMPTY_ROOT(root) ((root)->rb_node == NULL)
#define VM_WARN_ON(cond) ((void)0)

static inline void list_del(struct list_head *entry) {
    entry->next->prev = entry->prev;
    entry->prev->next = entry->next;
}

static inline void anon_vma_interval_tree_remove(struct anon_vma_chain *node, 
                                               struct rb_root_cached *root) {}
static inline void anon_vma_chain_free(struct anon_vma_chain *avc) {}
static inline struct anon_vma *lock_anon_vma_root(struct anon_vma *root, 
                                                struct anon_vma *anon_vma) { return NULL; }
static inline void unlock_anon_vma_root(struct anon_vma *root) {}
static inline void put_anon_vma(struct anon_vma *anon_vma) {}