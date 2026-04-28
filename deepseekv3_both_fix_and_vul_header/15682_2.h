#include <stdbool.h>
#include <stddef.h>

#define likely(x)       __builtin_expect(!!(x), 1)
#define unlikely(x)     __builtin_expect(!!(x), 0)

#define VMA_LOCK_MISS   1
#define VMA_LOCK_ABORT  2

struct maple_tree {
    // Minimal definition for compilation
    void *root;
};

struct ma_state {
    struct maple_tree *tree;
    unsigned long index;
    unsigned long last;
    void *node;
    void *alloc;
    unsigned int mas_flags;
};

struct anon_vma {
    // Minimal definition for compilation
    void *root;
};

struct vm_area_struct {
    unsigned long vm_start;
    unsigned long vm_end;
    struct anon_vma *anon_vma;
    bool detached;
};

struct mm_struct {
    struct maple_tree mm_mt;
};

bool vma_is_anonymous(struct vm_area_struct *vma);
bool vma_is_tcp(struct vm_area_struct *vma);
bool vma_start_read(struct vm_area_struct *vma);
void vma_end_read(struct vm_area_struct *vma);
bool userfaultfd_armed(struct vm_area_struct *vma);
void count_vm_vma_lock_event(int event);
struct vm_area_struct *mas_walk(struct ma_state *mas);
void rcu_read_lock(void);
void rcu_read_unlock(void);

#define MA_STATE(name, mt, first, end) \
    struct ma_state name = {           \
        .tree = mt,                    \
        .index = first,                \
        .last = end,                   \
        .node = NULL,                  \
        .alloc = NULL,                 \
        .mas_flags = 0,                \
    }