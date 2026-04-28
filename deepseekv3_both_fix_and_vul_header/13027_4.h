#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define NVKM_VMA_PAGE_NONE 0
#define EINVAL 22
#define ENOSPC 28
#define ENOMEM 12

#define VMM_TRACE(vmm, fmt, ...)
#define VMM_DEBUG(vmm, fmt, ...)
#define max_t(type, x, y) ((x) > (y) ? (x) : (y))
#define ALIGN(x, a) (((x) + (a) - 1) & ~((a) - 1))
#define ALIGN_DOWN(x, a) ((x) & ~((a) - 1))
#define IS_ALIGNED(x, a) (((x) & ((typeof(x))(a) - 1)) == 0)
#define unlikely(x) (x)

typedef uint8_t u8;
typedef uint64_t u64;

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct rb_root {
    struct rb_node *rb_node;
};

#define rb_entry(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))
#define rb_next(node) ((node)->rb_right)
#define rb_erase(node, root)

struct nvkm_vmm;
struct nvkm_vma;
struct nvkm_vmm_page {
    u8 shift;
};

struct nvkm_vmm_func {
    struct nvkm_vmm_page *page;
    u64 page_block;
};

struct nvkm_vma {
    struct rb_node tree;
    u64 addr;
    u64 size;
    int page;
    bool mapref;
    bool sparse;
    bool used;
    int refd;
    struct nvkm_vma *prev;
    struct nvkm_vma *next;
};

struct nvkm_vmm {
    struct rb_root free;
    struct nvkm_vmm_func *func;
};

struct nvkm_vma *nvkm_vma_tail(struct nvkm_vma *vma, u64 size);
void nvkm_vmm_put_region(struct nvkm_vmm *vmm, struct nvkm_vma *vma);
void nvkm_vmm_free_insert(struct nvkm_vmm *vmm, struct nvkm_vma *vma);
int nvkm_vmm_ptes_sparse_get(struct nvkm_vmm *vmm, const struct nvkm_vmm_page *page, u64 addr, u64 size);
int nvkm_vmm_ptes_sparse(struct nvkm_vmm *vmm, u64 addr, u64 size, bool map);
int nvkm_vmm_ptes_get(struct nvkm_vmm *vmm, const struct nvkm_vmm_page *page, u64 addr, u64 size);
void nvkm_vmm_node_insert(struct nvkm_vmm *vmm, struct nvkm_vma *vma);

#define node(vma, member) ((vma)->member)