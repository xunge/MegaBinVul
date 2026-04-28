#include <stddef.h>
#include <sys/types.h>
#include <errno.h>
#include <stdint.h>

struct drm_device;
struct drm_file;

struct drm_gem_object {
    size_t size;
};

struct drm_i915_gem_object {
};

struct drm_i915_gem_pread {
    uint32_t handle;
    uint64_t offset;
    uint64_t size;
    uint64_t data_ptr;
};

#define ENOENT 2
#define EINVAL 22
#define EFAULT 14
#define VERIFY_WRITE 1
#define __user

static inline int access_ok(int type, const void *addr, unsigned long size) {
    return 1;
}

static inline struct drm_gem_object *drm_gem_object_lookup(struct drm_device *dev, 
                                                         struct drm_file *file_priv,
                                                         uint32_t handle) {
    return NULL;
}

static inline struct drm_i915_gem_object *to_intel_bo(struct drm_gem_object *obj) {
    return NULL;
}

static inline int i915_gem_object_needs_bit17_swizzle(struct drm_gem_object *obj) {
    return 0;
}

static inline int i915_gem_shmem_pread_slow(struct drm_device *dev,
                                          struct drm_gem_object *obj,
                                          struct drm_i915_gem_pread *args,
                                          struct drm_file *file_priv) {
    return 0;
}

static inline int i915_gem_shmem_pread_fast(struct drm_device *dev,
                                          struct drm_gem_object *obj,
                                          struct drm_i915_gem_pread *args,
                                          struct drm_file *file_priv) {
    return 0;
}

static inline void drm_gem_object_unreference_unlocked(struct drm_gem_object *obj) {
}