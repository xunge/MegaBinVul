#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint64_t u64;

struct nvkm_memory;

struct nvkm_vmm;
struct nvkm_vma;
struct nvkm_vmm_page;
struct nvkm_vmm_func;

enum {
    NVKM_VMA_PAGE_NONE
};

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct nvkm_vma {
    bool part;
    bool mapref;
    bool sparse;
    bool used;
    bool user;
    struct nvkm_memory *memory;
    u8 refd;
    u8 page;
    u64 addr;
    u64 size;
    struct rb_node tree;
};

struct nvkm_vmm {
    struct rb_root root;
    struct nvkm_vmm_func *func;
};

struct nvkm_vmm_page {
    // members unknown
};

struct nvkm_vmm_func {
    struct nvkm_vmm_page *page;
    // other members unknown
};

static inline struct nvkm_vma *node(struct nvkm_vma *prev, struct nvkm_vma *next)
{
    return next;
}

static inline void rb_erase(struct rb_node *node, struct rb_root *root) {}
static inline void nvkm_vmm_ptes_unmap_put(struct nvkm_vmm *vmm, const struct nvkm_vmm_page *page, u64 addr, u64 size, bool sparse) {}
static inline void nvkm_vmm_ptes_put(struct nvkm_vmm *vmm, const struct nvkm_vmm_page *page, u64 addr, u64 size) {}
static inline void nvkm_vmm_unmap_region(struct nvkm_vmm *vmm, struct nvkm_vma *vma) {}
static inline void nvkm_vmm_ptes_sparse_put(struct nvkm_vmm *vmm, const struct nvkm_vmm_page *page, u64 addr, u64 size) {}
static inline void nvkm_vmm_ptes_sparse(struct nvkm_vmm *vmm, u64 addr, u64 size, bool sparse) {}
static inline void nvkm_vmm_put_region(struct nvkm_vmm *vmm, struct nvkm_vma *vma) {}

#define BUG_ON(cond) ((void)(cond))