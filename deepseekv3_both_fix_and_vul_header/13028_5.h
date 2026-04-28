#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <errno.h>

typedef uint32_t u32;
typedef uint64_t u64;

struct nvkm_object {
    struct nvkm_client *client;
};

struct nvkm_uvmm {
    struct nvkm_object object;
    struct nvkm_vmm *vmm;
};

struct nvkm_client {
    bool super;
};

struct nvkm_vmm {
    int mutex;
};

struct nvkm_vma {
    u64 addr;
    u64 size;
    bool user;
    bool busy;
    bool part;
    bool mapref;
    int refd;
    struct nvkm_memory *memory;
};

struct nvkm_memory {};

struct nvif_vmm_map_v0 {
    u64 addr;
    u64 size;
    u64 memory;
    u64 offset;
};

#define NVKM_VMA_PAGE_NONE 0
#define VMM_DEBUG(vmm, fmt, ...) do {} while (0)
#define IS_ERR(x) ((uintptr_t)(x) > (uintptr_t)(-1000))
#define PTR_ERR(x) ((int)(intptr_t)(x))

static inline void mutex_lock(int *lock) {}
static inline void mutex_unlock(int *lock) {}
static inline int nvif_unpack(int ret, void **argv, u32 *argc, struct nvif_vmm_map_v0 v0, int a, int b, bool c) { return 0; }
static inline struct nvkm_memory *nvkm_umem_search(struct nvkm_client *client, u64 handle) { return NULL; }
static inline struct nvkm_vma *nvkm_vmm_node_search(struct nvkm_vmm *vmm, u64 addr) { return NULL; }
static inline struct nvkm_vma *nvkm_vma_tail(struct nvkm_vma *vma, u64 tail) { return NULL; }
static inline void nvkm_vmm_node_insert(struct nvkm_vmm *vmm, struct nvkm_vma *vma) {}
static inline void nvkm_vmm_unmap_region(struct nvkm_vmm *vmm, struct nvkm_vma *vma) {}
static inline int nvkm_memory_map(struct nvkm_memory *memory, u64 offset, struct nvkm_vmm *vmm, struct nvkm_vma *vma, void *argv, u32 argc) { return 0; }
static inline void nvkm_memory_unref(struct nvkm_memory **memory) {}