#include <stdint.h>
#include <stddef.h>

struct drm_i915_gem_pwrite {
    uint32_t handle;
    uint32_t pad;
    uint64_t offset;
    uint64_t size;
    uint64_t data_ptr;
};

struct drm_gem_object {
    size_t size;
    uint32_t write_domain;
};

struct drm_i915_gem_object {
    int phys_obj;
    uint32_t tiling_mode;
};

struct drm_device {
    unsigned long gtt_total;
};

struct drm_file;

#define ENOENT 2
#define EINVAL 22
#define EFAULT 14

#define VERIFY_READ 0
#define VERIFY_WRITE 1

#define I915_TILING_NONE 0
#define I915_GEM_DOMAIN_CPU (1 << 0)

#define WATCH_PWRITE 0

#define __user

static inline int access_ok(int type, const void *addr, unsigned long size) {
    return 1;
}

static inline struct drm_gem_object *drm_gem_object_lookup(struct drm_device *dev, 
                                                          struct drm_file *file,
                                                          uint32_t handle) {
    return NULL;
}

static inline struct drm_i915_gem_object *to_intel_bo(struct drm_gem_object *obj) {
    return (struct drm_i915_gem_object *)obj;
}

static inline void drm_gem_object_unreference_unlocked(struct drm_gem_object *obj) {
}

static inline int i915_gem_phys_pwrite(struct drm_device *dev, struct drm_gem_object *obj,
                                      struct drm_i915_gem_pwrite *args, struct drm_file *file_priv) {
    return 0;
}

static inline int i915_gem_gtt_pwrite_fast(struct drm_device *dev, struct drm_gem_object *obj,
                                          struct drm_i915_gem_pwrite *args, struct drm_file *file_priv) {
    return 0;
}

static inline int i915_gem_gtt_pwrite_slow(struct drm_device *dev, struct drm_gem_object *obj,
                                          struct drm_i915_gem_pwrite *args, struct drm_file *file_priv) {
    return 0;
}

static inline int i915_gem_object_needs_bit17_swizzle(struct drm_gem_object *obj) {
    return 0;
}

static inline int i915_gem_shmem_pwrite_slow(struct drm_device *dev, struct drm_gem_object *obj,
                                            struct drm_i915_gem_pwrite *args, struct drm_file *file_priv) {
    return 0;
}

static inline int i915_gem_shmem_pwrite_fast(struct drm_device *dev, struct drm_gem_object *obj,
                                            struct drm_i915_gem_pwrite *args, struct drm_file *file_priv) {
    return 0;
}