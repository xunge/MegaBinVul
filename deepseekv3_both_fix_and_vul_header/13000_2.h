#include <stdbool.h>
#include <stdint.h>

typedef uint32_t u32;

struct drm_plane_state {
    struct drm_framebuffer *fb;
};

struct drm_framebuffer;

struct drm_gem_object;
struct drm_gem_cma_object;
struct sg_table;
struct scatterlist;

struct malidp_plane_state {
    struct drm_plane_state base;
    int n_planes;
};

struct drm_gem_object_funcs {
    struct sg_table *(*get_sg_table)(struct drm_gem_object *obj);
};

struct drm_gem_object {
    struct drm_gem_object_funcs *funcs;
};

struct drm_gem_cma_object {
    struct sg_table *sgt;
};

struct sg_table {
    struct scatterlist *sgl;
};

struct scatterlist {
    unsigned long length;
    struct scatterlist *next;
};

#define sg_next(sg) ((sg)->next)
#define kfree(ptr) free(ptr)