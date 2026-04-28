#include <stdlib.h>
#include <stdbool.h>

struct rb_node {
    struct rb_node *rb_left;
    struct rb_node *rb_right;
};

struct list_head {
    struct list_head *next, *prev;
};

struct nvkm_vma {
    struct rb_node tree;
    struct list_head head;
    bool used;
    unsigned long addr;
    unsigned long size;
};

struct nvkm_vmm {
    struct rb_node free;
};

#define kfree free