#include <stddef.h>

struct list_head {
    struct list_head *next, *prev;
};

struct vm_area_struct {
    struct anon_vma *anon_vma;
    struct list_head anon_vma_chain;
};

struct anon_vma {
    unsigned long num_children;
    unsigned long num_active_vmas;
    unsigned long degree;
};

struct anon_vma_chain {
    struct anon_vma *anon_vma;
    struct list_head same_vma;
};

#define GFP_NOWAIT 0
#define __GFP_NOWARN 0
#define GFP_KERNEL 0
#define ENOMEM 12

#define unlikely(x) (x)
#define list_for_each_entry_reverse(pos, head, member) \
    for (struct list_head *_tmp = (head)->prev; \
         _tmp != (head) && \
         ({ pos = (typeof(*pos)*)((char*)_tmp - offsetof(typeof(*pos), member)); 1; }); \
         _tmp = _tmp->prev)

static inline struct anon_vma_chain *anon_vma_chain_alloc(int gfp) { return NULL; }
static inline void unlock_anon_vma_root(struct anon_vma *root) {}
static inline struct anon_vma *lock_anon_vma_root(struct anon_vma *root, struct anon_vma *anon_vma) { return NULL; }
static inline void anon_vma_chain_link(struct vm_area_struct *dst, struct anon_vma_chain *avc, struct anon_vma *anon_vma) {}
static inline void unlink_anon_vmas(struct vm_area_struct *dst) {}