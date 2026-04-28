#include <stddef.h>

#define DEFAULT_CONTEXT_HANDLE 0
#define EINVAL 22
#define ENOENT 2
#define EINTR 4

struct mutex {
    int dummy;
};

struct idr {
    int dummy;
};

struct drm_device {
    struct mutex struct_mutex;
};

struct drm_file {
    void *driver_priv;
};

struct drm_i915_file_private {
    struct idr context_idr;
    struct mutex context_idr_lock;
};

struct drm_i915_gem_context_destroy {
    unsigned int ctx_id;
    unsigned int pad;
};

struct i915_gem_context {
    unsigned int user_handle;
};

int mutex_lock_interruptible(struct mutex *lock);
void mutex_unlock(struct mutex *lock);
void *idr_remove(struct idr *idr, int id);
void context_close(struct i915_gem_context *ctx);
struct i915_gem_context *i915_gem_context_lookup(struct drm_i915_file_private *file_priv, unsigned int ctx_id);
void i915_gem_context_put(struct i915_gem_context *ctx);