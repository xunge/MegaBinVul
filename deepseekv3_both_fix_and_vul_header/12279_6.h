#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#include <stddef.h>

typedef struct list_head {
    struct list_head *next;
    struct list_head *prev;
} list_head_t;

struct drm_device;
struct drm_gem_object {
    uint32_t paddr;
    void *vaddr;
    list_head_t base;
};

struct vc4_exec_info {
    struct drm_vc4_submit_cl *args;
    void *shader_rec_u;
    void *uniforms_u;
    void *shader_state;
    uint32_t shader_state_size;
    struct drm_gem_object *exec_bo;
    list_head_t unref_list;
    uint32_t ct0ca;
    void *bin_u;
    void *shader_rec_v;
    uint32_t shader_rec_p;
    uint32_t shader_rec_size;
    void *uniforms_v;
    uint32_t uniforms_p;
    uint32_t uniforms_size;
    uint64_t bin_dep_seqno;
};

struct drm_vc4_submit_cl {
    uint32_t bin_cl_size;
    uint32_t shader_rec_size;
    uint32_t uniforms_size;
    uint32_t shader_rec_count;
    uint64_t bin_cl;
    uint64_t shader_rec;
    uint64_t uniforms;
};

struct vc4_shader_state {
    uint32_t size;
};

struct vc4_bo {
    struct drm_gem_object base;
    void *vaddr;
    uint32_t paddr;
    list_head_t unref_head;
};

#define DRM_ERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define ENOMEM 12
#define EFAULT 14
#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)(-1000))
#define PTR_ERR(ptr) ((int)(intptr_t)(ptr))
#define roundup(x, y) ((((x) + (y) - 1) / (y)) * (y))
#define __user

static inline void *drm_malloc_ab(size_t nmemb, size_t size) {
    return calloc(nmemb, size);
}

static inline void drm_free_large(void *ptr) {
    free(ptr);
}

static inline struct vc4_bo *to_vc4_bo(struct drm_gem_object *bo) {
    return (struct vc4_bo *)bo;
}

static inline void list_add_tail(list_head_t *new, list_head_t *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}

static inline int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline struct vc4_bo *vc4_bo_create(struct drm_device *dev, uint32_t size, bool flag) {
    return NULL;
}

static inline int vc4_validate_bin_cl(struct drm_device *dev, void *vaddr, void *bin, struct vc4_exec_info *exec) {
    return 0;
}

static inline int vc4_validate_shader_recs(struct drm_device *dev, struct vc4_exec_info *exec) {
    return 0;
}

static inline int vc4_wait_for_seqno(struct drm_device *dev, uint64_t seqno, uint64_t mask, bool flag) {
    return 0;
}