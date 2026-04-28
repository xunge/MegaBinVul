#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct nvkm_device;
struct nvkm_memory;

struct rb_node {
    unsigned long __rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
};

struct rb_root {
    struct rb_node *rb_node;
};

struct list_head {
    struct list_head *next, *prev;
};

struct nvkm_subdev {
    struct nvkm_device *device;
};

struct nvkm_mmu {
    struct nvkm_subdev subdev;
};

struct nvkm_vma {
    struct nvkm_memory *memory;
    struct list_head head;
    struct rb_node tree;
    bool part;
    unsigned long size;
    void *tags;
    struct nvkm_vma *prev;
    struct nvkm_vma *next;
};

struct nvkm_vmm {
    struct rb_root root;
    struct nvkm_mmu *mmu;
};

void nvkm_memory_tags_put(struct nvkm_memory *, struct nvkm_device *, void **);
void nvkm_memory_unref(struct nvkm_memory **);

static inline void rb_erase(struct rb_node *node, struct rb_root *root) {}
static inline void list_del(struct list_head *entry) {}
static inline void kfree(void *ptr) { free(ptr); }

static inline struct nvkm_vma *node(struct nvkm_vma *vma, const char *type)
{
    if (!strcmp(type, "prev"))
        return vma->prev;
    else if (!strcmp(type, "next"))
        return vma->next;
    return NULL;
}