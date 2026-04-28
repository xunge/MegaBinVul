#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

struct list_head {
    struct list_head *next;
    struct list_head *prev;
};

struct drm_gem_object {
    void *vaddr;
    uintptr_t paddr;
    struct drm_gem_object *base;
};

struct vc4_bo {
    struct drm_gem_object base;
    struct list_head unref_head;
};

struct drm_device;
struct drm_vc4_submit_cl {
    uint32_t bin_cl_size;
    uint32_t shader_rec_size;
    uint32_t uniforms_size;
    uint32_t shader_rec_count;
    void *bin_cl;
    void *shader_rec;
    void *uniforms;
};

struct vc4_shader_state {
    uint32_t dummy;
};

struct vc4_exec_info {
    struct drm_vc4_submit_cl *args;
    void *shader_rec_u;
    void *uniforms_u;
    void *shader_state;
    uint32_t shader_state_size;
    struct drm_gem_object *exec_bo;
    struct list_head unref_list;
    uintptr_t ct0ca;
    void *bin_u;
    void *shader_rec_v;
    uintptr_t shader_rec_p;
    uint32_t shader_rec_size;
    void *uniforms_v;
    uintptr_t uniforms_p;
    uint32_t uniforms_size;
    uint64_t bin_dep_seqno;
};

#define DRM_ERROR(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define roundup(x, y) ((((x) + ((y) - 1)) / (y)) * (y))
#define IS_ERR(ptr) ((uintptr_t)(ptr) > (uintptr_t)(-1000))
#define PTR_ERR(ptr) ((intptr_t)(ptr))
#define __user
#define to_vc4_bo(ptr) ((struct vc4_bo *)(ptr))
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14

static inline void *drm_malloc_ab(size_t nmemb, size_t size) { return malloc(nmemb * size); }
static inline void drm_free_large(void *ptr) { free(ptr); }
static inline int copy_from_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static inline void list_add_tail(struct list_head *new, struct list_head *head) {
    new->next = head;
    new->prev = head->prev;
    head->prev->next = new;
    head->prev = new;
}
static inline struct vc4_bo *vc4_bo_create(struct drm_device *dev, uint32_t size, bool zero) { return NULL; }
static inline int vc4_validate_bin_cl(struct drm_device *dev, void *vaddr, void *bin, struct vc4_exec_info *exec) { return 0; }
static inline int vc4_validate_shader_recs(struct drm_device *dev, struct vc4_exec_info *exec) { return 0; }
static inline int vc4_wait_for_seqno(struct drm_device *dev, uint64_t seqno, uint64_t timeout, bool interruptible) { return 0; }